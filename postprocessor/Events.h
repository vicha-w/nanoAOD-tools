//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jan 26 23:37:10 2024 by ROOT version 6.26/06
// from TTree Events/Events
// found on file: sample_output_NanoHRT-tools/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_1_tree.root
//////////////////////////////////////////////////////////

#ifndef Events_h
#define Events_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Events {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   UInt_t          luminosityBlock;
   ULong64_t       event;
   Float_t         genWeight;
   UInt_t          nPSWeight;
   Float_t         PSWeight[4];   //[nPSWeight]
   Float_t         LHE_Vpt;
   Float_t         LHEScaleWeight[9];
   Float_t         LHEScaleWeightNorm[9];
   Int_t           genTtbarId;
   Int_t           PV_npvs;
   Bool_t          HLT_Ele27_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf;
   Bool_t          HLT_Ele35_WPTight_Gsf;
   Bool_t          HLT_Ele32_WPTight_Gsf_L1DoubleEG;
   Bool_t          HLT_IsoMu24;
   Bool_t          HLT_IsoMu27;
   Bool_t          HLT_PFHT180;
   Bool_t          HLT_PFHT250;
   Bool_t          HLT_PFHT370;
   Bool_t          HLT_PFHT430;
   Bool_t          HLT_PFHT510;
   Bool_t          HLT_PFHT590;
   Bool_t          HLT_PFHT680;
   Bool_t          HLT_PFHT780;
   Bool_t          HLT_PFHT890;
   Bool_t          HLT_PFHT1050;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1;
   Bool_t          HLT_PFMET120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne110_PFMHT110_IDTight;
   Bool_t          HLT_PFMETTypeOne120_PFMHT120_IDTight;
   Bool_t          HLT_PFMETTypeOne130_PFMHT130_IDTight;
   Bool_t          HLT_PFMETTypeOne140_PFMHT140_IDTight;
   Bool_t          HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;
   Bool_t          HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;
   Bool_t          HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;
   Bool_t          HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;
   Bool_t          HLT_PFHT350;
   Bool_t          HLT_PFMET100_PFMHT100_IDTight_PFHT60;
   Bool_t          HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;
   Bool_t          HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;
   Int_t           year;
   Float_t         lumiwgt;
   Float_t         jetR;
   Bool_t          passmetfilters;
   Float_t         l1PreFiringWeight;
   Float_t         l1PreFiringWeightUp;
   Float_t         l1PreFiringWeightDown;
   Int_t           nlep;
   Float_t         ht;
   Float_t         met;
   Float_t         metphi;
   Bool_t          fj_1_is_qualified;
   Float_t         fj_1_pt;
   Float_t         fj_1_eta;
   Float_t         fj_1_phi;
   Float_t         fj_1_rawmass;
   Float_t         fj_1_sdmass;
   Float_t         fj_1_regressed_mass;
   Float_t         fj_1_tau21;
   Float_t         fj_1_tau32;
   Float_t         fj_1_btagcsvv2;
   Float_t         fj_1_btagjp;
   Float_t         fj_1_deltaR_sj12;
   Float_t         fj_1_sj1_pt;
   Float_t         fj_1_sj1_eta;
   Float_t         fj_1_sj1_phi;
   Float_t         fj_1_sj1_rawmass;
   Float_t         fj_1_sj1_btagdeepcsv;
   Float_t         fj_1_sj2_pt;
   Float_t         fj_1_sj2_eta;
   Float_t         fj_1_sj2_phi;
   Float_t         fj_1_sj2_rawmass;
   Float_t         fj_1_sj2_btagdeepcsv;
   Float_t         fj_1_DeepAK8_TvsQCD;
   Float_t         fj_1_DeepAK8_WvsQCD;
   Float_t         fj_1_DeepAK8_ZvsQCD;
   Float_t         fj_1_DeepAK8_ZHbbvsQCD;
   Float_t         fj_1_DeepAK8MD_TvsQCD;
   Float_t         fj_1_DeepAK8MD_WvsQCD;
   Float_t         fj_1_DeepAK8MD_ZvsQCD;
   Float_t         fj_1_DeepAK8MD_ZHbbvsQCD;
   Float_t         fj_1_DeepAK8MD_ZHccvsQCD;
   Float_t         fj_1_DeepAK8MD_bbVsLight;
   Float_t         fj_1_DeepAK8MD_bbVsTop;
   Float_t         fj_1_ParticleNet_TvsQCD;
   Float_t         fj_1_ParticleNet_WvsQCD;
   Float_t         fj_1_ParticleNet_ZvsQCD;
   Float_t         fj_1_ParticleNetMD_Xbb;
   Float_t         fj_1_ParticleNetMD_Xcc;
   Float_t         fj_1_ParticleNetMD_Xqq;
   Float_t         fj_1_ParticleNetMD_QCD;
   Float_t         fj_1_ParticleNetMD_XbbVsQCD;
   Float_t         fj_1_ParticleNetMD_XccVsQCD;
   Float_t         fj_1_ParticleNetMD_XccOrXqqVsQCD;
   Int_t           fj_1_nbhadrons;
   Int_t           fj_1_nchadrons;
   Int_t           fj_1_partonflavour;
   Int_t           fj_1_sj1_nbhadrons;
   Int_t           fj_1_sj1_nchadrons;
   Int_t           fj_1_sj1_partonflavour;
   Int_t           fj_1_sj2_nbhadrons;
   Int_t           fj_1_sj2_nchadrons;
   Int_t           fj_1_sj2_partonflavour;
   Float_t         fj_1_dr_H;
   Float_t         fj_1_dr_H_daus;
   Float_t         fj_1_H_pt;
   Int_t           fj_1_H_decay;
   Float_t         fj_1_dr_Z;
   Float_t         fj_1_dr_Z_daus;
   Float_t         fj_1_Z_pt;
   Int_t           fj_1_Z_decay;
   Float_t         fj_1_dr_W;
   Float_t         fj_1_dr_W_daus;
   Float_t         fj_1_W_pt;
   Int_t           fj_1_W_decay;
   Float_t         fj_1_dr_T;
   Float_t         fj_1_dr_T_b;
   Float_t         fj_1_dr_T_Wq_max;
   Float_t         fj_1_dr_T_Wq_min;
   Int_t           fj_1_T_Wq_max_pdgId;
   Int_t           fj_1_T_Wq_min_pdgId;
   Float_t         fj_1_T_pt;
   Bool_t          passMuTrig;
   Float_t         muon_pt;
   Float_t         muon_eta;
   Float_t         muon_miniIso;
   Float_t         leptonicW_pt;
   Float_t         puWeight;
   Float_t         puWeightUp;
   Float_t         puWeightDown;
   Float_t         topptWeight;

   Bool_t  preselectedHOTVRJets_has_hadronicTop_topIsInside;
   Bool_t  preselectedHOTVRJets_has_hadronicW_topIsInside;
   Float_t preselectedHOTVRJets_scoreBDT;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_luminosityBlock;   //!
   TBranch        *b_event;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_nPSWeight;   //!
   TBranch        *b_PSWeight;   //!
   TBranch        *b_LHE_Vpt;   //!
   TBranch        *b_genTtbarId;   //!
   TBranch        *b_PV_npvs;   //!
   TBranch        *b_HLT_Ele27_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele35_WPTight_Gsf;   //!
   TBranch        *b_HLT_Ele32_WPTight_Gsf_L1DoubleEG;   //!
   TBranch        *b_HLT_IsoMu24;   //!
   TBranch        *b_HLT_IsoMu27;   //!
   TBranch        *b_HLT_PFHT180;   //!
   TBranch        *b_HLT_PFHT250;   //!
   TBranch        *b_HLT_PFHT370;   //!
   TBranch        *b_HLT_PFHT430;   //!
   TBranch        *b_HLT_PFHT510;   //!
   TBranch        *b_HLT_PFHT590;   //!
   TBranch        *b_HLT_PFHT680;   //!
   TBranch        *b_HLT_PFHT780;   //!
   TBranch        *b_HLT_PFHT890;   //!
   TBranch        *b_HLT_PFHT1050;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1;   //!
   TBranch        *b_HLT_PFMET120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne110_PFMHT110_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne120_PFMHT120_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne130_PFMHT130_IDTight;   //!
   TBranch        *b_HLT_PFMETTypeOne140_PFMHT140_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu110_PFMHTNoMu110_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu120_PFMHTNoMu120_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu130_PFMHTNoMu130_IDTight;   //!
   TBranch        *b_HLT_PFMETNoMu140_PFMHTNoMu140_IDTight;   //!
   TBranch        *b_HLT_PFHT350;   //!
   TBranch        *b_HLT_PFMET100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60;   //!
   TBranch        *b_HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60;   //!
   TBranch        *b_year;   //!
   TBranch        *b_lumiwgt;   //!
   TBranch        *b_jetR;   //!
   TBranch        *b_passmetfilters;   //!
   TBranch        *b_l1PreFiringWeight;   //!
   TBranch        *b_l1PreFiringWeightUp;   //!
   TBranch        *b_l1PreFiringWeightDown;   //!
   TBranch        *b_nlep;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_met;   //!
   TBranch        *b_metphi;   //!
   TBranch        *b_fj_1_is_qualified;   //!
   TBranch        *b_fj_1_pt;   //!
   TBranch        *b_fj_1_eta;   //!
   TBranch        *b_fj_1_phi;   //!
   TBranch        *b_fj_1_rawmass;   //!
   TBranch        *b_fj_1_sdmass;   //!
   TBranch        *b_fj_1_regressed_mass;   //!
   TBranch        *b_fj_1_tau21;   //!
   TBranch        *b_fj_1_tau32;   //!
   TBranch        *b_fj_1_btagcsvv2;   //!
   TBranch        *b_fj_1_btagjp;   //!
   TBranch        *b_fj_1_deltaR_sj12;   //!
   TBranch        *b_fj_1_sj1_pt;   //!
   TBranch        *b_fj_1_sj1_eta;   //!
   TBranch        *b_fj_1_sj1_phi;   //!
   TBranch        *b_fj_1_sj1_rawmass;   //!
   TBranch        *b_fj_1_sj1_btagdeepcsv;   //!
   TBranch        *b_fj_1_sj2_pt;   //!
   TBranch        *b_fj_1_sj2_eta;   //!
   TBranch        *b_fj_1_sj2_phi;   //!
   TBranch        *b_fj_1_sj2_rawmass;   //!
   TBranch        *b_fj_1_sj2_btagdeepcsv;   //!
   TBranch        *b_fj_1_DeepAK8_TvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8_WvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8_ZvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8_ZHbbvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8MD_TvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8MD_WvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8MD_ZvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8MD_ZHbbvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8MD_ZHccvsQCD;   //!
   TBranch        *b_fj_1_DeepAK8MD_bbVsLight;   //!
   TBranch        *b_fj_1_DeepAK8MD_bbVsTop;   //!
   TBranch        *b_fj_1_ParticleNet_TvsQCD;   //!
   TBranch        *b_fj_1_ParticleNet_WvsQCD;   //!
   TBranch        *b_fj_1_ParticleNet_ZvsQCD;   //!
   TBranch        *b_fj_1_ParticleNetMD_Xbb;   //!
   TBranch        *b_fj_1_ParticleNetMD_Xcc;   //!
   TBranch        *b_fj_1_ParticleNetMD_Xqq;   //!
   TBranch        *b_fj_1_ParticleNetMD_QCD;   //!
   TBranch        *b_fj_1_ParticleNetMD_XbbVsQCD;   //!
   TBranch        *b_fj_1_ParticleNetMD_XccVsQCD;   //!
   TBranch        *b_fj_1_ParticleNetMD_XccOrXqqVsQCD;   //!
   TBranch        *b_fj_1_nbhadrons;   //!
   TBranch        *b_fj_1_nchadrons;   //!
   TBranch        *b_fj_1_partonflavour;   //!
   TBranch        *b_fj_1_sj1_nbhadrons;   //!
   TBranch        *b_fj_1_sj1_nchadrons;   //!
   TBranch        *b_fj_1_sj1_partonflavour;   //!
   TBranch        *b_fj_1_sj2_nbhadrons;   //!
   TBranch        *b_fj_1_sj2_nchadrons;   //!
   TBranch        *b_fj_1_sj2_partonflavour;   //!
   TBranch        *b_fj_1_dr_H;   //!
   TBranch        *b_fj_1_dr_H_daus;   //!
   TBranch        *b_fj_1_H_pt;   //!
   TBranch        *b_fj_1_H_decay;   //!
   TBranch        *b_fj_1_dr_Z;   //!
   TBranch        *b_fj_1_dr_Z_daus;   //!
   TBranch        *b_fj_1_Z_pt;   //!
   TBranch        *b_fj_1_Z_decay;   //!
   TBranch        *b_fj_1_dr_W;   //!
   TBranch        *b_fj_1_dr_W_daus;   //!
   TBranch        *b_fj_1_W_pt;   //!
   TBranch        *b_fj_1_W_decay;   //!
   TBranch        *b_fj_1_dr_T;   //!
   TBranch        *b_fj_1_dr_T_b;   //!
   TBranch        *b_fj_1_dr_T_Wq_max;   //!
   TBranch        *b_fj_1_dr_T_Wq_min;   //!
   TBranch        *b_fj_1_T_Wq_max_pdgId;   //!
   TBranch        *b_fj_1_T_Wq_min_pdgId;   //!
   TBranch        *b_fj_1_T_pt;   //!
   TBranch        *b_passMuTrig;   //!
   TBranch        *b_muon_pt;   //!
   TBranch        *b_muon_eta;   //!
   TBranch        *b_muon_miniIso;   //!
   TBranch        *b_leptonicW_pt;   //!
   TBranch        *b_puWeight;   //!
   TBranch        *b_puWeightUp;   //!
   TBranch        *b_puWeightDown;   //!
   TBranch        *b_topptWeight;   //!

   Events(TString outfilename);
   TFile *outfile;
   virtual ~Events();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
   void FillTree();
   void WriteFile();
};

