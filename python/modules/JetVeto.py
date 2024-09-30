import ROOT

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

from functools import reduce
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
        # if Module.globalOptions['year']:
        #     lib_path = "/afs/desy.de/user/g/gmilella/ttx3_analysis/CMSSW_11_1_7/lib/slc7_amd64_gcc820/libPhysicsToolsNanoAODTools.so"
        #     load_result = ROOT.gSystem.Load(lib_path)
        # if load_result != 0:
        #     print(f"Failed to load library {lib_path} with error code {load_result}")
        # else:
        #     print(f"Successfully loaded library {lib_path}")

        # try:
        # self.corrlibreader = ROOT.JetVetolibReader()
        #     print("JetVetolibReader initialized successfully")
        # try:
        #     ROOT.gSystem.Load("libPhysicsToolsNanoAODTools")
        #     self.corrlibreader = ROOT.JetVetolibReader()
        #     self.corrlibreader.loadCorrections(self.jetVetoMaps)
        #     self.corrlibreader.printTypes()
        # except Exception as e:
        #     print("Could not load module via python, trying via ROOT" + str(e))
        #     print("Load C++ Worker")
        #     ROOT.gROOT.ProcessLine(
        #         ".L %s/src/PhysicsTools/NanoAODTools/src/JetVetolibReader.h++"
        #         % os.environ['CMSSW_BASE'])
        self.corrlibreader = ROOT.JetVetolibReader()
        self.corrlibreader.loadCorrections(self.jetVetoMaps)
        self.corrlibreader.printTypes()

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree

        self.out.branch("jetMapVeto", "I")


    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def eventVeto(self, reader, data_type, jets):
        for idx, jet in enumerate(jets):
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

