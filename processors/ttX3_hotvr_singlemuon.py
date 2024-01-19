import argparse
import json
import math
import os
import random
import sys
from collections import OrderedDict

import numpy as np
import ROOT
from PhysicsTools.NanoAODTools.modules import *
from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import (
    Collection, Object)
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
from PhysicsTools.NanoAODTools.postprocessing.framework.postprocessor import \
    PostProcessor

def polarP4(obj=None, pt='pt', eta='eta', phi='phi', mass='mass'):
    if obj is None:
        return ROOT.Math.PtEtaPhiMVector()
    pt_val   = getattr(obj, pt) if pt else 0
    eta_val  = getattr(obj, eta) if eta else 0
    phi_val  = getattr(obj, phi) if phi else 0
    mass_val = getattr(obj, mass) if mass else 0
    return ROOT.Math.PtEtaPhiMVector(pt_val, eta_val, phi_val, mass_val)

def deltaPhi(phi1, phi2):
    dphi = phi1 - phi2
    while dphi > math.pi: dphi -= 2*math.pi
    while dphi < -math.pi: dphi += 2*math.pi
    return dphi

parser = argparse.ArgumentParser()


parser.add_argument('--isData', dest='isData',
                    action='store_true', default=False)
parser.add_argument('--isSignal', dest='isSignal',
                    action='store_true', default=False)
parser.add_argument('--nosys', dest='nosys',
                    action='store_true', default=False)
parser.add_argument('--invid', dest='invid',
                    action='store_true', default=False)
parser.add_argument('--year', dest='year',
                    action='store', type=str, default='2017', choices=['2016','2016preVFP','2017','2018'])
parser.add_argument('-i','--input', dest='inputFiles', action='append', default=[])
parser.add_argument('--maxEvents', dest='maxEvents', type=int, default=None)
parser.add_argument('--trigger', dest='trigger', type=str, default=None, choices=['mumu','emu','ee'])
parser.add_argument('output', nargs=1)

args = parser.parse_args()

print("isData:",args.isData)
print("isSignal:",args.isSignal)
print("evaluate systematics:",not args.nosys)
print("invert lepton id/iso:",args.invid)
print("inputs:",len(args.inputFiles))
print("year:", args.year)
print("output directory:", args.output[0])
if args.maxEvents:
    print('max number of events', args.maxEvents)

globalOptions = {
    "isData": args.isData,
    "isSignal": args.isSignal,
    "year": args.year,
    "trigger": args.trigger, 
    "era": None
}

Module.globalOptions = globalOptions

isMC = not args.isData
isPowheg = 'powheg' in args.inputFiles[0].lower()
isPowhegTTbar = 'TTTo' in args.inputFiles[0] and isPowheg

#recommended pT threshold for the subleading lepton --> https://cms.cern.ch/iCMS/jsp/db_notes/noteInfo.jsp?cmsnoteid=CMS%20AN-2020/085 (4 top in dilepton final state)
minMuonPt =     {'2016': 15., '2016preVFP': 15., '2017': 15., '2018': 15.}
minElectronPt = {'2016': 15., '2016preVFP': 15., '2017': 15., '2018': 15.}

if args.isData:
    if args.year == '2016preVFP':
        with open(os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/GoldenJSON/13TeV_UL2016_GoldenJSON.txt", 'r') as f:
            data_json = json.load(f)
    else:
        with open(os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/GoldenJSON/13TeV_UL"+args.year+"_GoldenJSON.txt", 'r') as f:
            data_json = json.load(f)

    filtered_data = dict()
    for run in data_json.keys():
        filtered_data[int(run)] = list()
        for lumi in data_json[run]:
            filtered_data[int(run)].extend(range(lumi[0], lumi[1]+1))


#b-tagging working point
b_tagging_wpValues = {
    '2016preVFP': [0.0614, 0.3093, 0.7221], #https://btv-wiki.docs.cern.ch/ScaleFactors/UL2016preVFP/
    '2016': [0.0480, 0.2489, 0.6377], #https://btv-wiki.docs.cern.ch/ScaleFactors/UL2016postVFP/
    '2017': [0.0532, 0.3040, 0.7476], #https://btv-wiki.docs.cern.ch/ScaleFactors/UL2017/
    '2018': [0.0490, 0.2783, 0.7100] #https://btv-wiki.docs.cern.ch/ScaleFactors/UL2018/
}

jesUncertaintyFilesRegrouped = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/RegroupedV2_Summer19UL16_V7_MC_UncertaintySources_AK4PFchs.txt",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/RegroupedV2_Summer19UL16APV_V7_MC_UncertaintySources_AK4PFchs.txt",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/RegroupedV2_Summer19UL17_V5_MC_UncertaintySources_AK4PFchs.txt",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/RegroupedV2_Summer19UL18_V5_MC_UncertaintySources_AK4PFchs.txt"
}
jerResolutionFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16_JRV3_MC_PtResolution_AK4PFchs.txt",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16APV_JRV3_MC_PtResolution_AK4PFchs.txt",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL17_JRV3_MC_PtResolution_AK4PFchs.txt",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL18_JRV2_MC_PtResolution_AK4PFchs.txt"
}
jerSFUncertaintyFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16_JRV3_MC_SF_AK4PFchs.txt",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16APV_JRV3_MC_SF_AK4PFchs.txt",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL17_JRV3_MC_SF_AK4PFchs.txt",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL18_JRV2_MC_SF_AK4PFchs.txt"
}

