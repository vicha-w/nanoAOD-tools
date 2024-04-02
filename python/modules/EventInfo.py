import os
import sys
import math
import json
import ROOT
import random

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

class EventInfo(Module):
    def __init__(
        self,
        storeVariables = []
    ):
        self.storeVariables = storeVariables
        
    def beginJob(self):
        pass
    def endJob(self):
        pass
    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        for variable in self.storeVariables:
            variable[0](self.out)
        
    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):

        if not Module.globalOptions["isData"]:            
            if self.genEventInfoInFile == True:
                runsTree = InputTree(inputFile.Get("Runs"))
                runsEvent = Event(runsTree, 0)
                self.genEventSumw = runsEvent.genEventSumw
                self.genEventCount = runsEvent.genEventCount
                self.genEventSumw2 = runsEvent.genEventSumw2
                self.LHEScaleSumw = [runsEvent.LHEScaleSumw[i] for i in range(9)]

            nGenEventCount_parameter = ROOT.TParameter(float)("genEventCount", self.genEventCount)
            nGenWeight_parameter = ROOT.TParameter(float)("sumGenWeights", self.genEventSumw)
            genEventSumw2_parameter = ROOT.TParameter(float)("sumGenWeights2", self.genEventSumw2)
            LHEScaleSumw_parameter = []
            # -- in case the parameters are not already stored in "Runs" TTree of the input file,
            # -- a manual calculation is required --> https://cms-nanoaod-integration.web.cern.ch/autoDoc/NanoAODv9/2017UL/doc_TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_RunIISummer20UL17NanoAODv9-106X_mc2017_realistic_v9-v1.html

            if self.genEventInfoInFile == True:
                for i in range(9): LHEScaleSumw_parameter.append(ROOT.TParameter(float)("LHEScaleSumw_{}".format(i), self.LHEScaleSumw[i]))
            else:
                for i in range(9): LHEScaleSumw_parameter.append(ROOT.TParameter(float)("LHEScaleSumw_{}".format(i), self.LHEScaleSumw[i]/self.genEventSumw))

            outputFile.cd()
            nGenEventCount_parameter.Write()
            nGenWeight_parameter.Write() 
            genEventSumw2_parameter.Write()
            for i in range(9): LHEScaleSumw_parameter[i].Write()
        else:
            pass
        
    def analyze(self, event):
        for variable in self.storeVariables:
            variable[1](self.out,event)
        return True
        
