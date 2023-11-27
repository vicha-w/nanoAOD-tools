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
            trainingEventMasking=False
        ):
        self.outputName = outputName
        self.modelPath = modelPath
        self.inputHOTVRJetCollection = inputHOTVRJetCollection
        self.trainingEventMasking = trainingEventMasking

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

        self.out.branch('npreselectedHOTVRJets', "I")
        self.out.branch("preselectedHOTVRJets_"+self.outputName, "F", lenVar='npreselectedHOTVRJets')

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):

        hotvrjets = self.inputHOTVRJetCollection(event)

        feature_dict = []
        for input in self.inputs:
            feature_dict.append(np.array(list(map(lambda hotvr: getattr(hotvr, input), hotvrjets))))
            # feature_dict.append(list(map(lambda hotvr: getattr(hotvr, input), hotvrjets)))
        features_array = np.stack(feature_dict, axis=1)

        if len(features_array) > 0:
            start_time = time.time()
            bdt_score = self.model.predict_proba(features_array)
            end_time =  time.time()
            inference_time_perJet = (end_time - start_time) / len(features_array)

            self.out.fillBranch("npreselectedHOTVRJets", len(hotvrjets))

            # to avoid overtraining, the training is done on jets of odd event number
            # while the evaluation on jets of even number

            # VW: Why??? Haven't we already checked that our BDTs are not overtrained?
            # If we can prove that both output distributions from training and evaluation set are identical,
            # I do not see why we should mask them!
            # Besides, for the dataset that is not used for the training, guaranteed,
            # we should have BDT outputs from *all* events.

            if self.trainingEventMasking:
                if event.run % 2 == 0:
                    self.out.fillBranch("preselectedHOTVRJets_"+self.outputName, map(lambda hotvr: -1, hotvrjets))
                else: self.out.fillBranch("preselectedHOTVRJets_"+self.outputName, bdt_score[:, 1].tolist())
            else:
                self.out.fillBranch("preselectedHOTVRJets_"+self.outputName, bdt_score[:, 1].tolist())

            self.out.fillBranch("inference_time_"+self.outputName, inference_time_perJet)

        return True