jesAK8UncertaintyFilesRegrouped = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL16_V7_MC_UncertaintySources_AK8PFPuppi.txt",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL16APV_V7_MC_UncertaintySources_AK8PFPuppi.txt",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL17_V5_MC_UncertaintySources_AK8PFPuppi.txt",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL18_V5_MC_UncertaintySources_AK8PFPuppi.txt"
}
jerAK8ResolutionFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16_JRV3_MC_PtResolution_AK8PFPuppi.txt",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16APV_JRV3_MC_PtResolution_AK8PFPuppi.txt",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL17_JRV3_MC_PtResolution_AK8PFPuppi.txt",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL18_JRV2_MC_PtResolution_AK8PFPuppi.txt"
}
jerAK8SFUncertaintyFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16_JRV3_MC_SF_AK8PFPuppi.txt",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer20UL16APV_JRV3_MC_SF_AK8PFPuppi.txt",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL17_JRV3_MC_SF_AK8PFPuppi.txt",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/jme/Summer19UL18_JRV2_MC_SF_AK8PFPuppi.txt"
}

#dilepton triggers SF provided by TOP PAG --> https://twiki.cern.ch/twiki/bin/view/CMS/TopTrigger#Dilepton_triggers
dileptonTriggerSFFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/dilepton_triggerSF/2016postVFP_UL/TriggerSF_2016postVFP_ULv2.root",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/dilepton_triggerSF/2016preVFP_UL/TriggerSF_2016preVFP_ULv2.root",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/dilepton_triggerSF/2017_UL/TriggerSF_2017_ULv2.root",
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/dilepton_triggerSF/2018_UL/TriggerSF_2018_ULv2.root"    
}

#muon and electron SF files from the central POG repository--> https://gitlab.cern.ch/cms-nanoAOD/jsonpog-integration/-/tree/master/POG
muonSFFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/muon/2016postVFP_UL/muon_Z.json.gz",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/muon/2016preVFP_UL/muon_Z.json.gz",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/muon/2017_UL/muon_Z.json.gz", 
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/muon/2018_UL/muon_Z.json.gz"      
}

electronSFFiles = {
    '2016':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/electron/2016postVFP/electron.json.gz",
    '2016preVFP': os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/electron/2016preVFP/electron.json.gz",
    '2017':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/electron/2017/electron.json.gz", 
    '2018':       os.environ['CMSSW_BASE']+"/src/PhysicsTools/NanoAODTools/data/electron/2018/electron.json.gz"      
}

#xgb models
xgb_models = {
    '2018': os.environ['CMSSW_BASE'] + "/src/PhysicsTools/NanoAODTools/data/bdt/2018/hadronicTopVSQCD_bdt_nTrees1000_maxDepth3_learningRate0.05_minChildWeight0.5.bin",
    '2017': os.environ['CMSSW_BASE'] + "/src/PhysicsTools/NanoAODTools/data/bdt/2018/hadronicTopVSQCD_bdt_nTrees500_maxDepth8_learningRate0.03_minChildWeight0.1.bin", ###CHANGE IT!!!!!
    '2016': '',
    '2016preVFP': ''
}

