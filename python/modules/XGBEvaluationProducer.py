import time
import pandas as pd
import numpy as np

from xgboost import XGBClassifier, Booster, DMatrix

from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

class XGBEvaluationProducer(Module):
    def __init__(
            self,
            modelPath="",
            inputHOTVRJetCollection="",
            outputName="scoreBDT",
            outputJetPrefix='selectedHOTVRJets_nominal'
        ):
        self.outputName = outputName
        self.modelPath = modelPath
        self.inputHOTVRJetCollection = inputHOTVRJetCollection
        self.outputJetPrefix = outputJetPrefix

        self.inputs = (
            'fractional_subjet_pt', 'min_pairwise_subjets_mass', 'mass', 'nsubjets', 'tau3_over_tau2'
        )

    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        
        self.model = XGBClassifier()
        self.booster = Booster(model_file=self.modelPath)
        self.model._Booster = self.booster

        self.out.branch("inference_time_"+self.outputName, "F")

        self.out.branch("{}_{}".format(self.outputJetPrefix, self.outputName), "F", lenVar="n{}".format(self.outputJetPrefix))

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):

        hotvrjets = self.inputHOTVRJetCollection(event)

        feature_dict = []
        for input in self.inputs:
            feature_dict.append(np.array(list(map(lambda hotvr: getattr(hotvr, input), hotvrjets))))
        features_array = np.stack(feature_dict, axis=1)

        if len(features_array) > 0:
            start_time = time.time()
            bdt_score = self.model.predict_proba(features_array)
            end_time =  time.time()
            inference_time_perJet = (end_time - start_time) / len(features_array)

            assert len(hotvrjets) == len(bdt_score[:, 1]), "Mismatch in number of jets and BDT scores."
            for jet, score in zip(hotvrjets, bdt_score[:, 1]):
                setattr(jet, format(self.outputName), score)

            self.out.fillBranch("{}_{}".format(self.outputJetPrefix, self.outputName), bdt_score[:, 1].tolist())
            self.out.fillBranch("inference_time_"+self.outputName, inference_time_perJet)

        return True

