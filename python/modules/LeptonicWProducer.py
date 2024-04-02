import os
import sys
import math
import json
import ROOT
import random

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection, Object
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

class LeptonicWProducer(Module):
    def __init__(self,
        inputMuonCollection=lambda event: Collection(event, "Muon"),
        inputMet=lambda event: Object(event, "MET"),
        outputName="Leptonic_W_pt"
    ):
        self.inputMuonCollection = inputMuonCollection
        self.inputMet = inputMet
        self.outputName = outputName

    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        if self.outputName is not None:
            self.out.branch(self.outputName, "F")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):

        met = self.inputMet(event)
        metvec = ROOT.Math.PtEtaPhiMVector(met.pt, 0, met.phi, 0)

        if len(self.inputMuonCollection(event)) > 0:
            muon = self.inputMuonCollection(event)[0]
            muonvec = ROOT.Math.PtEtaPhiMVector(muon.pt, muon.eta, muon.phi, muon.mass)
            leptonic_W_pt = (muonvec + metvec).Pt()
        else: leptonic_W_pt = 0

        self.out.fillBranch(self.outputName, leptonic_W_pt)
        return True