##### LEPTON MODULES
muon_dict, electron_dict = {}, {}
def leptonSequence():
    seq = [
        MuonSelection(
            inputCollection=lambda event: Collection(event, "Muon"),
            outputName_list=["tightRelIso_tightID_Muons","tightRelIso_mediumID_Muons","tightRelIso_looseID_Muons"],
            triggerMatch=True,
            storeKinematics=['pt','eta','charge','phi','mass', "miniPFRelIso_all"],
            #muonMinPt=minMuonPt[args.year],
            muonMinPt=55,
            muonMaxEta=2.4,
            additionalMuonCuts = lambda muon: (math.fabs(muon.dxy)<0.2 and math.fabs(muon.dz)<0.5 and muon.miniPFRelIso_all < 0.10)
        ),
               
        #MuonVeto(
        #    inputCollection=lambda event: event.unselectedMuons,
        #    outputName = "vetoMuons",
        #    muonMinPt = 10.,
        #    muonMaxEta = 2.4,
        #    storeKinematics=['pt','eta','charge','phi','mass'],
        #),

        ElectronSelection(
            inputCollection = lambda event: Collection(event, "Electron"),
            id_type = ['MVA', 'cutBased'],
            #outputName_list = ["tight_MVA_Electrons","medium_MVA_Electrons","loose_MVA_Electrons"],
            triggerMatch=True,
            electronMinPt = minElectronPt[args.year],
            electronMaxEta = 2.4,
            storeKinematics=['pt','eta','charge','phi','mass'],#, 
        ),

        #ElectronVeto(
        #    inputCollection=lambda event: event.unselectedElectrons,
        #    outputName = "vetoElectrons",
        #    electronMinPt = 10.,
        #    electronMaxEta = 2.4,
        #    storeKinematics=['pt','eta','charge','phi','mass'],
        #),

        # EventSkim(selection=lambda event: (len(event.tightRelIso_looseID_Muons) + ( len(event.loose_cutBased_Electrons) + len(event.loose_MVA_Electrons) ) > 1 )),
    ]

    if not Module.globalOptions["isData"]:
        for wp, muon_collection in muon_dict.items():
            seq.extend([
                MuonSFProducer(
                    muonSFFiles[args.year],
                    inputMuonCollection = muon_collection,
                    nosyst = False,
                    outputName = 'tightRelIso_'+wp+'ID_Muons',
                    WP = wp,
                    ),
            ])
        
        for wp in electron_dict.keys():
            for id_type, electron_collection in electron_dict[wp].items():
                seq.extend([
                    ElectronSFProducer(
                        electronSFFiles[args.year],
                        inputElectronCollection = electron_collection,
                        nosyst = False,
                        outputName = wp+'_'+id_type+'_Electrons',
                        WP = wp,
                    )
                ])

    return seq

muon_dict = {
    'tight': lambda event: event.tightRelIso_tightID_Muons,
    'medium': lambda event: event.tightRelIso_mediumID_Muons,
    'loose': lambda event: event.tightRelIso_looseID_Muons
}

electron_dict = {
    'tight': 
        {"MVA": lambda event: event.tight_MVA_Electrons, "cutBased": lambda event: event.tight_cutBased_Electrons},
    'medium':
        {"MVA": lambda event: event.medium_MVA_Electrons, "cutBased": lambda event: event.medium_cutBased_Electrons},
    'loose': 
        {"MVA": lambda event: event.loose_MVA_Electrons, "cutBased": lambda event: event.loose_cutBased_Electrons}
}

#####

##### TRIGGER MODULES - DILEPTON TRIGGER
def trigger():
    if args.isData:
        if args.trigger=='emu':
            seq = [
                ElectronMuonTriggerSelection(
                    outputName="trigger",
                ),
                EventSkim(selection=lambda event: (event.trigger_emu_flag)),
            ]
            return seq
        elif args.trigger=='mumu':
            seq = [
                DoubleMuonTriggerSelection(
                    outputName="trigger",
                ),	
                EventSkim(selection=lambda event: (event.trigger_mumu_flag)),
            ]
            return seq
        elif args.trigger=='ee':
            seq = [
                DoubleElectronTriggerSelection(
                    outputName="trigger",
                ),
                EventSkim(selection=lambda event: (event.trigger_ee_flag)),
            ] 
            return seq
    else: 
        seq = [
            DoubleLeptonTriggerSelection(
                dileptonTriggerSFFiles[args.year],
                inputMuonCollection = lambda event: event.tightRelIso_looseID_Muons,
                inputElectronCollection = lambda event: event.loose_MVA_Electrons,
                outputName="trigger",
                storeWeights=True,
                thresholdPt=15. #minDiMuonPt[args.year], PRELIMINARY VALUE
            ),
            EventSkim(selection=lambda event: (event.trigger_general_flag)),
        ]
        return seq
#####

