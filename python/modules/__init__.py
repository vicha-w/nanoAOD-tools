import ROOT
import sys
#can only load this once
if (ROOT.gSystem.Load("libPhysicsToolsNanoAODTools.so")!=0):
    print "Cannot load 'libPhysicsToolsNanoAODTools'"
    sys.exit(1)

#genParticle
from GenParticleModule import GenParticleModule

#trigger
from DoubleMuonTriggerSelection import DoubleMuonTriggerSelection
from DoubleElectronTriggerSelection import DoubleElectronTriggerSelection
from ElectronMuonTriggerSelection import ElectronMuonTriggerSelection
#from TriggerMatching import TriggerMatching 
from DoubleLeptonTriggerSelection import DoubleLeptonTriggerSelection

#muons
from SingleMuonTriggerSelection import SingleMuonTriggerSelection
from MuonSelection import MuonSelection
from MuonSFProducer import MuonSFProducer
from MuonVeto import MuonVeto
from LeptonicWProducer import LeptonicWProducer

#electrons
from SingleElectronTriggerSelection import SingleElectronTriggerSelection
from ElectronSelection import ElectronSelection
from ElectronVeto import ElectronVeto
from ElectronSFProducer import ElectronSFProducer

#aux
from EventSkim import EventSkim
from MetFilter import MetFilter
from MetSelection import MetSelection
from EventInfo import EventInfo

#jets
from JetMetUncertainties import JetMetUncertainties
from JetSelection import JetSelection
from BTagSelection import BTagSelection
from btagSFProducer import btagSFProducer

#event
from PUWeightProducer import puWeightProducer, PUWeightProducer_dict
from GenWeightProducer import GenWeightProducer
from TopPtWeightProducer import TopPtWeightProducer

#event reco + HOTVR mva + fat jet composition
from EventReconstruction import EventReconstruction
#from HOTVR_MVA import HOTVR_MVA
from HOTVRJetComposition import HOTVRJetComposition
from FatJetComposition import FatJetComposition

#bdt evaluation
from XGBEvaluationProducer import XGBEvaluationProducer

#genparticles
from GenParticleSelection import GenParticleSelection