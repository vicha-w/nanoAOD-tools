import os
import sys
import math
import json
import ROOT
import random
import itertools
import tarfile
import tempfile
import re

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection, Object
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
from PhysicsTools.NanoAODTools.postprocessing.tools import matchObjectCollection, matchObjectCollectionMultiple

from utils import PhysicsObject, deltaR

class JERUncertaintyCalculator():
    def __init__(self,jerResolutionFileName,jerSFUncertaintyFileName):
        self.jerResolutionFileName = os.path.expandvars(jerResolutionFileName)
        self.jerSFUncertaintyFileName = os.path.expandvars(jerSFUncertaintyFileName)

        if not os.path.exists(self.jerResolutionFileName):
            raise Exception("File '"+self.jerResolutionFileName+"' does not exists")
        self.jer = ROOT.PyJetResolutionWrapper(self.jerResolutionFileName)

        if not os.path.exists(self.jerSFUncertaintyFileName):
            raise Exception("File '"+self.jerSFUncertaintyFileName+"' does not exists")
        self.jerSF_and_Uncertainty = ROOT.PyJetResolutionScaleFactorWrapper(self.jerSFUncertaintyFileName)
        
        self.params_sf_and_uncertainty = ROOT.PyJetParametersWrapper()
        self.params_resolution = ROOT.PyJetParametersWrapper()
        
        self.rnd = ROOT.TRandom3(12345)
        
    def setSeed(self,event):
        """Set seed deterministically."""
        # (cf. https://github.com/cms-sw/cmssw/blob/master/PhysicsTools/PatUtils/interface/SmearedJetProducerT.h)
        runnum  = long(event.run) << 20
        luminum = long(event.luminosityBlock) << 10
        evtnum  = event.event
        jet0eta = long(event.Jet_eta[0]/0.01 if event.nJet>0 else 0)
        seed    = 1L + runnum + evtnum + luminum + jet0eta
        self.rnd.SetSeed(seed)
        
    def getResolution(self,jetIn,rho):
        if hasattr( jetIn, "p4"):
            jet = jetIn.p4()
        else:
            jet = jetIn
        self.params_resolution.setJetEta(jet.Eta())
        self.params_resolution.setJetPt(jet.Pt())
        self.params_resolution.setRho(rho)

        return self.jer.getResolution(self.params_resolution)
        
    def getFactor(self, jetIn, genJetIn, rho):
        
        if hasattr( jetIn, "p4"):
            jet = jetIn.p4()
        else:
            jet = jetIn
        if hasattr( genJetIn, "p4"):
            genJet = genJetIn.p4()
        else:
            genJet = genJetIn
        
        
        #--------------------------------------------------------------------------------------------
        # CV: Smear jet pT to account for measured difference in JER between data and simulation.
        #     The function computes the nominal smeared jet pT simultaneously with the JER up and down shifts,
        #     in order to use the same random number to smear all three (for consistency reasons).
        #
        #     The implementation of this function follows PhysicsTools/PatUtils/interface/SmearedJetProducerT.h 
        #
        #--------------------------------------------------------------------------------------------

        if not (jet.Perp() > 0.):
            print("WARNING: jet pT = %1.1f !!" % jet.Perp())
            return ( jet.Perp(), jet.Perp(), jet.Perp() )
        
        #--------------------------------------------------------------------------------------------
        # CV: define enums needed to access JER scale factors and uncertainties
        #    (cf. CondFormats/JetMETObjects/interface/JetResolutionObject.h) 
        enum_nominal         = 0
        enum_shift_up        = 2
        enum_shift_down      = 1
        #--------------------------------------------------------------------------------------------
        
        jet_pt_sf_and_uncertainty = {}
        for enum_central_or_shift in [ enum_nominal, enum_shift_up, enum_shift_down ]:
            self.params_sf_and_uncertainty.setJetEta(jet.Eta())
            self.params_sf_and_uncertainty.setJetPt(jet.Pt())
            self.params_sf_and_uncertainty.setRho(rho)
            jet_pt_sf_and_uncertainty[enum_central_or_shift] = self.jerSF_and_Uncertainty.getScaleFactor(self.params_sf_and_uncertainty, enum_central_or_shift)
        
        smear_vals = {}
        if genJet:
          for central_or_shift in [ enum_nominal, enum_shift_up, enum_shift_down ]:
              #
              # Case 1: we have a "good" generator level jet matched to the reconstructed jet
              #
              dPt = jet.Perp() - genJet.Perp()
              smearFactor = 1. + (jet_pt_sf_and_uncertainty[central_or_shift] - 1.)*dPt/jet.Perp()
              
              # check that smeared jet energy remains positive,
              # as the direction of the jet would change ("flip") otherwise - and this is not what we want
              if (smearFactor*jet.Perp()) < 1.e-2:
                smearFactor = 1.e-2
              smear_vals[central_or_shift] = smearFactor
              
        else:
          self.params_resolution.setJetPt(jet.Perp())
          self.params_resolution.setJetEta(jet.Eta())
          self.params_resolution.setRho(rho)
          jet_pt_resolution = self.jer.getResolution(self.params_resolution)
          
          rand = self.rnd.Gaus(0,jet_pt_resolution)
          for central_or_shift in [ enum_nominal, enum_shift_up, enum_shift_down ]:
            if jet_pt_sf_and_uncertainty[central_or_shift] > 1.:
              #
              # Case 2: we don't have a generator level jet. Smear jet pT using a random Gaussian variation
              #
              smearFactor = 1. + rand * math.sqrt(jet_pt_sf_and_uncertainty[central_or_shift]**2 - 1.)
            else:
              #
              # Case 3: we cannot smear this jet, as we don't have a generator level jet and the resolution in data is better than the resolution in the simulation,
              #         so we would need to randomly "unsmear" the jet, which is impossible
              #
              smearFactor = 1.
            
            # check that smeared jet energy remains positive,
            # as the direction of the jet would change ("flip") otherwise - and this is not what we want
            if (smearFactor*jet.Perp()) < 1.e-2:
                smearFactor = 1.e-2
            smear_vals[central_or_shift] = smearFactor
        
        return {
            "nominal": smear_vals[enum_nominal], 
            "up": smear_vals[enum_shift_up], 
            "down": smear_vals[enum_shift_down]
        }
        