##### JET MODULES   
selectedFatJets_dict, selectedJets_dict, selectedBJets_dict = {}, {}, {}
def jetSelection(jetDict):
    seq = []
    
    for systName,(jetCollection,fatjetCollection, hotvrjetCollection, hotvrsubjetCollection) in jetDict.items():
        seq.extend([
            JetSelection(
                inputCollection= jetCollection, 
                leptonCollectionDRCleaning=lambda event: event.tightRelIso_looseID_Muons+event.loose_MVA_Electrons,
                #leptonCollectionDRCleaning=lambda event: event.tightRelIso_tightID_Muons+event.loose_MVA_Electrons,
                jetMinPt=30.,
                jetMaxEta=2.4,
                dRCleaning=0.4,
                jetId=JetSelection.TIGHTLEPVETO,
                storeKinematics=['pt', 'eta','phi','mass','btagDeepFlavB', 'area'],
                outputName_list=["selectedJets_"+systName,"unselectedJets_"+systName],
                metInput = lambda event: Object(event, "MET"),
                storeTruthKeys = ['hadronFlavour','partonFlavour'],
            ),
            #TODO: every ak8 will also be ak4 -> some cross cleaning required
            JetSelection(
                inputCollection= fatjetCollection, 
                leptonCollectionDRCleaning=lambda event,sys=systName: event.tightRelIso_looseID_Muons+event.loose_MVA_Electrons,
                #leptonCollectionDRCleaning=lambda event,sys=systName: event.tightRelIso_tightID_Muons+event.loose_MVA_Electrons,
                jetMinPt=200., 
                jetMaxEta=2.4,
                dRCleaning=0.8,
                jetId=JetSelection.TIGHT,
                storeKinematics=['pt', 'eta','phi','mass', 'genJetAK8Idx', 'deepTag_TvsQCD', 'deepTag_WvsQCD', 'particleNet_TvsQCD', 'particleNet_WvsQCD', 'particleNet_QCD', 'particleNet_mass', 'btagDeepB', 'tau2', 'tau3', 'tau1', 'msoftdrop', 'area'],
                outputName_list=["selectedFatJets_"+systName,"unselectedFatJets_"+systName],
                metInput = lambda event: Object(event, "MET"),
                storeTruthKeys = ['hadronFlavour','nBHadrons', 'nCHadrons'],
            ),
        ])

        
        seq.append(
            BTagSelection(
                b_tagging_wpValues[args.year],
                inputCollection=lambda event,sys=systName: getattr(event,"selectedJets_"+sys),
                outputName_list=["selectedBJets_"+systName+"_tight", "selectedBJets_"+systName+"_medium", "selectedBJets_"+systName+"_loose"],
                jetMinPt=30.,
                jetMaxEta=2.4,
                workingpoint = [],
                storeKinematics=['pt', 'eta','phi','mass', 'area'],
                storeTruthKeys = ['hadronFlavour','partonFlavour'],
            )
        )

    seq.extend([
        JetSelection(
            inputCollection= lambda event: Collection(event,"HOTVRJet"), 
            #leptonCollectionDRCleaning=lambda event: event.tightRelIso_looseID_Muons+event.loose_MVA_Electrons,
            leptonCollectionDRCleaning=lambda event: event.tightRelIso_tightID_Muons+event.loose_MVA_Electrons,
            jetMinPt=200., 
            jetMaxEta= 2.4,
            dRCleaning=0.,
            jetId=JetSelection.NONE,
            storeKinematics=['pt','eta','phi','mass', 'btagDeepB', 'tau2', 'tau3', 'tau1', 'area', 'btagDeepFlavB', 'btagDeepB', 'nConstituents', 'subJetIdx1', 'subJetIdx2', 'subJetIdx3'],
            outputName_list=["preselectedHOTVRJets","preunselectedHOTVRJets"],
            metInput = lambda event: Object(event, "MET"),
            storeTruthKeys = ['hadronFlavour','partonFlavour'],
            )])

    seq.extend([
        JetSelection(
            inputCollection= lambda event: Collection(event,"HOTVRSubJet"), 
            #leptonCollectionDRCleaning=lambda event: event.tightRelIso_looseID_Muons+event.loose_MVA_Electrons,
            leptonCollectionDRCleaning=lambda event: event.tightRelIso_tightID_Muons+event.loose_MVA_Electrons,
            jetMinPt=30., 
            jetMaxEta= 2.4,
            dRCleaning=0.,
            jetId=JetSelection.NONE,
            storeKinematics=['pt','eta','phi','mass','_index', 'area'],
            outputName_list=["preselectedHOTVRSubJets","preunselectedHOTVRSubJets"],
            metInput = lambda event: Object(event, "MET"),
            storeTruthKeys = ['hadronFlavour','partonFlavour'],
            )])

    systNames = jetDict.keys()
   
    # at least 1 HOTVR
    # seq.append(
    #    EventSkim(selection=lambda event: 
    #        getattr(event, "npreselectedHOTVRJets") > 0
    #    ),
    # )
   
    #at least 2 AK8 jets
    #seq.append(
    #    EventSkim(selection=lambda event, systNames=systNames: 
    #        any([getattr(event, "nselectedFatJets_"+systName) >= 2 for systName in systNames])
    #    )
    #)
    
    if isMC:
        jesUncertForBtag = ['jes'+syst.replace('Total','') for syst in jesUncertaintyNames]
        seq.append(
            btagSFProducer(
            era=args.year,
            jesSystsForShape = jesUncertForBtag,
            nosyst = args.nosys
            )
        )

    return seq

