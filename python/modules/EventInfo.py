import os
import sys
import math
import json
import ROOT
import random
import yaml
import re

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
        self.nGenWeights = 0
        self.nGenEventCount = 0
        self.genEventSumw2 = 0
        self.LHEScaleSumw = [0, 0, 0, 0, 0, 0, 0, 0, 0]
        self.existingSumSaved = False
        self.out = wrappedOutputTree
        for variable in self.storeVariables:
            variable[0](self.out)
        
    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
    	if not Module.globalOptions["isData"]:
            nGenEventCount_parameter = ROOT.TParameter(float)("genEventCount", self.nGenEventCount)
            nGenWeight_parameter = ROOT.TParameter(float)("sumGenWeights", self.nGenWeights)
            genEventSumw2_parameter = ROOT.TParameter(float)("sumGenWeights2", self.genEventSumw2)
            LHEScaleSumw_parameter = []
            for i in range(9): LHEScaleSumw_parameter.append(ROOT.TParameter(float)("LHEScaleSumw_{}".format(i), self.LHEScaleSumw[i]/self.nGenWeights))

            outputFile.cd()
            nGenEventCount_parameter.Write()
            nGenWeight_parameter.Write() 
            genEventSumw2_parameter.Write()
            for i in range(9): LHEScaleSumw_parameter[i].Write()
        else:
            pass
        
    def analyze(self, event):

        if not Module.globalOptions["isData"]:
            self.nGenWeights += event.Generator_weight
            self.nGenEventCount += 1
            self.genEventSumw2 += event.Generator_weight ** 2
            for i in range(9): self.LHEScaleSumw[i] += event.LHEScaleWeight[i] * event.Generator_weight

        else:
            with open(os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/13TeV_UL_Era_runNumber.yaml") as yaml_f:
                try:
                    era_yaml = yaml.safe_load(yaml_f)
                except yaml.YAMLError as exc:
                    print(exc)

            for era in era_yaml[Module.globalOptions['year']]:
                if event.run >= era_yaml[Module.globalOptions['year']][era][0] and event.run <= era_yaml[Module.globalOptions['year']][era][1]:
                    Module.globalOptions['era'] = era

        for variable in self.storeVariables:
            variable[1](self.out, event)
        return True
