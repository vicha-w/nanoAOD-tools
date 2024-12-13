from PhysicsTools.NanoAODTools.modules.JetReCalibrator import JetReCalibrator
from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection, Object
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
import ROOT
import math
import os
import re
import tarfile
import tempfile
import shutil
import numpy as np
import re

ROOT.PyConfig.IgnoreCommandLineOptions = True

from utils import PhysicsObject, deltaR

class HOTVRJetRecalibration(Module):
    def __init__(
            self, 
            jesUncertaintyFile,
            jetType="AK4PFchs", 
            redoJEC=True,
            rhoInput=lambda event: event.fixedGridRhoFastjetAll,
            jetCollection=lambda event: Collection(event,"HOTVRJet"),
            subjetCollection=lambda event: Collection(event,"HOTVRSubJet"),
            outputJetPrefix='hotvrjets_',
            outputSubJetPrefix='hotvrsubjets_',
            jetKeys=[],
        ):

        self.redoJEC = redoJEC
        self.rhoInput = rhoInput
        self.jetCollection = jetCollection
        self.subjetCollection = subjetCollection

        self.outputJetPrefix = outputJetPrefix
        self.outputSubJetPrefix = outputSubJetPrefix

        self.jetKeys = jetKeys

        self.jetBranchName = "HOTVRJet"

        self.rhoBranchName = "fixedGridRhoFastjetAll"
        self.lenVar = "n" + self.jetBranchName

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
            self.globalTag = match.group(1)
        else:
            print("No match found")

        self.jesArchive = tarfile.open(
            jesUncertaintyFile, "r:gz")
        self.jesInputFilePath = tempfile.mkdtemp()
        self.jesArchive.extractall(self.jesInputFilePath)
        print('\nExtracting JEC correction (HOTVR) from {}; globalTag: {}'.format(
            jesUncertaintyFile,
            self.globalTag
        ))

        self.jetReCalibrator = JetReCalibrator(
            self.globalTag,
            jetType,
            True,
            self.jesInputFilePath,
            calculateSeparateCorrections=False,
            calculateType1METCorrection=False)

        # load libraries for accessing JES scale factors and
        # uncertainties from txt files
        for library in [
                "libCondFormatsJetMETObjects", 
                "libPhysicsToolsNanoAODTools"
        ]:
            if library not in ROOT.gSystem.GetLibraries():
                print("Load Library '%s'" % library.replace("lib", ""))
                ROOT.gSystem.Load(library)

        self.puppiCorrFile = ROOT.TFile.Open(
            os.environ['CMSSW_BASE'] +
            "/src/PhysicsTools/NanoAODTools/data/jme/puppiCorr.root")
        self.puppisd_corrGEN = self.puppiCorrFile.Get("puppiJECcorr_gen")
        self.puppisd_corrRECO_cen = self.puppiCorrFile.Get(
            "puppiJECcorr_reco_0eta1v3")
        self.puppisd_corrRECO_for = self.puppiCorrFile.Get(
            "puppiJECcorr_reco_1v3eta2v5")

    def makeNewJetCollection(self, jets, collection_type='jets'):
        newJets = []
        newKeys = self.jetKeys
        if collection_type == 'subjets': 
            newKeys = ['_index', 'area']
        for jet in jets:
            corrFactor = jet.recalibration_p4.Pt() / jet.pt
            newJet = PhysicsObject(
                jet,
                pt = jet.recalibration_p4.Pt(), 
                eta = jet.recalibration_p4.Eta(), 
                phi = jet.recalibration_p4.Phi(),
                mass = jet.mass,
                keys = newKeys
            )
            newJet.corrFactor = corrFactor
            if collection_type == 'jets':
                newJet.subjets = jet.subjets  
            newJets.append(newJet)
        newJets = sorted(newJets, key=lambda x: x.pt, reverse=True)
        #print 'jet',variation,newJets[0].pt
        return newJets

    def beginJob(self):
        pass

    def endJob(self):
        shutil.rmtree(self.jesInputFilePath)

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree

        # self.out.branch("%s_pt_raw" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("%s_pt_nom" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("%s_mass_raw" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("%s_mass_nom" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("%s_msoftdrop_raw" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("%s_msoftdrop_nom" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("%s_groomed_corr_PUPPI" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)
        # self.out.branch("MET_pt_nom", "F")
        # self.out.branch("MET_phi_nom", "F")
        # self.out.branch("%s_corr_JEC" % self.jetBranchName,
        #                 "F",
        #                 lenVar=self.lenVar)

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail,
        go to next event)"""
        jets = self.jetCollection(event)
        subjets = self.subjetCollection(event)
        met = Object(event, "MET")

        jets_pt_raw = []
        jets_pt_nom = []
        jets_mass_raw = []
        jets_mass_nom = []
        jets_msoftdrop_raw = []
        jets_msoftdrop_nom = []
        jets_groomed_corr_PUPPI = []
        jets_corr_JEC = []
        (met_px, met_py) = (met.pt * math.cos(met.phi),
                            met.pt * math.sin(met.phi))
        (met_px_nom, met_py_nom) = (met_px, met_py)
        met_px_nom = met_px
        met_py_nom = met_py

        rho = getattr(event, self.rhoBranchName)

        for ijet, jet in enumerate(jets):
            subjets_in_hotvr = []
            matched_subjets_sum_p4 = ROOT.TLorentzVector(0, 0, 0, 0)  # Sum of matched subjets, used for the uncalibrated 4-vectors
            jet_p4 = ROOT.TLorentzVector()
            jet_p4.SetPtEtaPhiM(jet.pt, jet.eta, jet.phi, jet.mass)

            for isubjet, subjet in enumerate(subjets):
                subjet_pt = subjet.pt
                subjet_mass = subjet.mass

                uncalibrated_p4 = ROOT.TLorentzVector()
                uncalibrated_p4.SetPtEtaPhiM(
                    subjet_pt,
                    subjet.eta,
                    subjet.phi,
                    subjet_mass
                )
                
                # first step is to match jet and subjets with correct subjet indexes
                if (jet.subJetIdx1 == subjet._index or 
                    jet.subJetIdx2 == subjet._index or 
                    jet.subJetIdx3 == subjet._index or 
                    (hasattr(jet, 'subJetIdx4') and jet.subJetIdx4 == subjet._index)):
                    subjets_in_hotvr.append(subjet)
                    matched_subjets_sum_p4 += uncalibrated_p4

                    # N.B.: JES, JER corrections are to be applied only on HOTVR subjets --> https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#Working_point_and_scale_factors
                    if self.redoJEC:
                        (subjet_pt, subjet_mass) = self.jetReCalibrator.correct(subjet, rho)
                        # if abs(subjet_pt/subjet.pt-1)>0.7:
                        #     print ((subjet_pt/subjet.pt-1),subjet.eta,subjet.pt, subjet.mass, jet.eta, rho)
                    subjet.recalibration_p4 = ROOT.TLorentzVector()
                    subjet.recalibration_p4.SetPtEtaPhiM(
                        subjet_pt,
                        subjet.eta,
                        subjet.phi,
                        subjet_mass
                    )

            subjets_in_hotvr = sorted(subjets_in_hotvr, key=lambda x: x.pt, reverse=True)
            setattr(jet, "subjets", subjets_in_hotvr)

            jet.recalibration_p4 = ROOT.TLorentzVector(0, 0, 0, 0)
            # If no subjets are found, assign original jet p4 to recalibration_p4
            if len(subjets_in_hotvr) == 0:
                jet.recalibration_p4.SetPtEtaPhiM(
                    jet.pt,
                    jet.eta,
                    jet.phi,
                    jet.mass
                )
            else:
                unclustered_energy_p4 = jet_p4 - matched_subjets_sum_p4

                for isubjet, subjet in enumerate(subjets_in_hotvr):
                    jet.recalibration_p4 += subjet.recalibration_p4
                jet.recalibration_p4 += unclustered_energy_p4

                # if unclustered_energy_p4.Pt() > 3:
                #     print('\n### Unclustered pT > 3 GeV ###')
                #     print('Before recalibration --> ijet {}, jet pt {}, subjets pt: {}'.format(
                #         ijet, 
                #         jet.pt, 
                #         [subjet.pt for subjet in subjets_in_hotvr], 
                #         # sum(subjet.pt for subjet in subjets_in_hotvr)
                #     ))
                #     print('After recalibration --> ijet {}, jet pt after re-summ: {}, subjets pt: {}, unclustered pt: {}'.format(
                #         ijet,
                #         jet.recalibration_p4.Pt(), 
                #         [subjet.recalibration_p4.Pt() for subjet in subjets_in_hotvr],
                #         unclustered_energy_p4.Pt()
                #     ))


                    # subjet_pt_nom = subjet_pt  # don't smear resolution in data
                    # if subjet_pt_nom < 0.0:
                    #     subjet_pt_nom *= -1.0
                    # jets_pt_nom.append(subjet_pt_nom)

                    # subjet_mass_nom = subjet_mass
                    # if subjet_mass_nom < 0.0:
                    #     subjet_mass_nom *= -1.0
                    # jets_mass_nom.append(subjet_mass_nom)

                    # if subjet_pt_nom > 15.:
                    #     jet_cosPhi = math.cos(jet.phi)
                    #     jet_sinPhi = math.sin(jet.phi)
                    #     met_px_nom = met_px_nom - (subjet_pt_nom - jet.pt) * jet_cosPhi
                    #     met_py_nom = met_py_nom - (subjet_pt_nom - jet.pt) * jet_sinPhi

            # if jet.subJetIdx1 >= 0 and jet.subJetIdx2 >= 0:
            #     groomedP4 = subjets[jet.subJetIdx1].p4() + subjets[
            #         jet.subJetIdx2].p4()  # check subjet jecs
            # else:
            #     groomedP4 = None

            # jets_msoftdrop_raw.append(
            #     0.0) if groomedP4 == None else jets_msoftdrop_raw.append(
            #         groomedP4.M())

            # puppisd_genCorr = self.puppisd_corrGEN.Eval(jet.pt)
            # if abs(jet.eta) <= 1.3:
            #     puppisd_recoCorr = self.puppisd_corrRECO_cen.Eval(jet.pt)
            # else:
            #     puppisd_recoCorr = self.puppisd_corrRECO_for.Eval(jet.pt)

            # puppisd_total = puppisd_genCorr * puppisd_recoCorr
            # if groomedP4 != None:
            #     groomedP4.SetPtEtaPhiM(groomedP4.Perp(), groomedP4.Eta(),
            #                            groomedP4.Phi(),
            #                            groomedP4.M() * puppisd_total)

            # jets_groomed_corr_PUPPI.append(puppisd_total)
            # jets_msoftdrop_nom.append(
            #     0.0) if groomedP4 == None else jets_msoftdrop_nom.append(
            #         groomedP4.M())

        setattr(
            event, 
            self.outputJetPrefix + "jec", 
            self.makeNewJetCollection(jets, collection_type='jets')
        )
        #creating the subjet collection only for the matched subjets
        setattr(
            event, 
            self.outputSubJetPrefix + "jec", 
            self.makeNewJetCollection([subjet for jet in jets for subjet in jet.subjets], collection_type='subjets')
        )

        # self.out.fillBranch("%s_pt_raw" % self.jetBranchName, jets_pt_raw)
        # self.out.fillBranch("%s_pt_nom" % self.jetBranchName, jets_pt_nom)
        # self.out.fillBranch("%s_mass_raw" % self.jetBranchName, jets_mass_raw)
        # self.out.fillBranch("%s_mass_nom" % self.jetBranchName, jets_mass_nom)
        # self.out.fillBranch("%s_groomed_corr_PUPPI" % self.jetBranchName,
        #                     jets_groomed_corr_PUPPI)
        # self.out.fillBranch("%s_msoftdrop_raw" % self.jetBranchName,
        #                     jets_msoftdrop_raw)
        # self.out.fillBranch("%s_msoftdrop_nom" % self.jetBranchName,
        #                     jets_msoftdrop_nom)
        # self.out.fillBranch("MET_pt_nom",
        #                     math.sqrt(met_px_nom**2 + met_py_nom**2))
        # self.out.fillBranch("MET_phi_nom", math.atan2(met_py_nom, met_px_nom))
        # self.out.fillBranch("%s_corr_JEC" % self.jetBranchName, jets_corr_JEC)

        return True


# define modules using the syntax 'name = lambda : constructor' to avoid
# having them loaded when not needed
# jetRecalib2016BCD = lambda: jetRecalib("Summer16_07Aug2017BCD_V11_DATA",
#                                        "Summer16_07Aug2017_V11_DATA")
# jetRecalib2016EF = lambda: jetRecalib("Summer16_07Aug2017EF_V11_DATA",
#                                       "Summer16_07Aug2017_V11_DATA")
# jetRecalib2016GH = lambda: jetRecalib("Summer16_07Aug2017GH_V11_DATA",
#                                       "Summer16_07Aug2017_V11_DATA")

# jetRecalib2016BCDAK8Puppi = lambda: jetRecalib(
#     "Summer16_07Aug2017BCD_V11_DATA",
#     "Summer16_07Aug2017_V11_DATA",
#     jetType="AK8PFPuppi")
# jetRecalib2016EFAK8Puppi = lambda: jetRecalib("Summer16_07Aug2017EF_V11_DATA",
#                                               "Summer16_07Aug2017_V11_DATA",
#                                               jetType="AK8PFPuppi")
# jetRecalib2016GHAK8Puppi = lambda: jetRecalib("Summer16_07Aug2017GH_V11_DATA",
#                                               "Summer16_07Aug2017_V11_DATA",
#                                               jetType="AK8PFPuppi")

# jetRecalib2017B = lambda: jetRecalib("Fall17_17Nov2017B_V32_DATA",
#                                      "Fall17_17Nov2017_V32_DATA")
# jetRecalib2017C = lambda: jetRecalib("Fall17_17Nov2017C_V32_DATA",
#                                      "Fall17_17Nov2017_V32_DATA")
# jetRecalib2017DE = lambda: jetRecalib("Fall17_17Nov2017DE_V32_DATA",
#                                       "Fall17_17Nov2017_V32_DATA")
# jetRecalib2017F = lambda: jetRecalib("Fall17_17Nov2017F_V32_DATA",
#                                      "Fall17_17Nov2017_V32_DATA")

# jetRecalib2017BAK8Puppi = lambda: jetRecalib("Fall17_17Nov2017B_V32_DATA",
#                                              "Fall17_17Nov2017_V32_DATA",
#                                              jetType="AK8PFPuppi")
# jetRecalib2017CAK8Puppi = lambda: jetRecalib("Fall17_17Nov2017C_V32_DATA",
#                                              "Fall17_17Nov2017_V32_DATA",
#                                              jetType="AK8PFPuppi")
# jetRecalib2017DEAK8Puppi = lambda: jetRecalib("Fall17_17Nov2017DE_V32_DATA",
#                                               "Fall17_17Nov2017_V32_DATA",
#                                               jetType="AK8PFPuppi")
# jetRecalib2017FAK8Puppi = lambda: jetRecalib("Fall17_17Nov2017F_V32_DATA",
#                                              "Fall17_17Nov2017_V32_DATA",
#                                              jetType="AK8PFPuppi")

# jetRecalib2018A = lambda: jetRecalib(
#     "Autumn18_RunA_V8_DATA", "Autumn18_V8_DATA", redoJEC=True)
# jetRecalib2018B = lambda: jetRecalib(
#     "Autumn18_RunB_V8_DATA", "Autumn18_V8_DATA", redoJEC=True)
# jetRecalib2018C = lambda: jetRecalib(
#     "Autumn18_RunC_V8_DATA", "Autumn18_V8_DATA", redoJEC=True)
# jetRecalib2018D = lambda: jetRecalib(
#     "Autumn18_RunD_V8_DATA", "Autumn18_V8_DATA", redoJEC=True)

# jetRecalib2018AAK8Puppi = lambda: jetRecalib("Autumn18_RunA_V8_DATA",
#                                              "Autumn18_V8_DATA",
#                                              jetType="AK8PFPuppi",
#                                              redoJEC=True)
# jetRecalib2018BAK8Puppi = lambda: jetRecalib("Autumn18_RunB_V8_DATA",
#                                              "Autumn18_V8_DATA",
#                                              jetType="AK8PFPuppi",
#                                              redoJEC=True)
# jetRecalib2018CAK8Puppi = lambda: jetRecalib("Autumn18_RunC_V8_DATA",
#                                              "Autumn18_V8_DATA",
#                                              jetType="AK8PFPuppi",
#                                              redoJEC=True)
# jetRecalib2018DAK8Puppi = lambda: jetRecalib("Autumn18_RunD_V8_DATA",
#                                              "Autumn18_V8_DATA",
#                                              jetType="AK8PFPuppi",
#                                              redoJEC=True)