# selectedFatJets_dict = {systName: lambda event,sys=systName: getattr(event,"selectedFatJets_"+sys)}
# selectedJets_dict = {systName: lambda event,sys=systName: getattr(event,"selectedJets_"+sys)}
# selectedBJets_dict = {systName: [lambda event,sys=systName: getattr(event,"selectedBJets_"+sys+"_tight"),lambda event,sys=systName: getattr(event,"selectedBJets_"+sys+"_medium"),lambda event,sys=systName: getattr(event,"selectedBJets_"+sys+"_loose")]}
#####

##### EVENT INFO MODULE
if not Module.globalOptions["isData"]:
    storeVariables = [[lambda tree: tree.branch("genweight", "F"), 
                       lambda tree, event: tree.fillBranch("genweight", event.Generator_weight)], 
                       [lambda tree: tree.branch("run", "I"), 
                        lambda tree, event: tree.fillBranch("run", event.run)],
                        [lambda tree: tree.branch("PV_npvs", "I"), lambda tree,
                        event: tree.fillBranch("PV_npvs", event.PV_npvs)],
                        [lambda tree: tree.branch("PV_npvsGood", "I"), lambda tree,
                        event: tree.fillBranch("PV_npvsGood", event.PV_npvsGood)],
                        [lambda tree: tree.branch("fixedGridRhoFastjetAll", "F"), lambda tree,
                        event: tree.fillBranch("fixedGridRhoFastjetAll",
                        event.fixedGridRhoFastjetAll)],
    ]
	
else: 
    storeVariables = [[lambda tree: tree.branch("run", "I"),
        lambda tree, event: tree.fillBranch("run", event.run)],
        [lambda tree: tree.branch("PV_npvs", "I"), lambda tree,
        event: tree.fillBranch("PV_npvs", event.PV_npvs)],
        [lambda tree: tree.branch("PV_npvsGood", "I"), lambda tree,
        event: tree.fillBranch("PV_npvsGood", event.PV_npvsGood)],
        [lambda tree: tree.branch("luminosityBlock", "I"), lambda tree,
        event: tree.fillBranch("luminosityBlock", event.luminosityBlock)],
        [lambda tree: tree.branch("fixedGridRhoFastjetAll", "F"), lambda tree,
        event: tree.fillBranch("fixedGridRhoFastjetAll",
        event.fixedGridRhoFastjetAll)],
    ]

#####ANALYZER CHAIN : DATA ARE FILTERED FROM GOLDENJSON RUNS
# VW: This gives MET_filter branch equivalent to passmetfilters in NanoHRT-tools
if not Module.globalOptions["isData"]:	
    analyzerChain = [
        EventInfo(storeVariables=storeVariables),
        EventSkim(selection=lambda event: event.nTrigObj > 0),
        MetFilter(
            globalOptions=globalOptions,
            outputName="MET_filter"
            ),
        ]
else:                   
    analyzerChain = [
        EventInfo(storeVariables=storeVariables),
        EventSkim(selection=lambda event: event.run in filtered_data.keys()),
        EventSkim(selection=lambda event: event.luminosityBlock in filtered_data[event.run]) ,
        EventSkim(selection=lambda event: event.nTrigObj > 0),
        MetFilter(
            globalOptions=globalOptions,
            outputName="MET_filter"
        ),
]
#####

analyzerChain.extend(leptonSequence())
#analyzerChain.extend(trigger())

analyzerChain.extend([
    SingleMuonTriggerSelection(
        inputCollection=lambda event: Collection(event, "tightRelIso_tightID_Muons"),
        storeWeights=False,
        outputName="SingleMu_Trigger"
    )
])

#####JETMET UNCERTAINTIES MODULE
if args.isData:
    analyzerChain.extend(
        jetSelection({
            "nominal": (lambda event: Collection(event,"Jet"),lambda event: Collection(event,"FatJet"),lambda event: Collection(event,"HOTVRJet"),lambda event: Collection(event,"HOTVRSubJet"))
        })
    )

