//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr  3 11:15:22 2024 by ROOT version 6.20/07
// from TTree Friends/Friend tree for Events
// found on file: SingleMuonB_2017_hotvr_Friend.root
//////////////////////////////////////////////////////////

//#ifndef Friends_h
//#define Friends_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Friends_data {
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
   Int_t           MET_filter;
   UInt_t          nMuon;
   Float_t         muon_PFRelIso04[2];   //[nMuon]
   Float_t         muon_tightID[2];   //[nMuon]
   Float_t         muon_mediumID[2];   //[nMuon]
   Float_t         muon_looseID[2];   //[nMuon]
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
   Float_t         electron_cutBasedID[2];   //[nElectron]
   Float_t         electron_MVA_tightID[2];   //[nElectron]
   Float_t         electron_MVA_mediumID[2];   //[nElectron]
   Float_t         electron_MVA_looseID[2];   //[nElectron]
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
   Float_t         loose_MVA_Electrons_pt[1];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_eta[1];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_charge[1];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_phi[1];   //[nloose_MVA_Electrons]
   Float_t         loose_MVA_Electrons_mass[1];   //[nloose_MVA_Electrons]
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
   Int_t           SingleMu_Trigger_flag;
   Int_t           nselectedJets_nominal;
   Float_t         selectedJets_nominal_pt[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_eta[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_phi[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_mass[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_btagDeepFlavB[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_area[9];   //[nselectedJets_nominal]
   Int_t           nunselectedJets_nominal;
   Float_t         unselectedJets_nominal_pt[14];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_eta[14];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_phi[14];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_mass[14];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_btagDeepFlavB[14];   //[nunselectedJets_nominal]
   Float_t         unselectedJets_nominal_area[14];   //[nunselectedJets_nominal]
   Int_t           nselectedFatJets_nominal;
   Float_t         selectedFatJets_nominal_pt[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_eta[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_phi[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_mass[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_deepTag_TvsQCD[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_deepTag_WvsQCD[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_TvsQCD[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_WvsQCD[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_QCD[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_particleNet_mass[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_btagDeepB[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_tau2[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_tau3[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_tau1[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_msoftdrop[5];   //[nselectedFatJets_nominal]
   Float_t         selectedFatJets_nominal_area[5];   //[nselectedFatJets_nominal]
   Int_t           nunselectedFatJets_nominal;
   Float_t         unselectedFatJets_nominal_pt[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_eta[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_phi[3];   //[nunselectedFatJets_nominal]
   Float_t         unselectedFatJets_nominal_mass[3];   //[nunselectedFatJets_nominal]
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
   Float_t         unselectedHOTVRJets_nominal_pt[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_eta[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_phi[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_mass[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_btagDeepB[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_tau2[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_tau3[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_tau1[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_area[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_btagDeepFlavB[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_nConstituents[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_subJetIdx1[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_subJetIdx2[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         unselectedHOTVRJets_nominal_subJetIdx3[3];   //[nunselectedHOTVRJets_nominal]
   Float_t         MET_nominal_pt;
   Float_t         MET_nominal_phi;
   Float_t         MET_nominal_E;
   Int_t           nselectedHOTVRSubJets_nominal;
   Float_t         selectedHOTVRSubJets_nominal_pt[10];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_eta[10];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_phi[10];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_mass[10];   //[nselectedHOTVRSubJets_nominal]
   Int_t           selectedHOTVRSubJets_nominal_index[10];   //[nselectedHOTVRSubJets_nominal]
   Float_t         selectedHOTVRSubJets_nominal_area[10];   //[nselectedHOTVRSubJets_nominal]
   Int_t           nunselectedHOTVRSubJets_nominal;
   Float_t         unselectedHOTVRSubJets_nominal_pt[5];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_eta[5];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_phi[5];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_mass[5];   //[nunselectedHOTVRSubJets_nominal]
   Int_t           unselectedHOTVRSubJets_nominal_index[5];   //[nunselectedHOTVRSubJets_nominal]
   Float_t         unselectedHOTVRSubJets_nominal_area[5];   //[nunselectedHOTVRSubJets_nominal]
   Int_t           nselectedBJets_nominal_tight;
   Float_t         selectedBJets_nominal_tight_pt[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_eta[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_phi[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_mass[4];   //[nselectedBJets_nominal_tight]
   Float_t         selectedBJets_nominal_tight_area[4];   //[nselectedBJets_nominal_tight]
   Int_t           nselectedBJets_nominal_medium;
   Float_t         selectedBJets_nominal_medium_pt[4];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_eta[4];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_phi[4];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_mass[4];   //[nselectedBJets_nominal_medium]
   Float_t         selectedBJets_nominal_medium_area[4];   //[nselectedBJets_nominal_medium]
   Int_t           nselectedBJets_nominal_loose;
   Float_t         selectedBJets_nominal_loose_pt[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_eta[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_phi[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_mass[6];   //[nselectedBJets_nominal_loose]
   Float_t         selectedBJets_nominal_loose_area[6];   //[nselectedBJets_nominal_loose]
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
   Float_t         preunselectedHOTVRJets_pt[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_eta[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_phi[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_mass[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_btagDeepB[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_tau2[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_tau3[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_tau1[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_area[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_btagDeepFlavB[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_nConstituents[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_subJetIdx1[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_subJetIdx2[3];   //[npreunselectedHOTVRJets]
   Float_t         preunselectedHOTVRJets_subJetIdx3[3];   //[npreunselectedHOTVRJets]
   Float_t         Leptonic_W_pt;
   Int_t           eventSelection_ee_cut_nominal;
   Float_t         dilepton_invariant_mass_ee_nominal;
   Int_t           eventSelection_emu_cut_nominal;
   Float_t         dilepton_invariant_mass_emu_nominal;
   Int_t           eventSelection_mumu_cut_nominal;
   Float_t         dilepton_invariant_mass_mumu_nominal;
   Int_t           selectedJets_nominal_is_inside_hotvr[9];   //[nselectedJets_nominal]
   Int_t           selectedJets_nominal_is_inside_ak8[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_min_deltaRVSak8Jet[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_min_deltaRVShotvrJet[9];   //[nselectedJets_nominal]
   Float_t         selectedJets_nominal_rho_over_pt_closest_hotvr[9];   //[nselectedJets_nominal]
   Int_t           selectedHOTVRJets_nominal_nsubjets[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau3_over_tau2[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_fractional_subjet_pt[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_min_pairwise_subjets_mass[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_effective_radius[3];   //[nselectedHOTVRJets_nominal]
   Float_t         selectedHOTVRJets_nominal_tau2_over_tau1[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_genTop_inside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedFatJets_nominal_has_genTop_inside[5];   //[nselectedFatJets_nominal]
   Int_t           selectedHOTVRJets_nominal_has_genTopHadronic_inside[3];   //[nselectedHOTVRJets_nominal]
   Int_t           selectedFatJets_nominal_has_genTopHadronic_inside[5];   //[nselectedFatJets_nominal]
   Float_t         inference_time_scoreBDT;
   Float_t         selectedHOTVRJets_nominal_scoreBDT[3];   //[nselectedHOTVRJets_nominal]

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_PV_npvsGood;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_fixedGridRhoFastjetAll;   //!
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
   TBranch        *b_SingleMu_Trigger_flag;   //!
   TBranch        *b_nselectedJets_nominal;   //!
   TBranch        *b_selectedJets_nominal_pt;   //!
   TBranch        *b_selectedJets_nominal_eta;   //!
   TBranch        *b_selectedJets_nominal_phi;   //!
   TBranch        *b_selectedJets_nominal_mass;   //!
   TBranch        *b_selectedJets_nominal_btagDeepFlavB;   //!
   TBranch        *b_selectedJets_nominal_area;   //!
   TBranch        *b_nunselectedJets_nominal;   //!
   TBranch        *b_unselectedJets_nominal_pt;   //!
   TBranch        *b_unselectedJets_nominal_eta;   //!
   TBranch        *b_unselectedJets_nominal_phi;   //!
   TBranch        *b_unselectedJets_nominal_mass;   //!
   TBranch        *b_unselectedJets_nominal_btagDeepFlavB;   //!
   TBranch        *b_unselectedJets_nominal_area;   //!
   TBranch        *b_nselectedFatJets_nominal;   //!
   TBranch        *b_selectedFatJets_nominal_pt;   //!
   TBranch        *b_selectedFatJets_nominal_eta;   //!
   TBranch        *b_selectedFatJets_nominal_phi;   //!
   TBranch        *b_selectedFatJets_nominal_mass;   //!
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
   TBranch        *b_nunselectedFatJets_nominal;   //!
   TBranch        *b_unselectedFatJets_nominal_pt;   //!
   TBranch        *b_unselectedFatJets_nominal_eta;   //!
   TBranch        *b_unselectedFatJets_nominal_phi;   //!
   TBranch        *b_unselectedFatJets_nominal_mass;   //!
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
   TBranch        *b_MET_nominal_E;   //!
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
   TBranch        *b_nselectedBJets_nominal_medium;   //!
   TBranch        *b_selectedBJets_nominal_medium_pt;   //!
   TBranch        *b_selectedBJets_nominal_medium_eta;   //!
   TBranch        *b_selectedBJets_nominal_medium_phi;   //!
   TBranch        *b_selectedBJets_nominal_medium_mass;   //!
   TBranch        *b_selectedBJets_nominal_medium_area;   //!
   TBranch        *b_nselectedBJets_nominal_loose;   //!
   TBranch        *b_selectedBJets_nominal_loose_pt;   //!
   TBranch        *b_selectedBJets_nominal_loose_eta;   //!
   TBranch        *b_selectedBJets_nominal_loose_phi;   //!
   TBranch        *b_selectedBJets_nominal_loose_mass;   //!
   TBranch        *b_selectedBJets_nominal_loose_area;   //!
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
   TBranch        *b_Leptonic_W_pt;   //!
   TBranch        *b_eventSelection_ee_cut_nominal;   //!
   TBranch        *b_dilepton_invariant_mass_ee_nominal;   //!
   TBranch        *b_eventSelection_emu_cut_nominal;   //!
   TBranch        *b_dilepton_invariant_mass_emu_nominal;   //!
   TBranch        *b_eventSelection_mumu_cut_nominal;   //!
   TBranch        *b_dilepton_invariant_mass_mumu_nominal;   //!
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
   TBranch        *b_selectedFatJets_nominal_has_genTop_inside;   //!
   TBranch        *b_selectedHOTVRJets_nominal_has_genTopHadronic_inside;   //!
   TBranch        *b_selectedFatJets_nominal_has_genTopHadronic_inside;   //!
   TBranch        *b_inference_time_scoreBDT;   //!
   TBranch        *b_selectedHOTVRJets_nominal_scoreBDT;   //!

   Friends_data(TTree *tree=0);
   virtual ~Friends_data();
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
Friends_data::Friends_data(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SingleMuonB_2017_hotvr_Friend.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SingleMuonB_2017_hotvr_Friend.root");
      }
      f->GetObject("Friends",tree);

   }
   Init(tree);
}

Friends_data::~Friends_data()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Friends_data::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Friends_data::LoadTree(Long64_t entry)
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

void Friends_data::Init(TTree *tree)
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
   fChain->SetBranchAddress("SingleMu_Trigger_flag", &SingleMu_Trigger_flag, &b_SingleMu_Trigger_flag);
   fChain->SetBranchAddress("nselectedJets_nominal", &nselectedJets_nominal, &b_nselectedJets_nominal);
   fChain->SetBranchAddress("selectedJets_nominal_pt", selectedJets_nominal_pt, &b_selectedJets_nominal_pt);
   fChain->SetBranchAddress("selectedJets_nominal_eta", selectedJets_nominal_eta, &b_selectedJets_nominal_eta);
   fChain->SetBranchAddress("selectedJets_nominal_phi", selectedJets_nominal_phi, &b_selectedJets_nominal_phi);
   fChain->SetBranchAddress("selectedJets_nominal_mass", selectedJets_nominal_mass, &b_selectedJets_nominal_mass);
   fChain->SetBranchAddress("selectedJets_nominal_btagDeepFlavB", selectedJets_nominal_btagDeepFlavB, &b_selectedJets_nominal_btagDeepFlavB);
   fChain->SetBranchAddress("selectedJets_nominal_area", selectedJets_nominal_area, &b_selectedJets_nominal_area);
   fChain->SetBranchAddress("nunselectedJets_nominal", &nunselectedJets_nominal, &b_nunselectedJets_nominal);
   fChain->SetBranchAddress("unselectedJets_nominal_pt", unselectedJets_nominal_pt, &b_unselectedJets_nominal_pt);
   fChain->SetBranchAddress("unselectedJets_nominal_eta", unselectedJets_nominal_eta, &b_unselectedJets_nominal_eta);
   fChain->SetBranchAddress("unselectedJets_nominal_phi", unselectedJets_nominal_phi, &b_unselectedJets_nominal_phi);
   fChain->SetBranchAddress("unselectedJets_nominal_mass", unselectedJets_nominal_mass, &b_unselectedJets_nominal_mass);
   fChain->SetBranchAddress("unselectedJets_nominal_btagDeepFlavB", unselectedJets_nominal_btagDeepFlavB, &b_unselectedJets_nominal_btagDeepFlavB);
   fChain->SetBranchAddress("unselectedJets_nominal_area", unselectedJets_nominal_area, &b_unselectedJets_nominal_area);
   fChain->SetBranchAddress("nselectedFatJets_nominal", &nselectedFatJets_nominal, &b_nselectedFatJets_nominal);
   fChain->SetBranchAddress("selectedFatJets_nominal_pt", selectedFatJets_nominal_pt, &b_selectedFatJets_nominal_pt);
   fChain->SetBranchAddress("selectedFatJets_nominal_eta", selectedFatJets_nominal_eta, &b_selectedFatJets_nominal_eta);
   fChain->SetBranchAddress("selectedFatJets_nominal_phi", selectedFatJets_nominal_phi, &b_selectedFatJets_nominal_phi);
   fChain->SetBranchAddress("selectedFatJets_nominal_mass", selectedFatJets_nominal_mass, &b_selectedFatJets_nominal_mass);
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
   fChain->SetBranchAddress("nunselectedFatJets_nominal", &nunselectedFatJets_nominal, &b_nunselectedFatJets_nominal);
   fChain->SetBranchAddress("unselectedFatJets_nominal_pt", unselectedFatJets_nominal_pt, &b_unselectedFatJets_nominal_pt);
   fChain->SetBranchAddress("unselectedFatJets_nominal_eta", unselectedFatJets_nominal_eta, &b_unselectedFatJets_nominal_eta);
   fChain->SetBranchAddress("unselectedFatJets_nominal_phi", unselectedFatJets_nominal_phi, &b_unselectedFatJets_nominal_phi);
   fChain->SetBranchAddress("unselectedFatJets_nominal_mass", unselectedFatJets_nominal_mass, &b_unselectedFatJets_nominal_mass);
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
   fChain->SetBranchAddress("MET_nominal_E", &MET_nominal_E, &b_MET_nominal_E);
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
   fChain->SetBranchAddress("nselectedBJets_nominal_medium", &nselectedBJets_nominal_medium, &b_nselectedBJets_nominal_medium);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_pt", selectedBJets_nominal_medium_pt, &b_selectedBJets_nominal_medium_pt);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_eta", selectedBJets_nominal_medium_eta, &b_selectedBJets_nominal_medium_eta);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_phi", selectedBJets_nominal_medium_phi, &b_selectedBJets_nominal_medium_phi);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_mass", selectedBJets_nominal_medium_mass, &b_selectedBJets_nominal_medium_mass);
   fChain->SetBranchAddress("selectedBJets_nominal_medium_area", selectedBJets_nominal_medium_area, &b_selectedBJets_nominal_medium_area);
   fChain->SetBranchAddress("nselectedBJets_nominal_loose", &nselectedBJets_nominal_loose, &b_nselectedBJets_nominal_loose);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_pt", selectedBJets_nominal_loose_pt, &b_selectedBJets_nominal_loose_pt);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_eta", selectedBJets_nominal_loose_eta, &b_selectedBJets_nominal_loose_eta);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_phi", selectedBJets_nominal_loose_phi, &b_selectedBJets_nominal_loose_phi);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_mass", selectedBJets_nominal_loose_mass, &b_selectedBJets_nominal_loose_mass);
   fChain->SetBranchAddress("selectedBJets_nominal_loose_area", selectedBJets_nominal_loose_area, &b_selectedBJets_nominal_loose_area);
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
   fChain->SetBranchAddress("Leptonic_W_pt", &Leptonic_W_pt, &b_Leptonic_W_pt);
   fChain->SetBranchAddress("eventSelection_ee_cut_nominal", &eventSelection_ee_cut_nominal, &b_eventSelection_ee_cut_nominal);
   fChain->SetBranchAddress("dilepton_invariant_mass_ee_nominal", &dilepton_invariant_mass_ee_nominal, &b_dilepton_invariant_mass_ee_nominal);
   fChain->SetBranchAddress("eventSelection_emu_cut_nominal", &eventSelection_emu_cut_nominal, &b_eventSelection_emu_cut_nominal);
   fChain->SetBranchAddress("dilepton_invariant_mass_emu_nominal", &dilepton_invariant_mass_emu_nominal, &b_dilepton_invariant_mass_emu_nominal);
   fChain->SetBranchAddress("eventSelection_mumu_cut_nominal", &eventSelection_mumu_cut_nominal, &b_eventSelection_mumu_cut_nominal);
   fChain->SetBranchAddress("dilepton_invariant_mass_mumu_nominal", &dilepton_invariant_mass_mumu_nominal, &b_dilepton_invariant_mass_mumu_nominal);
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
   fChain->SetBranchAddress("selectedFatJets_nominal_has_genTop_inside", selectedFatJets_nominal_has_genTop_inside, &b_selectedFatJets_nominal_has_genTop_inside);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_has_genTopHadronic_inside", selectedHOTVRJets_nominal_has_genTopHadronic_inside, &b_selectedHOTVRJets_nominal_has_genTopHadronic_inside);
   fChain->SetBranchAddress("selectedFatJets_nominal_has_genTopHadronic_inside", selectedFatJets_nominal_has_genTopHadronic_inside, &b_selectedFatJets_nominal_has_genTopHadronic_inside);
   fChain->SetBranchAddress("inference_time_scoreBDT", &inference_time_scoreBDT, &b_inference_time_scoreBDT);
   fChain->SetBranchAddress("selectedHOTVRJets_nominal_scoreBDT", selectedHOTVRJets_nominal_scoreBDT, &b_selectedHOTVRJets_nominal_scoreBDT);
   Notify();
}

Bool_t Friends_data::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Friends_data::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Friends_data::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
//#endif // #ifdef Friends_cxx
