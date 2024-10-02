from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

import ROOT
import os
from utils import deltaR

ROOT.PyConfig.IgnoreCommandLineOptions = True

class JetVeto(Module):

    def __init__(
        self,
        inputCollection=lambda event: Collection(event, "Jet"),
        leptonCollectionDRCleaning=lambda event: [],
        jetVetoMaps = [],
        jetMinPt=15.,
        dRCleaning=0.2,
    ):

        self.inputCollection = inputCollection
        self.leptonCollectionDRCleaning = leptonCollectionDRCleaning
        self.jetVetoMaps = jetVetoMaps
        self.jetMinPt = jetMinPt
        self.dRCleaning = dRCleaning


    def beginJob(self):
        # the src libraries are not corrected loaded when skimming data (--> need to fix the bug; for MC, they are loaded when calling the PUWeightProducer module)
        try:
            # Attempt to load the library that contains JetVetolibReader
            ROOT.gSystem.Load("libPhysicsToolsNanoAODTools")
            dummy = ROOT.JetVetolibReader
        except Exception as e:
            header_path = "{}/src/PhysicsTools/NanoAODTools/src/JetVetolibReader.h".format(os.environ['CMSSW_BASE'])
            ROOT.gInterpreter.Declare('''
            #include "{}"
            '''.format(header_path))

        self.corrlibreader = ROOT.JetVetolibReader()
        self.corrlibreader.loadCorrections(self.jetVetoMaps)

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree

        self.out.branch("jetMapVeto", "I")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def eventVeto(self, reader, data_type, jets):
        for idx, jet in enumerate(jets):
            #if jet.phi > 3.1415926535: jet_phi_safe = 3.14159
            #elif jet.phi < -3.1415926535: jet_phi_safe = -3.14159
            #else: jet_phi_safe = jet.phi
            veto_value = reader.evaluateVetoRegion(data_type, jet.eta, jet.phi)
            if veto_value > 0:
                return True
        return False

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""

        jets = self.inputCollection(event)
        leptonsForDRCleaning = self.leptonCollectionDRCleaning(event)

        corrlibreader = self.corrlibreader 

        # recomended cuts for "loose" jet: https://cms-jerc.web.cern.ch/Recommendations/#jet-veto-maps
        loose_jets = []
        for i, jet in enumerate(jets):
            
            # -- jet tightID
            if (jet.jetId & (1 << 2)) == 0:
                continue
            # --
            # -- lepton cleaning
            if len(leptonsForDRCleaning) > 0:
                mindr = min(map(lambda lepton: deltaR(lepton, jet), leptonsForDRCleaning))
                if mindr < self.dRCleaning:
                    continue
            # --

            if jet.pt < self.jetMinPt: continue
            if (jet.chHEF + jet.neHEF) > 0.9: continue

            loose_jets.append(jet)

        if Module.globalOptions['year'] == '2022':
            data_type = "Summer22_23Sep2023_RunCD_V1"
        if Module.globalOptions['year'] == '2022EE':
            data_type = "Summer22EE_23Sep2023_RunEFG_V1"
        is_vetoed = self.eventVeto(corrlibreader, data_type, loose_jets)

        setattr(event, "jetMapVeto", is_vetoed)
        self.out.fillBranch("jetMapVeto", is_vetoed)


        return True