else:
    analyzerChain.append(PUWeightProducer_dict[args.year]())

    if args.nosys:
        jesUncertaintyNames = []
    else:
        
        jesUncertaintyNames = ["Total","Absolute","EC2","BBEC1", "HF","RelativeBal","FlavorQCD" ]
        for jesUncertaintyExtra in ["RelativeSample","HF","Absolute","EC2","BBEC1"]:
            jesUncertaintyNames.append(jesUncertaintyExtra+"_"+args.year.replace("preVFP",""))
        
        jesUncertaintyNames = ["Total"]
            
        print("JECs: ",jesUncertaintyNames)
        
    #TODO: apply type2 corrections? -> improves met modelling; in particular for 2018
    analyzerChain.extend([
        JetMetUncertainties(
            jesUncertaintyFilesRegrouped[args.year],
            jerResolutionFiles[args.year],
            jerSFUncertaintyFiles[args.year],
            jesUncertaintyNames = jesUncertaintyNames, 
            metInput = lambda event: Object(event, "MET"),
            rhoInput = lambda event: event.fixedGridRhoFastjetAll,
            jetCollection = lambda event: Collection(event,"Jet"),
            lowPtJetCollection = lambda event: Collection(event,"CorrT1METJet"),
            genJetCollection = lambda event: Collection(event,"GenJet"),
            muonCollection = lambda event: Collection(event,"Muon"),
            electronCollection = lambda event: Collection(event,"Electron"),
            propagateJER = False, #not recommended
            outputJetPrefix = 'jets_',
            outputMetPrefix = 'met_',
            jetKeys=['jetId', 'nConstituents','btagDeepFlavB','hadronFlavour','partonFlavour','genJetIdx', 'area'],
        ),
        JetMetUncertainties(
            jesAK8UncertaintyFilesRegrouped[args.year],
            jerAK8ResolutionFiles[args.year],
            jerAK8SFUncertaintyFiles[args.year],
            jesUncertaintyNames = jesUncertaintyNames, 
            metInput = None,
            rhoInput = lambda event: event.fixedGridRhoFastjetAll,
            jetCollection = lambda event: Collection(event,"FatJet"),
            lowPtJetCollection = lambda event: [],
            genJetCollection = lambda event: Collection(event,"GenJetAK8"),
            muonCollection = lambda event: Collection(event,"Muon"),
            electronCollection = lambda event: Collection(event,"Electron"),
            propagateToMet = False, #no met variations
            propagateJER = False, #not recommended
            outputJetPrefix = 'fatjets_',
            outputMetPrefix = None,
            jetKeys=['jetId', 'btagDeepB','deepTag_TvsQCD','deepTag_WvsQCD','particleNet_TvsQCD','particleNet_WvsQCD','particleNet_mass', 'particleNet_QCD','hadronFlavour', 'genJetAK8Idx', 'nBHadrons', 'tau2', 'tau3', 'tau1', 'msoftdrop', 'nCHadrons', 'nBHadrons', 'area'],  #'nConstituents'
        ), 
        # JetMetUncertaintiesHOTVR(
        #     jesUncertaintyFilesRegrouped[args.year],
        #     jerResolutionFiles[args.year],
        #     jerSFUncertaintyFiles[args.year],
        #     jesUncertaintyNames = jesUncertaintyNames, 
        #     metInput = lambda event: Object(event, "MET"),
        #     rhoInput = lambda event: event.fixedGridRhoFastjetAll,
        #     jetCollection = lambda event: Collection(event,"HOTVRJet"),
        #     subjetCollection = lambda event: Collection(event,"SubHOTVRJet"),
        #     lowPtJetCollection = lambda event: Collection(event,"CorrT1METJet"),
        #     genJetCollection = lambda event: Collection(event,"GenHOTVRJet"),
        #     muonCollection = lambda event: Collection(event,"Muon"),
        #     electronCollection = lambda event: Collection(event,"Electron"),
        #     propagateJER = False, #not recommended
        #     outputJetPrefix = 'hotvrjets_',
        #     outputMetPrefix = None,
        #     jetKeys=['nConstituents','hadronFlavour','partonFlavour', 'tau2', 'tau3', 'tau1', 'area'],
        # ),
        # JetMetUncertainties(
        #     jesUncertaintyFilesRegrouped[args.year],
        #     jerResolutionFiles[args.year],
        #     jerSFUncertaintyFiles[args.year],
        #     jesUncertaintyNames = jesUncertaintyNames, 
        #     metInput = lambda event: Object(event, "MET"),
        #     rhoInput = lambda event: event.fixedGridRhoFastjetAll,
        #     jetCollection = lambda event: Collection(event,"HOTVRSubJet"),
        #     lowPtJetCollection = lambda event: Collection(event,"CorrT1METJet"),
        #     genJetCollection = lambda event: Collection(event,"GenHOTVRSubJet"),
        #     muonCollection = lambda event: Collection(event,"Muon"),
        #     electronCollection = lambda event: Collection(event,"Electron"),
        #     propagateJER = False, #not recommended
        #     outputJetPrefix = 'hotvrsubjets_',
        #     outputMetPrefix = None,
        #     jetKeys=['nConstituents','hadronFlavour','partonFlavour', 'area'],
        # )
    ])

    jetDict = {
        "nominal": (lambda event: event.jets_nominal,lambda event: event.fatjets_nominal,lambda event: event.hotvrjets_nominal,lambda event: event.hotvrsubjets_nominal)
    }
    
    if not args.nosys:
        jetDict["jerUp"] = (lambda event: event.jets_jerUp,lambda event: event.fatjets_jerUp,lambda event: event.hotvrjets_jerUp,lambda event: event.hotvrsubjets_jerUp)
        jetDict["jerDown"] = (lambda event: event.jets_jerDown,lambda event: event.fatjets_jerDown,lambda event: event.hotvrjets_jerDown,lambda event: event.hotvrsubjets_jerDown)
        
        for jesUncertaintyName in jesUncertaintyNames:
            jetDict['jes'+jesUncertaintyName+"Up"] = (lambda event,sys=jesUncertaintyName: getattr(event,"jets_jes"+sys+"Up"),lambda event,sys=jesUncertaintyName: getattr(event,"fatjets_jes"+sys+"Up"),lambda event,sys=jesUncertaintyName: getattr(event,"hotvrjets_jes"+sys+"Up"),lambda event,sys=jesUncertaintyName: getattr(event,"hotvrsubjets_jes"+sys+"Up"))
            jetDict['jes'+jesUncertaintyName+"Down"] = (lambda event,sys=jesUncertaintyName: getattr(event,"jets_jes"+sys+"Down"),lambda event,sys=jesUncertaintyName: getattr(event,"fatjets_jes"+sys+"Down"),lambda event,sys=jesUncertaintyName: getattr(event,"hotvrjets_jes"+sys+"Down"),lambda event,sys=jesUncertaintyName: getattr(event,"hotvrsubjets_jes"+sys+"Down"))
    
    analyzerChain.extend(
        jetSelection(jetDict)
    )
