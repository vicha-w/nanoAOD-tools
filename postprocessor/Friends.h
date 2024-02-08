//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Feb  8 23:24:39 2024 by ROOT version 6.30/02
// from TTree Friends/Friend tree for Events
// found on file: test/NANO_NANO_3262_Friend.root
//////////////////////////////////////////////////////////

#ifndef Friends_h
#define Friends_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Friends {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           PV_npvs;
   Int_t           PV_npvsGood;
   Int_t           luminosityBlock;
   Float_t         fixedGridRhoFastjetAll;
   Float_t         genweight;
   Float_t         LHE_HT;
   Int_t           nLHEScaleWeight;
   Float_t         LHEScaleWeight[9];   //[nLHEScaleWeight]
   Float_t         L1PreFiringWeight_Nom;
   Float_t         L1PreFiringWeight_Up;
   Float_t         L1PreFiringWeight_Dn;
   Int_t           MET_filter;
   UInt_t          nMuon;
   Float_t         muon_PFRelIso04[4];   //[nMuon]
   Float_t         muon_tightID[4];   //[nMuon]
   Float_t         muon_mediumID[4];   //[nMuon]
   Float_t         muon_looseID[4];   //[nMuon]
   Int_t           ntightRelIso_tightID_Muons;
   Float_t         tightRelIso_tightID_Muons_pt[2];   //[ntightRelIso_tightID_Muons]
   Float_t         tightRelIso_tightID_Muons_eta[2];   //[ntightRelIso_tightID_Muons]
   Float_t         tightRelIso_tightID_Muons_charge[2];   //[ntightRelIso_tightID_Muons]
   Float_t         tightRelIso_tightID_Muons_phi[2];   //[ntightRelIso_tightID_Muons]
   Float_t         tightRelIso_tightID_Muons_mass[2];   //[ntightRelIso_tightID_Muons]
   Float_t         tightRelIso_tightID_Muons_miniPFRelIso_all[2];   //[ntightRelIso_tightID_Muons]
   Int_t           ntightRelIso_mediumID_Muons;
   Float_t         tightRelIso_mediumID_Muons_pt[2];   //[ntightRelIso_mediumID_Muons]
   Float_t         tightRelIso_mediumID_Muons_eta[2];   //[ntightRelIso_mediumID_Muons]
   Float_t         tightRelIso_mediumID_Muons_charge[2];   //[ntightRelIso_mediumID_Muons]
   Float_t         tightRelIso_mediumID_Muons_phi[2];   //[ntightRelIso_mediumID_Muons]
   Float_t         tightRelIso_mediumID_Muons_mass[2];   //[ntightRelIso_mediumID_Muons]
   Float_t         tightRelIso_mediumID_Muons_miniPFRelIso_all[2];   //[ntightRelIso_mediumID_Muons]
   Int_t           ntightRelIso_looseID_Muons;
   Float_t         tightRelIso_looseID_Muons_pt[2];   //[ntightRelIso_looseID_Muons]
   Float_t         tightRelIso_looseID_Muons_eta[2];   //[ntightRelIso_looseID_Muons]
   Float_t         tightRelIso_looseID_Muons_charge[2];   //[ntightRelIso_looseID_Muons]
   Float_t         tightRelIso_looseID_Muons_phi[2];   //[ntightRelIso_looseID_Muons]
   Float_t         tightRelIso_looseID_Muons_mass[2];   //[ntightRelIso_looseID_Muons]
   Float_t         tightRelIso_looseID_Muons_miniPFRelIso_all[2];   //[ntightRelIso_looseID_Muons]
   UInt_t          nElectron;
   Float_t         electron_cutBasedID[3];   //[nElectron]
   Float_t         electron_MVA_tightID[3];   //[nElectron]
   Float_t         electron_MVA_mediumID[3];   //[nElectron]
   Float_t         electron_MVA_looseID[3];   //[nElectron]
   Int_t           ntight_MVA_Electrons;
   Float_t         tight_MVA_Electrons_pt[1];   //[ntight_MVA_Electrons]
   Float_t         tight_MVA_Electrons_eta[1];   //[ntight_MVA_Electrons]
   Float_t         tight_MVA_Electrons_charge[1];   //[ntight_MVA_Electrons]
   Float_t         tight_MVA_Electrons_phi[1];   //[ntight_MVA_Electrons]
   Float_t         tight_MVA_Electrons_mass[1];   //[ntight_MVA_Electrons]
   Int_t           nmedium_MVA_Electrons;
   Float_t         medium_MVA_Electrons_pt[1];   //[nmedium_MVA_Electrons]
   Float_t         medium_MVA_Electrons_eta[1];   //[nmedium_MVA_Electrons]
   Float_t         medium_MVA_Electrons_charge[1];   //[nmedium_MVA_Electrons]
   Float_t         medium_MVA_Electrons_phi[1];   //[nmedium_MVA_Electrons]
   Float_t         medium_MVA_Electrons_mass[1];   //[nmedium_MVA_Electrons]
   Int_t           nloose_MVA_Electrons;
   Float_t         loose_MVA_Electrons_pt[2];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_eta[2];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_charge[2];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_phi[2];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_mass[2];   //[nloose_MVA_Electrons]
   Int_t           ntight_cutBased_Electrons;
   Float_t         tight_cutBased_Electrons_pt[1];   //[ntight_cutBased_Electrons]
   Float_t         tight_cutBased_Electrons_eta[1];   //[ntight_cutBased_Electrons]
   Float_t         tight_cutBased_Electrons_charge[1];   //[ntight_cutBased_Electrons]
   Float_t         tight_cutBased_Electrons_phi[1];   //[ntight_cutBased_Electrons]
   Float_t         tight_cutBased_Electrons_mass[1];   //[ntight_cutBased_Electrons]
   Int_t           nmedium_cutBased_Electrons;
   Float_t         medium_cutBased_Electrons_pt[1];   //[nmedium_cutBased_Electrons]
   Float_t         medium_cutBased_Electrons_eta[1];   //[nmedium_cutBased_Electrons]
   Float_t         medium_cutBased_Electrons_charge[1];   //[nmedium_cutBased_Electrons]
   Float_t         medium_cutBased_Electrons_phi[1];   //[nmedium_cutBased_Electrons]
   Float_t         medium_cutBased_Electrons_mass[1];   //[nmedium_cutBased_Electrons]
   Int_t           nloose_cutBased_Electrons;
   Float_t         loose_cutBased_Electrons_pt[1];   //[nloose_cutBased_Electrons]
   Float_t         loose_cutBased_Electrons_eta[1];   //[nloose_cutBased_Electrons]
   Float_t         loose_cutBased_Electrons_charge[1];   //[nloose_cutBased_Electrons]
   Float_t         loose_cutBased_Electrons_phi[1];   //[nloose_cutBased_Electrons]
   Float_t         loose_cutBased_Electrons_mass[1];   //[nloose_cutBased_Electrons]
   Float_t         tightRelIso_tightID_Muons_weight_id_nominal;
   Float_t         tightRelIso_tightID_Muons_weight_iso_nominal;
   Float_t         tightRelIso_tightID_Muons_weight_id_up;
   Float_t         tightRelIso_tightID_Muons_weight_iso_up;
   Float_t         tightRelIso_tightID_Muons_weight_id_down;
   Float_t         tightRelIso_tightID_Muons_weight_iso_down;
   Float_t         tightRelIso_mediumID_Muons_weight_id_nominal;
   Float_t         tightRelIso_mediumID_Muons_weight_iso_nominal;
   Float_t         tightRelIso_mediumID_Muons_weight_id_up;
   Float_t         tightRelIso_mediumID_Muons_weight_iso_up;
   Float_t         tightRelIso_mediumID_Muons_weight_id_down;
   Float_t         tightRelIso_mediumID_Muons_weight_iso_down;
   Float_t         tightRelIso_looseID_Muons_weight_id_nominal;
   Float_t         tightRelIso_looseID_Muons_weight_iso_nominal;
   Float_t         tightRelIso_looseID_Muons_weight_id_up;
   Float_t         tightRelIso_looseID_Muons_weight_iso_up;
   Float_t         tightRelIso_looseID_Muons_weight_id_down;
   Float_t         tightRelIso_looseID_Muons_weight_iso_down;
   Float_t         tight_MVA_Electrons_weight_id_nominal;
   Float_t         tight_MVA_Electrons_weight_recoPt_nominal;
   Float_t         tight_MVA_Electrons_weight_id_up;
   Float_t         tight_MVA_Electrons_weight_recoPt_up;
   Float_t         tight_MVA_Electrons_weight_id_down;
   Float_t         tight_MVA_Electrons_weight_recoPt_down;
   Float_t         tight_cutBased_Electrons_weight_id_nominal;
   Float_t         tight_cutBased_Electrons_weight_recoPt_nominal;
   Float_t         tight_cutBased_Electrons_weight_id_up;
   Float_t         tight_cutBased_Electrons_weight_recoPt_up;
   Float_t         tight_cutBased_Electrons_weight_id_down;
   Float_t         tight_cutBased_Electrons_weight_recoPt_down;
   Float_t         medium_MVA_Electrons_weight_id_nominal;
   Float_t         medium_MVA_Electrons_weight_recoPt_nominal;
   Float_t         medium_MVA_Electrons_weight_id_up;
   Float_t         medium_MVA_Electrons_weight_recoPt_up;
   Float_t         medium_MVA_Electrons_weight_id_down;
   Float_t         medium_MVA_Electrons_weight_recoPt_down;
   Float_t         medium_cutBased_Electrons_weight_id_nominal;
   Float_t         medium_cutBased_Electrons_weight_recoPt_nominal;
   Float_t         medium_cutBased_Electrons_weight_id_up;
   Float_t         medium_cutBased_Electrons_weight_recoPt_up;
   Float_t         medium_cutBased_Electrons_weight_id_down;
   Float_t         medium_cutBased_Electrons_weight_recoPt_down;
   Float_t         loose_MVA_Electrons_weight_id_nominal;
   Float_t         loose_MVA_Electrons_weight_recoPt_nominal;
   Float_t         loose_MVA_Electrons_weight_id_up;
   Float_t         loose_MVA_Electrons_weight_recoPt_up;
   Float_t         loose_MVA_Electrons_weight_id_down;
   Float_t         loose_MVA_Electrons_weight_recoPt_down;
   Float_t         loose_cutBased_Electrons_weight_id_nominal;
   Float_t         loose_cutBased_Electrons_weight_recoPt_nominal;
   Float_t         loose_cutBased_Electrons_weight_id_up;
   Float_t         loose_cutBased_Electrons_weight_recoPt_up;
   Float_t         loose_cutBased_Electrons_weight_id_down;
   Float_t         loose_cutBased_Electrons_weight_recoPt_down;
   Int_t           SingleMu_Trigger_flag;
   Float_t         puWeight;
   Float_t         puWeightUp;
   Float_t         puWeightDown;
   Float_t         MET_energy;
   Int_t           nselectedJets_jesTotalDown;
   Float_t         selectedJets_jesTotalDown_pt[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_eta[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_phi[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_mass[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_btagDeepFlavB[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_area[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_hadronFlavour[11];   //[nselectedJets_jesTotalDown]
   Float_t         selectedJets_jesTotalDown_partonFlavour[11];   //[nselectedJets_jesTotalDown]
   Int_t           nunselectedJets_jesTotalDown;
   Float_t         unselectedJets_jesTotalDown_pt[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_eta[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_phi[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_mass[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_btagDeepFlavB[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_area[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_hadronFlavour[21];   //[nunselectedJets_jesTotalDown]
   Float_t         unselectedJets_jesTotalDown_partonFlavour[21];   //[nunselectedJets_jesTotalDown]
   Int_t           nselectedFatJets_jesTotalDown;
   Float_t         selectedFatJets_jesTotalDown_pt[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_eta[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_phi[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_mass[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_genJetAK8Idx[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_deepTag_TvsQCD[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_deepTag_WvsQCD[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_particleNet_TvsQCD[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_particleNet_WvsQCD[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_particleNet_QCD[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_particleNet_mass[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_btagDeepB[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_tau2[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_tau3[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_tau1[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_msoftdrop[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_area[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_hadronFlavour[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_nBHadrons[4];   //[nselectedFatJets_jesTotalDown]
   Float_t         selectedFatJets_jesTotalDown_nCHadrons[4];   //[nselectedFatJets_jesTotalDown]
   Int_t           nunselectedFatJets_jesTotalDown;
   Float_t         unselectedFatJets_jesTotalDown_pt[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_eta[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_phi[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_mass[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_genJetAK8Idx[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_deepTag_TvsQCD[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_deepTag_WvsQCD[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_particleNet_TvsQCD[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_particleNet_WvsQCD[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_particleNet_QCD[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_particleNet_mass[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_btagDeepB[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_tau2[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_tau3[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_tau1[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_msoftdrop[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_area[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_hadronFlavour[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_nBHadrons[3];   //[nunselectedFatJets_jesTotalDown]
   Float_t         unselectedFatJets_jesTotalDown_nCHadrons[3];   //[nunselectedFatJets_jesTotalDown]
   Int_t           nselectedHOTVRJets_jesTotalDown;
   Float_t         selectedHOTVRJets_jesTotalDown_pt[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_eta[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_phi[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_mass[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_btagDeepB[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_tau2[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_tau3[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_tau1[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_area[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_btagDeepFlavB[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_nConstituents[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_subJetIdx1[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_subJetIdx2[3];   //[nselectedHOTVRJets_jesTotalDown]
   Float_t         selectedHOTVRJets_jesTotalDown_subJetIdx3[3];   //[nselectedHOTVRJets_jesTotalDown]
   Int_t           nunselectedHOTVRJets_jesTotalDown;
   Float_t         unselectedHOTVRJets_jesTotalDown_pt[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_eta[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_phi[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_mass[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_btagDeepB[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_tau2[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_tau3[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_tau1[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_area[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_btagDeepFlavB[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_nConstituents[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_subJetIdx1[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_subJetIdx2[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         unselectedHOTVRJets_jesTotalDown_subJetIdx3[4];   //[nunselectedHOTVRJets_jesTotalDown]
   Float_t         MET_jesTotalDown_pt;
   Float_t         MET_jesTotalDown_phi;
   Int_t           nselectedBJets_jesTotalDown_tight;
   Float_t         selectedBJets_jesTotalDown_tight_pt[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_eta[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_phi[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_mass[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_area[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_hadronFlavour[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_partonFlavour[4];   //[nselectedBJets_jesTotalDown_tight]
   Float_t         selectedBJets_jesTotalDown_tight_genJetIdx[4];   //[nselectedBJets_jesTotalDown_tight]
   Int_t           nselectedBJets_jesTotalDown_medium;
   Float_t         selectedBJets_jesTotalDown_medium_pt[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_eta[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_phi[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_mass[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_area[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_hadronFlavour[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_partonFlavour[5];   //[nselectedBJets_jesTotalDown_medium]
   Float_t         selectedBJets_jesTotalDown_medium_genJetIdx[5];   //[nselectedBJets_jesTotalDown_medium]
   Int_t           nselectedBJets_jesTotalDown_loose;
   Float_t         selectedBJets_jesTotalDown_loose_pt[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_eta[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_phi[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_mass[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_area[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_hadronFlavour[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_partonFlavour[6];   //[nselectedBJets_jesTotalDown_loose]
   Float_t         selectedBJets_jesTotalDown_loose_genJetIdx[6];   //[nselectedBJets_jesTotalDown_loose]
   Int_t           nselectedJets_jerUp;
   Float_t         selectedJets_jerUp_pt[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_eta[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_phi[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_mass[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_btagDeepFlavB[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_area[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_hadronFlavour[11];   //[nselectedJets_jerUp]
   Float_t         selectedJets_jerUp_partonFlavour[11];   //[nselectedJets_jerUp]
   Int_t           nunselectedJets_jerUp;
   Float_t         unselectedJets_jerUp_pt[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_eta[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_phi[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_mass[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_btagDeepFlavB[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_area[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_hadronFlavour[21];   //[nunselectedJets_jerUp]
   Float_t         unselectedJets_jerUp_partonFlavour[21];   //[nunselectedJets_jerUp]
   Int_t           nselectedFatJets_jerUp;
   Float_t         selectedFatJets_jerUp_pt[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_eta[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_phi[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_mass[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_genJetAK8Idx[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_deepTag_TvsQCD[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_deepTag_WvsQCD[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_particleNet_TvsQCD[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_particleNet_WvsQCD[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_particleNet_QCD[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_particleNet_mass[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_btagDeepB[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_tau2[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_tau3[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_tau1[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_msoftdrop[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_area[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_hadronFlavour[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_nBHadrons[4];   //[nselectedFatJets_jerUp]
   Float_t         selectedFatJets_jerUp_nCHadrons[4];   //[nselectedFatJets_jerUp]
   Int_t           nunselectedFatJets_jerUp;
   Float_t         unselectedFatJets_jerUp_pt[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_eta[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_phi[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_mass[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_genJetAK8Idx[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_deepTag_TvsQCD[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_deepTag_WvsQCD[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_particleNet_TvsQCD[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_particleNet_WvsQCD[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_particleNet_QCD[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_particleNet_mass[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_btagDeepB[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_tau2[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_tau3[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_tau1[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_msoftdrop[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_area[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_hadronFlavour[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_nBHadrons[3];   //[nunselectedFatJets_jerUp]
   Float_t         unselectedFatJets_jerUp_nCHadrons[3];   //[nunselectedFatJets_jerUp]
   Int_t           nselectedHOTVRJets_jerUp;
   Float_t         selectedHOTVRJets_jerUp_pt[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_eta[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_phi[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_mass[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_btagDeepB[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_tau2[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_tau3[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_tau1[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_area[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_btagDeepFlavB[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_nConstituents[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_subJetIdx1[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_subJetIdx2[3];   //[nselectedHOTVRJets_jerUp]
   Float_t         selectedHOTVRJets_jerUp_subJetIdx3[3];   //[nselectedHOTVRJets_jerUp]
   Int_t           nunselectedHOTVRJets_jerUp;
   Float_t         unselectedHOTVRJets_jerUp_pt[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_eta[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_phi[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_mass[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_btagDeepB[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_tau2[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_tau3[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_tau1[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_area[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_btagDeepFlavB[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_nConstituents[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_subJetIdx1[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_subJetIdx2[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         unselectedHOTVRJets_jerUp_subJetIdx3[4];   //[nunselectedHOTVRJets_jerUp]
   Float_t         MET_jerUp_pt;
   Float_t         MET_jerUp_phi;
   Int_t           nselectedBJets_jerUp_tight;
   Float_t         selectedBJets_jerUp_tight_pt[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_eta[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_phi[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_mass[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_area[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_hadronFlavour[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_partonFlavour[4];   //[nselectedBJets_jerUp_tight]
   Float_t         selectedBJets_jerUp_tight_genJetIdx[4];   //[nselectedBJets_jerUp_tight]
   Int_t           nselectedBJets_jerUp_medium;
   Float_t         selectedBJets_jerUp_medium_pt[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_eta[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_phi[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_mass[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_area[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_hadronFlavour[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_partonFlavour[5];   //[nselectedBJets_jerUp_medium]
   Float_t         selectedBJets_jerUp_medium_genJetIdx[5];   //[nselectedBJets_jerUp_medium]
   Int_t           nselectedBJets_jerUp_loose;
   Float_t         selectedBJets_jerUp_loose_pt[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_eta[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_phi[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_mass[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_area[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_hadronFlavour[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_partonFlavour[7];   //[nselectedBJets_jerUp_loose]
   Float_t         selectedBJets_jerUp_loose_genJetIdx[7];   //[nselectedBJets_jerUp_loose]
   Int_t           nselectedJets_nominal;
   Float_t         selectedJets_nominal_pt[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_eta[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_phi[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_mass[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_btagDeepFlavB[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_area[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_hadronFlavour[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_partonFlavour[11];   //[nselectedJets_nominal]
   Int_t           nunselectedJets_nominal;
   Float_t         unselectedJets_nominal_pt[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_eta[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_phi[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_mass[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_btagDeepFlavB[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_area[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_hadronFlavour[21];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_partonFlavour[21];   //[nunselectedJets_nominal]
   Int_t           nselectedFatJets_nominal;
   Float_t         selectedFatJets_nominal_pt[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_eta[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_phi[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_mass[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_genJetAK8Idx[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_deepTag_TvsQCD[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_deepTag_WvsQCD[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_TvsQCD[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_WvsQCD[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_QCD[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_mass[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_btagDeepB[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_tau2[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_tau3[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_tau1[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_msoftdrop[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_area[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_hadronFlavour[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_nBHadrons[4];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_nCHadrons[4];   //[nselectedFatJets_nominal]
   Int_t           nunselectedFatJets_nominal;
   Float_t         unselectedFatJets_nominal_pt[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_eta[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_phi[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_mass[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_genJetAK8Idx[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_deepTag_TvsQCD[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_deepTag_WvsQCD[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_particleNet_TvsQCD[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_particleNet_WvsQCD[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_particleNet_QCD[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_particleNet_mass[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_btagDeepB[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_tau2[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_tau3[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_tau1[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_msoftdrop[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_area[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_hadronFlavour[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_nBHadrons[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_nCHadrons[3];   //[nunselectedFatJets_nominal]
   Int_t           nselectedHOTVRJets_nominal;
   Float_t         selectedHOTVRJets_nominal_pt[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_eta[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_phi[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_mass[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_btagDeepB[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau2[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau3[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau1[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_area[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_btagDeepFlavB[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_nConstituents[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_subJetIdx1[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_subJetIdx2[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_subJetIdx3[3];   //[nselectedHOTVRJets_nominal]
   Int_t           nunselectedHOTVRJets_nominal;
   Float_t         unselectedHOTVRJets_nominal_pt[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_eta[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_phi[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_mass[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_btagDeepB[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_tau2[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_tau3[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_tau1[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_area[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_btagDeepFlavB[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_nConstituents[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_subJetIdx1[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_subJetIdx2[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_subJetIdx3[4];   //[nunselectedHOTVRJets_nominal]
   Float_t         MET_nominal_pt;
   Float_t         MET_nominal_phi;
   Int_t           nselectedHOTVRSubJets_nominal;
   Float_t         selectedHOTVRSubJets_nominal_pt[11];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_eta[11];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_phi[11];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_mass[11];   //[nselectedHOTVRSubJets_nominal]
   Int_t           selectedHOTVRSubJets_nominal_index[11];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_area[11];   //[nselectedHOTVRSubJets_nominal]
   Int_t           nunselectedHOTVRSubJets_nominal;
   Float_t         unselectedHOTVRSubJets_nominal_pt[7];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_eta[7];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_phi[7];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_mass[7];   //[nunselectedHOTVRSubJets_nominal]
   Int_t           unselectedHOTVRSubJets_nominal_index[7];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_area[7];   //[nunselectedHOTVRSubJets_nominal]
   Int_t           nselectedBJets_nominal_tight;
   Float_t         selectedBJets_nominal_tight_pt[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_eta[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_phi[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_mass[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_area[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_hadronFlavour[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_partonFlavour[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_genJetIdx[4];   //[nselectedBJets_nominal_tight]
   Int_t           nselectedBJets_nominal_medium;
   Float_t         selectedBJets_nominal_medium_pt[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_eta[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_phi[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_mass[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_area[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_hadronFlavour[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_partonFlavour[5];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_genJetIdx[5];   //[nselectedBJets_nominal_medium]
   Int_t           nselectedBJets_nominal_loose;
   Float_t         selectedBJets_nominal_loose_pt[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_eta[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_phi[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_mass[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_area[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_hadronFlavour[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_partonFlavour[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_genJetIdx[6];   //[nselectedBJets_nominal_loose]
   Int_t           nselectedJets_jerDown;
   Float_t         selectedJets_jerDown_pt[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_eta[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_phi[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_mass[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_btagDeepFlavB[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_area[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_hadronFlavour[11];   //[nselectedJets_jerDown]
   Float_t         selectedJets_jerDown_partonFlavour[11];   //[nselectedJets_jerDown]
   Int_t           nunselectedJets_jerDown;
   Float_t         unselectedJets_jerDown_pt[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_eta[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_phi[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_mass[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_btagDeepFlavB[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_area[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_hadronFlavour[21];   //[nunselectedJets_jerDown]
   Float_t         unselectedJets_jerDown_partonFlavour[21];   //[nunselectedJets_jerDown]
   Int_t           nselectedFatJets_jerDown;
   Float_t         selectedFatJets_jerDown_pt[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_eta[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_phi[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_mass[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_genJetAK8Idx[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_deepTag_TvsQCD[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_deepTag_WvsQCD[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_particleNet_TvsQCD[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_particleNet_WvsQCD[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_particleNet_QCD[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_particleNet_mass[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_btagDeepB[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_tau2[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_tau3[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_tau1[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_msoftdrop[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_area[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_hadronFlavour[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_nBHadrons[4];   //[nselectedFatJets_jerDown]
   Float_t         selectedFatJets_jerDown_nCHadrons[4];   //[nselectedFatJets_jerDown]
   Int_t           nunselectedFatJets_jerDown;
   Float_t         unselectedFatJets_jerDown_pt[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_eta[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_phi[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_mass[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_genJetAK8Idx[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_deepTag_TvsQCD[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_deepTag_WvsQCD[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_particleNet_TvsQCD[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_particleNet_WvsQCD[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_particleNet_QCD[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_particleNet_mass[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_btagDeepB[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_tau2[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_tau3[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_tau1[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_msoftdrop[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_area[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_hadronFlavour[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_nBHadrons[3];   //[nunselectedFatJets_jerDown]
   Float_t         unselectedFatJets_jerDown_nCHadrons[3];   //[nunselectedFatJets_jerDown]
   Int_t           nselectedHOTVRJets_jerDown;
   Float_t         selectedHOTVRJets_jerDown_pt[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_eta[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_phi[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_mass[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_btagDeepB[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_tau2[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_tau3[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_tau1[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_area[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_btagDeepFlavB[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_nConstituents[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_subJetIdx1[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_subJetIdx2[3];   //[nselectedHOTVRJets_jerDown]
   Float_t         selectedHOTVRJets_jerDown_subJetIdx3[3];   //[nselectedHOTVRJets_jerDown]
   Int_t           nunselectedHOTVRJets_jerDown;
   Float_t         unselectedHOTVRJets_jerDown_pt[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_eta[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_phi[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_mass[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_btagDeepB[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_tau2[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_tau3[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_tau1[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_area[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_btagDeepFlavB[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_nConstituents[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_subJetIdx1[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_subJetIdx2[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         unselectedHOTVRJets_jerDown_subJetIdx3[4];   //[nunselectedHOTVRJets_jerDown]
   Float_t         MET_jerDown_pt;
   Float_t         MET_jerDown_phi;
   Int_t           nselectedBJets_jerDown_tight;
   Float_t         selectedBJets_jerDown_tight_pt[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_eta[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_phi[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_mass[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_area[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_hadronFlavour[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_partonFlavour[4];   //[nselectedBJets_jerDown_tight]
   Float_t         selectedBJets_jerDown_tight_genJetIdx[4];   //[nselectedBJets_jerDown_tight]
   Int_t           nselectedBJets_jerDown_medium;
   Float_t         selectedBJets_jerDown_medium_pt[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_eta[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_phi[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_mass[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_area[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_hadronFlavour[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_partonFlavour[5];   //[nselectedBJets_jerDown_medium]
   Float_t         selectedBJets_jerDown_medium_genJetIdx[5];   //[nselectedBJets_jerDown_medium]
   Int_t           nselectedBJets_jerDown_loose;
   Float_t         selectedBJets_jerDown_loose_pt[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_eta[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_phi[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_mass[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_area[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_hadronFlavour[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_partonFlavour[6];   //[nselectedBJets_jerDown_loose]
   Float_t         selectedBJets_jerDown_loose_genJetIdx[6];   //[nselectedBJets_jerDown_loose]
   Int_t           nselectedJets_jesTotalUp;
   Float_t         selectedJets_jesTotalUp_pt[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_eta[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_phi[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_mass[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_btagDeepFlavB[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_area[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_hadronFlavour[11];   //[nselectedJets_jesTotalUp]
   Float_t         selectedJets_jesTotalUp_partonFlavour[11];   //[nselectedJets_jesTotalUp]
   Int_t           nunselectedJets_jesTotalUp;
   Float_t         unselectedJets_jesTotalUp_pt[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_eta[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_phi[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_mass[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_btagDeepFlavB[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_area[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_hadronFlavour[21];   //[nunselectedJets_jesTotalUp]
   Float_t         unselectedJets_jesTotalUp_partonFlavour[21];   //[nunselectedJets_jesTotalUp]
   Int_t           nselectedFatJets_jesTotalUp;
   Float_t         selectedFatJets_jesTotalUp_pt[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_eta[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_phi[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_mass[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_genJetAK8Idx[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_deepTag_TvsQCD[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_deepTag_WvsQCD[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_particleNet_TvsQCD[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_particleNet_WvsQCD[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_particleNet_QCD[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_particleNet_mass[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_btagDeepB[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_tau2[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_tau3[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_tau1[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_msoftdrop[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_area[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_hadronFlavour[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_nBHadrons[4];   //[nselectedFatJets_jesTotalUp]
   Float_t         selectedFatJets_jesTotalUp_nCHadrons[4];   //[nselectedFatJets_jesTotalUp]
   Int_t           nunselectedFatJets_jesTotalUp;
   Float_t         unselectedFatJets_jesTotalUp_pt[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_eta[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_phi[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_mass[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_genJetAK8Idx[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_deepTag_TvsQCD[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_deepTag_WvsQCD[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_particleNet_TvsQCD[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_particleNet_WvsQCD[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_particleNet_QCD[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_particleNet_mass[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_btagDeepB[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_tau2[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_tau3[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_tau1[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_msoftdrop[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_area[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_hadronFlavour[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_nBHadrons[3];   //[nunselectedFatJets_jesTotalUp]
   Float_t         unselectedFatJets_jesTotalUp_nCHadrons[3];   //[nunselectedFatJets_jesTotalUp]
   Int_t           nselectedHOTVRJets_jesTotalUp;
   Float_t         selectedHOTVRJets_jesTotalUp_pt[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_eta[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_phi[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_mass[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_btagDeepB[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_tau2[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_tau3[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_tau1[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_area[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_btagDeepFlavB[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_nConstituents[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_subJetIdx1[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_subJetIdx2[3];   //[nselectedHOTVRJets_jesTotalUp]
   Float_t         selectedHOTVRJets_jesTotalUp_subJetIdx3[3];   //[nselectedHOTVRJets_jesTotalUp]
   Int_t           nunselectedHOTVRJets_jesTotalUp;
   Float_t         unselectedHOTVRJets_jesTotalUp_pt[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_eta[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_phi[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_mass[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_btagDeepB[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_tau2[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_tau3[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_tau1[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_area[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_btagDeepFlavB[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_nConstituents[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_subJetIdx1[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_subJetIdx2[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         unselectedHOTVRJets_jesTotalUp_subJetIdx3[4];   //[nunselectedHOTVRJets_jesTotalUp]
   Float_t         MET_jesTotalUp_pt;
   Float_t         MET_jesTotalUp_phi;
   Int_t           nselectedBJets_jesTotalUp_tight;
   Float_t         selectedBJets_jesTotalUp_tight_pt[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_eta[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_phi[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_mass[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_area[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_hadronFlavour[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_partonFlavour[4];   //[nselectedBJets_jesTotalUp_tight]
   Float_t         selectedBJets_jesTotalUp_tight_genJetIdx[4];   //[nselectedBJets_jesTotalUp_tight]
   Int_t           nselectedBJets_jesTotalUp_medium;
   Float_t         selectedBJets_jesTotalUp_medium_pt[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_eta[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_phi[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_mass[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_area[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_hadronFlavour[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_partonFlavour[5];   //[nselectedBJets_jesTotalUp_medium]
   Float_t         selectedBJets_jesTotalUp_medium_genJetIdx[5];   //[nselectedBJets_jesTotalUp_medium]
   Int_t           nselectedBJets_jesTotalUp_loose;
   Float_t         selectedBJets_jesTotalUp_loose_pt[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_eta[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_phi[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_mass[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_area[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_hadronFlavour[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_partonFlavour[7];   //[nselectedBJets_jesTotalUp_loose]
   Float_t         selectedBJets_jesTotalUp_loose_genJetIdx[7];   //[nselectedBJets_jesTotalUp_loose]
   Int_t           npreselectedHOTVRJets;
   Float_t         preselectedHOTVRJets_pt[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_eta[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_phi[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_mass[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_btagDeepB[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_tau2[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_tau3[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_tau1[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_area[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_btagDeepFlavB[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_nConstituents[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_subJetIdx1[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_subJetIdx2[3];   //[npreselectedHOTVRJets]
   Float_t         preselectedHOTVRJets_subJetIdx3[3];   //[npreselectedHOTVRJets]
   Int_t           npreunselectedHOTVRJets;
   Float_t         preunselectedHOTVRJets_pt[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_eta[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_phi[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_mass[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_btagDeepB[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_tau2[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_tau3[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_tau1[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_area[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_btagDeepFlavB[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_nConstituents[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_subJetIdx1[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_subJetIdx2[4];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_subJetIdx3[4];   //[npreunselectedHOTVRJets]
   Float_t         btagSFlight_deepJet_M_2017_down;
   Float_t         btagSFbc_deepJet_M_2017_down;
   Float_t         btagSFlight_deepJet_M_2017_up;
   Float_t         btagSFbc_deepJet_M_2017_up;
   Float_t         btagSFlight_deepJet_M_2017;
   Float_t         btagSFbc_deepJet_M_2017;
   Float_t         btagSFlight_deepJet_M_correlated_up;
   Float_t         btagSFbc_deepJet_M_correlated_up;
   Float_t         btagSFlight_deepJet_M_correlated_down;
   Float_t         btagSFbc_deepJet_M_correlated_down;
   Float_t         btagSFlight_deepJet_L_2017_down;
   Float_t         btagSFbc_deepJet_L_2017_down;
   Float_t         btagSFlight_deepJet_L_2017_up;
   Float_t         btagSFbc_deepJet_L_2017_up;
   Float_t         btagSFlight_deepJet_L_2017;
   Float_t         btagSFbc_deepJet_L_2017;
   Float_t         btagSFlight_deepJet_L_correlated_up;
   Float_t         btagSFbc_deepJet_L_correlated_up;
   Float_t         btagSFlight_deepJet_L_correlated_down;
   Float_t         btagSFbc_deepJet_L_correlated_down;
   Float_t         btagSFlight_deepJet_T_2017_down;
   Float_t         btagSFbc_deepJet_T_2017_down;
   Float_t         btagSFlight_deepJet_T_2017_up;
   Float_t         btagSFbc_deepJet_T_2017_up;
   Float_t         btagSFlight_deepJet_T_2017;
   Float_t         btagSFbc_deepJet_T_2017;
   Float_t         btagSFlight_deepJet_T_correlated_up;
   Float_t         btagSFbc_deepJet_T_correlated_up;
   Float_t         btagSFlight_deepJet_T_correlated_down;
   Float_t         btagSFbc_deepJet_T_correlated_down;
   Float_t         MET_unclEnUp_pt;
   Float_t         MET_unclEnUp_phi;
   Float_t         MET_unclEnDown_pt;
   Float_t         MET_unclEnDown_phi;
   Int_t           ngenTop;
   Int_t           genTop_has_hadronically_decay[2];   //[ngenTop]
   Int_t           genTop_is_inside_ak8[2];   //[ngenTop]
   Int_t           genTop_is_inside_ak8_top_tagged[2];   //[ngenTop]
   Int_t           genTop_inside_nak8[2];   //[ngenTop]
   Float_t         genTop_min_deltaR_ak8[2];   //[ngenTop]
   Int_t           genTop_first_daughter[2];   //[ngenTop]
   Int_t           genTop_second_daughter[2];   //[ngenTop]
   Int_t           genTop_third_daughter[2];   //[ngenTop]
   Int_t           genTop_all_decays_inside_ak8[2];   //[ngenTop]
   Float_t         genTop_max_deltaR_q_ak8[2];   //[ngenTop]
   Float_t         genTop_pt[2];   //[ngenTop]
   Float_t         genTop_eta[2];   //[ngenTop]
   Float_t         genTop_phi[2];   //[ngenTop]
   Float_t         genTop_mass[2];   //[ngenTop]
   Int_t           genTop_daughters_pdgId[2];   //[ngenTop]
   Float_t         Leptonic_W_pt;
   Int_t           eventSelection_ee_cut;
   Float_t         dilepton_invariant_mass_ee;
   Int_t           eventSelection_emu_cut;
   Float_t         dilepton_invariant_mass_emu;
   Int_t           eventSelection_mumu_cut;
   Float_t         dilepton_invariant_mass_mumu;
   Int_t           selectedJets_nominal_is_inside_hotvr[11];   //[nselectedJets_nominal]
   Int_t           selectedJets_nominal_is_inside_ak8[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_min_deltaRVSak8Jet[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_min_deltaRVShotvrJet[11];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_rho_over_pt_closest_hotvr[11];   //[nselectedJets_nominal]
   Int_t           selectedHOTVRJets_nominal_nsubjets[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau3_over_tau2[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_fractional_subjet_pt[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_min_pairwise_subjets_mass[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_effective_radius[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau2_over_tau1[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_genTop_inside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_genTopHadronic_inside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedFatJets_nominal_has_genTop_inside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_genTopHadronic_inside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_other[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_other_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_noTopDaughters_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_not_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_other_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedFatJets_nominal_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_other[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_other_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_noTopDaughters_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_leptonicW_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicW_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_quark_fromW_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_not_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_other_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_noTopDaughters_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Int_t           selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop[4];   //[nselectedFatJets_nominal]
   Float_t         inference_time_scoreBDT;
   Float_t         selectedHOTVRJets_nominal_scoreBDT[3];   //[nselectedHOTVRJets_nominal]
   Float_t         TopPtWeight;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
   TBranch        *b_genweight;   //!
   TBranch        *b_LHE_HT;   //!
   TBranch        *b_nLHEScaleWeight;   //!
   TBranch        *b_LHEScaleWeight;   //!
   TBranch        *b_L1PreFiringWeight_Nom;   //!
   TBranch        *b_L1PreFiringWeight_Up;   //!
   TBranch        *b_L1PreFiringWeight_Dn;   //!
   TBranch        *b_MET_filter;   //!
   TBranch        *b_nMuon;   //!
   TBranch        *b_muon_PFRelIso04;   //!
   TBranch        *b_muon_tightID;   //!
   TBranch        *b_muon_mediumID;   //!
   TBranch        *b_muon_looseID;   //!
   TBranch        *b_ntightRelIso_tightID_Muons;   //!
   TBranch        *b_tightRelIso_tightID_Muons_pt;   //!
   TBranch        *b_tightRelIso_tightID_Muons_eta;   //!
   TBranch        *b_tightRelIso_tightID_Muons_charge;   //!
   TBranch        *b_tightRelIso_tightID_Muons_phi;   //!
   TBranch        *b_tightRelIso_tightID_Muons_mass;   //!
   TBranch        *b_tightRelIso_tightID_Muons_miniPFRelIso_all;   //!
   TBranch        *b_ntightRelIso_mediumID_Muons;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_pt;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_eta;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_charge;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_phi;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_mass;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_miniPFRelIso_all;   //!
   TBranch        *b_ntightRelIso_looseID_Muons;   //!
   TBranch        *b_tightRelIso_looseID_Muons_pt;   //!
   TBranch        *b_tightRelIso_looseID_Muons_eta;   //!
   TBranch        *b_tightRelIso_looseID_Muons_charge;   //!
   TBranch        *b_tightRelIso_looseID_Muons_phi;   //!
   TBranch        *b_tightRelIso_looseID_Muons_mass;   //!
   TBranch        *b_tightRelIso_looseID_Muons_miniPFRelIso_all;   //!
   TBranch        *b_nElectron;   //!
   TBranch        *b_electron_cutBasedID;   //!
   TBranch        *b_electron_MVA_tightID;   //!
   TBranch        *b_electron_MVA_mediumID;   //!
   TBranch        *b_electron_MVA_looseID;   //!
   TBranch        *b_ntight_MVA_Electrons;   //!
   TBranch        *b_tight_MVA_Electrons_pt;   //!
   TBranch        *b_tight_MVA_Electrons_eta;   //!
   TBranch        *b_tight_MVA_Electrons_charge;   //!
   TBranch        *b_tight_MVA_Electrons_phi;   //!
   TBranch        *b_tight_MVA_Electrons_mass;   //!
   TBranch        *b_nmedium_MVA_Electrons;   //!
   TBranch        *b_medium_MVA_Electrons_pt;   //!
   TBranch        *b_medium_MVA_Electrons_eta;   //!
   TBranch        *b_medium_MVA_Electrons_charge;   //!
   TBranch        *b_medium_MVA_Electrons_phi;   //!
   TBranch        *b_medium_MVA_Electrons_mass;   //!
   TBranch        *b_nloose_MVA_Electrons;   //!
   TBranch        *b_loose_MVA_Electrons_pt;   //!
   TBranch        *b_loose_MVA_Electrons_eta;   //!
   TBranch        *b_loose_MVA_Electrons_charge;   //!
   TBranch        *b_loose_MVA_Electrons_phi;   //!
   TBranch        *b_loose_MVA_Electrons_mass;   //!
   TBranch        *b_ntight_cutBased_Electrons;   //!
   TBranch        *b_tight_cutBased_Electrons_pt;   //!
   TBranch        *b_tight_cutBased_Electrons_eta;   //!
   TBranch        *b_tight_cutBased_Electrons_charge;   //!
   TBranch        *b_tight_cutBased_Electrons_phi;   //!
   TBranch        *b_tight_cutBased_Electrons_mass;   //!
   TBranch        *b_nmedium_cutBased_Electrons;   //!
   TBranch        *b_medium_cutBased_Electrons_pt;   //!
   TBranch        *b_medium_cutBased_Electrons_eta;   //!
   TBranch        *b_medium_cutBased_Electrons_charge;   //!
   TBranch        *b_medium_cutBased_Electrons_phi;   //!
   TBranch        *b_medium_cutBased_Electrons_mass;   //!
   TBranch        *b_nloose_cutBased_Electrons;   //!
   TBranch        *b_loose_cutBased_Electrons_pt;   //!
   TBranch        *b_loose_cutBased_Electrons_eta;   //!
   TBranch        *b_loose_cutBased_Electrons_charge;   //!
   TBranch        *b_loose_cutBased_Electrons_phi;   //!
   TBranch        *b_loose_cutBased_Electrons_mass;   //!
   TBranch        *b_tightRelIso_tightID_Muons_weight_id_nominal;   //!
   TBranch        *b_tightRelIso_tightID_Muons_weight_iso_nominal;   //!
   TBranch        *b_tightRelIso_tightID_Muons_weight_id_up;   //!
   TBranch        *b_tightRelIso_tightID_Muons_weight_iso_up;   //!
   TBranch        *b_tightRelIso_tightID_Muons_weight_id_down;   //!
   TBranch        *b_tightRelIso_tightID_Muons_weight_iso_down;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_weight_id_nominal;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_weight_iso_nominal;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_weight_id_up;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_weight_iso_up;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_weight_id_down;   //!
   TBranch        *b_tightRelIso_mediumID_Muons_weight_iso_down;   //!
   TBranch        *b_tightRelIso_looseID_Muons_weight_id_nominal;   //!
   TBranch        *b_tightRelIso_looseID_Muons_weight_iso_nominal;   //!
   TBranch        *b_tightRelIso_looseID_Muons_weight_id_up;   //!
   TBranch        *b_tightRelIso_looseID_Muons_weight_iso_up;   //!
   TBranch        *b_tightRelIso_looseID_Muons_weight_id_down;   //!
   TBranch        *b_tightRelIso_looseID_Muons_weight_iso_down;   //!
   TBranch        *b_tight_MVA_Electrons_weight_id_nominal;   //!
   TBranch        *b_tight_MVA_Electrons_weight_recoPt_nominal;   //!
   TBranch        *b_tight_MVA_Electrons_weight_id_up;   //!
   TBranch        *b_tight_MVA_Electrons_weight_recoPt_up;   //!
   TBranch        *b_tight_MVA_Electrons_weight_id_down;   //!
   TBranch        *b_tight_MVA_Electrons_weight_recoPt_down;   //!
   TBranch        *b_tight_cutBased_Electrons_weight_id_nominal;   //!
   TBranch        *b_tight_cutBased_Electrons_weight_recoPt_nominal;   //!
   TBranch        *b_tight_cutBased_Electrons_weight_id_up;   //!
   TBranch        *b_tight_cutBased_Electrons_weight_recoPt_up;   //!
   TBranch        *b_tight_cutBased_Electrons_weight_id_down;   //!
   TBranch        *b_tight_cutBased_Electrons_weight_recoPt_down;   //!
   TBranch        *b_medium_MVA_Electrons_weight_id_nominal;   //!
   TBranch        *b_medium_MVA_Electrons_weight_recoPt_nominal;   //!
   TBranch        *b_medium_MVA_Electrons_weight_id_up;   //!
   TBranch        *b_medium_MVA_Electrons_weight_recoPt_up;   //!
   TBranch        *b_medium_MVA_Electrons_weight_id_down;   //!
   TBranch        *b_medium_MVA_Electrons_weight_recoPt_down;   //!
   TBranch        *b_medium_cutBased_Electrons_weight_id_nominal;   //!
   TBranch        *b_medium_cutBased_Electrons_weight_recoPt_nominal;   //!
   TBranch        *b_medium_cutBased_Electrons_weight_id_up;   //!
   TBranch        *b_medium_cutBased_Electrons_weight_recoPt_up;   //!
   TBranch        *b_medium_cutBased_Electrons_weight_id_down;   //!
   TBranch        *b_medium_cutBased_Electrons_weight_recoPt_down;   //!
   TBranch        *b_loose_MVA_Electrons_weight_id_nominal;   //!
   TBranch        *b_loose_MVA_Electrons_weight_recoPt_nominal;   //!
   TBranch        *b_loose_MVA_Electrons_weight_id_up;   //!
   TBranch        *b_loose_MVA_Electrons_weight_recoPt_up;   //!
   TBranch        *b_loose_MVA_Electrons_weight_id_down;   //!
   TBranch        *b_loose_MVA_Electrons_weight_recoPt_down;   //!
   TBranch        *b_loose_cutBased_Electrons_weight_id_nominal;   //!
   TBranch        *b_loose_cutBased_Electrons_weight_recoPt_nominal;   //!
   TBranch        *b_loose_cutBased_Electrons_weight_id_up;   //!
   TBranch        *b_loose_cutBased_Electrons_weight_recoPt_up;   //!
   TBranch        *b_loose_cutBased_Electrons_weight_id_down;   //!
   TBranch        *b_loose_cutBased_Electrons_weight_recoPt_down;   //!
   TBranch        *b_SingleMu_Trigger_flag;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_puWeightDown;   //!
   TBranch        *b_MET_energy;   //!
   TBranch        *b_nselectedJets_jesTotalDown;   //!
   TBranch        *b_selectedJets_jesTotalDown_pt;   //!
   TBranch        *b_selectedJets_jesTotalDown_eta;   //!
   TBranch        *b_selectedJets_jesTotalDown_phi;   //!
   TBranch        *b_selectedJets_jesTotalDown_mass;   //!
   TBranch        *b_selectedJets_jesTotalDown_btagDeepFlavB;   //!
   TBranch        *b_selectedJets_jesTotalDown_area;   //!
   TBranch        *b_selectedJets_jesTotalDown_hadronFlavour;   //!
   TBranch        *b_selectedJets_jesTotalDown_partonFlavour;   //!
   TBranch        *b_nunselectedJets_jesTotalDown;   //!
   TBranch        *b_unselectedJets_jesTotalDown_pt;   //!
   TBranch        *b_unselectedJets_jesTotalDown_eta;   //!
   TBranch        *b_unselectedJets_jesTotalDown_phi;   //!
   TBranch        *b_unselectedJets_jesTotalDown_mass;   //!
   TBranch        *b_unselectedJets_jesTotalDown_btagDeepFlavB;   //!
   TBranch        *b_unselectedJets_jesTotalDown_area;   //!
   TBranch        *b_unselectedJets_jesTotalDown_hadronFlavour;   //!
   TBranch        *b_unselectedJets_jesTotalDown_partonFlavour;   //!
   TBranch        *b_nselectedFatJets_jesTotalDown;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_pt;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_eta;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_phi;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_mass;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_genJetAK8Idx;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_deepTag_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_deepTag_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_particleNet_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_particleNet_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_particleNet_QCD;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_particleNet_mass;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_btagDeepB;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_tau2;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_tau3;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_tau1;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_msoftdrop;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_area;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_hadronFlavour;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_nBHadrons;   //!
   TBranch        *b_selectedFatJets_jesTotalDown_nCHadrons;   //!
   TBranch        *b_nunselectedFatJets_jesTotalDown;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_pt;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_eta;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_phi;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_mass;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_genJetAK8Idx;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_deepTag_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_deepTag_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_particleNet_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_particleNet_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_particleNet_QCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_particleNet_mass;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_btagDeepB;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_tau2;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_tau3;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_tau1;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_msoftdrop;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_area;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_hadronFlavour;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_nBHadrons;   //!
   TBranch        *b_unselectedFatJets_jesTotalDown_nCHadrons;   //!
   TBranch        *b_nselectedHOTVRJets_jesTotalDown;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_pt;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_eta;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_phi;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_mass;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_btagDeepB;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_tau2;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_tau3;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_tau1;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_area;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_btagDeepFlavB;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_nConstituents;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_subJetIdx1;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_subJetIdx2;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalDown_subJetIdx3;   //!
   TBranch        *b_nunselectedHOTVRJets_jesTotalDown;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_pt;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_eta;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_phi;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_mass;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_btagDeepB;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_tau2;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_tau3;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_tau1;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_area;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_btagDeepFlavB;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_nConstituents;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_subJetIdx1;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_subJetIdx2;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalDown_subJetIdx3;   //!
   TBranch        *b_MET_jesTotalDown_pt;   //!
   TBranch        *b_MET_jesTotalDown_phi;   //!
   TBranch        *b_nselectedBJets_jesTotalDown_tight;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_pt;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_eta;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_phi;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_mass;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_area;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_partonFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalDown_tight_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jesTotalDown_medium;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_pt;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_eta;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_phi;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_mass;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_area;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_partonFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalDown_medium_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jesTotalDown_loose;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_pt;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_eta;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_phi;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_mass;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_area;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_partonFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalDown_loose_genJetIdx;   //!
   TBranch        *b_nselectedJets_jerUp;   //!
   TBranch        *b_selectedJets_jerUp_pt;   //!
   TBranch        *b_selectedJets_jerUp_eta;   //!
   TBranch        *b_selectedJets_jerUp_phi;   //!
   TBranch        *b_selectedJets_jerUp_mass;   //!
   TBranch        *b_selectedJets_jerUp_btagDeepFlavB;   //!
   TBranch        *b_selectedJets_jerUp_area;   //!
   TBranch        *b_selectedJets_jerUp_hadronFlavour;   //!
   TBranch        *b_selectedJets_jerUp_partonFlavour;   //!
   TBranch        *b_nunselectedJets_jerUp;   //!
   TBranch        *b_unselectedJets_jerUp_pt;   //!
   TBranch        *b_unselectedJets_jerUp_eta;   //!
   TBranch        *b_unselectedJets_jerUp_phi;   //!
   TBranch        *b_unselectedJets_jerUp_mass;   //!
   TBranch        *b_unselectedJets_jerUp_btagDeepFlavB;   //!
   TBranch        *b_unselectedJets_jerUp_area;   //!
   TBranch        *b_unselectedJets_jerUp_hadronFlavour;   //!
   TBranch        *b_unselectedJets_jerUp_partonFlavour;   //!
   TBranch        *b_nselectedFatJets_jerUp;   //!
   TBranch        *b_selectedFatJets_jerUp_pt;   //!
   TBranch        *b_selectedFatJets_jerUp_eta;   //!
   TBranch        *b_selectedFatJets_jerUp_phi;   //!
   TBranch        *b_selectedFatJets_jerUp_mass;   //!
   TBranch        *b_selectedFatJets_jerUp_genJetAK8Idx;   //!
   TBranch        *b_selectedFatJets_jerUp_deepTag_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jerUp_deepTag_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jerUp_particleNet_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jerUp_particleNet_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jerUp_particleNet_QCD;   //!
   TBranch        *b_selectedFatJets_jerUp_particleNet_mass;   //!
   TBranch        *b_selectedFatJets_jerUp_btagDeepB;   //!
   TBranch        *b_selectedFatJets_jerUp_tau2;   //!
   TBranch        *b_selectedFatJets_jerUp_tau3;   //!
   TBranch        *b_selectedFatJets_jerUp_tau1;   //!
   TBranch        *b_selectedFatJets_jerUp_msoftdrop;   //!
   TBranch        *b_selectedFatJets_jerUp_area;   //!
   TBranch        *b_selectedFatJets_jerUp_hadronFlavour;   //!
   TBranch        *b_selectedFatJets_jerUp_nBHadrons;   //!
   TBranch        *b_selectedFatJets_jerUp_nCHadrons;   //!
   TBranch        *b_nunselectedFatJets_jerUp;   //!
   TBranch        *b_unselectedFatJets_jerUp_pt;   //!
   TBranch        *b_unselectedFatJets_jerUp_eta;   //!
   TBranch        *b_unselectedFatJets_jerUp_phi;   //!
   TBranch        *b_unselectedFatJets_jerUp_mass;   //!
   TBranch        *b_unselectedFatJets_jerUp_genJetAK8Idx;   //!
   TBranch        *b_unselectedFatJets_jerUp_deepTag_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerUp_deepTag_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerUp_particleNet_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerUp_particleNet_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerUp_particleNet_QCD;   //!
   TBranch        *b_unselectedFatJets_jerUp_particleNet_mass;   //!
   TBranch        *b_unselectedFatJets_jerUp_btagDeepB;   //!
   TBranch        *b_unselectedFatJets_jerUp_tau2;   //!
   TBranch        *b_unselectedFatJets_jerUp_tau3;   //!
   TBranch        *b_unselectedFatJets_jerUp_tau1;   //!
   TBranch        *b_unselectedFatJets_jerUp_msoftdrop;   //!
   TBranch        *b_unselectedFatJets_jerUp_area;   //!
   TBranch        *b_unselectedFatJets_jerUp_hadronFlavour;   //!
   TBranch        *b_unselectedFatJets_jerUp_nBHadrons;   //!
   TBranch        *b_unselectedFatJets_jerUp_nCHadrons;   //!
   TBranch        *b_nselectedHOTVRJets_jerUp;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_pt;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_eta;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_phi;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_mass;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_btagDeepB;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_tau2;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_tau3;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_tau1;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_area;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_btagDeepFlavB;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_nConstituents;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_subJetIdx1;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_subJetIdx2;   //!
   TBranch        *b_selectedHOTVRJets_jerUp_subJetIdx3;   //!
   TBranch        *b_nunselectedHOTVRJets_jerUp;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_pt;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_eta;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_phi;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_mass;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_btagDeepB;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_tau2;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_tau3;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_tau1;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_area;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_btagDeepFlavB;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_nConstituents;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_subJetIdx1;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_subJetIdx2;   //!
   TBranch        *b_unselectedHOTVRJets_jerUp_subJetIdx3;   //!
   TBranch        *b_MET_jerUp_pt;   //!
   TBranch        *b_MET_jerUp_phi;   //!
   TBranch        *b_nselectedBJets_jerUp_tight;   //!
   TBranch        *b_selectedBJets_jerUp_tight_pt;   //!
   TBranch        *b_selectedBJets_jerUp_tight_eta;   //!
   TBranch        *b_selectedBJets_jerUp_tight_phi;   //!
   TBranch        *b_selectedBJets_jerUp_tight_mass;   //!
   TBranch        *b_selectedBJets_jerUp_tight_area;   //!
   TBranch        *b_selectedBJets_jerUp_tight_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jerUp_tight_partonFlavour;   //!
   TBranch        *b_selectedBJets_jerUp_tight_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jerUp_medium;   //!
   TBranch        *b_selectedBJets_jerUp_medium_pt;   //!
   TBranch        *b_selectedBJets_jerUp_medium_eta;   //!
   TBranch        *b_selectedBJets_jerUp_medium_phi;   //!
   TBranch        *b_selectedBJets_jerUp_medium_mass;   //!
   TBranch        *b_selectedBJets_jerUp_medium_area;   //!
   TBranch        *b_selectedBJets_jerUp_medium_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jerUp_medium_partonFlavour;   //!
   TBranch        *b_selectedBJets_jerUp_medium_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jerUp_loose;   //!
   TBranch        *b_selectedBJets_jerUp_loose_pt;   //!
   TBranch        *b_selectedBJets_jerUp_loose_eta;   //!
   TBranch        *b_selectedBJets_jerUp_loose_phi;   //!
   TBranch        *b_selectedBJets_jerUp_loose_mass;   //!
   TBranch        *b_selectedBJets_jerUp_loose_area;   //!
   TBranch        *b_selectedBJets_jerUp_loose_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jerUp_loose_partonFlavour;   //!
   TBranch        *b_selectedBJets_jerUp_loose_genJetIdx;   //!
   TBranch        *b_nselectedJets_nominal;   //!
   TBranch        *b_selectedJets_nominal_pt;   //!
   TBranch        *b_selectedJets_nominal_eta;   //!
   TBranch        *b_selectedJets_nominal_phi;   //!
   TBranch        *b_selectedJets_nominal_mass;   //!
   TBranch        *b_selectedJets_nominal_btagDeepFlavB;   //!
   TBranch        *b_selectedJets_nominal_area;   //!
   TBranch        *b_selectedJets_nominal_hadronFlavour;   //!
   TBranch        *b_selectedJets_nominal_partonFlavour;   //!
   TBranch        *b_nunselectedJets_nominal;   //!
   TBranch        *b_unselectedJets_nominal_pt;   //!
   TBranch        *b_unselectedJets_nominal_eta;   //!
   TBranch        *b_unselectedJets_nominal_phi;   //!
   TBranch        *b_unselectedJets_nominal_mass;   //!
   TBranch        *b_unselectedJets_nominal_btagDeepFlavB;   //!
   TBranch        *b_unselectedJets_nominal_area;   //!
   TBranch        *b_unselectedJets_nominal_hadronFlavour;   //!
   TBranch        *b_unselectedJets_nominal_partonFlavour;   //!
   TBranch        *b_nselectedFatJets_nominal;   //!
   TBranch        *b_selectedFatJets_nominal_pt;   //!
   TBranch        *b_selectedFatJets_nominal_eta;   //!
   TBranch        *b_selectedFatJets_nominal_phi;   //!
   TBranch        *b_selectedFatJets_nominal_mass;   //!
   TBranch        *b_selectedFatJets_nominal_genJetAK8Idx;   //!
   TBranch        *b_selectedFatJets_nominal_deepTag_TvsQCD;   //!
   TBranch        *b_selectedFatJets_nominal_deepTag_WvsQCD;   //!
   TBranch        *b_selectedFatJets_nominal_particleNet_TvsQCD;   //!
   TBranch        *b_selectedFatJets_nominal_particleNet_WvsQCD;   //!
   TBranch        *b_selectedFatJets_nominal_particleNet_QCD;   //!
   TBranch        *b_selectedFatJets_nominal_particleNet_mass;   //!
   TBranch        *b_selectedFatJets_nominal_btagDeepB;   //!
   TBranch        *b_selectedFatJets_nominal_tau2;   //!
   TBranch        *b_selectedFatJets_nominal_tau3;   //!
   TBranch        *b_selectedFatJets_nominal_tau1;   //!
   TBranch        *b_selectedFatJets_nominal_msoftdrop;   //!
   TBranch        *b_selectedFatJets_nominal_area;   //!
   TBranch        *b_selectedFatJets_nominal_hadronFlavour;   //!
   TBranch        *b_selectedFatJets_nominal_nBHadrons;   //!
   TBranch        *b_selectedFatJets_nominal_nCHadrons;   //!
   TBranch        *b_nunselectedFatJets_nominal;   //!
   TBranch        *b_unselectedFatJets_nominal_pt;   //!
   TBranch        *b_unselectedFatJets_nominal_eta;   //!
   TBranch        *b_unselectedFatJets_nominal_phi;   //!
   TBranch        *b_unselectedFatJets_nominal_mass;   //!
   TBranch        *b_unselectedFatJets_nominal_genJetAK8Idx;   //!
   TBranch        *b_unselectedFatJets_nominal_deepTag_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_nominal_deepTag_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_nominal_particleNet_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_nominal_particleNet_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_nominal_particleNet_QCD;   //!
   TBranch        *b_unselectedFatJets_nominal_particleNet_mass;   //!
   TBranch        *b_unselectedFatJets_nominal_btagDeepB;   //!
   TBranch        *b_unselectedFatJets_nominal_tau2;   //!
   TBranch        *b_unselectedFatJets_nominal_tau3;   //!
   TBranch        *b_unselectedFatJets_nominal_tau1;   //!
   TBranch        *b_unselectedFatJets_nominal_msoftdrop;   //!
   TBranch        *b_unselectedFatJets_nominal_area;   //!
   TBranch        *b_unselectedFatJets_nominal_hadronFlavour;   //!
   TBranch        *b_unselectedFatJets_nominal_nBHadrons;   //!
   TBranch        *b_unselectedFatJets_nominal_nCHadrons;   //!
   TBranch        *b_nselectedHOTVRJets_nominal;   //!
   TBranch        *b_selectedHOTVRJets_nominal_pt;   //!
   TBranch        *b_selectedHOTVRJets_nominal_eta;   //!
   TBranch        *b_selectedHOTVRJets_nominal_phi;   //!
   TBranch        *b_selectedHOTVRJets_nominal_mass;   //!
   TBranch        *b_selectedHOTVRJets_nominal_btagDeepB;   //!
   TBranch        *b_selectedHOTVRJets_nominal_tau2;   //!
   TBranch        *b_selectedHOTVRJets_nominal_tau3;   //!
   TBranch        *b_selectedHOTVRJets_nominal_tau1;   //!
   TBranch        *b_selectedHOTVRJets_nominal_area;   //!
   TBranch        *b_selectedHOTVRJets_nominal_btagDeepFlavB;   //!
   TBranch        *b_selectedHOTVRJets_nominal_nConstituents;   //!
   TBranch        *b_selectedHOTVRJets_nominal_subJetIdx1;   //!
   TBranch        *b_selectedHOTVRJets_nominal_subJetIdx2;   //!
   TBranch        *b_selectedHOTVRJets_nominal_subJetIdx3;   //!
   TBranch        *b_nunselectedHOTVRJets_nominal;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_pt;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_eta;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_phi;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_mass;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_btagDeepB;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_tau2;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_tau3;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_tau1;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_area;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_btagDeepFlavB;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_nConstituents;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_subJetIdx1;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_subJetIdx2;   //!
   TBranch        *b_unselectedHOTVRJets_nominal_subJetIdx3;   //!
   TBranch        *b_MET_nominal_pt;   //!
   TBranch        *b_MET_nominal_phi;   //!
   TBranch        *b_nselectedHOTVRSubJets_nominal;   //!
   TBranch        *b_selectedHOTVRSubJets_nominal_pt;   //!
   TBranch        *b_selectedHOTVRSubJets_nominal_eta;   //!
   TBranch        *b_selectedHOTVRSubJets_nominal_phi;   //!
   TBranch        *b_selectedHOTVRSubJets_nominal_mass;   //!
   TBranch        *b_selectedHOTVRSubJets_nominal_index;   //!
   TBranch        *b_selectedHOTVRSubJets_nominal_area;   //!
   TBranch        *b_nunselectedHOTVRSubJets_nominal;   //!
   TBranch        *b_unselectedHOTVRSubJets_nominal_pt;   //!
   TBranch        *b_unselectedHOTVRSubJets_nominal_eta;   //!
   TBranch        *b_unselectedHOTVRSubJets_nominal_phi;   //!
   TBranch        *b_unselectedHOTVRSubJets_nominal_mass;   //!
   TBranch        *b_unselectedHOTVRSubJets_nominal_index;   //!
   TBranch        *b_unselectedHOTVRSubJets_nominal_area;   //!
   TBranch        *b_nselectedBJets_nominal_tight;   //!
   TBranch        *b_selectedBJets_nominal_tight_pt;   //!
   TBranch        *b_selectedBJets_nominal_tight_eta;   //!
   TBranch        *b_selectedBJets_nominal_tight_phi;   //!
   TBranch        *b_selectedBJets_nominal_tight_mass;   //!
   TBranch        *b_selectedBJets_nominal_tight_area;   //!
   TBranch        *b_selectedBJets_nominal_tight_hadronFlavour;   //!
   TBranch        *b_selectedBJets_nominal_tight_partonFlavour;   //!
   TBranch        *b_selectedBJets_nominal_tight_genJetIdx;   //!
   TBranch        *b_nselectedBJets_nominal_medium;   //!
   TBranch        *b_selectedBJets_nominal_medium_pt;   //!
   TBranch        *b_selectedBJets_nominal_medium_eta;   //!
   TBranch        *b_selectedBJets_nominal_medium_phi;   //!
   TBranch        *b_selectedBJets_nominal_medium_mass;   //!
   TBranch        *b_selectedBJets_nominal_medium_area;   //!
   TBranch        *b_selectedBJets_nominal_medium_hadronFlavour;   //!
   TBranch        *b_selectedBJets_nominal_medium_partonFlavour;   //!
   TBranch        *b_selectedBJets_nominal_medium_genJetIdx;   //!
   TBranch        *b_nselectedBJets_nominal_loose;   //!
   TBranch        *b_selectedBJets_nominal_loose_pt;   //!
   TBranch        *b_selectedBJets_nominal_loose_eta;   //!
   TBranch        *b_selectedBJets_nominal_loose_phi;   //!
   TBranch        *b_selectedBJets_nominal_loose_mass;   //!
   TBranch        *b_selectedBJets_nominal_loose_area;   //!
   TBranch        *b_selectedBJets_nominal_loose_hadronFlavour;   //!
   TBranch        *b_selectedBJets_nominal_loose_partonFlavour;   //!
   TBranch        *b_selectedBJets_nominal_loose_genJetIdx;   //!
   TBranch        *b_nselectedJets_jerDown;   //!
   TBranch        *b_selectedJets_jerDown_pt;   //!
   TBranch        *b_selectedJets_jerDown_eta;   //!
   TBranch        *b_selectedJets_jerDown_phi;   //!
   TBranch        *b_selectedJets_jerDown_mass;   //!
   TBranch        *b_selectedJets_jerDown_btagDeepFlavB;   //!
   TBranch        *b_selectedJets_jerDown_area;   //!
   TBranch        *b_selectedJets_jerDown_hadronFlavour;   //!
   TBranch        *b_selectedJets_jerDown_partonFlavour;   //!
   TBranch        *b_nunselectedJets_jerDown;   //!
   TBranch        *b_unselectedJets_jerDown_pt;   //!
   TBranch        *b_unselectedJets_jerDown_eta;   //!
   TBranch        *b_unselectedJets_jerDown_phi;   //!
   TBranch        *b_unselectedJets_jerDown_mass;   //!
   TBranch        *b_unselectedJets_jerDown_btagDeepFlavB;   //!
   TBranch        *b_unselectedJets_jerDown_area;   //!
   TBranch        *b_unselectedJets_jerDown_hadronFlavour;   //!
   TBranch        *b_unselectedJets_jerDown_partonFlavour;   //!
   TBranch        *b_nselectedFatJets_jerDown;   //!
   TBranch        *b_selectedFatJets_jerDown_pt;   //!
   TBranch        *b_selectedFatJets_jerDown_eta;   //!
   TBranch        *b_selectedFatJets_jerDown_phi;   //!
   TBranch        *b_selectedFatJets_jerDown_mass;   //!
   TBranch        *b_selectedFatJets_jerDown_genJetAK8Idx;   //!
   TBranch        *b_selectedFatJets_jerDown_deepTag_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jerDown_deepTag_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jerDown_particleNet_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jerDown_particleNet_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jerDown_particleNet_QCD;   //!
   TBranch        *b_selectedFatJets_jerDown_particleNet_mass;   //!
   TBranch        *b_selectedFatJets_jerDown_btagDeepB;   //!
   TBranch        *b_selectedFatJets_jerDown_tau2;   //!
   TBranch        *b_selectedFatJets_jerDown_tau3;   //!
   TBranch        *b_selectedFatJets_jerDown_tau1;   //!
   TBranch        *b_selectedFatJets_jerDown_msoftdrop;   //!
   TBranch        *b_selectedFatJets_jerDown_area;   //!
   TBranch        *b_selectedFatJets_jerDown_hadronFlavour;   //!
   TBranch        *b_selectedFatJets_jerDown_nBHadrons;   //!
   TBranch        *b_selectedFatJets_jerDown_nCHadrons;   //!
   TBranch        *b_nunselectedFatJets_jerDown;   //!
   TBranch        *b_unselectedFatJets_jerDown_pt;   //!
   TBranch        *b_unselectedFatJets_jerDown_eta;   //!
   TBranch        *b_unselectedFatJets_jerDown_phi;   //!
   TBranch        *b_unselectedFatJets_jerDown_mass;   //!
   TBranch        *b_unselectedFatJets_jerDown_genJetAK8Idx;   //!
   TBranch        *b_unselectedFatJets_jerDown_deepTag_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerDown_deepTag_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerDown_particleNet_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerDown_particleNet_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jerDown_particleNet_QCD;   //!
   TBranch        *b_unselectedFatJets_jerDown_particleNet_mass;   //!
   TBranch        *b_unselectedFatJets_jerDown_btagDeepB;   //!
   TBranch        *b_unselectedFatJets_jerDown_tau2;   //!
   TBranch        *b_unselectedFatJets_jerDown_tau3;   //!
   TBranch        *b_unselectedFatJets_jerDown_tau1;   //!
   TBranch        *b_unselectedFatJets_jerDown_msoftdrop;   //!
   TBranch        *b_unselectedFatJets_jerDown_area;   //!
   TBranch        *b_unselectedFatJets_jerDown_hadronFlavour;   //!
   TBranch        *b_unselectedFatJets_jerDown_nBHadrons;   //!
   TBranch        *b_unselectedFatJets_jerDown_nCHadrons;   //!
   TBranch        *b_nselectedHOTVRJets_jerDown;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_pt;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_eta;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_phi;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_mass;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_btagDeepB;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_tau2;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_tau3;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_tau1;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_area;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_btagDeepFlavB;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_nConstituents;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_subJetIdx1;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_subJetIdx2;   //!
   TBranch        *b_selectedHOTVRJets_jerDown_subJetIdx3;   //!
   TBranch        *b_nunselectedHOTVRJets_jerDown;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_pt;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_eta;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_phi;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_mass;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_btagDeepB;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_tau2;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_tau3;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_tau1;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_area;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_btagDeepFlavB;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_nConstituents;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_subJetIdx1;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_subJetIdx2;   //!
   TBranch        *b_unselectedHOTVRJets_jerDown_subJetIdx3;   //!
   TBranch        *b_MET_jerDown_pt;   //!
   TBranch        *b_MET_jerDown_phi;   //!
   TBranch        *b_nselectedBJets_jerDown_tight;   //!
   TBranch        *b_selectedBJets_jerDown_tight_pt;   //!
   TBranch        *b_selectedBJets_jerDown_tight_eta;   //!
   TBranch        *b_selectedBJets_jerDown_tight_phi;   //!
   TBranch        *b_selectedBJets_jerDown_tight_mass;   //!
   TBranch        *b_selectedBJets_jerDown_tight_area;   //!
   TBranch        *b_selectedBJets_jerDown_tight_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jerDown_tight_partonFlavour;   //!
   TBranch        *b_selectedBJets_jerDown_tight_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jerDown_medium;   //!
   TBranch        *b_selectedBJets_jerDown_medium_pt;   //!
   TBranch        *b_selectedBJets_jerDown_medium_eta;   //!
   TBranch        *b_selectedBJets_jerDown_medium_phi;   //!
   TBranch        *b_selectedBJets_jerDown_medium_mass;   //!
   TBranch        *b_selectedBJets_jerDown_medium_area;   //!
   TBranch        *b_selectedBJets_jerDown_medium_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jerDown_medium_partonFlavour;   //!
   TBranch        *b_selectedBJets_jerDown_medium_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jerDown_loose;   //!
   TBranch        *b_selectedBJets_jerDown_loose_pt;   //!
   TBranch        *b_selectedBJets_jerDown_loose_eta;   //!
   TBranch        *b_selectedBJets_jerDown_loose_phi;   //!
   TBranch        *b_selectedBJets_jerDown_loose_mass;   //!
   TBranch        *b_selectedBJets_jerDown_loose_area;   //!
   TBranch        *b_selectedBJets_jerDown_loose_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jerDown_loose_partonFlavour;   //!
   TBranch        *b_selectedBJets_jerDown_loose_genJetIdx;   //!
   TBranch        *b_nselectedJets_jesTotalUp;   //!
   TBranch        *b_selectedJets_jesTotalUp_pt;   //!
   TBranch        *b_selectedJets_jesTotalUp_eta;   //!
   TBranch        *b_selectedJets_jesTotalUp_phi;   //!
   TBranch        *b_selectedJets_jesTotalUp_mass;   //!
   TBranch        *b_selectedJets_jesTotalUp_btagDeepFlavB;   //!
   TBranch        *b_selectedJets_jesTotalUp_area;   //!
   TBranch        *b_selectedJets_jesTotalUp_hadronFlavour;   //!
   TBranch        *b_selectedJets_jesTotalUp_partonFlavour;   //!
   TBranch        *b_nunselectedJets_jesTotalUp;   //!
   TBranch        *b_unselectedJets_jesTotalUp_pt;   //!
   TBranch        *b_unselectedJets_jesTotalUp_eta;   //!
   TBranch        *b_unselectedJets_jesTotalUp_phi;   //!
   TBranch        *b_unselectedJets_jesTotalUp_mass;   //!
   TBranch        *b_unselectedJets_jesTotalUp_btagDeepFlavB;   //!
   TBranch        *b_unselectedJets_jesTotalUp_area;   //!
   TBranch        *b_unselectedJets_jesTotalUp_hadronFlavour;   //!
   TBranch        *b_unselectedJets_jesTotalUp_partonFlavour;   //!
   TBranch        *b_nselectedFatJets_jesTotalUp;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_pt;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_eta;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_phi;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_mass;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_genJetAK8Idx;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_deepTag_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_deepTag_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_particleNet_TvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_particleNet_WvsQCD;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_particleNet_QCD;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_particleNet_mass;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_btagDeepB;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_tau2;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_tau3;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_tau1;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_msoftdrop;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_area;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_hadronFlavour;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_nBHadrons;   //!
   TBranch        *b_selectedFatJets_jesTotalUp_nCHadrons;   //!
   TBranch        *b_nunselectedFatJets_jesTotalUp;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_pt;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_eta;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_phi;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_mass;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_genJetAK8Idx;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_deepTag_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_deepTag_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_particleNet_TvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_particleNet_WvsQCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_particleNet_QCD;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_particleNet_mass;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_btagDeepB;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_tau2;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_tau3;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_tau1;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_msoftdrop;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_area;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_hadronFlavour;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_nBHadrons;   //!
   TBranch        *b_unselectedFatJets_jesTotalUp_nCHadrons;   //!
   TBranch        *b_nselectedHOTVRJets_jesTotalUp;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_pt;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_eta;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_phi;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_mass;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_btagDeepB;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_tau2;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_tau3;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_tau1;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_area;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_btagDeepFlavB;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_nConstituents;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_subJetIdx1;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_subJetIdx2;   //!
   TBranch        *b_selectedHOTVRJets_jesTotalUp_subJetIdx3;   //!
   TBranch        *b_nunselectedHOTVRJets_jesTotalUp;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_pt;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_eta;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_phi;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_mass;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_btagDeepB;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_tau2;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_tau3;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_tau1;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_area;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_btagDeepFlavB;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_nConstituents;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_subJetIdx1;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_subJetIdx2;   //!
   TBranch        *b_unselectedHOTVRJets_jesTotalUp_subJetIdx3;   //!
   TBranch        *b_MET_jesTotalUp_pt;   //!
   TBranch        *b_MET_jesTotalUp_phi;   //!
   TBranch        *b_nselectedBJets_jesTotalUp_tight;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_pt;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_eta;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_phi;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_mass;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_area;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_partonFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalUp_tight_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jesTotalUp_medium;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_pt;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_eta;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_phi;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_mass;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_area;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_partonFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalUp_medium_genJetIdx;   //!
   TBranch        *b_nselectedBJets_jesTotalUp_loose;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_pt;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_eta;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_phi;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_mass;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_area;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_hadronFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_partonFlavour;   //!
   TBranch        *b_selectedBJets_jesTotalUp_loose_genJetIdx;   //!
   TBranch        *b_npreselectedHOTVRJets;   //!
   TBranch        *b_preselectedHOTVRJets_pt;   //!
   TBranch        *b_preselectedHOTVRJets_eta;   //!
   TBranch        *b_preselectedHOTVRJets_phi;   //!
   TBranch        *b_preselectedHOTVRJets_mass;   //!
   TBranch        *b_preselectedHOTVRJets_btagDeepB;   //!
   TBranch        *b_preselectedHOTVRJets_tau2;   //!
   TBranch        *b_preselectedHOTVRJets_tau3;   //!
   TBranch        *b_preselectedHOTVRJets_tau1;   //!
   TBranch        *b_preselectedHOTVRJets_area;   //!
   TBranch        *b_preselectedHOTVRJets_btagDeepFlavB;   //!
   TBranch        *b_preselectedHOTVRJets_nConstituents;   //!
   TBranch        *b_preselectedHOTVRJets_subJetIdx1;   //!
   TBranch        *b_preselectedHOTVRJets_subJetIdx2;   //!
   TBranch        *b_preselectedHOTVRJets_subJetIdx3;   //!
   TBranch        *b_npreunselectedHOTVRJets;   //!
   TBranch        *b_preunselectedHOTVRJets_pt;   //!
   TBranch        *b_preunselectedHOTVRJets_eta;   //!
   TBranch        *b_preunselectedHOTVRJets_phi;   //!
   TBranch        *b_preunselectedHOTVRJets_mass;   //!
   TBranch        *b_preunselectedHOTVRJets_btagDeepB;   //!
   TBranch        *b_preunselectedHOTVRJets_tau2;   //!
   TBranch        *b_preunselectedHOTVRJets_tau3;   //!
   TBranch        *b_preunselectedHOTVRJets_tau1;   //!
   TBranch        *b_preunselectedHOTVRJets_area;   //!
   TBranch        *b_preunselectedHOTVRJets_btagDeepFlavB;   //!
   TBranch        *b_preunselectedHOTVRJets_nConstituents;   //!
   TBranch        *b_preunselectedHOTVRJets_subJetIdx1;   //!
   TBranch        *b_preunselectedHOTVRJets_subJetIdx2;   //!
   TBranch        *b_preunselectedHOTVRJets_subJetIdx3;   //!
   TBranch        *b_btagSFlight_deepJet_M_2017_down;   //!
   TBranch        *b_btagSFbc_deepJet_M_2017_down;   //!
   TBranch        *b_btagSFlight_deepJet_M_2017_up;   //!
   TBranch        *b_btagSFbc_deepJet_M_2017_up;   //!
   TBranch        *b_btagSFlight_deepJet_M_2017;   //!
   TBranch        *b_btagSFbc_deepJet_M_2017;   //!
   TBranch        *b_btagSFlight_deepJet_M_correlated_up;   //!
   TBranch        *b_btagSFbc_deepJet_M_correlated_up;   //!
   TBranch        *b_btagSFlight_deepJet_M_correlated_down;   //!
   TBranch        *b_btagSFbc_deepJet_M_correlated_down;   //!
   TBranch        *b_btagSFlight_deepJet_L_2017_down;   //!
   TBranch        *b_btagSFbc_deepJet_L_2017_down;   //!
   TBranch        *b_btagSFlight_deepJet_L_2017_up;   //!
   TBranch        *b_btagSFbc_deepJet_L_2017_up;   //!
   TBranch        *b_btagSFlight_deepJet_L_2017;   //!
   TBranch        *b_btagSFbc_deepJet_L_2017;   //!
   TBranch        *b_btagSFlight_deepJet_L_correlated_up;   //!
   TBranch        *b_btagSFbc_deepJet_L_correlated_up;   //!
   TBranch        *b_btagSFlight_deepJet_L_correlated_down;   //!
   TBranch        *b_btagSFbc_deepJet_L_correlated_down;   //!
   TBranch        *b_btagSFlight_deepJet_T_2017_down;   //!
   TBranch        *b_btagSFbc_deepJet_T_2017_down;   //!
   TBranch        *b_btagSFlight_deepJet_T_2017_up;   //!
   TBranch        *b_btagSFbc_deepJet_T_2017_up;   //!
   TBranch        *b_btagSFlight_deepJet_T_2017;   //!
   TBranch        *b_btagSFbc_deepJet_T_2017;   //!
   TBranch        *b_btagSFlight_deepJet_T_correlated_up;   //!
   TBranch        *b_btagSFbc_deepJet_T_correlated_up;   //!
   TBranch        *b_btagSFlight_deepJet_T_correlated_down;   //!
   TBranch        *b_btagSFbc_deepJet_T_correlated_down;   //!
   TBranch        *b_MET_unclEnUp_pt;   //!
   TBranch        *b_MET_unclEnUp_phi;   //!
   TBranch        *b_MET_unclEnDown_pt;   //!
   TBranch        *b_MET_unclEnDown_phi;   //!
   TBranch        *b_ngenTop;   //!
   TBranch        *b_genTop_has_hadronically_decay;   //!
   TBranch        *b_genTop_is_inside_ak8;   //!
   TBranch        *b_genTop_is_inside_ak8_top_tagged;   //!
   TBranch        *b_genTop_inside_nak8;   //!
   TBranch        *b_genTop_min_deltaR_ak8;   //!
   TBranch        *b_genTop_first_daughter;   //!
   TBranch        *b_genTop_second_daughter;   //!
   TBranch        *b_genTop_third_daughter;   //!
   TBranch        *b_genTop_all_decays_inside_ak8;   //!
   TBranch        *b_genTop_max_deltaR_q_ak8;   //!
   TBranch        *b_genTop_pt;   //!
   TBranch        *b_genTop_eta;   //!
   TBranch        *b_genTop_phi;   //!
   TBranch        *b_genTop_mass;   //!
   TBranch        *b_genTop_daughters_pdgId;   //!
   TBranch        *b_Leptonic_W_pt;   //!
   TBranch        *b_eventSelection_ee_cut;   //!
   TBranch        *b_dilepton_invariant_mass_ee;   //!
   TBranch        *b_eventSelection_emu_cut;   //!
   TBranch        *b_dilepton_invariant_mass_emu;   //!
   TBranch        *b_eventSelection_mumu_cut;   //!
   TBranch        *b_dilepton_invariant_mass_mumu;   //!
   TBranch        *b_selectedJets_nominal_is_inside_hotvr;   //!
   TBranch        *b_selectedJets_nominal_is_inside_ak8;   //!
   TBranch        *b_selectedJets_nominal_min_deltaRVSak8Jet;   //!
   TBranch        *b_selectedJets_nominal_min_deltaRVShotvrJet;   //!
   TBranch        *b_selectedJets_nominal_rho_over_pt_closest_hotvr;   //!
   TBranch        *b_selectedHOTVRJets_nominal_nsubjets;   //!
   TBranch        *b_selectedHOTVRJets_nominal_tau3_over_tau2;   //!
   TBranch        *b_selectedHOTVRJets_nominal_fractional_subjet_pt;   //!
   TBranch        *b_selectedHOTVRJets_nominal_min_pairwise_subjets_mass;   //!
   TBranch        *b_selectedHOTVRJets_nominal_effective_radius;   //!
   TBranch        *b_selectedHOTVRJets_nominal_tau2_over_tau1;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_genTop_inside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_genTopHadronic_inside;   //!
   TBranch        *b_selectedFatJets_nominal_has_genTop_inside;   //!
   TBranch        *b_selectedFatJets_nominal_has_genTopHadronic_inside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_other;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_other_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_noTopDaughters_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_other_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_other;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_other_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_noTopDaughters_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_leptonicW_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicW_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_quark_fromW_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_other_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_noTopDaughters_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop;   //!
   TBranch        *b_inference_time_scoreBDT;   //!
   TBranch        *b_selectedHOTVRJets_nominal_scoreBDT;   //!
   TBranch        *b_TopPtWeight;   //!

   Friends(TTree *tree=0);
   virtual ~Friends();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Friends_cxx
Friends::Friends(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("test/NANO_NANO_3262_Friend.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("test/NANO_NANO_3262_Friend.root");
      }
      f->GetObject("Friends",tree);

   }
   Init(tree);
}

Friends::~Friends()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Friends::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Friends::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void Friends::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("PV_npvs", &PV_npvs, &b_PV_npvs);
   fChain->SetBranchAddress("PV_npvsGood", &PV_npvsGood, &b_PV_npvsGood);
   fChain->SetBranchAddress("luminosityBlock", &luminosityBlock, &b_luminosityBlock);
   fChain->SetBranchAddress("fixedGridRhoFastjetAll", &fixedGridRhoFastjetAll, &b_fixedGridRhoFastjetAll);
   fChain->SetBranchAddress("genweight", &genweight, &b_genweight);
   fChain->SetBranchAddress("LHE_HT", &LHE_HT, &b_LHE_HT);
   fChain->SetBranchAddress("nLHEScaleWeight", &nLHEScaleWeight, &b_nLHEScaleWeight);
   fChain->SetBranchAddress("LHEScaleWeight", LHEScaleWeight, &b_LHEScaleWeight);
   fChain->SetBranchAddress("L1PreFiringWeight_Nom", &L1PreFiringWeight_Nom, &b_L1PreFiringWeight_Nom);
   fChain->SetBranchAddress("L1PreFiringWeight_Up", &L1PreFiringWeight_Up, &b_L1PreFiringWeight_Up);
   fChain->SetBranchAddress("L1PreFiringWeight_Dn", &L1PreFiringWeight_Dn, &b_L1PreFiringWeight_Dn);
   fChain->SetBranchAddress("MET_filter", &MET_filter, &b_MET_filter);
   fChain->SetBranchAddress("nMuon", &nMuon, &b_nMuon);
   fChain->SetBranchAddress("muon_PFRelIso04", muon_PFRelIso04, &b_muon_PFRelIso04);
   fChain->SetBranchAddress("muon_tightID", muon_tightID, &b_muon_tightID);
   fChain->SetBranchAddress("muon_mediumID", muon_mediumID, &b_muon_mediumID);
   fChain->SetBranchAddress("muon_looseID", muon_looseID, &b_muon_looseID);
   fChain->SetBranchAddress("ntightRelIso_tightID_Muons", &ntightRelIso_tightID_Muons, &b_ntightRelIso_tightID_Muons);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_pt", tightRelIso_tightID_Muons_pt, &b_tightRelIso_tightID_Muons_pt);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_eta", tightRelIso_tightID_Muons_eta, &b_tightRelIso_tightID_Muons_eta);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_charge", tightRelIso_tightID_Muons_charge, &b_tightRelIso_tightID_Muons_charge);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_phi", tightRelIso_tightID_Muons_phi, &b_tightRelIso_tightID_Muons_phi);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_mass", tightRelIso_tightID_Muons_mass, &b_tightRelIso_tightID_Muons_mass);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_miniPFRelIso_all", tightRelIso_tightID_Muons_miniPFRelIso_all, &b_tightRelIso_tightID_Muons_miniPFRelIso_all);
   fChain->SetBranchAddress("ntightRelIso_mediumID_Muons", &ntightRelIso_mediumID_Muons, &b_ntightRelIso_mediumID_Muons);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_pt", tightRelIso_mediumID_Muons_pt, &b_tightRelIso_mediumID_Muons_pt);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_eta", tightRelIso_mediumID_Muons_eta, &b_tightRelIso_mediumID_Muons_eta);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_charge", tightRelIso_mediumID_Muons_charge, &b_tightRelIso_mediumID_Muons_charge);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_phi", tightRelIso_mediumID_Muons_phi, &b_tightRelIso_mediumID_Muons_phi);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_mass", tightRelIso_mediumID_Muons_mass, &b_tightRelIso_mediumID_Muons_mass);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_miniPFRelIso_all", tightRelIso_mediumID_Muons_miniPFRelIso_all, &b_tightRelIso_mediumID_Muons_miniPFRelIso_all);
   fChain->SetBranchAddress("ntightRelIso_looseID_Muons", &ntightRelIso_looseID_Muons, &b_ntightRelIso_looseID_Muons);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_pt", tightRelIso_looseID_Muons_pt, &b_tightRelIso_looseID_Muons_pt);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_eta", tightRelIso_looseID_Muons_eta, &b_tightRelIso_looseID_Muons_eta);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_charge", tightRelIso_looseID_Muons_charge, &b_tightRelIso_looseID_Muons_charge);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_phi", tightRelIso_looseID_Muons_phi, &b_tightRelIso_looseID_Muons_phi);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_mass", tightRelIso_looseID_Muons_mass, &b_tightRelIso_looseID_Muons_mass);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_miniPFRelIso_all", tightRelIso_looseID_Muons_miniPFRelIso_all, &b_tightRelIso_looseID_Muons_miniPFRelIso_all);
   fChain->SetBranchAddress("nElectron", &nElectron, &b_nElectron);
   fChain->SetBranchAddress("electron_cutBasedID", electron_cutBasedID, &b_electron_cutBasedID);
   fChain->SetBranchAddress("electron_MVA_tightID", electron_MVA_tightID, &b_electron_MVA_tightID);
   fChain->SetBranchAddress("electron_MVA_mediumID", electron_MVA_mediumID, &b_electron_MVA_mediumID);
   fChain->SetBranchAddress("electron_MVA_looseID", electron_MVA_looseID, &b_electron_MVA_looseID);
   fChain->SetBranchAddress("ntight_MVA_Electrons", &ntight_MVA_Electrons, &b_ntight_MVA_Electrons);
   fChain->SetBranchAddress("tight_MVA_Electrons_pt", tight_MVA_Electrons_pt, &b_tight_MVA_Electrons_pt);
   fChain->SetBranchAddress("tight_MVA_Electrons_eta", tight_MVA_Electrons_eta, &b_tight_MVA_Electrons_eta);
   fChain->SetBranchAddress("tight_MVA_Electrons_charge", tight_MVA_Electrons_charge, &b_tight_MVA_Electrons_charge);
   fChain->SetBranchAddress("tight_MVA_Electrons_phi", tight_MVA_Electrons_phi, &b_tight_MVA_Electrons_phi);
   fChain->SetBranchAddress("tight_MVA_Electrons_mass", tight_MVA_Electrons_mass, &b_tight_MVA_Electrons_mass);
   fChain->SetBranchAddress("nmedium_MVA_Electrons", &nmedium_MVA_Electrons, &b_nmedium_MVA_Electrons);
   fChain->SetBranchAddress("medium_MVA_Electrons_pt", medium_MVA_Electrons_pt, &b_medium_MVA_Electrons_pt);
   fChain->SetBranchAddress("medium_MVA_Electrons_eta", medium_MVA_Electrons_eta, &b_medium_MVA_Electrons_eta);
   fChain->SetBranchAddress("medium_MVA_Electrons_charge", medium_MVA_Electrons_charge, &b_medium_MVA_Electrons_charge);
   fChain->SetBranchAddress("medium_MVA_Electrons_phi", medium_MVA_Electrons_phi, &b_medium_MVA_Electrons_phi);
   fChain->SetBranchAddress("medium_MVA_Electrons_mass", medium_MVA_Electrons_mass, &b_medium_MVA_Electrons_mass);
   fChain->SetBranchAddress("nloose_MVA_Electrons", &nloose_MVA_Electrons, &b_nloose_MVA_Electrons);
   fChain->SetBranchAddress("loose_MVA_Electrons_pt", loose_MVA_Electrons_pt, &b_loose_MVA_Electrons_pt);
   fChain->SetBranchAddress("loose_MVA_Electrons_eta", loose_MVA_Electrons_eta, &b_loose_MVA_Electrons_eta);
   fChain->SetBranchAddress("loose_MVA_Electrons_charge", loose_MVA_Electrons_charge, &b_loose_MVA_Electrons_charge);
   fChain->SetBranchAddress("loose_MVA_Electrons_phi", loose_MVA_Electrons_phi, &b_loose_MVA_Electrons_phi);
   fChain->SetBranchAddress("loose_MVA_Electrons_mass", loose_MVA_Electrons_mass, &b_loose_MVA_Electrons_mass);
   fChain->SetBranchAddress("ntight_cutBased_Electrons", &ntight_cutBased_Electrons, &b_ntight_cutBased_Electrons);
   fChain->SetBranchAddress("tight_cutBased_Electrons_pt", tight_cutBased_Electrons_pt, &b_tight_cutBased_Electrons_pt);
   fChain->SetBranchAddress("tight_cutBased_Electrons_eta", tight_cutBased_Electrons_eta, &b_tight_cutBased_Electrons_eta);
   fChain->SetBranchAddress("tight_cutBased_Electrons_charge", tight_cutBased_Electrons_charge, &b_tight_cutBased_Electrons_charge);
   fChain->SetBranchAddress("tight_cutBased_Electrons_phi", tight_cutBased_Electrons_phi, &b_tight_cutBased_Electrons_phi);
   fChain->SetBranchAddress("tight_cutBased_Electrons_mass", tight_cutBased_Electrons_mass, &b_tight_cutBased_Electrons_mass);
   fChain->SetBranchAddress("nmedium_cutBased_Electrons", &nmedium_cutBased_Electrons, &b_nmedium_cutBased_Electrons);
   fChain->SetBranchAddress("medium_cutBased_Electrons_pt", medium_cutBased_Electrons_pt, &b_medium_cutBased_Electrons_pt);
   fChain->SetBranchAddress("medium_cutBased_Electrons_eta", medium_cutBased_Electrons_eta, &b_medium_cutBased_Electrons_eta);
   fChain->SetBranchAddress("medium_cutBased_Electrons_charge", medium_cutBased_Electrons_charge, &b_medium_cutBased_Electrons_charge);
   fChain->SetBranchAddress("medium_cutBased_Electrons_phi", medium_cutBased_Electrons_phi, &b_medium_cutBased_Electrons_phi);
   fChain->SetBranchAddress("medium_cutBased_Electrons_mass", medium_cutBased_Electrons_mass, &b_medium_cutBased_Electrons_mass);
   fChain->SetBranchAddress("nloose_cutBased_Electrons", &nloose_cutBased_Electrons, &b_nloose_cutBased_Electrons);
   fChain->SetBranchAddress("loose_cutBased_Electrons_pt", loose_cutBased_Electrons_pt, &b_loose_cutBased_Electrons_pt);
   fChain->SetBranchAddress("loose_cutBased_Electrons_eta", loose_cutBased_Electrons_eta, &b_loose_cutBased_Electrons_eta);
   fChain->SetBranchAddress("loose_cutBased_Electrons_charge", loose_cutBased_Electrons_charge, &b_loose_cutBased_Electrons_charge);
   fChain->SetBranchAddress("loose_cutBased_Electrons_phi", loose_cutBased_Electrons_phi, &b_loose_cutBased_Electrons_phi);
   fChain->SetBranchAddress("loose_cutBased_Electrons_mass", loose_cutBased_Electrons_mass, &b_loose_cutBased_Electrons_mass);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_weight_id_nominal", &tightRelIso_tightID_Muons_weight_id_nominal, &b_tightRelIso_tightID_Muons_weight_id_nominal);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_weight_iso_nominal", &tightRelIso_tightID_Muons_weight_iso_nominal, &b_tightRelIso_tightID_Muons_weight_iso_nominal);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_weight_id_up", &tightRelIso_tightID_Muons_weight_id_up, &b_tightRelIso_tightID_Muons_weight_id_up);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_weight_iso_up", &tightRelIso_tightID_Muons_weight_iso_up, &b_tightRelIso_tightID_Muons_weight_iso_up);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_weight_id_down", &tightRelIso_tightID_Muons_weight_id_down, &b_tightRelIso_tightID_Muons_weight_id_down);
   fChain->SetBranchAddress("tightRelIso_tightID_Muons_weight_iso_down", &tightRelIso_tightID_Muons_weight_iso_down, &b_tightRelIso_tightID_Muons_weight_iso_down);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_weight_id_nominal", &tightRelIso_mediumID_Muons_weight_id_nominal, &b_tightRelIso_mediumID_Muons_weight_id_nominal);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_weight_iso_nominal", &tightRelIso_mediumID_Muons_weight_iso_nominal, &b_tightRelIso_mediumID_Muons_weight_iso_nominal);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_weight_id_up", &tightRelIso_mediumID_Muons_weight_id_up, &b_tightRelIso_mediumID_Muons_weight_id_up);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_weight_iso_up", &tightRelIso_mediumID_Muons_weight_iso_up, &b_tightRelIso_mediumID_Muons_weight_iso_up);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_weight_id_down", &tightRelIso_mediumID_Muons_weight_id_down, &b_tightRelIso_mediumID_Muons_weight_id_down);
   fChain->SetBranchAddress("tightRelIso_mediumID_Muons_weight_iso_down", &tightRelIso_mediumID_Muons_weight_iso_down, &b_tightRelIso_mediumID_Muons_weight_iso_down);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_weight_id_nominal", &tightRelIso_looseID_Muons_weight_id_nominal, &b_tightRelIso_looseID_Muons_weight_id_nominal);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_weight_iso_nominal", &tightRelIso_looseID_Muons_weight_iso_nominal, &b_tightRelIso_looseID_Muons_weight_iso_nominal);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_weight_id_up", &tightRelIso_looseID_Muons_weight_id_up, &b_tightRelIso_looseID_Muons_weight_id_up);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_weight_iso_up", &tightRelIso_looseID_Muons_weight_iso_up, &b_tightRelIso_looseID_Muons_weight_iso_up);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_weight_id_down", &tightRelIso_looseID_Muons_weight_id_down, &b_tightRelIso_looseID_Muons_weight_id_down);
   fChain->SetBranchAddress("tightRelIso_looseID_Muons_weight_iso_down", &tightRelIso_looseID_Muons_weight_iso_down, &b_tightRelIso_looseID_Muons_weight_iso_down);
   fChain->SetBranchAddress("tight_MVA_Electrons_weight_id_nominal", &tight_MVA_Electrons_weight_id_nominal, &b_tight_MVA_Electrons_weight_id_nominal);
   fChain->SetBranchAddress("tight_MVA_Electrons_weight_recoPt_nominal", &tight_MVA_Electrons_weight_recoPt_nominal, &b_tight_MVA_Electrons_weight_recoPt_nominal);
   fChain->SetBranchAddress("tight_MVA_Electrons_weight_id_up", &tight_MVA_Electrons_weight_id_up, &b_tight_MVA_Electrons_weight_id_up);
   fChain->SetBranchAddress("tight_MVA_Electrons_weight_recoPt_up", &tight_MVA_Electrons_weight_recoPt_up, &b_tight_MVA_Electrons_weight_recoPt_up);
   fChain->SetBranchAddress("tight_MVA_Electrons_weight_id_down", &tight_MVA_Electrons_weight_id_down, &b_tight_MVA_Electrons_weight_id_down);
   fChain->SetBranchAddress("tight_MVA_Electrons_weight_recoPt_down", &tight_MVA_Electrons_weight_recoPt_down, &b_tight_MVA_Electrons_weight_recoPt_down);
   fChain->SetBranchAddress("tight_cutBased_Electrons_weight_id_nominal", &tight_cutBased_Electrons_weight_id_nominal, &b_tight_cutBased_Electrons_weight_id_nominal);
   fChain->SetBranchAddress("tight_cutBased_Electrons_weight_recoPt_nominal", &tight_cutBased_Electrons_weight_recoPt_nominal, &b_tight_cutBased_Electrons_weight_recoPt_nominal);
   fChain->SetBranchAddress("tight_cutBased_Electrons_weight_id_up", &tight_cutBased_Electrons_weight_id_up, &b_tight_cutBased_Electrons_weight_id_up);
   fChain->SetBranchAddress("tight_cutBased_Electrons_weight_recoPt_up", &tight_cutBased_Electrons_weight_recoPt_up, &b_tight_cutBased_Electrons_weight_recoPt_up);
   fChain->SetBranchAddress("tight_cutBased_Electrons_weight_id_down", &tight_cutBased_Electrons_weight_id_down, &b_tight_cutBased_Electrons_weight_id_down);
   fChain->SetBranchAddress("tight_cutBased_Electrons_weight_recoPt_down", &tight_cutBased_Electrons_weight_recoPt_down, &b_tight_cutBased_Electrons_weight_recoPt_down);
   fChain->SetBranchAddress("medium_MVA_Electrons_weight_id_nominal", &medium_MVA_Electrons_weight_id_nominal, &b_medium_MVA_Electrons_weight_id_nominal);
   fChain->SetBranchAddress("medium_MVA_Electrons_weight_recoPt_nominal", &medium_MVA_Electrons_weight_recoPt_nominal, &b_medium_MVA_Electrons_weight_recoPt_nominal);
   fChain->SetBranchAddress("medium_MVA_Electrons_weight_id_up", &medium_MVA_Electrons_weight_id_up, &b_medium_MVA_Electrons_weight_id_up);
   fChain->SetBranchAddress("medium_MVA_Electrons_weight_recoPt_up", &medium_MVA_Electrons_weight_recoPt_up, &b_medium_MVA_Electrons_weight_recoPt_up);
   fChain->SetBranchAddress("medium_MVA_Electrons_weight_id_down", &medium_MVA_Electrons_weight_id_down, &b_medium_MVA_Electrons_weight_id_down);
   fChain->SetBranchAddress("medium_MVA_Electrons_weight_recoPt_down", &medium_MVA_Electrons_weight_recoPt_down, &b_medium_MVA_Electrons_weight_recoPt_down);
   fChain->SetBranchAddress("medium_cutBased_Electrons_weight_id_nominal", &medium_cutBased_Electrons_weight_id_nominal, &b_medium_cutBased_Electrons_weight_id_nominal);
   fChain->SetBranchAddress("medium_cutBased_Electrons_weight_recoPt_nominal", &medium_cutBased_Electrons_weight_recoPt_nominal, &b_medium_cutBased_Electrons_weight_recoPt_nominal);
   fChain->SetBranchAddress("medium_cutBased_Electrons_weight_id_up", &medium_cutBased_Electrons_weight_id_up, &b_medium_cutBased_Electrons_weight_id_up);
   fChain->SetBranchAddress("medium_cutBased_Electrons_weight_recoPt_up", &medium_cutBased_Electrons_weight_recoPt_up, &b_medium_cutBased_Electrons_weight_recoPt_up);
   fChain->SetBranchAddress("medium_cutBased_Electrons_weight_id_down", &medium_cutBased_Electrons_weight_id_down, &b_medium_cutBased_Electrons_weight_id_down);
   fChain->SetBranchAddress("medium_cutBased_Electrons_weight_recoPt_down", &medium_cutBased_Electrons_weight_recoPt_down, &b_medium_cutBased_Electrons_weight_recoPt_down);
   fChain->SetBranchAddress("loose_MVA_Electrons_weight_id_nominal", &loose_MVA_Electrons_weight_id_nominal, &b_loose_MVA_Electrons_weight_id_nominal);
   fChain->SetBranchAddress("loose_MVA_Electrons_weight_recoPt_nominal", &loose_MVA_Electrons_weight_recoPt_nominal, &b_loose_MVA_Electrons_weight_recoPt_nominal);
   fChain->SetBranchAddress("loose_MVA_Electrons_weight_id_up", &loose_MVA_Electrons_weight_id_up, &b_loose_MVA_Electrons_weight_id_up);
   fChain->SetBranchAddress("loose_MVA_Electrons_weight_recoPt_up", &loose_MVA_Electrons_weight_recoPt_up, &b_loose_MVA_Electrons_weight_recoPt_up);
   fChain->SetBranchAddress("loose_MVA_Electrons_weight_id_down", &loose_MVA_Electrons_weight_id_down, &b_loose_MVA_Electrons_weight_id_down);
   fChain->SetBranchAddress("loose_MVA_Electrons_weight_recoPt_down", &loose_MVA_Electrons_weight_recoPt_down, &b_loose_MVA_Electrons_weight_recoPt_down);
   fChain->SetBranchAddress("loose_cutBased_Electrons_weight_id_nominal", &loose_cutBased_Electrons_weight_id_nominal, &b_loose_cutBased_Electrons_weight_id_nominal);
   fChain->SetBranchAddress("loose_cutBased_Electrons_weight_recoPt_nominal", &loose_cutBased_Electrons_weight_recoPt_nominal, &b_loose_cutBased_Electrons_weight_recoPt_nominal);
   fChain->SetBranchAddress("loose_cutBased_Electrons_weight_id_up", &loose_cutBased_Electrons_weight_id_up, &b_loose_cutBased_Electrons_weight_id_up);
   fChain->SetBranchAddress("loose_cutBased_Electrons_weight_recoPt_up", &loose_cutBased_Electrons_weight_recoPt_up, &b_loose_cutBased_Electrons_weight_recoPt_up);
   fChain->SetBranchAddress("loose_cutBased_Electrons_weight_id_down", &loose_cutBased_Electrons_weight_id_down, &b_loose_cutBased_Electrons_weight_id_down);
   fChain->SetBranchAddress("loose_cutBased_Electrons_weight_recoPt_down", &loose_cutBased_Electrons_weight_recoPt_down, &b_loose_cutBased_Electrons_weight_recoPt_down);
   fChain->SetBranchAddress("SingleMu_Trigger_flag", &SingleMu_Trigger_flag, &b_SingleMu_Trigger_flag);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);
   fChain->SetBranchAddress("puWeightUp", &puWeightUp, &b_puWeightUp);
   fChain->SetBranchAddress("puWeightDown", &puWeightDown, &b_puWeightDown);
   fChain->SetBranchAddress("MET_energy", &MET_energy, &b_MET_energy);
   fChain->SetBranchAddress("nselectedJets_jesTotalDown", &nselectedJets_jesTotalDown, &b_nselectedJets_jesTotalDown);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_pt", selectedJets_jesTotalDown_pt, &b_selectedJets_jesTotalDown_pt);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_eta", selectedJets_jesTotalDown_eta, &b_selectedJets_jesTotalDown_eta);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_phi", selectedJets_jesTotalDown_phi, &b_selectedJets_jesTotalDown_phi);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_mass", selectedJets_jesTotalDown_mass, &b_selectedJets_jesTotalDown_mass);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_btagDeepFlavB", selectedJets_jesTotalDown_btagDeepFlavB, &b_selectedJets_jesTotalDown_btagDeepFlavB);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_area", selectedJets_jesTotalDown_area, &b_selectedJets_jesTotalDown_area);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_hadronFlavour", selectedJets_jesTotalDown_hadronFlavour, &b_selectedJets_jesTotalDown_hadronFlavour);
   fChain->SetBranchAddress("selectedJets_jesTotalDown_partonFlavour", selectedJets_jesTotalDown_partonFlavour, &b_selectedJets_jesTotalDown_partonFlavour);
   fChain->SetBranchAddress("nunselectedJets_jesTotalDown", &nunselectedJets_jesTotalDown, &b_nunselectedJets_jesTotalDown);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_pt", unselectedJets_jesTotalDown_pt, &b_unselectedJets_jesTotalDown_pt);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_eta", unselectedJets_jesTotalDown_eta, &b_unselectedJets_jesTotalDown_eta);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_phi", unselectedJets_jesTotalDown_phi, &b_unselectedJets_jesTotalDown_phi);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_mass", unselectedJets_jesTotalDown_mass, &b_unselectedJets_jesTotalDown_mass);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_btagDeepFlavB", unselectedJets_jesTotalDown_btagDeepFlavB, &b_unselectedJets_jesTotalDown_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_area", unselectedJets_jesTotalDown_area, &b_unselectedJets_jesTotalDown_area);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_hadronFlavour", unselectedJets_jesTotalDown_hadronFlavour, &b_unselectedJets_jesTotalDown_hadronFlavour);
   fChain->SetBranchAddress("unselectedJets_jesTotalDown_partonFlavour", unselectedJets_jesTotalDown_partonFlavour, &b_unselectedJets_jesTotalDown_partonFlavour);
   fChain->SetBranchAddress("nselectedFatJets_jesTotalDown", &nselectedFatJets_jesTotalDown, &b_nselectedFatJets_jesTotalDown);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_pt", selectedFatJets_jesTotalDown_pt, &b_selectedFatJets_jesTotalDown_pt);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_eta", selectedFatJets_jesTotalDown_eta, &b_selectedFatJets_jesTotalDown_eta);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_phi", selectedFatJets_jesTotalDown_phi, &b_selectedFatJets_jesTotalDown_phi);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_mass", selectedFatJets_jesTotalDown_mass, &b_selectedFatJets_jesTotalDown_mass);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_genJetAK8Idx", selectedFatJets_jesTotalDown_genJetAK8Idx, &b_selectedFatJets_jesTotalDown_genJetAK8Idx);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_deepTag_TvsQCD", selectedFatJets_jesTotalDown_deepTag_TvsQCD, &b_selectedFatJets_jesTotalDown_deepTag_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_deepTag_WvsQCD", selectedFatJets_jesTotalDown_deepTag_WvsQCD, &b_selectedFatJets_jesTotalDown_deepTag_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_particleNet_TvsQCD", selectedFatJets_jesTotalDown_particleNet_TvsQCD, &b_selectedFatJets_jesTotalDown_particleNet_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_particleNet_WvsQCD", selectedFatJets_jesTotalDown_particleNet_WvsQCD, &b_selectedFatJets_jesTotalDown_particleNet_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_particleNet_QCD", selectedFatJets_jesTotalDown_particleNet_QCD, &b_selectedFatJets_jesTotalDown_particleNet_QCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_particleNet_mass", selectedFatJets_jesTotalDown_particleNet_mass, &b_selectedFatJets_jesTotalDown_particleNet_mass);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_btagDeepB", selectedFatJets_jesTotalDown_btagDeepB, &b_selectedFatJets_jesTotalDown_btagDeepB);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_tau2", selectedFatJets_jesTotalDown_tau2, &b_selectedFatJets_jesTotalDown_tau2);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_tau3", selectedFatJets_jesTotalDown_tau3, &b_selectedFatJets_jesTotalDown_tau3);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_tau1", selectedFatJets_jesTotalDown_tau1, &b_selectedFatJets_jesTotalDown_tau1);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_msoftdrop", selectedFatJets_jesTotalDown_msoftdrop, &b_selectedFatJets_jesTotalDown_msoftdrop);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_area", selectedFatJets_jesTotalDown_area, &b_selectedFatJets_jesTotalDown_area);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_hadronFlavour", selectedFatJets_jesTotalDown_hadronFlavour, &b_selectedFatJets_jesTotalDown_hadronFlavour);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_nBHadrons", selectedFatJets_jesTotalDown_nBHadrons, &b_selectedFatJets_jesTotalDown_nBHadrons);
   fChain->SetBranchAddress("selectedFatJets_jesTotalDown_nCHadrons", selectedFatJets_jesTotalDown_nCHadrons, &b_selectedFatJets_jesTotalDown_nCHadrons);
   fChain->SetBranchAddress("nunselectedFatJets_jesTotalDown", &nunselectedFatJets_jesTotalDown, &b_nunselectedFatJets_jesTotalDown);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_pt", unselectedFatJets_jesTotalDown_pt, &b_unselectedFatJets_jesTotalDown_pt);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_eta", unselectedFatJets_jesTotalDown_eta, &b_unselectedFatJets_jesTotalDown_eta);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_phi", unselectedFatJets_jesTotalDown_phi, &b_unselectedFatJets_jesTotalDown_phi);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_mass", unselectedFatJets_jesTotalDown_mass, &b_unselectedFatJets_jesTotalDown_mass);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_genJetAK8Idx", unselectedFatJets_jesTotalDown_genJetAK8Idx, &b_unselectedFatJets_jesTotalDown_genJetAK8Idx);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_deepTag_TvsQCD", unselectedFatJets_jesTotalDown_deepTag_TvsQCD, &b_unselectedFatJets_jesTotalDown_deepTag_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_deepTag_WvsQCD", unselectedFatJets_jesTotalDown_deepTag_WvsQCD, &b_unselectedFatJets_jesTotalDown_deepTag_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_particleNet_TvsQCD", unselectedFatJets_jesTotalDown_particleNet_TvsQCD, &b_unselectedFatJets_jesTotalDown_particleNet_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_particleNet_WvsQCD", unselectedFatJets_jesTotalDown_particleNet_WvsQCD, &b_unselectedFatJets_jesTotalDown_particleNet_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_particleNet_QCD", unselectedFatJets_jesTotalDown_particleNet_QCD, &b_unselectedFatJets_jesTotalDown_particleNet_QCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_particleNet_mass", unselectedFatJets_jesTotalDown_particleNet_mass, &b_unselectedFatJets_jesTotalDown_particleNet_mass);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_btagDeepB", unselectedFatJets_jesTotalDown_btagDeepB, &b_unselectedFatJets_jesTotalDown_btagDeepB);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_tau2", unselectedFatJets_jesTotalDown_tau2, &b_unselectedFatJets_jesTotalDown_tau2);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_tau3", unselectedFatJets_jesTotalDown_tau3, &b_unselectedFatJets_jesTotalDown_tau3);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_tau1", unselectedFatJets_jesTotalDown_tau1, &b_unselectedFatJets_jesTotalDown_tau1);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_msoftdrop", unselectedFatJets_jesTotalDown_msoftdrop, &b_unselectedFatJets_jesTotalDown_msoftdrop);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_area", unselectedFatJets_jesTotalDown_area, &b_unselectedFatJets_jesTotalDown_area);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_hadronFlavour", unselectedFatJets_jesTotalDown_hadronFlavour, &b_unselectedFatJets_jesTotalDown_hadronFlavour);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_nBHadrons", unselectedFatJets_jesTotalDown_nBHadrons, &b_unselectedFatJets_jesTotalDown_nBHadrons);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalDown_nCHadrons", unselectedFatJets_jesTotalDown_nCHadrons, &b_unselectedFatJets_jesTotalDown_nCHadrons);
   fChain->SetBranchAddress("nselectedHOTVRJets_jesTotalDown", &nselectedHOTVRJets_jesTotalDown, &b_nselectedHOTVRJets_jesTotalDown);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_pt", selectedHOTVRJets_jesTotalDown_pt, &b_selectedHOTVRJets_jesTotalDown_pt);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_eta", selectedHOTVRJets_jesTotalDown_eta, &b_selectedHOTVRJets_jesTotalDown_eta);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_phi", selectedHOTVRJets_jesTotalDown_phi, &b_selectedHOTVRJets_jesTotalDown_phi);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_mass", selectedHOTVRJets_jesTotalDown_mass, &b_selectedHOTVRJets_jesTotalDown_mass);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_btagDeepB", selectedHOTVRJets_jesTotalDown_btagDeepB, &b_selectedHOTVRJets_jesTotalDown_btagDeepB);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_tau2", selectedHOTVRJets_jesTotalDown_tau2, &b_selectedHOTVRJets_jesTotalDown_tau2);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_tau3", selectedHOTVRJets_jesTotalDown_tau3, &b_selectedHOTVRJets_jesTotalDown_tau3);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_tau1", selectedHOTVRJets_jesTotalDown_tau1, &b_selectedHOTVRJets_jesTotalDown_tau1);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_area", selectedHOTVRJets_jesTotalDown_area, &b_selectedHOTVRJets_jesTotalDown_area);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_btagDeepFlavB", selectedHOTVRJets_jesTotalDown_btagDeepFlavB, &b_selectedHOTVRJets_jesTotalDown_btagDeepFlavB);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_nConstituents", selectedHOTVRJets_jesTotalDown_nConstituents, &b_selectedHOTVRJets_jesTotalDown_nConstituents);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_subJetIdx1", selectedHOTVRJets_jesTotalDown_subJetIdx1, &b_selectedHOTVRJets_jesTotalDown_subJetIdx1);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_subJetIdx2", selectedHOTVRJets_jesTotalDown_subJetIdx2, &b_selectedHOTVRJets_jesTotalDown_subJetIdx2);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalDown_subJetIdx3", selectedHOTVRJets_jesTotalDown_subJetIdx3, &b_selectedHOTVRJets_jesTotalDown_subJetIdx3);
   fChain->SetBranchAddress("nunselectedHOTVRJets_jesTotalDown", &nunselectedHOTVRJets_jesTotalDown, &b_nunselectedHOTVRJets_jesTotalDown);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_pt", unselectedHOTVRJets_jesTotalDown_pt, &b_unselectedHOTVRJets_jesTotalDown_pt);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_eta", unselectedHOTVRJets_jesTotalDown_eta, &b_unselectedHOTVRJets_jesTotalDown_eta);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_phi", unselectedHOTVRJets_jesTotalDown_phi, &b_unselectedHOTVRJets_jesTotalDown_phi);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_mass", unselectedHOTVRJets_jesTotalDown_mass, &b_unselectedHOTVRJets_jesTotalDown_mass);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_btagDeepB", unselectedHOTVRJets_jesTotalDown_btagDeepB, &b_unselectedHOTVRJets_jesTotalDown_btagDeepB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_tau2", unselectedHOTVRJets_jesTotalDown_tau2, &b_unselectedHOTVRJets_jesTotalDown_tau2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_tau3", unselectedHOTVRJets_jesTotalDown_tau3, &b_unselectedHOTVRJets_jesTotalDown_tau3);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_tau1", unselectedHOTVRJets_jesTotalDown_tau1, &b_unselectedHOTVRJets_jesTotalDown_tau1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_area", unselectedHOTVRJets_jesTotalDown_area, &b_unselectedHOTVRJets_jesTotalDown_area);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_btagDeepFlavB", unselectedHOTVRJets_jesTotalDown_btagDeepFlavB, &b_unselectedHOTVRJets_jesTotalDown_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_nConstituents", unselectedHOTVRJets_jesTotalDown_nConstituents, &b_unselectedHOTVRJets_jesTotalDown_nConstituents);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_subJetIdx1", unselectedHOTVRJets_jesTotalDown_subJetIdx1, &b_unselectedHOTVRJets_jesTotalDown_subJetIdx1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_subJetIdx2", unselectedHOTVRJets_jesTotalDown_subJetIdx2, &b_unselectedHOTVRJets_jesTotalDown_subJetIdx2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalDown_subJetIdx3", unselectedHOTVRJets_jesTotalDown_subJetIdx3, &b_unselectedHOTVRJets_jesTotalDown_subJetIdx3);
   fChain->SetBranchAddress("MET_jesTotalDown_pt", &MET_jesTotalDown_pt, &b_MET_jesTotalDown_pt);
   fChain->SetBranchAddress("MET_jesTotalDown_phi", &MET_jesTotalDown_phi, &b_MET_jesTotalDown_phi);
   fChain->SetBranchAddress("nselectedBJets_jesTotalDown_tight", &nselectedBJets_jesTotalDown_tight, &b_nselectedBJets_jesTotalDown_tight);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_pt", selectedBJets_jesTotalDown_tight_pt, &b_selectedBJets_jesTotalDown_tight_pt);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_eta", selectedBJets_jesTotalDown_tight_eta, &b_selectedBJets_jesTotalDown_tight_eta);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_phi", selectedBJets_jesTotalDown_tight_phi, &b_selectedBJets_jesTotalDown_tight_phi);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_mass", selectedBJets_jesTotalDown_tight_mass, &b_selectedBJets_jesTotalDown_tight_mass);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_area", selectedBJets_jesTotalDown_tight_area, &b_selectedBJets_jesTotalDown_tight_area);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_hadronFlavour", selectedBJets_jesTotalDown_tight_hadronFlavour, &b_selectedBJets_jesTotalDown_tight_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_partonFlavour", selectedBJets_jesTotalDown_tight_partonFlavour, &b_selectedBJets_jesTotalDown_tight_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_tight_genJetIdx", selectedBJets_jesTotalDown_tight_genJetIdx, &b_selectedBJets_jesTotalDown_tight_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jesTotalDown_medium", &nselectedBJets_jesTotalDown_medium, &b_nselectedBJets_jesTotalDown_medium);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_pt", selectedBJets_jesTotalDown_medium_pt, &b_selectedBJets_jesTotalDown_medium_pt);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_eta", selectedBJets_jesTotalDown_medium_eta, &b_selectedBJets_jesTotalDown_medium_eta);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_phi", selectedBJets_jesTotalDown_medium_phi, &b_selectedBJets_jesTotalDown_medium_phi);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_mass", selectedBJets_jesTotalDown_medium_mass, &b_selectedBJets_jesTotalDown_medium_mass);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_area", selectedBJets_jesTotalDown_medium_area, &b_selectedBJets_jesTotalDown_medium_area);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_hadronFlavour", selectedBJets_jesTotalDown_medium_hadronFlavour, &b_selectedBJets_jesTotalDown_medium_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_partonFlavour", selectedBJets_jesTotalDown_medium_partonFlavour, &b_selectedBJets_jesTotalDown_medium_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_medium_genJetIdx", selectedBJets_jesTotalDown_medium_genJetIdx, &b_selectedBJets_jesTotalDown_medium_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jesTotalDown_loose", &nselectedBJets_jesTotalDown_loose, &b_nselectedBJets_jesTotalDown_loose);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_pt", selectedBJets_jesTotalDown_loose_pt, &b_selectedBJets_jesTotalDown_loose_pt);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_eta", selectedBJets_jesTotalDown_loose_eta, &b_selectedBJets_jesTotalDown_loose_eta);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_phi", selectedBJets_jesTotalDown_loose_phi, &b_selectedBJets_jesTotalDown_loose_phi);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_mass", selectedBJets_jesTotalDown_loose_mass, &b_selectedBJets_jesTotalDown_loose_mass);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_area", selectedBJets_jesTotalDown_loose_area, &b_selectedBJets_jesTotalDown_loose_area);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_hadronFlavour", selectedBJets_jesTotalDown_loose_hadronFlavour, &b_selectedBJets_jesTotalDown_loose_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_partonFlavour", selectedBJets_jesTotalDown_loose_partonFlavour, &b_selectedBJets_jesTotalDown_loose_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalDown_loose_genJetIdx", selectedBJets_jesTotalDown_loose_genJetIdx, &b_selectedBJets_jesTotalDown_loose_genJetIdx);
   fChain->SetBranchAddress("nselectedJets_jerUp", &nselectedJets_jerUp, &b_nselectedJets_jerUp);
   fChain->SetBranchAddress("selectedJets_jerUp_pt", selectedJets_jerUp_pt, &b_selectedJets_jerUp_pt);
   fChain->SetBranchAddress("selectedJets_jerUp_eta", selectedJets_jerUp_eta, &b_selectedJets_jerUp_eta);
   fChain->SetBranchAddress("selectedJets_jerUp_phi", selectedJets_jerUp_phi, &b_selectedJets_jerUp_phi);
   fChain->SetBranchAddress("selectedJets_jerUp_mass", selectedJets_jerUp_mass, &b_selectedJets_jerUp_mass);
   fChain->SetBranchAddress("selectedJets_jerUp_btagDeepFlavB", selectedJets_jerUp_btagDeepFlavB, &b_selectedJets_jerUp_btagDeepFlavB);
   fChain->SetBranchAddress("selectedJets_jerUp_area", selectedJets_jerUp_area, &b_selectedJets_jerUp_area);
   fChain->SetBranchAddress("selectedJets_jerUp_hadronFlavour", selectedJets_jerUp_hadronFlavour, &b_selectedJets_jerUp_hadronFlavour);
   fChain->SetBranchAddress("selectedJets_jerUp_partonFlavour", selectedJets_jerUp_partonFlavour, &b_selectedJets_jerUp_partonFlavour);
   fChain->SetBranchAddress("nunselectedJets_jerUp", &nunselectedJets_jerUp, &b_nunselectedJets_jerUp);
   fChain->SetBranchAddress("unselectedJets_jerUp_pt", unselectedJets_jerUp_pt, &b_unselectedJets_jerUp_pt);
   fChain->SetBranchAddress("unselectedJets_jerUp_eta", unselectedJets_jerUp_eta, &b_unselectedJets_jerUp_eta);
   fChain->SetBranchAddress("unselectedJets_jerUp_phi", unselectedJets_jerUp_phi, &b_unselectedJets_jerUp_phi);
   fChain->SetBranchAddress("unselectedJets_jerUp_mass", unselectedJets_jerUp_mass, &b_unselectedJets_jerUp_mass);
   fChain->SetBranchAddress("unselectedJets_jerUp_btagDeepFlavB", unselectedJets_jerUp_btagDeepFlavB, &b_unselectedJets_jerUp_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedJets_jerUp_area", unselectedJets_jerUp_area, &b_unselectedJets_jerUp_area);
   fChain->SetBranchAddress("unselectedJets_jerUp_hadronFlavour", unselectedJets_jerUp_hadronFlavour, &b_unselectedJets_jerUp_hadronFlavour);
   fChain->SetBranchAddress("unselectedJets_jerUp_partonFlavour", unselectedJets_jerUp_partonFlavour, &b_unselectedJets_jerUp_partonFlavour);
   fChain->SetBranchAddress("nselectedFatJets_jerUp", &nselectedFatJets_jerUp, &b_nselectedFatJets_jerUp);
   fChain->SetBranchAddress("selectedFatJets_jerUp_pt", selectedFatJets_jerUp_pt, &b_selectedFatJets_jerUp_pt);
   fChain->SetBranchAddress("selectedFatJets_jerUp_eta", selectedFatJets_jerUp_eta, &b_selectedFatJets_jerUp_eta);
   fChain->SetBranchAddress("selectedFatJets_jerUp_phi", selectedFatJets_jerUp_phi, &b_selectedFatJets_jerUp_phi);
   fChain->SetBranchAddress("selectedFatJets_jerUp_mass", selectedFatJets_jerUp_mass, &b_selectedFatJets_jerUp_mass);
   fChain->SetBranchAddress("selectedFatJets_jerUp_genJetAK8Idx", selectedFatJets_jerUp_genJetAK8Idx, &b_selectedFatJets_jerUp_genJetAK8Idx);
   fChain->SetBranchAddress("selectedFatJets_jerUp_deepTag_TvsQCD", selectedFatJets_jerUp_deepTag_TvsQCD, &b_selectedFatJets_jerUp_deepTag_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerUp_deepTag_WvsQCD", selectedFatJets_jerUp_deepTag_WvsQCD, &b_selectedFatJets_jerUp_deepTag_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerUp_particleNet_TvsQCD", selectedFatJets_jerUp_particleNet_TvsQCD, &b_selectedFatJets_jerUp_particleNet_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerUp_particleNet_WvsQCD", selectedFatJets_jerUp_particleNet_WvsQCD, &b_selectedFatJets_jerUp_particleNet_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerUp_particleNet_QCD", selectedFatJets_jerUp_particleNet_QCD, &b_selectedFatJets_jerUp_particleNet_QCD);
   fChain->SetBranchAddress("selectedFatJets_jerUp_particleNet_mass", selectedFatJets_jerUp_particleNet_mass, &b_selectedFatJets_jerUp_particleNet_mass);
   fChain->SetBranchAddress("selectedFatJets_jerUp_btagDeepB", selectedFatJets_jerUp_btagDeepB, &b_selectedFatJets_jerUp_btagDeepB);
   fChain->SetBranchAddress("selectedFatJets_jerUp_tau2", selectedFatJets_jerUp_tau2, &b_selectedFatJets_jerUp_tau2);
   fChain->SetBranchAddress("selectedFatJets_jerUp_tau3", selectedFatJets_jerUp_tau3, &b_selectedFatJets_jerUp_tau3);
   fChain->SetBranchAddress("selectedFatJets_jerUp_tau1", selectedFatJets_jerUp_tau1, &b_selectedFatJets_jerUp_tau1);
   fChain->SetBranchAddress("selectedFatJets_jerUp_msoftdrop", selectedFatJets_jerUp_msoftdrop, &b_selectedFatJets_jerUp_msoftdrop);
   fChain->SetBranchAddress("selectedFatJets_jerUp_area", selectedFatJets_jerUp_area, &b_selectedFatJets_jerUp_area);
   fChain->SetBranchAddress("selectedFatJets_jerUp_hadronFlavour", selectedFatJets_jerUp_hadronFlavour, &b_selectedFatJets_jerUp_hadronFlavour);
   fChain->SetBranchAddress("selectedFatJets_jerUp_nBHadrons", selectedFatJets_jerUp_nBHadrons, &b_selectedFatJets_jerUp_nBHadrons);
   fChain->SetBranchAddress("selectedFatJets_jerUp_nCHadrons", selectedFatJets_jerUp_nCHadrons, &b_selectedFatJets_jerUp_nCHadrons);
   fChain->SetBranchAddress("nunselectedFatJets_jerUp", &nunselectedFatJets_jerUp, &b_nunselectedFatJets_jerUp);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_pt", unselectedFatJets_jerUp_pt, &b_unselectedFatJets_jerUp_pt);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_eta", unselectedFatJets_jerUp_eta, &b_unselectedFatJets_jerUp_eta);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_phi", unselectedFatJets_jerUp_phi, &b_unselectedFatJets_jerUp_phi);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_mass", unselectedFatJets_jerUp_mass, &b_unselectedFatJets_jerUp_mass);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_genJetAK8Idx", unselectedFatJets_jerUp_genJetAK8Idx, &b_unselectedFatJets_jerUp_genJetAK8Idx);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_deepTag_TvsQCD", unselectedFatJets_jerUp_deepTag_TvsQCD, &b_unselectedFatJets_jerUp_deepTag_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_deepTag_WvsQCD", unselectedFatJets_jerUp_deepTag_WvsQCD, &b_unselectedFatJets_jerUp_deepTag_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_particleNet_TvsQCD", unselectedFatJets_jerUp_particleNet_TvsQCD, &b_unselectedFatJets_jerUp_particleNet_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_particleNet_WvsQCD", unselectedFatJets_jerUp_particleNet_WvsQCD, &b_unselectedFatJets_jerUp_particleNet_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_particleNet_QCD", unselectedFatJets_jerUp_particleNet_QCD, &b_unselectedFatJets_jerUp_particleNet_QCD);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_particleNet_mass", unselectedFatJets_jerUp_particleNet_mass, &b_unselectedFatJets_jerUp_particleNet_mass);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_btagDeepB", unselectedFatJets_jerUp_btagDeepB, &b_unselectedFatJets_jerUp_btagDeepB);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_tau2", unselectedFatJets_jerUp_tau2, &b_unselectedFatJets_jerUp_tau2);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_tau3", unselectedFatJets_jerUp_tau3, &b_unselectedFatJets_jerUp_tau3);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_tau1", unselectedFatJets_jerUp_tau1, &b_unselectedFatJets_jerUp_tau1);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_msoftdrop", unselectedFatJets_jerUp_msoftdrop, &b_unselectedFatJets_jerUp_msoftdrop);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_area", unselectedFatJets_jerUp_area, &b_unselectedFatJets_jerUp_area);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_hadronFlavour", unselectedFatJets_jerUp_hadronFlavour, &b_unselectedFatJets_jerUp_hadronFlavour);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_nBHadrons", unselectedFatJets_jerUp_nBHadrons, &b_unselectedFatJets_jerUp_nBHadrons);
   fChain->SetBranchAddress("unselectedFatJets_jerUp_nCHadrons", unselectedFatJets_jerUp_nCHadrons, &b_unselectedFatJets_jerUp_nCHadrons);
   fChain->SetBranchAddress("nselectedHOTVRJets_jerUp", &nselectedHOTVRJets_jerUp, &b_nselectedHOTVRJets_jerUp);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_pt", selectedHOTVRJets_jerUp_pt, &b_selectedHOTVRJets_jerUp_pt);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_eta", selectedHOTVRJets_jerUp_eta, &b_selectedHOTVRJets_jerUp_eta);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_phi", selectedHOTVRJets_jerUp_phi, &b_selectedHOTVRJets_jerUp_phi);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_mass", selectedHOTVRJets_jerUp_mass, &b_selectedHOTVRJets_jerUp_mass);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_btagDeepB", selectedHOTVRJets_jerUp_btagDeepB, &b_selectedHOTVRJets_jerUp_btagDeepB);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_tau2", selectedHOTVRJets_jerUp_tau2, &b_selectedHOTVRJets_jerUp_tau2);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_tau3", selectedHOTVRJets_jerUp_tau3, &b_selectedHOTVRJets_jerUp_tau3);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_tau1", selectedHOTVRJets_jerUp_tau1, &b_selectedHOTVRJets_jerUp_tau1);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_area", selectedHOTVRJets_jerUp_area, &b_selectedHOTVRJets_jerUp_area);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_btagDeepFlavB", selectedHOTVRJets_jerUp_btagDeepFlavB, &b_selectedHOTVRJets_jerUp_btagDeepFlavB);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_nConstituents", selectedHOTVRJets_jerUp_nConstituents, &b_selectedHOTVRJets_jerUp_nConstituents);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_subJetIdx1", selectedHOTVRJets_jerUp_subJetIdx1, &b_selectedHOTVRJets_jerUp_subJetIdx1);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_subJetIdx2", selectedHOTVRJets_jerUp_subJetIdx2, &b_selectedHOTVRJets_jerUp_subJetIdx2);
   fChain->SetBranchAddress("selectedHOTVRJets_jerUp_subJetIdx3", selectedHOTVRJets_jerUp_subJetIdx3, &b_selectedHOTVRJets_jerUp_subJetIdx3);
   fChain->SetBranchAddress("nunselectedHOTVRJets_jerUp", &nunselectedHOTVRJets_jerUp, &b_nunselectedHOTVRJets_jerUp);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_pt", unselectedHOTVRJets_jerUp_pt, &b_unselectedHOTVRJets_jerUp_pt);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_eta", unselectedHOTVRJets_jerUp_eta, &b_unselectedHOTVRJets_jerUp_eta);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_phi", unselectedHOTVRJets_jerUp_phi, &b_unselectedHOTVRJets_jerUp_phi);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_mass", unselectedHOTVRJets_jerUp_mass, &b_unselectedHOTVRJets_jerUp_mass);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_btagDeepB", unselectedHOTVRJets_jerUp_btagDeepB, &b_unselectedHOTVRJets_jerUp_btagDeepB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_tau2", unselectedHOTVRJets_jerUp_tau2, &b_unselectedHOTVRJets_jerUp_tau2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_tau3", unselectedHOTVRJets_jerUp_tau3, &b_unselectedHOTVRJets_jerUp_tau3);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_tau1", unselectedHOTVRJets_jerUp_tau1, &b_unselectedHOTVRJets_jerUp_tau1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_area", unselectedHOTVRJets_jerUp_area, &b_unselectedHOTVRJets_jerUp_area);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_btagDeepFlavB", unselectedHOTVRJets_jerUp_btagDeepFlavB, &b_unselectedHOTVRJets_jerUp_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_nConstituents", unselectedHOTVRJets_jerUp_nConstituents, &b_unselectedHOTVRJets_jerUp_nConstituents);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_subJetIdx1", unselectedHOTVRJets_jerUp_subJetIdx1, &b_unselectedHOTVRJets_jerUp_subJetIdx1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_subJetIdx2", unselectedHOTVRJets_jerUp_subJetIdx2, &b_unselectedHOTVRJets_jerUp_subJetIdx2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerUp_subJetIdx3", unselectedHOTVRJets_jerUp_subJetIdx3, &b_unselectedHOTVRJets_jerUp_subJetIdx3);
   fChain->SetBranchAddress("MET_jerUp_pt", &MET_jerUp_pt, &b_MET_jerUp_pt);
   fChain->SetBranchAddress("MET_jerUp_phi", &MET_jerUp_phi, &b_MET_jerUp_phi);
   fChain->SetBranchAddress("nselectedBJets_jerUp_tight", &nselectedBJets_jerUp_tight, &b_nselectedBJets_jerUp_tight);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_pt", selectedBJets_jerUp_tight_pt, &b_selectedBJets_jerUp_tight_pt);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_eta", selectedBJets_jerUp_tight_eta, &b_selectedBJets_jerUp_tight_eta);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_phi", selectedBJets_jerUp_tight_phi, &b_selectedBJets_jerUp_tight_phi);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_mass", selectedBJets_jerUp_tight_mass, &b_selectedBJets_jerUp_tight_mass);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_area", selectedBJets_jerUp_tight_area, &b_selectedBJets_jerUp_tight_area);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_hadronFlavour", selectedBJets_jerUp_tight_hadronFlavour, &b_selectedBJets_jerUp_tight_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_partonFlavour", selectedBJets_jerUp_tight_partonFlavour, &b_selectedBJets_jerUp_tight_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jerUp_tight_genJetIdx", selectedBJets_jerUp_tight_genJetIdx, &b_selectedBJets_jerUp_tight_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jerUp_medium", &nselectedBJets_jerUp_medium, &b_nselectedBJets_jerUp_medium);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_pt", selectedBJets_jerUp_medium_pt, &b_selectedBJets_jerUp_medium_pt);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_eta", selectedBJets_jerUp_medium_eta, &b_selectedBJets_jerUp_medium_eta);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_phi", selectedBJets_jerUp_medium_phi, &b_selectedBJets_jerUp_medium_phi);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_mass", selectedBJets_jerUp_medium_mass, &b_selectedBJets_jerUp_medium_mass);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_area", selectedBJets_jerUp_medium_area, &b_selectedBJets_jerUp_medium_area);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_hadronFlavour", selectedBJets_jerUp_medium_hadronFlavour, &b_selectedBJets_jerUp_medium_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_partonFlavour", selectedBJets_jerUp_medium_partonFlavour, &b_selectedBJets_jerUp_medium_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jerUp_medium_genJetIdx", selectedBJets_jerUp_medium_genJetIdx, &b_selectedBJets_jerUp_medium_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jerUp_loose", &nselectedBJets_jerUp_loose, &b_nselectedBJets_jerUp_loose);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_pt", selectedBJets_jerUp_loose_pt, &b_selectedBJets_jerUp_loose_pt);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_eta", selectedBJets_jerUp_loose_eta, &b_selectedBJets_jerUp_loose_eta);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_phi", selectedBJets_jerUp_loose_phi, &b_selectedBJets_jerUp_loose_phi);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_mass", selectedBJets_jerUp_loose_mass, &b_selectedBJets_jerUp_loose_mass);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_area", selectedBJets_jerUp_loose_area, &b_selectedBJets_jerUp_loose_area);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_hadronFlavour", selectedBJets_jerUp_loose_hadronFlavour, &b_selectedBJets_jerUp_loose_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_partonFlavour", selectedBJets_jerUp_loose_partonFlavour, &b_selectedBJets_jerUp_loose_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jerUp_loose_genJetIdx", selectedBJets_jerUp_loose_genJetIdx, &b_selectedBJets_jerUp_loose_genJetIdx);
   fChain->SetBranchAddress("nselectedJets_nominal", &nselectedJets_nominal, &b_nselectedJets_nominal);
   fChain->SetBranchAddress("selectedJets_nominal_pt", selectedJets_nominal_pt, &b_selectedJets_nominal_pt);
   fChain->SetBranchAddress("selectedJets_nominal_eta", selectedJets_nominal_eta, &b_selectedJets_nominal_eta);
   fChain->SetBranchAddress("selectedJets_nominal_phi", selectedJets_nominal_phi, &b_selectedJets_nominal_phi);
   fChain->SetBranchAddress("selectedJets_nominal_mass", selectedJets_nominal_mass, &b_selectedJets_nominal_mass);
   fChain->SetBranchAddress("selectedJets_nominal_btagDeepFlavB", selectedJets_nominal_btagDeepFlavB, &b_selectedJets_nominal_btagDeepFlavB);
   fChain->SetBranchAddress("selectedJets_nominal_area", selectedJets_nominal_area, &b_selectedJets_nominal_area);
   fChain->SetBranchAddress("selectedJets_nominal_hadronFlavour", selectedJets_nominal_hadronFlavour, &b_selectedJets_nominal_hadronFlavour);
   fChain->SetBranchAddress("selectedJets_nominal_partonFlavour", selectedJets_nominal_partonFlavour, &b_selectedJets_nominal_partonFlavour);
   fChain->SetBranchAddress("nunselectedJets_nominal", &nunselectedJets_nominal, &b_nunselectedJets_nominal);
   fChain->SetBranchAddress("unselectedJets_nominal_pt", unselectedJets_nominal_pt, &b_unselectedJets_nominal_pt);
   fChain->SetBranchAddress("unselectedJets_nominal_eta", unselectedJets_nominal_eta, &b_unselectedJets_nominal_eta);
   fChain->SetBranchAddress("unselectedJets_nominal_phi", unselectedJets_nominal_phi, &b_unselectedJets_nominal_phi);
   fChain->SetBranchAddress("unselectedJets_nominal_mass", unselectedJets_nominal_mass, &b_unselectedJets_nominal_mass);
   fChain->SetBranchAddress("unselectedJets_nominal_btagDeepFlavB", unselectedJets_nominal_btagDeepFlavB, &b_unselectedJets_nominal_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedJets_nominal_area", unselectedJets_nominal_area, &b_unselectedJets_nominal_area);
   fChain->SetBranchAddress("unselectedJets_nominal_hadronFlavour", unselectedJets_nominal_hadronFlavour, &b_unselectedJets_nominal_hadronFlavour);
   fChain->SetBranchAddress("unselectedJets_nominal_partonFlavour", unselectedJets_nominal_partonFlavour, &b_unselectedJets_nominal_partonFlavour);
   fChain->SetBranchAddress("nselectedFatJets_nominal", &nselectedFatJets_nominal, &b_nselectedFatJets_nominal);
   fChain->SetBranchAddress("selectedFatJets_nominal_pt", selectedFatJets_nominal_pt, &b_selectedFatJets_nominal_pt);
   fChain->SetBranchAddress("selectedFatJets_nominal_eta", selectedFatJets_nominal_eta, &b_selectedFatJets_nominal_eta);
   fChain->SetBranchAddress("selectedFatJets_nominal_phi", selectedFatJets_nominal_phi, &b_selectedFatJets_nominal_phi);
   fChain->SetBranchAddress("selectedFatJets_nominal_mass", selectedFatJets_nominal_mass, &b_selectedFatJets_nominal_mass);
   fChain->SetBranchAddress("selectedFatJets_nominal_genJetAK8Idx", selectedFatJets_nominal_genJetAK8Idx, &b_selectedFatJets_nominal_genJetAK8Idx);
   fChain->SetBranchAddress("selectedFatJets_nominal_deepTag_TvsQCD", selectedFatJets_nominal_deepTag_TvsQCD, &b_selectedFatJets_nominal_deepTag_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_nominal_deepTag_WvsQCD", selectedFatJets_nominal_deepTag_WvsQCD, &b_selectedFatJets_nominal_deepTag_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_nominal_particleNet_TvsQCD", selectedFatJets_nominal_particleNet_TvsQCD, &b_selectedFatJets_nominal_particleNet_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_nominal_particleNet_WvsQCD", selectedFatJets_nominal_particleNet_WvsQCD, &b_selectedFatJets_nominal_particleNet_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_nominal_particleNet_QCD", selectedFatJets_nominal_particleNet_QCD, &b_selectedFatJets_nominal_particleNet_QCD);
   fChain->SetBranchAddress("selectedFatJets_nominal_particleNet_mass", selectedFatJets_nominal_particleNet_mass, &b_selectedFatJets_nominal_particleNet_mass);
   fChain->SetBranchAddress("selectedFatJets_nominal_btagDeepB", selectedFatJets_nominal_btagDeepB, &b_selectedFatJets_nominal_btagDeepB);
   fChain->SetBranchAddress("selectedFatJets_nominal_tau2", selectedFatJets_nominal_tau2, &b_selectedFatJets_nominal_tau2);
   fChain->SetBranchAddress("selectedFatJets_nominal_tau3", selectedFatJets_nominal_tau3, &b_selectedFatJets_nominal_tau3);
   fChain->SetBranchAddress("selectedFatJets_nominal_tau1", selectedFatJets_nominal_tau1, &b_selectedFatJets_nominal_tau1);
   fChain->SetBranchAddress("selectedFatJets_nominal_msoftdrop", selectedFatJets_nominal_msoftdrop, &b_selectedFatJets_nominal_msoftdrop);
   fChain->SetBranchAddress("selectedFatJets_nominal_area", selectedFatJets_nominal_area, &b_selectedFatJets_nominal_area);
   fChain->SetBranchAddress("selectedFatJets_nominal_hadronFlavour", selectedFatJets_nominal_hadronFlavour, &b_selectedFatJets_nominal_hadronFlavour);
   fChain->SetBranchAddress("selectedFatJets_nominal_nBHadrons", selectedFatJets_nominal_nBHadrons, &b_selectedFatJets_nominal_nBHadrons);
   fChain->SetBranchAddress("selectedFatJets_nominal_nCHadrons", selectedFatJets_nominal_nCHadrons, &b_selectedFatJets_nominal_nCHadrons);
   fChain->SetBranchAddress("nunselectedFatJets_nominal", &nunselectedFatJets_nominal, &b_nunselectedFatJets_nominal);
   fChain->SetBranchAddress("unselectedFatJets_nominal_pt", unselectedFatJets_nominal_pt, &b_unselectedFatJets_nominal_pt);
   fChain->SetBranchAddress("unselectedFatJets_nominal_eta", unselectedFatJets_nominal_eta, &b_unselectedFatJets_nominal_eta);
   fChain->SetBranchAddress("unselectedFatJets_nominal_phi", unselectedFatJets_nominal_phi, &b_unselectedFatJets_nominal_phi);
   fChain->SetBranchAddress("unselectedFatJets_nominal_mass", unselectedFatJets_nominal_mass, &b_unselectedFatJets_nominal_mass);
   fChain->SetBranchAddress("unselectedFatJets_nominal_genJetAK8Idx", unselectedFatJets_nominal_genJetAK8Idx, &b_unselectedFatJets_nominal_genJetAK8Idx);
   fChain->SetBranchAddress("unselectedFatJets_nominal_deepTag_TvsQCD", unselectedFatJets_nominal_deepTag_TvsQCD, &b_unselectedFatJets_nominal_deepTag_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_nominal_deepTag_WvsQCD", unselectedFatJets_nominal_deepTag_WvsQCD, &b_unselectedFatJets_nominal_deepTag_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_nominal_particleNet_TvsQCD", unselectedFatJets_nominal_particleNet_TvsQCD, &b_unselectedFatJets_nominal_particleNet_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_nominal_particleNet_WvsQCD", unselectedFatJets_nominal_particleNet_WvsQCD, &b_unselectedFatJets_nominal_particleNet_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_nominal_particleNet_QCD", unselectedFatJets_nominal_particleNet_QCD, &b_unselectedFatJets_nominal_particleNet_QCD);
   fChain->SetBranchAddress("unselectedFatJets_nominal_particleNet_mass", unselectedFatJets_nominal_particleNet_mass, &b_unselectedFatJets_nominal_particleNet_mass);
   fChain->SetBranchAddress("unselectedFatJets_nominal_btagDeepB", unselectedFatJets_nominal_btagDeepB, &b_unselectedFatJets_nominal_btagDeepB);
   fChain->SetBranchAddress("unselectedFatJets_nominal_tau2", unselectedFatJets_nominal_tau2, &b_unselectedFatJets_nominal_tau2);
   fChain->SetBranchAddress("unselectedFatJets_nominal_tau3", unselectedFatJets_nominal_tau3, &b_unselectedFatJets_nominal_tau3);
   fChain->SetBranchAddress("unselectedFatJets_nominal_tau1", unselectedFatJets_nominal_tau1, &b_unselectedFatJets_nominal_tau1);
   fChain->SetBranchAddress("unselectedFatJets_nominal_msoftdrop", unselectedFatJets_nominal_msoftdrop, &b_unselectedFatJets_nominal_msoftdrop);
   fChain->SetBranchAddress("unselectedFatJets_nominal_area", unselectedFatJets_nominal_area, &b_unselectedFatJets_nominal_area);
   fChain->SetBranchAddress("unselectedFatJets_nominal_hadronFlavour", unselectedFatJets_nominal_hadronFlavour, &b_unselectedFatJets_nominal_hadronFlavour);
   fChain->SetBranchAddress("unselectedFatJets_nominal_nBHadrons", unselectedFatJets_nominal_nBHadrons, &b_unselectedFatJets_nominal_nBHadrons);
   fChain->SetBranchAddress("unselectedFatJets_nominal_nCHadrons", unselectedFatJets_nominal_nCHadrons, &b_unselectedFatJets_nominal_nCHadrons);
   fChain->SetBranchAddress("nselectedHOTVRJets_nominal", &nselectedHOTVRJets_nominal, &b_nselectedHOTVRJets_nominal);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_pt", selectedHOTVRJets_nominal_pt, &b_selectedHOTVRJets_nominal_pt);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_eta", selectedHOTVRJets_nominal_eta, &b_selectedHOTVRJets_nominal_eta);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_phi", selectedHOTVRJets_nominal_phi, &b_selectedHOTVRJets_nominal_phi);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_mass", selectedHOTVRJets_nominal_mass, &b_selectedHOTVRJets_nominal_mass);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_btagDeepB", selectedHOTVRJets_nominal_btagDeepB, &b_selectedHOTVRJets_nominal_btagDeepB);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_tau2", selectedHOTVRJets_nominal_tau2, &b_selectedHOTVRJets_nominal_tau2);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_tau3", selectedHOTVRJets_nominal_tau3, &b_selectedHOTVRJets_nominal_tau3);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_tau1", selectedHOTVRJets_nominal_tau1, &b_selectedHOTVRJets_nominal_tau1);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_area", selectedHOTVRJets_nominal_area, &b_selectedHOTVRJets_nominal_area);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_btagDeepFlavB", selectedHOTVRJets_nominal_btagDeepFlavB, &b_selectedHOTVRJets_nominal_btagDeepFlavB);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_nConstituents", selectedHOTVRJets_nominal_nConstituents, &b_selectedHOTVRJets_nominal_nConstituents);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_subJetIdx1", selectedHOTVRJets_nominal_subJetIdx1, &b_selectedHOTVRJets_nominal_subJetIdx1);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_subJetIdx2", selectedHOTVRJets_nominal_subJetIdx2, &b_selectedHOTVRJets_nominal_subJetIdx2);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_subJetIdx3", selectedHOTVRJets_nominal_subJetIdx3, &b_selectedHOTVRJets_nominal_subJetIdx3);
   fChain->SetBranchAddress("nunselectedHOTVRJets_nominal", &nunselectedHOTVRJets_nominal, &b_nunselectedHOTVRJets_nominal);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_pt", unselectedHOTVRJets_nominal_pt, &b_unselectedHOTVRJets_nominal_pt);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_eta", unselectedHOTVRJets_nominal_eta, &b_unselectedHOTVRJets_nominal_eta);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_phi", unselectedHOTVRJets_nominal_phi, &b_unselectedHOTVRJets_nominal_phi);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_mass", unselectedHOTVRJets_nominal_mass, &b_unselectedHOTVRJets_nominal_mass);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_btagDeepB", unselectedHOTVRJets_nominal_btagDeepB, &b_unselectedHOTVRJets_nominal_btagDeepB);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_tau2", unselectedHOTVRJets_nominal_tau2, &b_unselectedHOTVRJets_nominal_tau2);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_tau3", unselectedHOTVRJets_nominal_tau3, &b_unselectedHOTVRJets_nominal_tau3);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_tau1", unselectedHOTVRJets_nominal_tau1, &b_unselectedHOTVRJets_nominal_tau1);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_area", unselectedHOTVRJets_nominal_area, &b_unselectedHOTVRJets_nominal_area);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_btagDeepFlavB", unselectedHOTVRJets_nominal_btagDeepFlavB, &b_unselectedHOTVRJets_nominal_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_nConstituents", unselectedHOTVRJets_nominal_nConstituents, &b_unselectedHOTVRJets_nominal_nConstituents);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_subJetIdx1", unselectedHOTVRJets_nominal_subJetIdx1, &b_unselectedHOTVRJets_nominal_subJetIdx1);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_subJetIdx2", unselectedHOTVRJets_nominal_subJetIdx2, &b_unselectedHOTVRJets_nominal_subJetIdx2);
   fChain->SetBranchAddress("unselectedHOTVRJets_nominal_subJetIdx3", unselectedHOTVRJets_nominal_subJetIdx3, &b_unselectedHOTVRJets_nominal_subJetIdx3);
   fChain->SetBranchAddress("MET_nominal_pt", &MET_nominal_pt, &b_MET_nominal_pt);
   fChain->SetBranchAddress("MET_nominal_phi", &MET_nominal_phi, &b_MET_nominal_phi);
   fChain->SetBranchAddress("nselectedHOTVRSubJets_nominal", &nselectedHOTVRSubJets_nominal, &b_nselectedHOTVRSubJets_nominal);
   fChain->SetBranchAddress("selectedHOTVRSubJets_nominal_pt", selectedHOTVRSubJets_nominal_pt, &b_selectedHOTVRSubJets_nominal_pt);
   fChain->SetBranchAddress("selectedHOTVRSubJets_nominal_eta", selectedHOTVRSubJets_nominal_eta, &b_selectedHOTVRSubJets_nominal_eta);
   fChain->SetBranchAddress("selectedHOTVRSubJets_nominal_phi", selectedHOTVRSubJets_nominal_phi, &b_selectedHOTVRSubJets_nominal_phi);
   fChain->SetBranchAddress("selectedHOTVRSubJets_nominal_mass", selectedHOTVRSubJets_nominal_mass, &b_selectedHOTVRSubJets_nominal_mass);
   fChain->SetBranchAddress("selectedHOTVRSubJets_nominal_index", selectedHOTVRSubJets_nominal_index, &b_selectedHOTVRSubJets_nominal_index);
   fChain->SetBranchAddress("selectedHOTVRSubJets_nominal_area", selectedHOTVRSubJets_nominal_area, &b_selectedHOTVRSubJets_nominal_area);
   fChain->SetBranchAddress("nunselectedHOTVRSubJets_nominal", &nunselectedHOTVRSubJets_nominal, &b_nunselectedHOTVRSubJets_nominal);
   fChain->SetBranchAddress("unselectedHOTVRSubJets_nominal_pt", unselectedHOTVRSubJets_nominal_pt, &b_unselectedHOTVRSubJets_nominal_pt);
   fChain->SetBranchAddress("unselectedHOTVRSubJets_nominal_eta", unselectedHOTVRSubJets_nominal_eta, &b_unselectedHOTVRSubJets_nominal_eta);
   fChain->SetBranchAddress("unselectedHOTVRSubJets_nominal_phi", unselectedHOTVRSubJets_nominal_phi, &b_unselectedHOTVRSubJets_nominal_phi);
   fChain->SetBranchAddress("unselectedHOTVRSubJets_nominal_mass", unselectedHOTVRSubJets_nominal_mass, &b_unselectedHOTVRSubJets_nominal_mass);
   fChain->SetBranchAddress("unselectedHOTVRSubJets_nominal_index", unselectedHOTVRSubJets_nominal_index, &b_unselectedHOTVRSubJets_nominal_index);
   fChain->SetBranchAddress("unselectedHOTVRSubJets_nominal_area", unselectedHOTVRSubJets_nominal_area, &b_unselectedHOTVRSubJets_nominal_area);
   fChain->SetBranchAddress("nselectedBJets_nominal_tight", &nselectedBJets_nominal_tight, &b_nselectedBJets_nominal_tight);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_pt", selectedBJets_nominal_tight_pt, &b_selectedBJets_nominal_tight_pt);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_eta", selectedBJets_nominal_tight_eta, &b_selectedBJets_nominal_tight_eta);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_phi", selectedBJets_nominal_tight_phi, &b_selectedBJets_nominal_tight_phi);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_mass", selectedBJets_nominal_tight_mass, &b_selectedBJets_nominal_tight_mass);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_area", selectedBJets_nominal_tight_area, &b_selectedBJets_nominal_tight_area);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_hadronFlavour", selectedBJets_nominal_tight_hadronFlavour, &b_selectedBJets_nominal_tight_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_partonFlavour", selectedBJets_nominal_tight_partonFlavour, &b_selectedBJets_nominal_tight_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_nominal_tight_genJetIdx", selectedBJets_nominal_tight_genJetIdx, &b_selectedBJets_nominal_tight_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_nominal_medium", &nselectedBJets_nominal_medium, &b_nselectedBJets_nominal_medium);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_pt", selectedBJets_nominal_medium_pt, &b_selectedBJets_nominal_medium_pt);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_eta", selectedBJets_nominal_medium_eta, &b_selectedBJets_nominal_medium_eta);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_phi", selectedBJets_nominal_medium_phi, &b_selectedBJets_nominal_medium_phi);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_mass", selectedBJets_nominal_medium_mass, &b_selectedBJets_nominal_medium_mass);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_area", selectedBJets_nominal_medium_area, &b_selectedBJets_nominal_medium_area);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_hadronFlavour", selectedBJets_nominal_medium_hadronFlavour, &b_selectedBJets_nominal_medium_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_partonFlavour", selectedBJets_nominal_medium_partonFlavour, &b_selectedBJets_nominal_medium_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_genJetIdx", selectedBJets_nominal_medium_genJetIdx, &b_selectedBJets_nominal_medium_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_nominal_loose", &nselectedBJets_nominal_loose, &b_nselectedBJets_nominal_loose);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_pt", selectedBJets_nominal_loose_pt, &b_selectedBJets_nominal_loose_pt);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_eta", selectedBJets_nominal_loose_eta, &b_selectedBJets_nominal_loose_eta);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_phi", selectedBJets_nominal_loose_phi, &b_selectedBJets_nominal_loose_phi);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_mass", selectedBJets_nominal_loose_mass, &b_selectedBJets_nominal_loose_mass);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_area", selectedBJets_nominal_loose_area, &b_selectedBJets_nominal_loose_area);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_hadronFlavour", selectedBJets_nominal_loose_hadronFlavour, &b_selectedBJets_nominal_loose_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_partonFlavour", selectedBJets_nominal_loose_partonFlavour, &b_selectedBJets_nominal_loose_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_genJetIdx", selectedBJets_nominal_loose_genJetIdx, &b_selectedBJets_nominal_loose_genJetIdx);
   fChain->SetBranchAddress("nselectedJets_jerDown", &nselectedJets_jerDown, &b_nselectedJets_jerDown);
   fChain->SetBranchAddress("selectedJets_jerDown_pt", selectedJets_jerDown_pt, &b_selectedJets_jerDown_pt);
   fChain->SetBranchAddress("selectedJets_jerDown_eta", selectedJets_jerDown_eta, &b_selectedJets_jerDown_eta);
   fChain->SetBranchAddress("selectedJets_jerDown_phi", selectedJets_jerDown_phi, &b_selectedJets_jerDown_phi);
   fChain->SetBranchAddress("selectedJets_jerDown_mass", selectedJets_jerDown_mass, &b_selectedJets_jerDown_mass);
   fChain->SetBranchAddress("selectedJets_jerDown_btagDeepFlavB", selectedJets_jerDown_btagDeepFlavB, &b_selectedJets_jerDown_btagDeepFlavB);
   fChain->SetBranchAddress("selectedJets_jerDown_area", selectedJets_jerDown_area, &b_selectedJets_jerDown_area);
   fChain->SetBranchAddress("selectedJets_jerDown_hadronFlavour", selectedJets_jerDown_hadronFlavour, &b_selectedJets_jerDown_hadronFlavour);
   fChain->SetBranchAddress("selectedJets_jerDown_partonFlavour", selectedJets_jerDown_partonFlavour, &b_selectedJets_jerDown_partonFlavour);
   fChain->SetBranchAddress("nunselectedJets_jerDown", &nunselectedJets_jerDown, &b_nunselectedJets_jerDown);
   fChain->SetBranchAddress("unselectedJets_jerDown_pt", unselectedJets_jerDown_pt, &b_unselectedJets_jerDown_pt);
   fChain->SetBranchAddress("unselectedJets_jerDown_eta", unselectedJets_jerDown_eta, &b_unselectedJets_jerDown_eta);
   fChain->SetBranchAddress("unselectedJets_jerDown_phi", unselectedJets_jerDown_phi, &b_unselectedJets_jerDown_phi);
   fChain->SetBranchAddress("unselectedJets_jerDown_mass", unselectedJets_jerDown_mass, &b_unselectedJets_jerDown_mass);
   fChain->SetBranchAddress("unselectedJets_jerDown_btagDeepFlavB", unselectedJets_jerDown_btagDeepFlavB, &b_unselectedJets_jerDown_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedJets_jerDown_area", unselectedJets_jerDown_area, &b_unselectedJets_jerDown_area);
   fChain->SetBranchAddress("unselectedJets_jerDown_hadronFlavour", unselectedJets_jerDown_hadronFlavour, &b_unselectedJets_jerDown_hadronFlavour);
   fChain->SetBranchAddress("unselectedJets_jerDown_partonFlavour", unselectedJets_jerDown_partonFlavour, &b_unselectedJets_jerDown_partonFlavour);
   fChain->SetBranchAddress("nselectedFatJets_jerDown", &nselectedFatJets_jerDown, &b_nselectedFatJets_jerDown);
   fChain->SetBranchAddress("selectedFatJets_jerDown_pt", selectedFatJets_jerDown_pt, &b_selectedFatJets_jerDown_pt);
   fChain->SetBranchAddress("selectedFatJets_jerDown_eta", selectedFatJets_jerDown_eta, &b_selectedFatJets_jerDown_eta);
   fChain->SetBranchAddress("selectedFatJets_jerDown_phi", selectedFatJets_jerDown_phi, &b_selectedFatJets_jerDown_phi);
   fChain->SetBranchAddress("selectedFatJets_jerDown_mass", selectedFatJets_jerDown_mass, &b_selectedFatJets_jerDown_mass);
   fChain->SetBranchAddress("selectedFatJets_jerDown_genJetAK8Idx", selectedFatJets_jerDown_genJetAK8Idx, &b_selectedFatJets_jerDown_genJetAK8Idx);
   fChain->SetBranchAddress("selectedFatJets_jerDown_deepTag_TvsQCD", selectedFatJets_jerDown_deepTag_TvsQCD, &b_selectedFatJets_jerDown_deepTag_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerDown_deepTag_WvsQCD", selectedFatJets_jerDown_deepTag_WvsQCD, &b_selectedFatJets_jerDown_deepTag_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerDown_particleNet_TvsQCD", selectedFatJets_jerDown_particleNet_TvsQCD, &b_selectedFatJets_jerDown_particleNet_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerDown_particleNet_WvsQCD", selectedFatJets_jerDown_particleNet_WvsQCD, &b_selectedFatJets_jerDown_particleNet_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jerDown_particleNet_QCD", selectedFatJets_jerDown_particleNet_QCD, &b_selectedFatJets_jerDown_particleNet_QCD);
   fChain->SetBranchAddress("selectedFatJets_jerDown_particleNet_mass", selectedFatJets_jerDown_particleNet_mass, &b_selectedFatJets_jerDown_particleNet_mass);
   fChain->SetBranchAddress("selectedFatJets_jerDown_btagDeepB", selectedFatJets_jerDown_btagDeepB, &b_selectedFatJets_jerDown_btagDeepB);
   fChain->SetBranchAddress("selectedFatJets_jerDown_tau2", selectedFatJets_jerDown_tau2, &b_selectedFatJets_jerDown_tau2);
   fChain->SetBranchAddress("selectedFatJets_jerDown_tau3", selectedFatJets_jerDown_tau3, &b_selectedFatJets_jerDown_tau3);
   fChain->SetBranchAddress("selectedFatJets_jerDown_tau1", selectedFatJets_jerDown_tau1, &b_selectedFatJets_jerDown_tau1);
   fChain->SetBranchAddress("selectedFatJets_jerDown_msoftdrop", selectedFatJets_jerDown_msoftdrop, &b_selectedFatJets_jerDown_msoftdrop);
   fChain->SetBranchAddress("selectedFatJets_jerDown_area", selectedFatJets_jerDown_area, &b_selectedFatJets_jerDown_area);
   fChain->SetBranchAddress("selectedFatJets_jerDown_hadronFlavour", selectedFatJets_jerDown_hadronFlavour, &b_selectedFatJets_jerDown_hadronFlavour);
   fChain->SetBranchAddress("selectedFatJets_jerDown_nBHadrons", selectedFatJets_jerDown_nBHadrons, &b_selectedFatJets_jerDown_nBHadrons);
   fChain->SetBranchAddress("selectedFatJets_jerDown_nCHadrons", selectedFatJets_jerDown_nCHadrons, &b_selectedFatJets_jerDown_nCHadrons);
   fChain->SetBranchAddress("nunselectedFatJets_jerDown", &nunselectedFatJets_jerDown, &b_nunselectedFatJets_jerDown);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_pt", unselectedFatJets_jerDown_pt, &b_unselectedFatJets_jerDown_pt);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_eta", unselectedFatJets_jerDown_eta, &b_unselectedFatJets_jerDown_eta);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_phi", unselectedFatJets_jerDown_phi, &b_unselectedFatJets_jerDown_phi);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_mass", unselectedFatJets_jerDown_mass, &b_unselectedFatJets_jerDown_mass);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_genJetAK8Idx", unselectedFatJets_jerDown_genJetAK8Idx, &b_unselectedFatJets_jerDown_genJetAK8Idx);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_deepTag_TvsQCD", unselectedFatJets_jerDown_deepTag_TvsQCD, &b_unselectedFatJets_jerDown_deepTag_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_deepTag_WvsQCD", unselectedFatJets_jerDown_deepTag_WvsQCD, &b_unselectedFatJets_jerDown_deepTag_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_particleNet_TvsQCD", unselectedFatJets_jerDown_particleNet_TvsQCD, &b_unselectedFatJets_jerDown_particleNet_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_particleNet_WvsQCD", unselectedFatJets_jerDown_particleNet_WvsQCD, &b_unselectedFatJets_jerDown_particleNet_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_particleNet_QCD", unselectedFatJets_jerDown_particleNet_QCD, &b_unselectedFatJets_jerDown_particleNet_QCD);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_particleNet_mass", unselectedFatJets_jerDown_particleNet_mass, &b_unselectedFatJets_jerDown_particleNet_mass);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_btagDeepB", unselectedFatJets_jerDown_btagDeepB, &b_unselectedFatJets_jerDown_btagDeepB);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_tau2", unselectedFatJets_jerDown_tau2, &b_unselectedFatJets_jerDown_tau2);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_tau3", unselectedFatJets_jerDown_tau3, &b_unselectedFatJets_jerDown_tau3);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_tau1", unselectedFatJets_jerDown_tau1, &b_unselectedFatJets_jerDown_tau1);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_msoftdrop", unselectedFatJets_jerDown_msoftdrop, &b_unselectedFatJets_jerDown_msoftdrop);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_area", unselectedFatJets_jerDown_area, &b_unselectedFatJets_jerDown_area);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_hadronFlavour", unselectedFatJets_jerDown_hadronFlavour, &b_unselectedFatJets_jerDown_hadronFlavour);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_nBHadrons", unselectedFatJets_jerDown_nBHadrons, &b_unselectedFatJets_jerDown_nBHadrons);
   fChain->SetBranchAddress("unselectedFatJets_jerDown_nCHadrons", unselectedFatJets_jerDown_nCHadrons, &b_unselectedFatJets_jerDown_nCHadrons);
   fChain->SetBranchAddress("nselectedHOTVRJets_jerDown", &nselectedHOTVRJets_jerDown, &b_nselectedHOTVRJets_jerDown);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_pt", selectedHOTVRJets_jerDown_pt, &b_selectedHOTVRJets_jerDown_pt);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_eta", selectedHOTVRJets_jerDown_eta, &b_selectedHOTVRJets_jerDown_eta);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_phi", selectedHOTVRJets_jerDown_phi, &b_selectedHOTVRJets_jerDown_phi);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_mass", selectedHOTVRJets_jerDown_mass, &b_selectedHOTVRJets_jerDown_mass);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_btagDeepB", selectedHOTVRJets_jerDown_btagDeepB, &b_selectedHOTVRJets_jerDown_btagDeepB);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_tau2", selectedHOTVRJets_jerDown_tau2, &b_selectedHOTVRJets_jerDown_tau2);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_tau3", selectedHOTVRJets_jerDown_tau3, &b_selectedHOTVRJets_jerDown_tau3);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_tau1", selectedHOTVRJets_jerDown_tau1, &b_selectedHOTVRJets_jerDown_tau1);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_area", selectedHOTVRJets_jerDown_area, &b_selectedHOTVRJets_jerDown_area);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_btagDeepFlavB", selectedHOTVRJets_jerDown_btagDeepFlavB, &b_selectedHOTVRJets_jerDown_btagDeepFlavB);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_nConstituents", selectedHOTVRJets_jerDown_nConstituents, &b_selectedHOTVRJets_jerDown_nConstituents);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_subJetIdx1", selectedHOTVRJets_jerDown_subJetIdx1, &b_selectedHOTVRJets_jerDown_subJetIdx1);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_subJetIdx2", selectedHOTVRJets_jerDown_subJetIdx2, &b_selectedHOTVRJets_jerDown_subJetIdx2);
   fChain->SetBranchAddress("selectedHOTVRJets_jerDown_subJetIdx3", selectedHOTVRJets_jerDown_subJetIdx3, &b_selectedHOTVRJets_jerDown_subJetIdx3);
   fChain->SetBranchAddress("nunselectedHOTVRJets_jerDown", &nunselectedHOTVRJets_jerDown, &b_nunselectedHOTVRJets_jerDown);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_pt", unselectedHOTVRJets_jerDown_pt, &b_unselectedHOTVRJets_jerDown_pt);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_eta", unselectedHOTVRJets_jerDown_eta, &b_unselectedHOTVRJets_jerDown_eta);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_phi", unselectedHOTVRJets_jerDown_phi, &b_unselectedHOTVRJets_jerDown_phi);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_mass", unselectedHOTVRJets_jerDown_mass, &b_unselectedHOTVRJets_jerDown_mass);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_btagDeepB", unselectedHOTVRJets_jerDown_btagDeepB, &b_unselectedHOTVRJets_jerDown_btagDeepB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_tau2", unselectedHOTVRJets_jerDown_tau2, &b_unselectedHOTVRJets_jerDown_tau2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_tau3", unselectedHOTVRJets_jerDown_tau3, &b_unselectedHOTVRJets_jerDown_tau3);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_tau1", unselectedHOTVRJets_jerDown_tau1, &b_unselectedHOTVRJets_jerDown_tau1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_area", unselectedHOTVRJets_jerDown_area, &b_unselectedHOTVRJets_jerDown_area);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_btagDeepFlavB", unselectedHOTVRJets_jerDown_btagDeepFlavB, &b_unselectedHOTVRJets_jerDown_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_nConstituents", unselectedHOTVRJets_jerDown_nConstituents, &b_unselectedHOTVRJets_jerDown_nConstituents);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_subJetIdx1", unselectedHOTVRJets_jerDown_subJetIdx1, &b_unselectedHOTVRJets_jerDown_subJetIdx1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_subJetIdx2", unselectedHOTVRJets_jerDown_subJetIdx2, &b_unselectedHOTVRJets_jerDown_subJetIdx2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jerDown_subJetIdx3", unselectedHOTVRJets_jerDown_subJetIdx3, &b_unselectedHOTVRJets_jerDown_subJetIdx3);
   fChain->SetBranchAddress("MET_jerDown_pt", &MET_jerDown_pt, &b_MET_jerDown_pt);
   fChain->SetBranchAddress("MET_jerDown_phi", &MET_jerDown_phi, &b_MET_jerDown_phi);
   fChain->SetBranchAddress("nselectedBJets_jerDown_tight", &nselectedBJets_jerDown_tight, &b_nselectedBJets_jerDown_tight);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_pt", selectedBJets_jerDown_tight_pt, &b_selectedBJets_jerDown_tight_pt);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_eta", selectedBJets_jerDown_tight_eta, &b_selectedBJets_jerDown_tight_eta);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_phi", selectedBJets_jerDown_tight_phi, &b_selectedBJets_jerDown_tight_phi);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_mass", selectedBJets_jerDown_tight_mass, &b_selectedBJets_jerDown_tight_mass);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_area", selectedBJets_jerDown_tight_area, &b_selectedBJets_jerDown_tight_area);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_hadronFlavour", selectedBJets_jerDown_tight_hadronFlavour, &b_selectedBJets_jerDown_tight_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_partonFlavour", selectedBJets_jerDown_tight_partonFlavour, &b_selectedBJets_jerDown_tight_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jerDown_tight_genJetIdx", selectedBJets_jerDown_tight_genJetIdx, &b_selectedBJets_jerDown_tight_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jerDown_medium", &nselectedBJets_jerDown_medium, &b_nselectedBJets_jerDown_medium);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_pt", selectedBJets_jerDown_medium_pt, &b_selectedBJets_jerDown_medium_pt);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_eta", selectedBJets_jerDown_medium_eta, &b_selectedBJets_jerDown_medium_eta);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_phi", selectedBJets_jerDown_medium_phi, &b_selectedBJets_jerDown_medium_phi);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_mass", selectedBJets_jerDown_medium_mass, &b_selectedBJets_jerDown_medium_mass);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_area", selectedBJets_jerDown_medium_area, &b_selectedBJets_jerDown_medium_area);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_hadronFlavour", selectedBJets_jerDown_medium_hadronFlavour, &b_selectedBJets_jerDown_medium_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_partonFlavour", selectedBJets_jerDown_medium_partonFlavour, &b_selectedBJets_jerDown_medium_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jerDown_medium_genJetIdx", selectedBJets_jerDown_medium_genJetIdx, &b_selectedBJets_jerDown_medium_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jerDown_loose", &nselectedBJets_jerDown_loose, &b_nselectedBJets_jerDown_loose);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_pt", selectedBJets_jerDown_loose_pt, &b_selectedBJets_jerDown_loose_pt);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_eta", selectedBJets_jerDown_loose_eta, &b_selectedBJets_jerDown_loose_eta);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_phi", selectedBJets_jerDown_loose_phi, &b_selectedBJets_jerDown_loose_phi);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_mass", selectedBJets_jerDown_loose_mass, &b_selectedBJets_jerDown_loose_mass);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_area", selectedBJets_jerDown_loose_area, &b_selectedBJets_jerDown_loose_area);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_hadronFlavour", selectedBJets_jerDown_loose_hadronFlavour, &b_selectedBJets_jerDown_loose_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_partonFlavour", selectedBJets_jerDown_loose_partonFlavour, &b_selectedBJets_jerDown_loose_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jerDown_loose_genJetIdx", selectedBJets_jerDown_loose_genJetIdx, &b_selectedBJets_jerDown_loose_genJetIdx);
   fChain->SetBranchAddress("nselectedJets_jesTotalUp", &nselectedJets_jesTotalUp, &b_nselectedJets_jesTotalUp);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_pt", selectedJets_jesTotalUp_pt, &b_selectedJets_jesTotalUp_pt);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_eta", selectedJets_jesTotalUp_eta, &b_selectedJets_jesTotalUp_eta);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_phi", selectedJets_jesTotalUp_phi, &b_selectedJets_jesTotalUp_phi);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_mass", selectedJets_jesTotalUp_mass, &b_selectedJets_jesTotalUp_mass);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_btagDeepFlavB", selectedJets_jesTotalUp_btagDeepFlavB, &b_selectedJets_jesTotalUp_btagDeepFlavB);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_area", selectedJets_jesTotalUp_area, &b_selectedJets_jesTotalUp_area);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_hadronFlavour", selectedJets_jesTotalUp_hadronFlavour, &b_selectedJets_jesTotalUp_hadronFlavour);
   fChain->SetBranchAddress("selectedJets_jesTotalUp_partonFlavour", selectedJets_jesTotalUp_partonFlavour, &b_selectedJets_jesTotalUp_partonFlavour);
   fChain->SetBranchAddress("nunselectedJets_jesTotalUp", &nunselectedJets_jesTotalUp, &b_nunselectedJets_jesTotalUp);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_pt", unselectedJets_jesTotalUp_pt, &b_unselectedJets_jesTotalUp_pt);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_eta", unselectedJets_jesTotalUp_eta, &b_unselectedJets_jesTotalUp_eta);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_phi", unselectedJets_jesTotalUp_phi, &b_unselectedJets_jesTotalUp_phi);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_mass", unselectedJets_jesTotalUp_mass, &b_unselectedJets_jesTotalUp_mass);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_btagDeepFlavB", unselectedJets_jesTotalUp_btagDeepFlavB, &b_unselectedJets_jesTotalUp_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_area", unselectedJets_jesTotalUp_area, &b_unselectedJets_jesTotalUp_area);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_hadronFlavour", unselectedJets_jesTotalUp_hadronFlavour, &b_unselectedJets_jesTotalUp_hadronFlavour);
   fChain->SetBranchAddress("unselectedJets_jesTotalUp_partonFlavour", unselectedJets_jesTotalUp_partonFlavour, &b_unselectedJets_jesTotalUp_partonFlavour);
   fChain->SetBranchAddress("nselectedFatJets_jesTotalUp", &nselectedFatJets_jesTotalUp, &b_nselectedFatJets_jesTotalUp);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_pt", selectedFatJets_jesTotalUp_pt, &b_selectedFatJets_jesTotalUp_pt);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_eta", selectedFatJets_jesTotalUp_eta, &b_selectedFatJets_jesTotalUp_eta);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_phi", selectedFatJets_jesTotalUp_phi, &b_selectedFatJets_jesTotalUp_phi);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_mass", selectedFatJets_jesTotalUp_mass, &b_selectedFatJets_jesTotalUp_mass);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_genJetAK8Idx", selectedFatJets_jesTotalUp_genJetAK8Idx, &b_selectedFatJets_jesTotalUp_genJetAK8Idx);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_deepTag_TvsQCD", selectedFatJets_jesTotalUp_deepTag_TvsQCD, &b_selectedFatJets_jesTotalUp_deepTag_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_deepTag_WvsQCD", selectedFatJets_jesTotalUp_deepTag_WvsQCD, &b_selectedFatJets_jesTotalUp_deepTag_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_particleNet_TvsQCD", selectedFatJets_jesTotalUp_particleNet_TvsQCD, &b_selectedFatJets_jesTotalUp_particleNet_TvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_particleNet_WvsQCD", selectedFatJets_jesTotalUp_particleNet_WvsQCD, &b_selectedFatJets_jesTotalUp_particleNet_WvsQCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_particleNet_QCD", selectedFatJets_jesTotalUp_particleNet_QCD, &b_selectedFatJets_jesTotalUp_particleNet_QCD);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_particleNet_mass", selectedFatJets_jesTotalUp_particleNet_mass, &b_selectedFatJets_jesTotalUp_particleNet_mass);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_btagDeepB", selectedFatJets_jesTotalUp_btagDeepB, &b_selectedFatJets_jesTotalUp_btagDeepB);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_tau2", selectedFatJets_jesTotalUp_tau2, &b_selectedFatJets_jesTotalUp_tau2);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_tau3", selectedFatJets_jesTotalUp_tau3, &b_selectedFatJets_jesTotalUp_tau3);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_tau1", selectedFatJets_jesTotalUp_tau1, &b_selectedFatJets_jesTotalUp_tau1);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_msoftdrop", selectedFatJets_jesTotalUp_msoftdrop, &b_selectedFatJets_jesTotalUp_msoftdrop);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_area", selectedFatJets_jesTotalUp_area, &b_selectedFatJets_jesTotalUp_area);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_hadronFlavour", selectedFatJets_jesTotalUp_hadronFlavour, &b_selectedFatJets_jesTotalUp_hadronFlavour);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_nBHadrons", selectedFatJets_jesTotalUp_nBHadrons, &b_selectedFatJets_jesTotalUp_nBHadrons);
   fChain->SetBranchAddress("selectedFatJets_jesTotalUp_nCHadrons", selectedFatJets_jesTotalUp_nCHadrons, &b_selectedFatJets_jesTotalUp_nCHadrons);
   fChain->SetBranchAddress("nunselectedFatJets_jesTotalUp", &nunselectedFatJets_jesTotalUp, &b_nunselectedFatJets_jesTotalUp);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_pt", unselectedFatJets_jesTotalUp_pt, &b_unselectedFatJets_jesTotalUp_pt);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_eta", unselectedFatJets_jesTotalUp_eta, &b_unselectedFatJets_jesTotalUp_eta);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_phi", unselectedFatJets_jesTotalUp_phi, &b_unselectedFatJets_jesTotalUp_phi);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_mass", unselectedFatJets_jesTotalUp_mass, &b_unselectedFatJets_jesTotalUp_mass);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_genJetAK8Idx", unselectedFatJets_jesTotalUp_genJetAK8Idx, &b_unselectedFatJets_jesTotalUp_genJetAK8Idx);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_deepTag_TvsQCD", unselectedFatJets_jesTotalUp_deepTag_TvsQCD, &b_unselectedFatJets_jesTotalUp_deepTag_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_deepTag_WvsQCD", unselectedFatJets_jesTotalUp_deepTag_WvsQCD, &b_unselectedFatJets_jesTotalUp_deepTag_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_particleNet_TvsQCD", unselectedFatJets_jesTotalUp_particleNet_TvsQCD, &b_unselectedFatJets_jesTotalUp_particleNet_TvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_particleNet_WvsQCD", unselectedFatJets_jesTotalUp_particleNet_WvsQCD, &b_unselectedFatJets_jesTotalUp_particleNet_WvsQCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_particleNet_QCD", unselectedFatJets_jesTotalUp_particleNet_QCD, &b_unselectedFatJets_jesTotalUp_particleNet_QCD);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_particleNet_mass", unselectedFatJets_jesTotalUp_particleNet_mass, &b_unselectedFatJets_jesTotalUp_particleNet_mass);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_btagDeepB", unselectedFatJets_jesTotalUp_btagDeepB, &b_unselectedFatJets_jesTotalUp_btagDeepB);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_tau2", unselectedFatJets_jesTotalUp_tau2, &b_unselectedFatJets_jesTotalUp_tau2);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_tau3", unselectedFatJets_jesTotalUp_tau3, &b_unselectedFatJets_jesTotalUp_tau3);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_tau1", unselectedFatJets_jesTotalUp_tau1, &b_unselectedFatJets_jesTotalUp_tau1);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_msoftdrop", unselectedFatJets_jesTotalUp_msoftdrop, &b_unselectedFatJets_jesTotalUp_msoftdrop);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_area", unselectedFatJets_jesTotalUp_area, &b_unselectedFatJets_jesTotalUp_area);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_hadronFlavour", unselectedFatJets_jesTotalUp_hadronFlavour, &b_unselectedFatJets_jesTotalUp_hadronFlavour);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_nBHadrons", unselectedFatJets_jesTotalUp_nBHadrons, &b_unselectedFatJets_jesTotalUp_nBHadrons);
   fChain->SetBranchAddress("unselectedFatJets_jesTotalUp_nCHadrons", unselectedFatJets_jesTotalUp_nCHadrons, &b_unselectedFatJets_jesTotalUp_nCHadrons);
   fChain->SetBranchAddress("nselectedHOTVRJets_jesTotalUp", &nselectedHOTVRJets_jesTotalUp, &b_nselectedHOTVRJets_jesTotalUp);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_pt", selectedHOTVRJets_jesTotalUp_pt, &b_selectedHOTVRJets_jesTotalUp_pt);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_eta", selectedHOTVRJets_jesTotalUp_eta, &b_selectedHOTVRJets_jesTotalUp_eta);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_phi", selectedHOTVRJets_jesTotalUp_phi, &b_selectedHOTVRJets_jesTotalUp_phi);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_mass", selectedHOTVRJets_jesTotalUp_mass, &b_selectedHOTVRJets_jesTotalUp_mass);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_btagDeepB", selectedHOTVRJets_jesTotalUp_btagDeepB, &b_selectedHOTVRJets_jesTotalUp_btagDeepB);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_tau2", selectedHOTVRJets_jesTotalUp_tau2, &b_selectedHOTVRJets_jesTotalUp_tau2);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_tau3", selectedHOTVRJets_jesTotalUp_tau3, &b_selectedHOTVRJets_jesTotalUp_tau3);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_tau1", selectedHOTVRJets_jesTotalUp_tau1, &b_selectedHOTVRJets_jesTotalUp_tau1);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_area", selectedHOTVRJets_jesTotalUp_area, &b_selectedHOTVRJets_jesTotalUp_area);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_btagDeepFlavB", selectedHOTVRJets_jesTotalUp_btagDeepFlavB, &b_selectedHOTVRJets_jesTotalUp_btagDeepFlavB);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_nConstituents", selectedHOTVRJets_jesTotalUp_nConstituents, &b_selectedHOTVRJets_jesTotalUp_nConstituents);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_subJetIdx1", selectedHOTVRJets_jesTotalUp_subJetIdx1, &b_selectedHOTVRJets_jesTotalUp_subJetIdx1);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_subJetIdx2", selectedHOTVRJets_jesTotalUp_subJetIdx2, &b_selectedHOTVRJets_jesTotalUp_subJetIdx2);
   fChain->SetBranchAddress("selectedHOTVRJets_jesTotalUp_subJetIdx3", selectedHOTVRJets_jesTotalUp_subJetIdx3, &b_selectedHOTVRJets_jesTotalUp_subJetIdx3);
   fChain->SetBranchAddress("nunselectedHOTVRJets_jesTotalUp", &nunselectedHOTVRJets_jesTotalUp, &b_nunselectedHOTVRJets_jesTotalUp);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_pt", unselectedHOTVRJets_jesTotalUp_pt, &b_unselectedHOTVRJets_jesTotalUp_pt);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_eta", unselectedHOTVRJets_jesTotalUp_eta, &b_unselectedHOTVRJets_jesTotalUp_eta);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_phi", unselectedHOTVRJets_jesTotalUp_phi, &b_unselectedHOTVRJets_jesTotalUp_phi);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_mass", unselectedHOTVRJets_jesTotalUp_mass, &b_unselectedHOTVRJets_jesTotalUp_mass);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_btagDeepB", unselectedHOTVRJets_jesTotalUp_btagDeepB, &b_unselectedHOTVRJets_jesTotalUp_btagDeepB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_tau2", unselectedHOTVRJets_jesTotalUp_tau2, &b_unselectedHOTVRJets_jesTotalUp_tau2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_tau3", unselectedHOTVRJets_jesTotalUp_tau3, &b_unselectedHOTVRJets_jesTotalUp_tau3);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_tau1", unselectedHOTVRJets_jesTotalUp_tau1, &b_unselectedHOTVRJets_jesTotalUp_tau1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_area", unselectedHOTVRJets_jesTotalUp_area, &b_unselectedHOTVRJets_jesTotalUp_area);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_btagDeepFlavB", unselectedHOTVRJets_jesTotalUp_btagDeepFlavB, &b_unselectedHOTVRJets_jesTotalUp_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_nConstituents", unselectedHOTVRJets_jesTotalUp_nConstituents, &b_unselectedHOTVRJets_jesTotalUp_nConstituents);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_subJetIdx1", unselectedHOTVRJets_jesTotalUp_subJetIdx1, &b_unselectedHOTVRJets_jesTotalUp_subJetIdx1);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_subJetIdx2", unselectedHOTVRJets_jesTotalUp_subJetIdx2, &b_unselectedHOTVRJets_jesTotalUp_subJetIdx2);
   fChain->SetBranchAddress("unselectedHOTVRJets_jesTotalUp_subJetIdx3", unselectedHOTVRJets_jesTotalUp_subJetIdx3, &b_unselectedHOTVRJets_jesTotalUp_subJetIdx3);
   fChain->SetBranchAddress("MET_jesTotalUp_pt", &MET_jesTotalUp_pt, &b_MET_jesTotalUp_pt);
   fChain->SetBranchAddress("MET_jesTotalUp_phi", &MET_jesTotalUp_phi, &b_MET_jesTotalUp_phi);
   fChain->SetBranchAddress("nselectedBJets_jesTotalUp_tight", &nselectedBJets_jesTotalUp_tight, &b_nselectedBJets_jesTotalUp_tight);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_pt", selectedBJets_jesTotalUp_tight_pt, &b_selectedBJets_jesTotalUp_tight_pt);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_eta", selectedBJets_jesTotalUp_tight_eta, &b_selectedBJets_jesTotalUp_tight_eta);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_phi", selectedBJets_jesTotalUp_tight_phi, &b_selectedBJets_jesTotalUp_tight_phi);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_mass", selectedBJets_jesTotalUp_tight_mass, &b_selectedBJets_jesTotalUp_tight_mass);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_area", selectedBJets_jesTotalUp_tight_area, &b_selectedBJets_jesTotalUp_tight_area);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_hadronFlavour", selectedBJets_jesTotalUp_tight_hadronFlavour, &b_selectedBJets_jesTotalUp_tight_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_partonFlavour", selectedBJets_jesTotalUp_tight_partonFlavour, &b_selectedBJets_jesTotalUp_tight_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_tight_genJetIdx", selectedBJets_jesTotalUp_tight_genJetIdx, &b_selectedBJets_jesTotalUp_tight_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jesTotalUp_medium", &nselectedBJets_jesTotalUp_medium, &b_nselectedBJets_jesTotalUp_medium);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_pt", selectedBJets_jesTotalUp_medium_pt, &b_selectedBJets_jesTotalUp_medium_pt);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_eta", selectedBJets_jesTotalUp_medium_eta, &b_selectedBJets_jesTotalUp_medium_eta);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_phi", selectedBJets_jesTotalUp_medium_phi, &b_selectedBJets_jesTotalUp_medium_phi);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_mass", selectedBJets_jesTotalUp_medium_mass, &b_selectedBJets_jesTotalUp_medium_mass);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_area", selectedBJets_jesTotalUp_medium_area, &b_selectedBJets_jesTotalUp_medium_area);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_hadronFlavour", selectedBJets_jesTotalUp_medium_hadronFlavour, &b_selectedBJets_jesTotalUp_medium_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_partonFlavour", selectedBJets_jesTotalUp_medium_partonFlavour, &b_selectedBJets_jesTotalUp_medium_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_medium_genJetIdx", selectedBJets_jesTotalUp_medium_genJetIdx, &b_selectedBJets_jesTotalUp_medium_genJetIdx);
   fChain->SetBranchAddress("nselectedBJets_jesTotalUp_loose", &nselectedBJets_jesTotalUp_loose, &b_nselectedBJets_jesTotalUp_loose);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_pt", selectedBJets_jesTotalUp_loose_pt, &b_selectedBJets_jesTotalUp_loose_pt);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_eta", selectedBJets_jesTotalUp_loose_eta, &b_selectedBJets_jesTotalUp_loose_eta);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_phi", selectedBJets_jesTotalUp_loose_phi, &b_selectedBJets_jesTotalUp_loose_phi);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_mass", selectedBJets_jesTotalUp_loose_mass, &b_selectedBJets_jesTotalUp_loose_mass);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_area", selectedBJets_jesTotalUp_loose_area, &b_selectedBJets_jesTotalUp_loose_area);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_hadronFlavour", selectedBJets_jesTotalUp_loose_hadronFlavour, &b_selectedBJets_jesTotalUp_loose_hadronFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_partonFlavour", selectedBJets_jesTotalUp_loose_partonFlavour, &b_selectedBJets_jesTotalUp_loose_partonFlavour);
   fChain->SetBranchAddress("selectedBJets_jesTotalUp_loose_genJetIdx", selectedBJets_jesTotalUp_loose_genJetIdx, &b_selectedBJets_jesTotalUp_loose_genJetIdx);
   fChain->SetBranchAddress("npreselectedHOTVRJets", &npreselectedHOTVRJets, &b_npreselectedHOTVRJets);
   fChain->SetBranchAddress("preselectedHOTVRJets_pt", preselectedHOTVRJets_pt, &b_preselectedHOTVRJets_pt);
   fChain->SetBranchAddress("preselectedHOTVRJets_eta", preselectedHOTVRJets_eta, &b_preselectedHOTVRJets_eta);
   fChain->SetBranchAddress("preselectedHOTVRJets_phi", preselectedHOTVRJets_phi, &b_preselectedHOTVRJets_phi);
   fChain->SetBranchAddress("preselectedHOTVRJets_mass", preselectedHOTVRJets_mass, &b_preselectedHOTVRJets_mass);
   fChain->SetBranchAddress("preselectedHOTVRJets_btagDeepB", preselectedHOTVRJets_btagDeepB, &b_preselectedHOTVRJets_btagDeepB);
   fChain->SetBranchAddress("preselectedHOTVRJets_tau2", preselectedHOTVRJets_tau2, &b_preselectedHOTVRJets_tau2);
   fChain->SetBranchAddress("preselectedHOTVRJets_tau3", preselectedHOTVRJets_tau3, &b_preselectedHOTVRJets_tau3);
   fChain->SetBranchAddress("preselectedHOTVRJets_tau1", preselectedHOTVRJets_tau1, &b_preselectedHOTVRJets_tau1);
   fChain->SetBranchAddress("preselectedHOTVRJets_area", preselectedHOTVRJets_area, &b_preselectedHOTVRJets_area);
   fChain->SetBranchAddress("preselectedHOTVRJets_btagDeepFlavB", preselectedHOTVRJets_btagDeepFlavB, &b_preselectedHOTVRJets_btagDeepFlavB);
   fChain->SetBranchAddress("preselectedHOTVRJets_nConstituents", preselectedHOTVRJets_nConstituents, &b_preselectedHOTVRJets_nConstituents);
   fChain->SetBranchAddress("preselectedHOTVRJets_subJetIdx1", preselectedHOTVRJets_subJetIdx1, &b_preselectedHOTVRJets_subJetIdx1);
   fChain->SetBranchAddress("preselectedHOTVRJets_subJetIdx2", preselectedHOTVRJets_subJetIdx2, &b_preselectedHOTVRJets_subJetIdx2);
   fChain->SetBranchAddress("preselectedHOTVRJets_subJetIdx3", preselectedHOTVRJets_subJetIdx3, &b_preselectedHOTVRJets_subJetIdx3);
   fChain->SetBranchAddress("npreunselectedHOTVRJets", &npreunselectedHOTVRJets, &b_npreunselectedHOTVRJets);
   fChain->SetBranchAddress("preunselectedHOTVRJets_pt", preunselectedHOTVRJets_pt, &b_preunselectedHOTVRJets_pt);
   fChain->SetBranchAddress("preunselectedHOTVRJets_eta", preunselectedHOTVRJets_eta, &b_preunselectedHOTVRJets_eta);
   fChain->SetBranchAddress("preunselectedHOTVRJets_phi", preunselectedHOTVRJets_phi, &b_preunselectedHOTVRJets_phi);
   fChain->SetBranchAddress("preunselectedHOTVRJets_mass", preunselectedHOTVRJets_mass, &b_preunselectedHOTVRJets_mass);
   fChain->SetBranchAddress("preunselectedHOTVRJets_btagDeepB", preunselectedHOTVRJets_btagDeepB, &b_preunselectedHOTVRJets_btagDeepB);
   fChain->SetBranchAddress("preunselectedHOTVRJets_tau2", preunselectedHOTVRJets_tau2, &b_preunselectedHOTVRJets_tau2);
   fChain->SetBranchAddress("preunselectedHOTVRJets_tau3", preunselectedHOTVRJets_tau3, &b_preunselectedHOTVRJets_tau3);
   fChain->SetBranchAddress("preunselectedHOTVRJets_tau1", preunselectedHOTVRJets_tau1, &b_preunselectedHOTVRJets_tau1);
   fChain->SetBranchAddress("preunselectedHOTVRJets_area", preunselectedHOTVRJets_area, &b_preunselectedHOTVRJets_area);
   fChain->SetBranchAddress("preunselectedHOTVRJets_btagDeepFlavB", preunselectedHOTVRJets_btagDeepFlavB, &b_preunselectedHOTVRJets_btagDeepFlavB);
   fChain->SetBranchAddress("preunselectedHOTVRJets_nConstituents", preunselectedHOTVRJets_nConstituents, &b_preunselectedHOTVRJets_nConstituents);
   fChain->SetBranchAddress("preunselectedHOTVRJets_subJetIdx1", preunselectedHOTVRJets_subJetIdx1, &b_preunselectedHOTVRJets_subJetIdx1);
   fChain->SetBranchAddress("preunselectedHOTVRJets_subJetIdx2", preunselectedHOTVRJets_subJetIdx2, &b_preunselectedHOTVRJets_subJetIdx2);
   fChain->SetBranchAddress("preunselectedHOTVRJets_subJetIdx3", preunselectedHOTVRJets_subJetIdx3, &b_preunselectedHOTVRJets_subJetIdx3);
   fChain->SetBranchAddress("btagSFlight_deepJet_M_2017_down", &btagSFlight_deepJet_M_2017_down, &b_btagSFlight_deepJet_M_2017_down);
   fChain->SetBranchAddress("btagSFbc_deepJet_M_2017_down", &btagSFbc_deepJet_M_2017_down, &b_btagSFbc_deepJet_M_2017_down);
   fChain->SetBranchAddress("btagSFlight_deepJet_M_2017_up", &btagSFlight_deepJet_M_2017_up, &b_btagSFlight_deepJet_M_2017_up);
   fChain->SetBranchAddress("btagSFbc_deepJet_M_2017_up", &btagSFbc_deepJet_M_2017_up, &b_btagSFbc_deepJet_M_2017_up);
   fChain->SetBranchAddress("btagSFlight_deepJet_M_2017", &btagSFlight_deepJet_M_2017, &b_btagSFlight_deepJet_M_2017);
   fChain->SetBranchAddress("btagSFbc_deepJet_M_2017", &btagSFbc_deepJet_M_2017, &b_btagSFbc_deepJet_M_2017);
   fChain->SetBranchAddress("btagSFlight_deepJet_M_correlated_up", &btagSFlight_deepJet_M_correlated_up, &b_btagSFlight_deepJet_M_correlated_up);
   fChain->SetBranchAddress("btagSFbc_deepJet_M_correlated_up", &btagSFbc_deepJet_M_correlated_up, &b_btagSFbc_deepJet_M_correlated_up);
   fChain->SetBranchAddress("btagSFlight_deepJet_M_correlated_down", &btagSFlight_deepJet_M_correlated_down, &b_btagSFlight_deepJet_M_correlated_down);
   fChain->SetBranchAddress("btagSFbc_deepJet_M_correlated_down", &btagSFbc_deepJet_M_correlated_down, &b_btagSFbc_deepJet_M_correlated_down);
   fChain->SetBranchAddress("btagSFlight_deepJet_L_2017_down", &btagSFlight_deepJet_L_2017_down, &b_btagSFlight_deepJet_L_2017_down);
   fChain->SetBranchAddress("btagSFbc_deepJet_L_2017_down", &btagSFbc_deepJet_L_2017_down, &b_btagSFbc_deepJet_L_2017_down);
   fChain->SetBranchAddress("btagSFlight_deepJet_L_2017_up", &btagSFlight_deepJet_L_2017_up, &b_btagSFlight_deepJet_L_2017_up);
   fChain->SetBranchAddress("btagSFbc_deepJet_L_2017_up", &btagSFbc_deepJet_L_2017_up, &b_btagSFbc_deepJet_L_2017_up);
   fChain->SetBranchAddress("btagSFlight_deepJet_L_2017", &btagSFlight_deepJet_L_2017, &b_btagSFlight_deepJet_L_2017);
   fChain->SetBranchAddress("btagSFbc_deepJet_L_2017", &btagSFbc_deepJet_L_2017, &b_btagSFbc_deepJet_L_2017);
   fChain->SetBranchAddress("btagSFlight_deepJet_L_correlated_up", &btagSFlight_deepJet_L_correlated_up, &b_btagSFlight_deepJet_L_correlated_up);
   fChain->SetBranchAddress("btagSFbc_deepJet_L_correlated_up", &btagSFbc_deepJet_L_correlated_up, &b_btagSFbc_deepJet_L_correlated_up);
   fChain->SetBranchAddress("btagSFlight_deepJet_L_correlated_down", &btagSFlight_deepJet_L_correlated_down, &b_btagSFlight_deepJet_L_correlated_down);
   fChain->SetBranchAddress("btagSFbc_deepJet_L_correlated_down", &btagSFbc_deepJet_L_correlated_down, &b_btagSFbc_deepJet_L_correlated_down);
   fChain->SetBranchAddress("btagSFlight_deepJet_T_2017_down", &btagSFlight_deepJet_T_2017_down, &b_btagSFlight_deepJet_T_2017_down);
   fChain->SetBranchAddress("btagSFbc_deepJet_T_2017_down", &btagSFbc_deepJet_T_2017_down, &b_btagSFbc_deepJet_T_2017_down);
   fChain->SetBranchAddress("btagSFlight_deepJet_T_2017_up", &btagSFlight_deepJet_T_2017_up, &b_btagSFlight_deepJet_T_2017_up);
   fChain->SetBranchAddress("btagSFbc_deepJet_T_2017_up", &btagSFbc_deepJet_T_2017_up, &b_btagSFbc_deepJet_T_2017_up);
   fChain->SetBranchAddress("btagSFlight_deepJet_T_2017", &btagSFlight_deepJet_T_2017, &b_btagSFlight_deepJet_T_2017);
   fChain->SetBranchAddress("btagSFbc_deepJet_T_2017", &btagSFbc_deepJet_T_2017, &b_btagSFbc_deepJet_T_2017);
   fChain->SetBranchAddress("btagSFlight_deepJet_T_correlated_up", &btagSFlight_deepJet_T_correlated_up, &b_btagSFlight_deepJet_T_correlated_up);
   fChain->SetBranchAddress("btagSFbc_deepJet_T_correlated_up", &btagSFbc_deepJet_T_correlated_up, &b_btagSFbc_deepJet_T_correlated_up);
   fChain->SetBranchAddress("btagSFlight_deepJet_T_correlated_down", &btagSFlight_deepJet_T_correlated_down, &b_btagSFlight_deepJet_T_correlated_down);
   fChain->SetBranchAddress("btagSFbc_deepJet_T_correlated_down", &btagSFbc_deepJet_T_correlated_down, &b_btagSFbc_deepJet_T_correlated_down);
   fChain->SetBranchAddress("MET_unclEnUp_pt", &MET_unclEnUp_pt, &b_MET_unclEnUp_pt);
   fChain->SetBranchAddress("MET_unclEnUp_phi", &MET_unclEnUp_phi, &b_MET_unclEnUp_phi);
   fChain->SetBranchAddress("MET_unclEnDown_pt", &MET_unclEnDown_pt, &b_MET_unclEnDown_pt);
   fChain->SetBranchAddress("MET_unclEnDown_phi", &MET_unclEnDown_phi, &b_MET_unclEnDown_phi);
   fChain->SetBranchAddress("ngenTop", &ngenTop, &b_ngenTop);
   fChain->SetBranchAddress("genTop_has_hadronically_decay", genTop_has_hadronically_decay, &b_genTop_has_hadronically_decay);
   fChain->SetBranchAddress("genTop_is_inside_ak8", genTop_is_inside_ak8, &b_genTop_is_inside_ak8);
   fChain->SetBranchAddress("genTop_is_inside_ak8_top_tagged", genTop_is_inside_ak8_top_tagged, &b_genTop_is_inside_ak8_top_tagged);
   fChain->SetBranchAddress("genTop_inside_nak8", genTop_inside_nak8, &b_genTop_inside_nak8);
   fChain->SetBranchAddress("genTop_min_deltaR_ak8", genTop_min_deltaR_ak8, &b_genTop_min_deltaR_ak8);
   fChain->SetBranchAddress("genTop_first_daughter", genTop_first_daughter, &b_genTop_first_daughter);
   fChain->SetBranchAddress("genTop_second_daughter", genTop_second_daughter, &b_genTop_second_daughter);
   fChain->SetBranchAddress("genTop_third_daughter", genTop_third_daughter, &b_genTop_third_daughter);
   fChain->SetBranchAddress("genTop_all_decays_inside_ak8", genTop_all_decays_inside_ak8, &b_genTop_all_decays_inside_ak8);
   fChain->SetBranchAddress("genTop_max_deltaR_q_ak8", genTop_max_deltaR_q_ak8, &b_genTop_max_deltaR_q_ak8);
   fChain->SetBranchAddress("genTop_pt", genTop_pt, &b_genTop_pt);
   fChain->SetBranchAddress("genTop_eta", genTop_eta, &b_genTop_eta);
   fChain->SetBranchAddress("genTop_phi", genTop_phi, &b_genTop_phi);
   fChain->SetBranchAddress("genTop_mass", genTop_mass, &b_genTop_mass);
   fChain->SetBranchAddress("genTop_daughters_pdgId", genTop_daughters_pdgId, &b_genTop_daughters_pdgId);
   fChain->SetBranchAddress("Leptonic_W_pt", &Leptonic_W_pt, &b_Leptonic_W_pt);
   fChain->SetBranchAddress("eventSelection_ee_cut", &eventSelection_ee_cut, &b_eventSelection_ee_cut);
   fChain->SetBranchAddress("dilepton_invariant_mass_ee", &dilepton_invariant_mass_ee, &b_dilepton_invariant_mass_ee);
   fChain->SetBranchAddress("eventSelection_emu_cut", &eventSelection_emu_cut, &b_eventSelection_emu_cut);
   fChain->SetBranchAddress("dilepton_invariant_mass_emu", &dilepton_invariant_mass_emu, &b_dilepton_invariant_mass_emu);
   fChain->SetBranchAddress("eventSelection_mumu_cut", &eventSelection_mumu_cut, &b_eventSelection_mumu_cut);
   fChain->SetBranchAddress("dilepton_invariant_mass_mumu", &dilepton_invariant_mass_mumu, &b_dilepton_invariant_mass_mumu);
   fChain->SetBranchAddress("selectedJets_nominal_is_inside_hotvr", selectedJets_nominal_is_inside_hotvr, &b_selectedJets_nominal_is_inside_hotvr);
   fChain->SetBranchAddress("selectedJets_nominal_is_inside_ak8", selectedJets_nominal_is_inside_ak8, &b_selectedJets_nominal_is_inside_ak8);
   fChain->SetBranchAddress("selectedJets_nominal_min_deltaRVSak8Jet", selectedJets_nominal_min_deltaRVSak8Jet, &b_selectedJets_nominal_min_deltaRVSak8Jet);
   fChain->SetBranchAddress("selectedJets_nominal_min_deltaRVShotvrJet", selectedJets_nominal_min_deltaRVShotvrJet, &b_selectedJets_nominal_min_deltaRVShotvrJet);
   fChain->SetBranchAddress("selectedJets_nominal_rho_over_pt_closest_hotvr", selectedJets_nominal_rho_over_pt_closest_hotvr, &b_selectedJets_nominal_rho_over_pt_closest_hotvr);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_nsubjets", selectedHOTVRJets_nominal_nsubjets, &b_selectedHOTVRJets_nominal_nsubjets);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_tau3_over_tau2", selectedHOTVRJets_nominal_tau3_over_tau2, &b_selectedHOTVRJets_nominal_tau3_over_tau2);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_fractional_subjet_pt", selectedHOTVRJets_nominal_fractional_subjet_pt, &b_selectedHOTVRJets_nominal_fractional_subjet_pt);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_min_pairwise_subjets_mass", selectedHOTVRJets_nominal_min_pairwise_subjets_mass, &b_selectedHOTVRJets_nominal_min_pairwise_subjets_mass);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_effective_radius", selectedHOTVRJets_nominal_effective_radius, &b_selectedHOTVRJets_nominal_effective_radius);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_tau2_over_tau1", selectedHOTVRJets_nominal_tau2_over_tau1, &b_selectedHOTVRJets_nominal_tau2_over_tau1);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_genTop_inside", selectedHOTVRJets_nominal_has_genTop_inside, &b_selectedHOTVRJets_nominal_has_genTop_inside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_genTopHadronic_inside", selectedHOTVRJets_nominal_has_genTopHadronic_inside, &b_selectedHOTVRJets_nominal_has_genTopHadronic_inside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_genTop_inside", selectedFatJets_nominal_has_genTop_inside, &b_selectedFatJets_nominal_has_genTop_inside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_genTopHadronic_inside", selectedFatJets_nominal_has_genTopHadronic_inside, &b_selectedFatJets_nominal_has_genTopHadronic_inside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_other", selectedHOTVRJets_nominal_has_other, &b_selectedHOTVRJets_nominal_has_other);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_not_fromTop", selectedHOTVRJets_nominal_has_b_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicTop_topIsInside", selectedHOTVRJets_nominal_has_hadronicTop_topIsInside, &b_selectedHOTVRJets_nominal_has_hadronicTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_other_topIsInside", selectedHOTVRJets_nominal_has_other_topIsInside, &b_selectedHOTVRJets_nominal_has_other_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_noTopDaughters_topIsInside", selectedHOTVRJets_nominal_has_noTopDaughters_topIsInside, &b_selectedHOTVRJets_nominal_has_noTopDaughters_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsInside", selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside", selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsInside", selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsInside", selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_fromTop_topIsInside", selectedHOTVRJets_nominal_has_b_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_b_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsInside", selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsInside", selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsInside", selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsInside", selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside", selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_not_fromTop_topIsInside", selectedHOTVRJets_nominal_has_b_not_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_b_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsInside", selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsInside, &b_selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside", selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_other_topIsNotInside", selectedHOTVRJets_nominal_has_other_topIsNotInside, &b_selectedHOTVRJets_nominal_has_other_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside", selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside, &b_selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside", selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside, &b_selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedHOTVRJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_other", selectedFatJets_nominal_has_other, &b_selectedFatJets_nominal_has_other);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_not_fromTop", selectedFatJets_nominal_has_b_not_fromTop, &b_selectedFatJets_nominal_has_b_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicTop_topIsInside", selectedFatJets_nominal_has_hadronicTop_topIsInside, &b_selectedFatJets_nominal_has_hadronicTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_other_topIsInside", selectedFatJets_nominal_has_other_topIsInside, &b_selectedFatJets_nominal_has_other_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_noTopDaughters_topIsInside", selectedFatJets_nominal_has_noTopDaughters_topIsInside, &b_selectedFatJets_nominal_has_noTopDaughters_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_leptonicW_fromTop_topIsInside", selectedFatJets_nominal_has_leptonicW_fromTop_topIsInside, &b_selectedFatJets_nominal_has_leptonicW_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicW_fromTop_topIsInside", selectedFatJets_nominal_has_hadronicW_fromTop_topIsInside, &b_selectedFatJets_nominal_has_hadronicW_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsInside", selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsInside, &b_selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsInside", selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsInside, &b_selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_fromTop_topIsInside", selectedFatJets_nominal_has_b_fromTop_topIsInside, &b_selectedFatJets_nominal_has_b_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_quark_fromW_fromTop_topIsInside", selectedFatJets_nominal_has_quark_fromW_fromTop_topIsInside, &b_selectedFatJets_nominal_has_quark_fromW_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsInside", selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsInside, &b_selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsInside", selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsInside, &b_selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsInside", selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsInside, &b_selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside", selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside, &b_selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_not_fromTop_topIsInside", selectedFatJets_nominal_has_b_not_fromTop_topIsInside, &b_selectedFatJets_nominal_has_b_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsInside", selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsInside, &b_selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicTop_topIsNotInside", selectedFatJets_nominal_has_hadronicTop_topIsNotInside, &b_selectedFatJets_nominal_has_hadronicTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_other_topIsNotInside", selectedFatJets_nominal_has_other_topIsNotInside, &b_selectedFatJets_nominal_has_other_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_noTopDaughters_topIsNotInside", selectedFatJets_nominal_has_noTopDaughters_topIsNotInside, &b_selectedFatJets_nominal_has_noTopDaughters_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside", selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside", selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside", selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside", selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_fromTop_topIsNotInside", selectedFatJets_nominal_has_b_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_b_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside", selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside", selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside", selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside", selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside", selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside", selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside", selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside, &b_selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_hadronicTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_leptonicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_hadronicW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_b_plus_quark_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_b_plus_lepton_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_b_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_quark_fromW_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_leptonicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_hadronicW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_b_plus_quark_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_b_plus_lepton_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_b_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop", selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop, &b_selectedFatJets_nominal_has_quark_fromW_not_fromTop_topIsNotInside_and_has_gluon_or_quark_not_fromTop);
   fChain->SetBranchAddress("inference_time_scoreBDT", &inference_time_scoreBDT, &b_inference_time_scoreBDT);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_scoreBDT", selectedHOTVRJets_nominal_scoreBDT, &b_selectedHOTVRJets_nominal_scoreBDT);

   if (fChain->GetListOfBranches()->FindObject("TopPtWeight"))
   {
      fChain->SetBranchAddress("TopPtWeight", &TopPtWeight, &b_TopPtWeight);
   }
   
   Notify();
}

Bool_t Friends::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Friends::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Friends::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Friends_cxx
