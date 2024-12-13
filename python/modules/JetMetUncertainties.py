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
        


class JetMetUncertainties(Module):
    def __init__(
        self,
        jesUncertaintyFile,
        jerFile,
        jetType="AK4PFchs",
        jesUncertaintyNames = [ "Total" ], 
        metInput = lambda event: Object(event, "MET"),
        rhoInput = lambda event: event.fixedGridRhoFastjetAll,
        jetCollection = lambda event: Collection(event,"Jet"),
        lowPtJetCollection = lambda event: Collection(event,"CorrT1METJet"),
        genJetCollection = lambda event: Collection(event,"GenJet"),
        muonCollection = lambda event: Collection(event,"Muon"),
        electronCollection = lambda event: Collection(event,"Electron"),
        propagateToMet = True,
        propagateJER = True,
        outputJetPrefix = 'jets_',
        outputMetPrefix = 'met_',
        jetKeys=[],
        metKeys = [],
        storeTruthKeys=[],
    ):

        self.jesUncertaintyNames = jesUncertaintyNames 
        self.jetType = jetType
        self.metInput = metInput
        self.rhoInput = rhoInput
        self.jetCollection = jetCollection
        self.lowPtJetCollection = lowPtJetCollection
        self.genJetCollection = genJetCollection
        self.muonCollection = muonCollection
        self.electronCollection = electronCollection
        self.propagateToMet = propagateToMet
        self.propagateJER = propagateJER
        self.outputJetPrefix = outputJetPrefix
        self.outputMetPrefix = outputMetPrefix
        self.jetKeys = jetKeys
        if '202' in Module.globalOptions["year"]: 
            if 'puId' in self.jetKeys:
                self.jetKeys.remove('puId')
        self.metKeys = metKeys
        self.storeTruthKeys=storeTruthKeys
        
        # if Module.globalOptions['isData']:
        #     raise Exception("Error - JetMetUncertainty module should never be run on data")
        
        if Module.globalOptions["isData"]:
            run_str = "_Run" + Module.globalOptions["era"]
            if Module.globalOptions["year"] == '2016':
                run_str = "_RunFGH"
            if Module.globalOptions["year"] == '2016preVFP':
                if Module.globalOptions["era"] == 'B' or Module.globalOptions["era"] == 'C' or Module.globalOptions["era"] == 'D':
                    run_str = "_RunBCD"
                if Module.globalOptions["era"] == 'E' or Module.globalOptions["era"] == 'F':
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

        print("\nJETMetUnc for %s from %s " % (self.uncTag, self.jetType))
        self.jesArchive = tarfile.open(jesUncertaintyFile, "r:gz")
        self.jesInputFilePath = tempfile.mkdtemp()
        self.jesArchive.extractall(self.jesInputFilePath)
        self.jesUncertaintyCaculators = {}
        for jesUncertaintyName in self.jesUncertaintyNames:
            filename = "%s/%s_UncertaintySources_%s.txt" % (self.jesInputFilePath, self.uncTag, self.jetType)
            if self.jetType == 'AK4PFchs' and not Module.globalOptions["isData"]:
                filename = "%s/RegroupedV2_%s_UncertaintySources_%s.txt" % (self.jesInputFilePath, self.uncTag, self.jetType)
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
            print("JETMetJR for %s from %s " % (self.jerTag, self.jetType))

        self.jerArchive = tarfile.open(jerFile, "r:gz")
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
        
    def makeNewJetCollection(self,jets,variation):
        newJets = []
        for jet in jets:
            uncFactor = jet.uncertainty_p4[variation].Pt()/jet.pt
            newJet = PhysicsObject(
                jet,
                pt = jet.uncertainty_p4[variation].Pt(), 
                eta = jet.uncertainty_p4[variation].Eta(), 
                phi = jet.uncertainty_p4[variation].Phi(),
                mass = jet.mass,
                keys = self.jetKeys + self.storeTruthKeys if not Module.globalOptions['isData'] else self.jetKeys
            )
            newJet.uncFactor = uncFactor
            newJets.append(newJet)
        newJets = sorted(newJets,key=lambda x: x.pt, reverse=True)
        #print 'jet',variation,newJets[0].pt
        return newJets
        
    def makeNewMetObject(self,met,variation):
        newMet = PhysicsObject(
            met,
            pt = met.uncertainty_p4[variation].Pt(), 
            eta = 0, 
            phi = met.uncertainty_p4[variation].Phi(),
            mass = 0,
            keys = self.metKeys 
        )
        #print 'met',variation,newMet.pt
        return newMet
    
    def analyze(self, event):
        rho = self.rhoInput(event)
        jets = self.jetCollection(event)
        lowPtJets = self.lowPtJetCollection(event)
        genJets = self.genJetCollection(event) if not Module.globalOptions['isData'] else {}
        muons = self.muonCollection(event)
        electrons = self.electronCollection(event)
        
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

            self.jerUncertaintyCalculator.setSeed(event)


        if self.propagateToMet:
            met = self.metInput(event)
        
            def metP4(obj):
                p4 = ROOT.TLorentzVector()
                p4.SetPtEtaPhiM(obj.pt,0,obj.phi,0)
                return p4

            met.uncertainty_p4 = {
                'nominal': metP4(met),
                'jerUp': metP4(met),
                'jerDown': metP4(met)
            }

        for ijet,jet in enumerate(itertools.chain(jets, lowPtJets)):
            jet.uncertainty_p4 = {}
            
            jet.uncertainty_p4['nominal'] = jet.p4() #if data, takes the raw values without jer correction
            if not Module.globalOptions['isData']:
                genJet = genjet_match[jet]
                    
                jerFactor = self.jerUncertaintyCalculator.getFactor(
                    jet,
                    genJet,
                    rho
                )
                jet.uncertainty_p4['nominal'] = jet.p4()*jerFactor['nominal']
                jet.uncertainty_p4['jerUp'] = jet.p4()*jerFactor['up']
                jet.uncertainty_p4['jerDown'] = jet.p4()*jerFactor['down']

            if self.propagateToMet and self.propagateJER:
                leptonP4 = ROOT.TLorentzVector(0,0,0,0)

                for muon in muons:
                    if deltaR(muon, jet) < 0.4:
                        leptonP4 += muon.p4()

                for electron in electrons:
                    if deltaR(electron, jet) < 0.4:
                        leptonP4 += electron.p4()

                if not Module.globalOptions['isData']:
                    if (jet.uncertainty_p4['nominal']-leptonP4).Pt()>self.unclEnThreshold and (jet.neEmEF+jet.chEmEF) < 0.9:
                        met.uncertainty_p4['nominal'] -= jet.p4()*(jerFactor['nominal']-1.)
                        
                    if (jet.uncertainty_p4['jerUp']-leptonP4).Pt()>self.unclEnThreshold and (jet.neEmEF+jet.chEmEF) < 0.9:
                        met.uncertainty_p4['jerUp'] -= jet.p4()*(jerFactor['up']-1.)
                        
                    if (jet.uncertainty_p4['jerDown']-leptonP4).Pt()>self.unclEnThreshold and (jet.neEmEF+jet.chEmEF) < 0.9:
                        met.uncertainty_p4['jerDown'] -= jet.p4()*(jerFactor['down']-1.)

            for jesUncertaintyName in self.jesUncertaintyNames:
                jecDelta = self.jesUncertaintyCaculators[jesUncertaintyName].getDelta(jet.uncertainty_p4['nominal'])
                jet.uncertainty_p4['jes'+jesUncertaintyName+"Up"] = jet.uncertainty_p4['nominal']*(1.+jecDelta)
                jet.uncertainty_p4['jes'+jesUncertaintyName+"Down"] = jet.uncertainty_p4['nominal']*(1.-jecDelta)

        if self.propagateToMet:
            for jesUncertaintyName in self.jesUncertaintyNames: 
                for mode in ["Up","Down"]:
                    if self.propagateJER:
                        met.uncertainty_p4['jes'+jesUncertaintyName+mode] = met.uncertainty_p4['nominal']
                    else:
                        met.uncertainty_p4['jes'+jesUncertaintyName+mode] = metP4(met)
                        
                    for jet in jets:
                        if jet.uncertainty_p4['jes'+jesUncertaintyName+mode].Pt()>self.unclEnThreshold and (jet.neEmEF+jet.chEmEF) < 0.9:
                            met.uncertainty_p4['jes'+jesUncertaintyName+mode] -= jet.uncertainty_p4['jes'+jesUncertaintyName+mode]-jet.uncertainty_p4['nominal']

            unclMetDelta = ROOT.TLorentzVector()
            unclMetDelta.SetXYZM(
                met.MetUnclustEnUpDeltaX,
                met.MetUnclustEnUpDeltaY,
                0,
                0
            )    
            met.uncertainty_p4['unclEnUp'] = met.uncertainty_p4['nominal']+unclMetDelta
            met.uncertainty_p4['unclEnDown'] = met.uncertainty_p4['nominal']-unclMetDelta


        setattr(event,self.outputJetPrefix+"nominal",self.makeNewJetCollection(jets,"nominal"))
        if self.propagateToMet:
            setattr(event,self.outputMetPrefix+"nominal",self.makeNewMetObject(met,"nominal"))

        for jesUncertaintyName in self.jesUncertaintyNames:
            for mode in ["Up","Down"]:
                setattr(event,self.outputJetPrefix+"jes"+jesUncertaintyName+mode,self.makeNewJetCollection(jets,"jes"+jesUncertaintyName+mode))
                if self.propagateToMet:
                    setattr(event,self.outputMetPrefix+"jes"+jesUncertaintyName+mode,self.makeNewMetObject(met,"jes"+jesUncertaintyName+mode))

        if not Module.globalOptions['isData']:
            for mode in ["Up","Down"]:
                setattr(event,self.outputJetPrefix+"jer"+mode,self.makeNewJetCollection(jets,"jer"+mode))
                if self.propagateToMet:
                    setattr(event,self.outputMetPrefix+"jer"+mode,self.makeNewMetObject(met,"jer"+mode))
                    setattr(event,self.outputMetPrefix+"unclEn"+mode,self.makeNewMetObject(met,"unclEn"+mode))

        return True