#####

# MET cut, requiring MET >= 50
analyzerChain.extend([
    MetSelection(metCut=lambda met: met.pt >= 50.0)
])

##### GENERATION MODULE
if isMC:
    # for systName,(jetCollection,fatjetCollection) in jetDict.items():
        analyzerChain.extend( [
            GenParticleModule(
                inputGenCollection=lambda event: Collection(event, "GenPart"),
                inputFatGenJetCollection=lambda event: Collection(event, "GenJetAK8"),
                inputGenJetCollection=lambda event: Collection(event, "GenJet"),
                inputMuonCollection=lambda event: event.tightRelIso_mediumID_Muons,
                inputElectronCollection=lambda event: event.medium_MVA_Electrons,
                outputName="genPart",
                storeKinematics= ['pt','eta','phi','mass'],
            ),
        ])
####


##### EVENT RECONSTRUCTION MODULE
triggers = {}
#if Module.globalOptions["isData"]:
#    triggers = {'ee': lambda event: False, 'emu': False, 'mumu': False} # initializing the dictionary 
#    triggers[args.trigger] = lambda event: getattr(event, "trigger_"+args.trigger+"_flag") # getting the trigger flag corresponding to the input trigger given
#else: 
#    triggers = {'ee': lambda event: event.trigger_ee_flag, 'emu': lambda event: event.trigger_emu_flag, 'mumu': lambda event: event.trigger_mumu_flag}
for key in ["ee", "emu", "mumu"]: triggers[key] = lambda event: False

event_reco_inputs = {
    'inputTriggersCollection': triggers,
    #'inputMuonCollection': lambda event: event.tightRelIso_looseID_Muons,
    'inputMuonCollection': lambda event: event.tightRelIso_tightID_Muons,
    'inputElectronCollection': lambda event: event.loose_MVA_Electrons,
    'inputJetCollection': lambda event: event.selectedJets_nominal,
    'inputBJetCollection': lambda event: event.selectedBJets_nominal_loose,
    'inputFatJetCollection': lambda event: event.selectedFatJets_nominal,
    'inputMETCollection': [],  # to be included!
    'inputHOTVRJetCollection': lambda event: getattr(event, "preselectedHOTVRJets"),
    'inputHOTVRSubJetCollection': lambda event: getattr(event, "preselectedHOTVRSubJets"),
}
if not Module.globalOptions["isData"]: event_reco_inputs['inputGenTopCollection'] = lambda event: event.genTops

if args.isData: ak4jet_systnames = ["nominal"]
else: ak4jet_systnames = jetDict.keys()