class JESUncertaintyCalculator():
    def __init__(self,jesUncertaintyFile,jesUncertaintyName):
        self.jesUncertaintyFile = os.path.expandvars(jesUncertaintyFile)
        self.jesUncertaintyName = jesUncertaintyName
        
        if not os.path.exists(self.jesUncertaintyFile):
            raise Exception("File '"+self.jesUncertaintyFile+"' does not exists")
        self.jesParameters = ROOT.JetCorrectorParameters(self.jesUncertaintyFile,self.jesUncertaintyName)
        self.jesUncertainty = ROOT.JetCorrectionUncertainty(self.jesParameters)   

    def getDelta(self,jetIn):
        if hasattr( jetIn, "p4"):
            jet = jetIn.p4()
        else:
            jet = jetIn
        self.jesUncertainty.setJetPt(jet.Pt())
        self.jesUncertainty.setJetEta(jet.Eta())
        return self.jesUncertainty.getUncertainty(True)
        


class JetHOTVRUncertainties(Module):
    def __init__(
        self,
        jesUncertaintyFile,
        jerFile,
        jetType="AK4PFPuppi",
        jesUncertaintyNames = [ "Total" ], 
        rhoInput = lambda event: event.fixedGridRhoFastjetAll,
        subjetCollection = lambda event: Collection(event,"HOTVRSubJets"),
        jetCollection = lambda event: Collection(event, "HOTVRJets"),
        lowPtJetCollection = lambda event: Collection(event,"CorrT1METJet"),
        genJetCollection = lambda event: Collection(event,"GenJet"),
        genSubJetCollection = lambda event: Collection(event,"GenSubJet"),
        outputJetPrefix = 'jets_',
        outputSubJetPrefix = 'subjets_',
        jetKeys=[],
    ):

        self.rhoInput = rhoInput
        self.jetType = jetType
        self.jesUncertaintyNames = jesUncertaintyNames 
        self.jetCollection = jetCollection
        self.subjetCollection = subjetCollection
        self.lowPtJetCollection = lowPtJetCollection
        self.genJetCollection = genJetCollection
        self.genSubJetCollection = genSubJetCollection
        self.outputJetPrefix = outputJetPrefix
        self.outputSubJetPrefix = outputSubJetPrefix
        self.jetKeys = jetKeys

        self.print_out = False

        # if Module.globalOptions['isData']:
        #     raise Exception("Error - JetMetUncertainty module should never be run on data")

        if Module.globalOptions["isData"]:
            run_str = "_Run" + Module.globalOptions["era"]
            if Module.globalOptions["year"] == '2016':
                run_str = "_RunFGH"
            if Module.globalOptions["year"] == '2016preVFP':
                if 'B_' in Module.globalOptions["era"] or Module.globalOptions["era"] == 'C' or Module.globalOptions["era"] == 'D':
                    run_str = "_RunBCD"
                if Module.globalOptions["era"] == 'E' or Module.globalOptions["era"] == 'F-HIPM':
                    run_str = "_RunEF"
            if Module.globalOptions["year"] == '2022':
                run_str = "_RunCD"

            jesUncertaintyFile = jesUncertaintyFile.rsplit("_", 1)[0] + run_str + "_" + jesUncertaintyFile.rsplit("_", 1)[1] + "_DATA.tar.gz"
        else: 
            jesUncertaintyFile = jesUncertaintyFile + "_MC.tar.gz"
        
        match = re.search(r'([^/]+)\.tar.gz$', jesUncertaintyFile)
        if match:
            self.uncTag = match.group(1)
        else:
            print("No match found")

        print("JETMetUnc (HOTVR) for %s from %s " % (self.uncTag, self.jetType))

        self.jesArchive = tarfile.open(jesUncertaintyFile, "r:gz")
        self.jesInputFilePath = tempfile.mkdtemp()
        self.jesArchive.extractall(self.jesInputFilePath)
        self.jesUncertaintyCaculators = {}
        for jesUncertaintyName in self.jesUncertaintyNames:
            filename = "%s/%s_UncertaintySources_%s.txt" % (self.jesInputFilePath, self.uncTag, self.jetType)
            self.jesUncertaintyCaculators[jesUncertaintyName] = JESUncertaintyCalculator(
                filename,
                jesUncertaintyName
            )

        jerFile = jerFile + "_MC.tar.gz"
        match = re.search(r'([^/]+)\.tar.gz$', jerFile)
        if match:
            self.jerTag = match.group(1)
        else:
            print("No match found")
        if not Module.globalOptions["isData"]: 
            print("JETMetJR (HOTVR) for %s from %s " % (self.jerTag, self.jetType))

        self.jerArchive = tarfile.open(
            jerFile, "r:gz")
        self.jerInputFilePath = tempfile.mkdtemp()
        self.jerArchive.extractall(self.jerInputFilePath)
        self.jerUncertaintyCalculator = JERUncertaintyCalculator(
            "%s/%s_PtResolution_%s.txt" % (self.jerInputFilePath, self.jerTag, self.jetType),
            "%s/%s_SF_%s.txt" % (self.jerInputFilePath, self.jerTag, self.jetType),
        )

        self.unclEnThreshold = 15.

    def beginJob(self):
        pass
        
    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        
    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass
        
    def makeNewJetCollection(self, jets, variation, collection_type='jets'):
        newJets = []
        newKeys = self.jetKeys
        if collection_type == 'subjets':
            newKeys = ['_index', 'area']
        for jet in jets:
            if not hasattr(jet, 'uncertainty_p4'): 
                #this takes include in the new collection also the subjets-not linked to jets (which do not have correction applied)
                newJets.append(jet)
            else:
                uncFactor = jet.uncertainty_p4[variation].Pt() / jet.pt
                newJet = PhysicsObject(
                    jet,
                    pt = jet.uncertainty_p4[variation].Pt(), 
                    eta = jet.uncertainty_p4[variation].Eta(), 
                    phi = jet.uncertainty_p4[variation].Phi(),
                    mass = jet.mass,
                    keys = newKeys
                )
                newJet.uncFactor = uncFactor
                newJets.append(newJet)
        newJets = sorted(newJets,key=lambda x: x.pt, reverse=True)
        #print 'jet',variation,newJets[0].pt
        return newJets


    def analyze(self, event):
        rho = self.rhoInput(event)
        jets = self.jetCollection(event)
        subjets = self.subjetCollection(event)
        lowPtJets = self.lowPtJetCollection(event)
        genJets = self.genJetCollection(event) if not Module.globalOptions['isData'] else {}
        gensubJets = self.genSubJetCollection(event) if not Module.globalOptions['isData'] else {}

        for lowPtJet in lowPtJets:
            lowPtJet.pt = lowPtJet.rawPt
            #dummy values
            lowPtJet.rawFactor = 0
            lowPtJet.mass = 0
            lowPtJet.neEmEF = 0
            lowPtJet.chEmEF = 0

        if not Module.globalOptions['isData']:
            def genjet_resolution_matching(jet, genjet):
                resolution = self.jerUncertaintyCalculator.getResolution(jet,rho)
                return abs(jet.pt - genjet.pt) < (3*resolution*jet.pt)

            genjet_match = matchObjectCollection(jets, genJets, dRmax=0.2, presel=genjet_resolution_matching)
            genjet_lowpt_match = matchObjectCollection(lowPtJets, genJets, dRmax=0.2, presel=genjet_resolution_matching)
            genjet_match.update(genjet_lowpt_match)
            gensubjet = matchObjectCollection([subjet for jet in jets for subjet in jet.subjets], gensubJets, dRmax=0.2, presel=genjet_resolution_matching)
            genjet_match.update(gensubjet)

            self.jerUncertaintyCalculator.setSeed(event)

        if self.print_out: print('EVENTO ########')

        for ijet, jet in enumerate(itertools.chain(jets, lowPtJets)):
            # JER/JES correction for subjets in the jet and resummation of the p4
            jet.uncertainty_p4 = {
                'nominal': ROOT.TLorentzVector(0, 0, 0, 0), 
                'jerUp': ROOT.TLorentzVector(0, 0, 0, 0), 
                'jerDown': ROOT.TLorentzVector(0, 0, 0, 0)
            }
            for jesUncertaintyName in self.jesUncertaintyNames:
                jet.uncertainty_p4['jes' + jesUncertaintyName + "Up"] = ROOT.TLorentzVector(0, 0, 0, 0)
                jet.uncertainty_p4['jes' + jesUncertaintyName + "Down"] = ROOT.TLorentzVector(0, 0, 0, 0)

            # N.B.: JES, JER corrections are to be applied only on HOTVR subjets --> https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#Working_point_and_scale_factors
            # first step is to match jet and subjets with correct subjet indexes
            # subjets_in_hotvr = []
            # for isubjet, subjet in enumerate(subjets):
            #     if (jet.subJetIdx1 == subjet._index or 
            #         jet.subJetIdx2 == subjet._index or 
            #         jet.subJetIdx3 == subjet._index or 
            #         (hasattr(jet, 'subJetIdx4') and jet.subJetIdx4 == subjet._index)):
            #         subjets_in_hotvr.append(subjet) 
            # subjets_in_hotvr = sorted(subjets_in_hotvr, key=lambda x: x.pt, reverse=True)

            if not jet.subjets: #subjets_in_hotvr:
                # Assign original jet p4 to all variations
                jet.uncertainty_p4['nominal'] = jet.p4()
                jet.uncertainty_p4['jerUp'] = jet.p4()
                jet.uncertainty_p4['jerDown'] = jet.p4()
                for jesUncertaintyName in self.jesUncertaintyNames:
                    jet.uncertainty_p4['jes' + jesUncertaintyName + "Up"] = jet.p4()
                    jet.uncertainty_p4['jes' + jesUncertaintyName + "Down"] = jet.p4()
                continue 

            else:
                for isubjet, subjet in enumerate(jet.subjets):
                    subjet.uncertainty_p4 = {}

                    if not Module.globalOptions['isData']:
                        genJet = genjet_match[subjet]

                        jerFactor = self.jerUncertaintyCalculator.getFactor(
                            subjet,
                            genJet,
                            rho
                        )
                        subjet.uncertainty_p4['nominal'] = subjet.p4() * jerFactor['nominal']
                        subjet.uncertainty_p4['jerUp'] = subjet.p4() * jerFactor['up']
                        subjet.uncertainty_p4['jerDown'] = subjet.p4() * jerFactor['down']

                        jet.uncertainty_p4['nominal'] += (subjet.p4() * jerFactor['nominal'])
                        jet.uncertainty_p4['jerUp'] += (subjet.p4() * jerFactor['up'])
                        jet.uncertainty_p4['jerDown'] += (subjet.p4() * jerFactor['down'])
                    else:
                        subjet.uncertainty_p4['nominal'] = subjet.p4()
                        jet.uncertainty_p4['nominal'] += subjet.p4()

                    for jesUncertaintyName in self.jesUncertaintyNames:
                        jecDelta = self.jesUncertaintyCaculators[jesUncertaintyName].getDelta(subjet.uncertainty_p4['nominal'])
                        jet.uncertainty_p4['jes' + jesUncertaintyName + "Up"] += (subjet.uncertainty_p4['nominal'] * (1. + jecDelta))
                        jet.uncertainty_p4['jes' + jesUncertaintyName + "Down"] += (subjet.uncertainty_p4['nominal'] * (1. - jecDelta))

                        subjet.uncertainty_p4['jes' + jesUncertaintyName + "Up"] = (subjet.uncertainty_p4['nominal'] * (1. + jecDelta))
                        subjet.uncertainty_p4['jes' + jesUncertaintyName + "Down"] = (subjet.uncertainty_p4['nominal'] * (1. - jecDelta))

                if self.print_out: print('jet {}; nominal pT: {}; non-corrected pT: {}'.format(ijet, jet.uncertainty_p4['nominal'].Pt(), jet.pt))


        setattr(event, self.outputJetPrefix + "nominal", self.makeNewJetCollection(jets, "nominal", collection_type='jets'))
        #for subjets, storing only the subjects collection linked to jets
        setattr(event, self.outputSubJetPrefix + "nominal", self.makeNewJetCollection(
            [subjet for jet in jets for subjet in jet.subjets], 
            "nominal", 
            collection_type='subjets')
        )

        for jesUncertaintyName in self.jesUncertaintyNames:
            for mode in ["Up","Down"]:
                setattr(
                    event, 
                    self.outputJetPrefix + "jes" + jesUncertaintyName + mode, 
                    self.makeNewJetCollection(jets, "jes"+jesUncertaintyName + mode)
                )
                setattr(
                    event, 
                    self.outputSubJetPrefix + "jes" + jesUncertaintyName + mode, 
                    self.makeNewJetCollection([subjet for jet in jets for subjet in jet.subjets], "jes"+jesUncertaintyName + mode, collection_type='subjets')
                )

        if not Module.globalOptions['isData']:
            for mode in ["Up","Down"]:
                setattr(
                    event, 
                    self.outputJetPrefix + "jer" + mode, 
                    self.makeNewJetCollection(jets, "jer" + mode)
                )
                setattr(
                    event, 
                    self.outputSubJetPrefix + "jer" + mode, 
                    self.makeNewJetCollection([subjet for jet in jets for subjet in jet.subjets], "jer" + mode, collection_type='subjets')
                )

        # print([subjet.pt for subjet in subjets])
        # print([subjet.pt for subjet in jets[1].subjets])
        # print([subjet.pt for jet in jets for subjet in jet.subjets])
        # print([subjet.pt for jet in jets for subjet in jet.uncalibrated_subjets])

        
        # ee = self.makeNewJetCollection(
        #     [subjet for jet in jets for subjet in jet.subjets], 
        #     "nominal", 
        #     collection_type='subjets')
        # print([subjet.recalibration_p4.Pt() for subjet in ee])

        

        return True
