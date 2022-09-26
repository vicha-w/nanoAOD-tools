import os
import sys
import math
import json
import ROOT
import random

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

from utils import deltaR, deltaPhi


class GenParticleSelection(Module):
    def __init__(
         self,
         inputCollection=lambda event: Collection(event, "GenPart"),
         outputName="genParticles",
         storeKinematics=['pt', 'eta', 'phi', 'mass', 'pdgId', "genPartIdxMother"]
     ):

        self.inputCollection = inputCollection
        self.outputName = outputName
        self.storeKinematics = storeKinematics

    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        
        self.out.branch("n"+self.outputName, "I")
        for variable in self.storeKinematics:
            self.out.branch(self.outputName+"_"+variable, "F", lenVar="n"+self.outputName)

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""

        genparticles = self.inputCollection(event)

        self.out.fillBranch("n"+self.outputName, len(genparticles))
        for variable in self.storeKinematics:
            self.out.fillBranch(
                self.outputName+"_"+variable,
                map(lambda p: getattr(p, variable), genparticles)
            )

        return True