def leptonic_W_cut(event):
    muon = event.tightRelIso_tightID_Muons[0]
    met = Object(event, "MET")
    metvec = ROOT.Math.PtEtaPhiMVector(met.pt, 0, met.phi, 0)
    return (polarP4(muon) + metvec).Pt() >= 100.0

def leptonic_W_pt(event):
    muon = event.tightRelIso_tightID_Muons[0]
    met = Object(event, "MET")
    metvec = ROOT.Math.PtEtaPhiMVector(met.pt, 0, met.phi, 0)
    return (polarP4(muon) + metvec).Pt()

def bjet_in_same_hemisphere_as_muon(event, systNames=ak4jet_systnames):
    muon = event.tightRelIso_tightID_Muons[0]

    #get_btag = lambda j: (j.btagDeepFlavB > b_tagging_wpValues[args.year][1]) and (abs(deltaPhi(j.phi, muon.phi)) < 2)
    get_btag = lambda j: (abs(deltaPhi(j.phi, muon.phi)) < 2)

    at_least_one_bjet_in_same_hemisphere = [len(filter(get_btag, getattr(event, "selectedBJets_"+systname+"_medium"))) != 0 for systname in systNames]

    return any(at_least_one_bjet_in_same_hemisphere)

def fatjet_away_from_muon(event, systNames=ak4jet_systnames):
    muon = event.tightRelIso_tightID_Muons[0]

    fatjet_is_away = lambda fj: abs(deltaPhi(fj.phi, muon.phi)) > 2

    probe_jets = [len(filter(fatjet_is_away, getattr(event, "selectedFatJets_"+systname))) != 0 for systname in systNames]

    return any(probe_jets)

analyzerChain.extend([
    # Exactly one muon
    EventSkim(selection=lambda event: event.ntightRelIso_tightID_Muons == 1),
    # Leptonic W pt cut
    EventSkim(selection=leptonic_W_cut),
    #EventSkim(selection=leptonic_W_pt, outputName="leptonicW_pt"),
    LeptonicWProducer(
        inputMuonCollection=lambda event: event.tightRelIso_tightID_Muons,
        inputMet=lambda event: Object(event, "MET"),
        outputName="Leptonic_W_pt"
    ),
    # At least one b-jet, in the same hemisphere of the muon
    EventSkim(selection=bjet_in_same_hemisphere_as_muon),
    # At least one fat jet away from the muon
    EventSkim(selection=fatjet_away_from_muon),
    EventReconstruction(**event_reco_inputs),
    #EventSkim(selection=lambda event: (event.event_selection_OS_dilepton_cut))
])

##### HOTVR/AK8 JET COMPOSITION MODULE 
if not Module.globalOptions["isData"]:
    analyzerChain.append(
        HOTVRJetComposition(
            inputHOTVRJetCollection = lambda event: getattr(event,"preselectedHOTVRJets"),
            inputGenParticleCollections = {
                'gentops': lambda event: event.genTops, 
                'genWs_not_from_top': lambda event: event.gen_w_bosons_not_from_top, 
                'genbs_not_from_top': lambda event: event.gen_b_quarks_not_from_top, 
                'genparticles_not_from_top': lambda event: event.gen_particles_not_from_top
                },
            inputSubHOTVRJetCollection = lambda event: getattr(event,"preselectedHOTVRSubJets"),
        )
    )
    analyzerChain.append(
        FatJetComposition(
            inputFatJetCollection = lambda event: getattr(event,"selectedFatJets_nominal"),
            inputGenParticleCollections = {
                'gentops': lambda event: event.genTops, 
                'genWs_not_from_top': lambda event: event.gen_w_bosons_not_from_top, 
                'genbs_not_from_top': lambda event: event.gen_b_quarks_not_from_top, 
                'genparticles_not_from_top': lambda event: event.gen_particles_not_from_top
                },
        )
    )

#### XGB EVALUATION MODULE
analyzerChain.append(
    XGBEvaluationProducer(
        modelPath=xgb_models[args.year],
        inputHOTVRJetCollection=lambda event: getattr(event,"preselectedHOTVRJets"),
        outputName="scoreBDT"
    )
)


if not args.isData:
    #analyzerChain.append(GenWeightProducer())
    if isPowhegTTbar:
        analyzerChain.append(
            TopPtWeightProducer(
                mode=TopPtWeightProducer.DATA_NLO
            )
        )


p = PostProcessor(
    args.output[0],
    args.inputFiles,
    cut="",#"(nJet>1)&&((nElectron+nMuon)>1)", #at least 2 jets + 2 leptons
    modules=analyzerChain,
    friend=True,
    maxEntries = args.maxEvents,
)

p.run()

