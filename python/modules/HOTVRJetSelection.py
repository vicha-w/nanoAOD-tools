import os
import sys
import math
import json
import ROOT
import random

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

from utils import deltaR, deltaPhi


class HOTVRJetSelection(Module):

    NONE = -1
    LOOSE = 0
    TIGHT = 1
    TIGHTLEPVETO = 2
    
    def __init__(
        self,
        inputCollection=lambda event: Collection(event, "Jet"),
        inputSubjetCollection=lambda event: Collection(event, "Jet"),
        leptonCollectionDRCleaning=lambda event: [],
        outputName_list=["selectedJets", "unselectedJets"],
        jetMinPt=30.,
        subjetMinPt=30.,
        jetMaxEta=4.8,
        dRCleaning=0.4,
        storeKinematics=['pt', 'eta','phi','mass'],
        jetId=LOOSE,
        fatFlag=True,
        metInput = lambda event: Object(event, "MET"),
        storeTruthKeys=[]
     ):

        self.inputCollection = inputCollection
        self.inputSubjetCollection = inputSubjetCollection
        self.leptonCollectionDRCleaning = leptonCollectionDRCleaning
        self.outputName_list = outputName_list
        self.jetMinPt = jetMinPt
        self.subjetMinPt = subjetMinPt
        self.jetMaxEta = jetMaxEta
        self.dRCleaning = dRCleaning
        self.storeKinematics = storeKinematics
        self.jetId=jetId
        self.fatFlag = fatFlag
        self.metInput = metInput
        self.storeTruthKeys = storeTruthKeys

        #loose jet ID does not exists for UL -> accepting all jets  https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookNanoAOD
        #more details on jets -> https://twiki.cern.ch/twiki/bin/view/CMSPublic/WorkBookNanoAOD#Jets
        if self.jetId==HOTVRJetSelection.LOOSE:
            self.jetId = HOTVRJetSelection.NONE

    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        
        self.out.branch("MET_energy", "F")
        for outputName in self.outputName_list:
            if 'unselected' in outputName and 'nominal' not in outputName:
                continue

            # Initialize branches for jets
            self.out.branch("n" + outputName, "I")
            for variable in self.storeKinematics:
                if variable == '_index':
                    self.out.branch(outputName + variable, "I", lenVar="n" + outputName)
                    continue
                if variable == 'nsubjets':
                    self.out.branch(outputName + "_" + variable, "I", lenVar="n" + outputName)
                    continue
                self.out.branch(outputName + "_" + variable, "F", lenVar="n" + outputName)
            if not Module.globalOptions.get("isData"):
                for variable in self.storeTruthKeys:
                    self.out.branch(outputName + "_" + variable, "F", lenVar="n" + outputName)

            # Initialize branches for subjets
            subjet_outputName = outputName.replace("HOTVRJet", "HOTVRSubJet")
            self.out.branch("n" + subjet_outputName, "I")
            for variable in self.storeKinematics:
                if variable not in ['pt', 'eta', 'phi', 'mass', '_index', 'area', 'minDPhiClean', 'minDRClean']:
                    continue
                if variable == '_index':
                    self.out.branch(subjet_outputName + variable, "I", lenVar="n" + subjet_outputName)
                    continue
                self.out.branch(subjet_outputName + "_" + variable, "F", lenVar="n" + subjet_outputName)
            if not Module.globalOptions.get("isData"):
                for variable in self.storeTruthKeys:
                    self.out.branch(subjet_outputName + "_" + variable, "F", lenVar="n" + subjet_outputName)


    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""

        jets = self.inputCollection(event)
        subjets = self.inputSubjetCollection(event)
        met = self.metInput(event)

        selectedJets = []
        selectedSubJets = []
        unselectedJets = []
        unselectedSubJets = []

        leptonsForDRCleaning = self.leptonCollectionDRCleaning(event)
        for ijet, jet in enumerate(jets):
            # -- lepton cleaning
            jet_radius = self.dRCleaning
            # in case of HOTVR, the radius is be calculated as 600/jet pT
            if self.dRCleaning == None:
                jet_radius = 600./ jet.pt if 600./ jet.pt <= 1.5 else 1.5 

            if hasattr(jet, "subjets"):
                setattr(jet, "max_eta_subjets", max(map(lambda subjet: subjet.eta, jet.subjets)))
                setattr(jet, "nsubjets", len(jet.subjets))
            else:
                setattr(jet, "max_eta_subjets", float('inf'))
                setattr(jet, "nsubjets", -1)

            minDeltaRSubtraction = 999.
            if len(leptonsForDRCleaning) > 0:
                mindphi = min(map(lambda lepton: deltaPhi(lepton, jet), leptonsForDRCleaning))
                mindr = min(map(lambda lepton: deltaR(lepton, jet), leptonsForDRCleaning))

                setattr(jet, "minDPhiClean", mindphi)
                setattr(jet, "minDRClean", mindr)

                if mindr < jet_radius:
                    unselectedJets.append(jet)
                    continue
            else:
                setattr(jet, "minDPhiClean", 100)
                setattr(jet, "minDRClean", 100)
            # --

            if jet.pt < self.jetMinPt:
                unselectedJets.append(jet)
                continue

            if math.fabs(jet.eta) > self.jetMaxEta:
                unselectedJets.append(jet)
                continue

            if self.jetId>=0 and ((jet.jetId & (1 << self.jetId)) == 0):
                unselectedJets.append(jet)
                continue

            selectedJets.append(jet)

            # --- matching with subjets
            # the jet.subjets is obtained in the "HOTVRJetRecalibration.py" module
            if not hasattr(jet, "subjets"): continue
            for isubjet, subjet in enumerate(jet.subjets):
                    if leptonsForDRCleaning:
                        mindphi = min(map(lambda lepton: deltaPhi(lepton, subjet), leptonsForDRCleaning))
                        mindr = min(map(lambda lepton: deltaR(lepton, subjet), leptonsForDRCleaning))
                    else:
                        mindphi = float('inf')
                        mindr = float('inf')

                    setattr(subjet, "minDPhiClean", mindphi)
                    setattr(subjet, "minDRClean", mindr)

                    if mindr < 0.4: #using 0.4 radius for the subjet
                        continue

                    if subjet.pt < self.subjetMinPt:
                        continue

                    selectedSubJets.append(subjet)
            # ---
            if selectedSubJets:
                setattr(jet, "max_eta_subjets", max(map(lambda subjet: subjet.eta, selectedSubJets)))
                setattr(jet, "nsubjets", len(selectedSubJets))

        def metP4(obj):
            p4 = ROOT.TLorentzVector()
            p4.SetPtEtaPhiM(obj.pt, 0, obj.phi, 0)
            return p4

        self.out.fillBranch("MET_energy", (metP4(met)).E())

        for outputName, jet_list in zip(self.outputName_list, [selectedJets, unselectedJets]):
            if 'unselected' in outputName and 'nominal' not in outputName: 
                continue

            setattr(event, outputName, jet_list)
            self.out.fillBranch("n" + outputName, len(jet_list))
            
            for variable in self.storeKinematics:
                branch_name = ("%s_%s" % (outputName, variable)) if variable != '_index' else ("%s%s" % (outputName, variable))
                values = list(map(lambda jet: getattr(jet, variable, None) if hasattr(jet, variable) else -999, jet_list))
                self.out.fillBranch(branch_name, values)

            if not Module.globalOptions.get("isData"):
                for variable in self.storeTruthKeys:
                    branch_name = "%s_%s" % (outputName, variable)
                    values = list(map(lambda jet: getattr(jet, variable, None) if hasattr(jet, variable) else -999, jet_list))
                    self.out.fillBranch(branch_name, values)

        for outputName, subjet_list in zip(self.outputName_list, [selectedSubJets, unselectedSubJets]):
            if 'unselected' in outputName and 'nominal' not in outputName: 
                continue

            outputName = outputName.replace("HOTVRJet", "HOTVRSubJet")
            
            setattr(event, outputName, subjet_list)
            self.out.fillBranch("n" + outputName, len(subjet_list))
            
            for variable in self.storeKinematics:
                if variable not in ['pt', 'eta', 'phi', 'mass', '_index', 'area', 'minDPhiClean', 'minDRClean']:
                    continue

                branch_name = ("%s_%s" % (outputName, variable)) if variable != '_index' else ("%s%s" % (outputName, variable))
                values = list(map(lambda jet: getattr(jet, variable, None) if hasattr(jet, variable) else -999, subjet_list))
                self.out.fillBranch(branch_name, values)

            if not Module.globalOptions.get("isData"):
                for variable in self.storeTruthKeys:
                    branch_name = "%s_%s" % (outputName, variable)
                    values = list(map(lambda jet: getattr(jet, variable, None) if hasattr(jet, variable) else -999, subjet_list))
                    self.out.fillBranch(branch_name, values)

        return True