#endif

#ifdef Events_cxx
Events::Events(TString outfilename)
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   //if (tree == 0) {
   //   TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("sample_output_NanoHRT-tools/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_1_tree.root");
   //   if (!f || !f->IsOpen()) {
   //      f = new TFile("sample_output_NanoHRT-tools/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8_1_tree.root");
   //   }
   //   f->GetObject("Events",tree);
   //
   //}
   outfile = new TFile(outfilename, "RECREATE");
   fChain = new TTree("Events", "Events");

   Init(fChain);
}

Events::~Events()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Events::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Events::LoadTree(Long64_t entry)
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

void Events::Init(TTree *tree)
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
   //fChain->SetMakeClass(1);

   fChain->Branch("run", &run, "run/i");
   fChain->Branch("luminosityBlock", &luminosityBlock, "luminosityBlock/i");
   fChain->Branch("event", &event, "event/l");
   fChain->Branch("genWeight", &genWeight, "genWeight/F");
   fChain->Branch("nPSWeight", &nPSWeight, "nPSWeight/i");
   fChain->Branch("PSWeight", PSWeight, "PSWeight[nPSWeight]/F");
   fChain->Branch("LHE_Vpt", &LHE_Vpt, "LHE_Vpt/F");
   fChain->Branch("LHEScaleWeight", LHEScaleWeight, "LHEScaleWeight[9]/F");
   fChain->Branch("LHEScaleWeightNorm", LHEScaleWeightNorm, "LHEScaleWeightNorm[9]/F");
   fChain->Branch("genTtbarId", &genTtbarId, "genTtbarId/I");
   fChain->Branch("PV_npvs", &PV_npvs, "PV_npvs/I");
   fChain->Branch("HLT_Ele27_WPTight_Gsf", &HLT_Ele27_WPTight_Gsf, "HLT_Ele27_WPTight_Gsf/O");
   fChain->Branch("HLT_Ele32_WPTight_Gsf", &HLT_Ele32_WPTight_Gsf, "HLT_Ele32_WPTight_Gsf/O");
   fChain->Branch("HLT_Ele35_WPTight_Gsf", &HLT_Ele35_WPTight_Gsf, "HLT_Ele35_WPTight_Gsf/O");
   fChain->Branch("HLT_Ele32_WPTight_Gsf_L1DoubleEG", &HLT_Ele32_WPTight_Gsf_L1DoubleEG, "HLT_Ele32_WPTight_Gsf_L1DoubleEG/O");
   fChain->Branch("HLT_IsoMu24", &HLT_IsoMu24, "HLT_IsoMu24/O");
   fChain->Branch("HLT_IsoMu27", &HLT_IsoMu27, "HLT_IsoMu27/O");
   fChain->Branch("HLT_PFHT180", &HLT_PFHT180, "HLT_PFHT180/O");
   fChain->Branch("HLT_PFHT250", &HLT_PFHT250, "HLT_PFHT250/O");
   fChain->Branch("HLT_PFHT370", &HLT_PFHT370, "HLT_PFHT370/O");
   fChain->Branch("HLT_PFHT430", &HLT_PFHT430, "HLT_PFHT430/O");
   fChain->Branch("HLT_PFHT510", &HLT_PFHT510, "HLT_PFHT510/O");
   fChain->Branch("HLT_PFHT590", &HLT_PFHT590, "HLT_PFHT590/O");
   fChain->Branch("HLT_PFHT680", &HLT_PFHT680, "HLT_PFHT680/O");
   fChain->Branch("HLT_PFHT780", &HLT_PFHT780, "HLT_PFHT780/O");
   fChain->Branch("HLT_PFHT890", &HLT_PFHT890, "HLT_PFHT890/O");
   fChain->Branch("HLT_PFHT1050", &HLT_PFHT1050, "HLT_PFHT1050/O");
   fChain->Branch("HLT_PFMET110_PFMHT110_IDTight", &HLT_PFMET110_PFMHT110_IDTight, "HLT_PFMET110_PFMHT110_IDTight/O");
   fChain->Branch("HLT_PFMET120_PFMHT120_IDTight", &HLT_PFMET120_PFMHT120_IDTight, "HLT_PFMET120_PFMHT120_IDTight/O");
   fChain->Branch("HLT_PFMET130_PFMHT130_IDTight", &HLT_PFMET130_PFMHT130_IDTight, "HLT_PFMET130_PFMHT130_IDTight/O");
   fChain->Branch("HLT_PFMET140_PFMHT140_IDTight", &HLT_PFMET140_PFMHT140_IDTight, "HLT_PFMET140_PFMHT140_IDTight/O");
   fChain->Branch("HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1", &HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1, "HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1/O");
   fChain->Branch("HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1", &HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1, "HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1/O");
   fChain->Branch("HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1", &HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1, "HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1/O");
   fChain->Branch("HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1", &HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1, "HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1/O");
   fChain->Branch("HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1", &HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1, "HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1/O");
   fChain->Branch("HLT_PFMET120_PFMHT120_IDTight_PFHT60", &HLT_PFMET120_PFMHT120_IDTight_PFHT60, "HLT_PFMET120_PFMHT120_IDTight_PFHT60/O");
   fChain->Branch("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60/O");
   fChain->Branch("HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60", &HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60, "HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60/O");
   fChain->Branch("HLT_PFMETTypeOne110_PFMHT110_IDTight", &HLT_PFMETTypeOne110_PFMHT110_IDTight, "HLT_PFMETTypeOne110_PFMHT110_IDTight/O");
   fChain->Branch("HLT_PFMETTypeOne120_PFMHT120_IDTight", &HLT_PFMETTypeOne120_PFMHT120_IDTight, "HLT_PFMETTypeOne120_PFMHT120_IDTight/O");
   fChain->Branch("HLT_PFMETTypeOne130_PFMHT130_IDTight", &HLT_PFMETTypeOne130_PFMHT130_IDTight, "HLT_PFMETTypeOne130_PFMHT130_IDTight/O");
   fChain->Branch("HLT_PFMETTypeOne140_PFMHT140_IDTight", &HLT_PFMETTypeOne140_PFMHT140_IDTight, "HLT_PFMETTypeOne140_PFMHT140_IDTight/O");
   fChain->Branch("HLT_PFMETNoMu110_PFMHTNoMu110_IDTight", &HLT_PFMETNoMu110_PFMHTNoMu110_IDTight, "HLT_PFMETNoMu110_PFMHTNoMu110_IDTight/O");
   fChain->Branch("HLT_PFMETNoMu120_PFMHTNoMu120_IDTight", &HLT_PFMETNoMu120_PFMHTNoMu120_IDTight, "HLT_PFMETNoMu120_PFMHTNoMu120_IDTight/O");
   fChain->Branch("HLT_PFMETNoMu130_PFMHTNoMu130_IDTight", &HLT_PFMETNoMu130_PFMHTNoMu130_IDTight, "HLT_PFMETNoMu130_PFMHTNoMu130_IDTight/O");
   fChain->Branch("HLT_PFMETNoMu140_PFMHTNoMu140_IDTight", &HLT_PFMETNoMu140_PFMHTNoMu140_IDTight, "HLT_PFMETNoMu140_PFMHTNoMu140_IDTight/O");
   fChain->Branch("HLT_PFHT350", &HLT_PFHT350, "HLT_PFHT350/O");
   fChain->Branch("HLT_PFMET100_PFMHT100_IDTight_PFHT60", &HLT_PFMET100_PFMHT100_IDTight_PFHT60, "HLT_PFMET100_PFMHT100_IDTight_PFHT60/O");
   fChain->Branch("HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60", &HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60, "HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60/O");
   fChain->Branch("HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60", &HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60, "HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60/O");
   fChain->Branch("year", &year, "year/I");
   fChain->Branch("lumiwgt", &lumiwgt, "lumiwgt/F");
   fChain->Branch("jetR", &jetR, "jetR/F");
   fChain->Branch("passmetfilters", &passmetfilters, "passmetfilters/O");
   fChain->Branch("l1PreFiringWeight", &l1PreFiringWeight, "l1PreFiringWeight/F");
   fChain->Branch("l1PreFiringWeightUp", &l1PreFiringWeightUp, "l1PreFiringWeightUp/F");
   fChain->Branch("l1PreFiringWeightDown", &l1PreFiringWeightDown, "l1PreFiringWeightDown/F");
   fChain->Branch("nlep", &nlep, "nlep/I");
   fChain->Branch("ht", &ht, "ht/F");
   fChain->Branch("met", &met, "met/F");
   fChain->Branch("metphi", &metphi, "metphi/F");
   fChain->Branch("fj_1_is_qualified", &fj_1_is_qualified, "fj_1_is_qualified/O");
   fChain->Branch("fj_1_pt", &fj_1_pt, "fj_1_pt/F");
   fChain->Branch("fj_1_eta", &fj_1_eta, "fj_1_eta/F");
   fChain->Branch("fj_1_phi", &fj_1_phi, "fj_1_phi/F");
   fChain->Branch("fj_1_rawmass", &fj_1_rawmass, "fj_1_rawmass/F");
   fChain->Branch("fj_1_sdmass", &fj_1_sdmass, "fj_1_sdmass/F");
   fChain->Branch("fj_1_regressed_mass", &fj_1_regressed_mass, "fj_1_regressed_mass/F");
   fChain->Branch("fj_1_tau21", &fj_1_tau21, "fj_1_tau21/F");
   fChain->Branch("fj_1_tau32", &fj_1_tau32, "fj_1_tau32/F");
   fChain->Branch("fj_1_btagcsvv2", &fj_1_btagcsvv2, "fj_1_btagcsvv2/F");
   fChain->Branch("fj_1_btagjp", &fj_1_btagjp, "fj_1_btagjp/F");
   fChain->Branch("fj_1_deltaR_sj12", &fj_1_deltaR_sj12, "fj_1_deltaR_sj12/F");
   fChain->Branch("fj_1_sj1_pt", &fj_1_sj1_pt, "fj_1_sj1_pt/F");
   fChain->Branch("fj_1_sj1_eta", &fj_1_sj1_eta, "fj_1_sj1_eta/F");
   fChain->Branch("fj_1_sj1_phi", &fj_1_sj1_phi, "fj_1_sj1_phi/F");
   fChain->Branch("fj_1_sj1_rawmass", &fj_1_sj1_rawmass, "fj_1_sj1_rawmass/F");
   fChain->Branch("fj_1_sj1_btagdeepcsv", &fj_1_sj1_btagdeepcsv, "fj_1_sj1_btagdeepcsv/F");
   fChain->Branch("fj_1_sj2_pt", &fj_1_sj2_pt, "fj_1_sj2_pt/F");
   fChain->Branch("fj_1_sj2_eta", &fj_1_sj2_eta, "fj_1_sj2_eta/F");
   fChain->Branch("fj_1_sj2_phi", &fj_1_sj2_phi, "fj_1_sj2_phi/F");
   fChain->Branch("fj_1_sj2_rawmass", &fj_1_sj2_rawmass, "fj_1_sj2_rawmass/F");
   fChain->Branch("fj_1_sj2_btagdeepcsv", &fj_1_sj2_btagdeepcsv, "fj_1_sj2_btagdeepcsv/F");
   fChain->Branch("fj_1_DeepAK8_TvsQCD", &fj_1_DeepAK8_TvsQCD, "fj_1_DeepAK8_TvsQCD/F");
   fChain->Branch("fj_1_DeepAK8_WvsQCD", &fj_1_DeepAK8_WvsQCD, "fj_1_DeepAK8_WvsQCD/F");
   fChain->Branch("fj_1_DeepAK8_ZvsQCD", &fj_1_DeepAK8_ZvsQCD, "fj_1_DeepAK8_ZvsQCD/F");
   fChain->Branch("fj_1_DeepAK8_ZHbbvsQCD", &fj_1_DeepAK8_ZHbbvsQCD, "fj_1_DeepAK8_ZHbbvsQCD/F");
   fChain->Branch("fj_1_DeepAK8MD_TvsQCD", &fj_1_DeepAK8MD_TvsQCD, "fj_1_DeepAK8MD_TvsQCD/F");
   fChain->Branch("fj_1_DeepAK8MD_WvsQCD", &fj_1_DeepAK8MD_WvsQCD, "fj_1_DeepAK8MD_WvsQCD/F");
   fChain->Branch("fj_1_DeepAK8MD_ZvsQCD", &fj_1_DeepAK8MD_ZvsQCD, "fj_1_DeepAK8MD_ZvsQCD/F");
   fChain->Branch("fj_1_DeepAK8MD_ZHbbvsQCD", &fj_1_DeepAK8MD_ZHbbvsQCD, "fj_1_DeepAK8MD_ZHbbvsQCD/F");
   fChain->Branch("fj_1_DeepAK8MD_ZHccvsQCD", &fj_1_DeepAK8MD_ZHccvsQCD, "fj_1_DeepAK8MD_ZHccvsQCD/F");
   fChain->Branch("fj_1_DeepAK8MD_bbVsLight", &fj_1_DeepAK8MD_bbVsLight, "fj_1_DeepAK8MD_bbVsLight/F");
   fChain->Branch("fj_1_DeepAK8MD_bbVsTop", &fj_1_DeepAK8MD_bbVsTop, "fj_1_DeepAK8MD_bbVsTop/F");
   fChain->Branch("fj_1_ParticleNet_TvsQCD", &fj_1_ParticleNet_TvsQCD, "fj_1_ParticleNet_TvsQCD/F");
   fChain->Branch("fj_1_ParticleNet_WvsQCD", &fj_1_ParticleNet_WvsQCD, "fj_1_ParticleNet_WvsQCD/F");
   fChain->Branch("fj_1_ParticleNet_ZvsQCD", &fj_1_ParticleNet_ZvsQCD, "fj_1_ParticleNet_ZvsQCD/F");
   fChain->Branch("fj_1_ParticleNetMD_Xbb", &fj_1_ParticleNetMD_Xbb, "fj_1_ParticleNetMD_Xbb/F");
   fChain->Branch("fj_1_ParticleNetMD_Xcc", &fj_1_ParticleNetMD_Xcc, "fj_1_ParticleNetMD_Xcc/F");
   fChain->Branch("fj_1_ParticleNetMD_Xqq", &fj_1_ParticleNetMD_Xqq, "fj_1_ParticleNetMD_Xqq/F");
   fChain->Branch("fj_1_ParticleNetMD_QCD", &fj_1_ParticleNetMD_QCD, "fj_1_ParticleNetMD_QCD/F");
   fChain->Branch("fj_1_ParticleNetMD_XbbVsQCD", &fj_1_ParticleNetMD_XbbVsQCD, "fj_1_ParticleNetMD_XbbVsQCD/F");
   fChain->Branch("fj_1_ParticleNetMD_XccVsQCD", &fj_1_ParticleNetMD_XccVsQCD, "fj_1_ParticleNetMD_XccVsQCD/F");
   fChain->Branch("fj_1_ParticleNetMD_XccOrXqqVsQCD", &fj_1_ParticleNetMD_XccOrXqqVsQCD, "fj_1_ParticleNetMD_XccOrXqqVsQCD/F");
   fChain->Branch("fj_1_nbhadrons", &fj_1_nbhadrons, "fj_1_nbhadrons/F");
   fChain->Branch("fj_1_nchadrons", &fj_1_nchadrons, "fj_1_nchadrons/F");
   fChain->Branch("fj_1_partonflavour", &fj_1_partonflavour, "fj_1_partonflavour/F");
   fChain->Branch("fj_1_sj1_nbhadrons", &fj_1_sj1_nbhadrons, "fj_1_sj1_nbhadrons/I");
   fChain->Branch("fj_1_sj1_nchadrons", &fj_1_sj1_nchadrons, "fj_1_sj1_nchadrons/I");
   fChain->Branch("fj_1_sj1_partonflavour", &fj_1_sj1_partonflavour, "fj_1_sj1_partonflavour/I");
   fChain->Branch("fj_1_sj2_nbhadrons", &fj_1_sj2_nbhadrons, "fj_1_sj2_nbhadrons/I");
   fChain->Branch("fj_1_sj2_nchadrons", &fj_1_sj2_nchadrons, "fj_1_sj2_nchadrons/I");
   fChain->Branch("fj_1_sj2_partonflavour", &fj_1_sj2_partonflavour, "fj_1_sj2_partonflavour/I");
   fChain->Branch("fj_1_dr_H", &fj_1_dr_H, "fj_1_dr_H/F");
   fChain->Branch("fj_1_dr_H_daus", &fj_1_dr_H_daus, "fj_1_dr_H_daus/F");
   fChain->Branch("fj_1_H_pt", &fj_1_H_pt, "fj_1_H_pt/F");
   fChain->Branch("fj_1_H_decay", &fj_1_H_decay, "fj_1_H_decay/I");
   fChain->Branch("fj_1_dr_Z", &fj_1_dr_Z, "fj_1_dr_Z/F");
   fChain->Branch("fj_1_dr_Z_daus", &fj_1_dr_Z_daus, "fj_1_dr_Z_daus/F");
   fChain->Branch("fj_1_Z_pt", &fj_1_Z_pt, "fj_1_Z_pt/F");
   fChain->Branch("fj_1_Z_decay", &fj_1_Z_decay, "fj_1_Z_decay/I");
   fChain->Branch("fj_1_dr_W", &fj_1_dr_W, "fj_1_dr_W/F");
   fChain->Branch("fj_1_dr_W_daus", &fj_1_dr_W_daus, "fj_1_dr_W_daus/F");
   fChain->Branch("fj_1_W_pt", &fj_1_W_pt, "fj_1_W_pt/F");
   fChain->Branch("fj_1_W_decay", &fj_1_W_decay, "fj_1_W_decay/I");
   fChain->Branch("fj_1_dr_T", &fj_1_dr_T, "fj_1_dr_T/F");
   fChain->Branch("fj_1_dr_T_b", &fj_1_dr_T_b, "fj_1_dr_T_b/F");
   fChain->Branch("fj_1_dr_T_Wq_max", &fj_1_dr_T_Wq_max, "fj_1_dr_T_Wq_max/F");
   fChain->Branch("fj_1_dr_T_Wq_min", &fj_1_dr_T_Wq_min, "fj_1_dr_T_Wq_min/F");
   fChain->Branch("fj_1_T_Wq_max_pdgId", &fj_1_T_Wq_max_pdgId, "fj_1_T_Wq_max_pdgId/I");
   fChain->Branch("fj_1_T_Wq_min_pdgId", &fj_1_T_Wq_min_pdgId, "fj_1_T_Wq_min_pdgId/I");
   fChain->Branch("fj_1_T_pt", &fj_1_T_pt, "fj_1_T_pt/F");
   fChain->Branch("passMuTrig", &passMuTrig, "passMuTrig/O");
   fChain->Branch("muon_pt", &muon_pt, "muon_pt/F");
   fChain->Branch("muon_eta", &muon_eta, "muon_eta/F");
   fChain->Branch("muon_miniIso", &muon_miniIso, "muon_miniIso/F");
   fChain->Branch("leptonicW_pt", &leptonicW_pt, "leptonicW_pt/F");
   fChain->Branch("puWeight", &puWeight, "puWeight/F");
   fChain->Branch("puWeightUp", &puWeightUp, "puWeightUp/F");
   fChain->Branch("puWeightDown", &puWeightDown, "puWeightDown/F");
   fChain->Branch("topptWeight", &topptWeight, "topptWeight/F");

   fChain->Branch("preselectedHOTVRJets_has_hadronicTop_topIsInside", &preselectedHOTVRJets_has_hadronicTop_topIsInside, "preselectedHOTVRJets_has_hadronicTop_topIsInside/O");
   fChain->Branch("preselectedHOTVRJets_has_hadronicW_topIsInside", &preselectedHOTVRJets_has_hadronicW_topIsInside, "preselectedHOTVRJets_has_hadronicW_topIsInside/O");
   fChain->Branch("preselectedHOTVRJets_scoreBDT", &preselectedHOTVRJets_scoreBDT, "preselectedHOTVRJets_scoreBDT/F");
   Notify();
}

void Events::FillTree()
{
   // Fills the tree after all variables have been set.
   fChain->Fill();
}

void Events::WriteFile()
{
   //TFile *outfile = new TFile(outfilename, "RECREATE");
   outfile->cd();
   fChain->Write();
   //outfile->Close();
   //printf("File %s written successfully.\n", (char*) outfilename);
   cout << "Write complete." << endl;
}

Bool_t Events::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Events::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Events::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Events_cxx