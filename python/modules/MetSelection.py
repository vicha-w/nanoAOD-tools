from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import (Collection, Object)
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
import ROOT
ROOT.PyConfig.IgnoreCommandLineOptions = True


class MetSelection(Module):
    def __init__(
         self,
         outputName="MET",
         storeKinematics=['pt', 'phi'],
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

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""
        met = self.metInput(event)
        if self.metCut(met):
            for variable in self.storeKinematics:
                self.out.fillBranch(self.outputName + "_" + variable, getattr(event, "MET_"+variable))
            return True
        else: return False