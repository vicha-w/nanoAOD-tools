from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
import ROOT
import os
from itertools import chain
from collections import OrderedDict
from itertools import izip_longest

ROOT.PyConfig.IgnoreCommandLineOptions = True

class HOTVRJetSFProducer(Module):
    """Calculate HOTVR BDT scale factors
    """

    def __init__(
            self, 
            sfFileName=None,
            inputHOTVRJetCollection = None,
            nosyst = False,
            verbose=0,
            outputName='',
    ):

        self.inputHOTVRJetCollection = inputHOTVRJetCollection
        self.nosyst = nosyst
        self.sfFileName = sfFileName
        self.verbose = verbose
        self.outputName = outputName

        self.sys = ['nominal', 'up', 'down']

    def beginJob(self):
        # initialize HOTVRCorrlibReader
        self.corrlibreader = ROOT.HOTVRCorrlibReader()
        self.corrlibreader.loadCorrections(self.sfFileName)
 
    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree

        for sys in self.sys:
            self.out.branch(self.outputName+"_weight_bdt_"+sys, "F")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def getSFs(self, reader, type, syst, jets):
        for idx, jet in enumerate(jets):
            if not jet.has_hadronicTop_topIsInside: continue # true hadronic jet
            # evaluate SF
            sf = None
            sf = reader.evaluateHOTVRSF(type, jet.pt, syst)
            # check if SF is OK
            
            if sf < 0.01:
                if self.verbose > 0:
                    print("hotvr jet #%i: pT = %1.1f, eta = %1.1f" % (
                        idx, jet.pt, jet.eta))
                sf = 1.
            yield sf

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""
        corrlibreader = self.corrlibreader 
        hotvrjets = self.inputHOTVRJetCollection(event)

        for sys, sys_type in zip(self.sys, ['nom', 'up', 'down']):
            ev_weight_bdt = 1. 
            scale_factors_id = list(self.getSFs(corrlibreader, "HOTVR_BDT", sys_type, hotvrjets))

            for sf_id in scale_factors_id:
                ev_weight_bdt *= sf_id

            self.out.fillBranch(self.outputName+"_weight_bdt_"+sys, ev_weight_bdt)

        return True

