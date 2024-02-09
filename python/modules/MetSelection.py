from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import (Collection, Object)
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
import ROOT
ROOT.PyConfig.IgnoreCommandLineOptions = True


class MetSelection(Module):
    def __init__(
         self,
         outputName="MET",
         storeKinematics=['pt', 'phi', "E"],
         metInput = lambda event: Object(event, "MET"),
         metCut=lambda met: True # Example: lambda met: met.pt >= 50.0
     ):
        self.outputName = outputName
        self.storeKinematics = storeKinematics
        self.metInput = metInput
        self.metCut = metCut

    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        for variable in self.storeKinematics:
            self.out.branch(self.outputName+"_"+variable, "F")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def metP4(obj):
        p4 = ROOT.TLorentzVector()
        p4.SetPtEtaPhiM(obj.pt,0,obj.phi,0)
        return p4
    
    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""
        met = self.metInput(event)
        if self.metCut(met):
            metP4_obj = self.metP4(met)
            for variable in self.storeKinematics:
                if variable == "E": self.out.fillBranch(self.outputName + "_" + variable, metP4_obj.E())
                else: self.out.fillBranch(self.outputName + "_" + variable, getattr(met, variable))
            return True
        else: return False