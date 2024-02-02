#include <stdio.h>
#include <stdlib.h>
#include "Friends.C"
#include "Events.C"
#include <TMath.h>
#include <glob.h>

std::vector<std::string> glob(const char *pattern) {
    glob_t g;
    glob(pattern, GLOB_TILDE, nullptr, &g); // one should ensure glob returns 0!
    std::vector<std::string> filelist;
    filelist.reserve(g.gl_pathc);
    for (size_t i = 0; i < g.gl_pathc; ++i) {
        filelist.emplace_back(g.gl_pathv[i]);
    }
    globfree(&g);
    return filelist;
}

Float_t deltaPhi(Float_t phi1, Float_t phi2)
{
    Float_t dphi = phi1 - phi2;
    while (dphi >  TMath::Pi()) dphi -= 2*TMath::Pi();
    while (dphi < -TMath::Pi()) dphi += 2*TMath::Pi();
    return TMath::Abs(dphi);
}

void single_muon_postprocessor(TString infilename, TString outfilename, bool isData=false, Int_t uncmode=0) // outfilename must not have .root suffix! 
{
    //enum class Unctype = { nominal, jesup, jesdown, jerup, jerdown, metdown, metup };

    Float_t sumgenweight = 0;
    int file_count = 0;

    if (!isData)
    {
        for (const auto &filename : glob(infilename.Data())) 
        {
            //chain->Add(filename.c_str());
            file_count += 1;
            TFile *infile = new TFile(filename.c_str());
            //if (!infile->Get("sumGenWeights")) break;

            sumgenweight += ((TParameter<float>*) infile->Get("sumGenWeights"))->GetVal();
            infile->Close();
        }
        printf("Walked through %d files.\n", file_count);
        printf("sumgenweight = %f\n", sumgenweight);
    }
    else
    {
        printf("Data mode activated. No files walked for sumGenWeights.\n", file_count);
    }

    if (isData && (uncmode!=0))
    {
        printf("Uncertainties are not supported while isData is true.\n");
        printf("uncmode = %d\n", uncmode);
        exit();
    }

    //TFile *infile = new TFile(infilename);
    //TTree *intree = (TTree*) infile->Get("Friends");
    TChain *intree = new TChain("Friends");
    intree->Add(infilename);

    printf("Found %lld events.\n", intree->GetEntries());
    
    Friends *infriends = new Friends(intree);

    TString final_outfilename;
    switch (uncmode)
    {
        case 0:
            printf("Starting nominal variant...\n");
            final_outfilename = outfilename + "_nominal.root";
            break;
        case 1:
            printf("Starting JESup variant...\n");
            final_outfilename = outfilename + "_jesUp.root";
            break;
        case 2:
            printf("Starting JESdown variant...\n");
            final_outfilename = outfilename + "_jesDown.root";
            break;
        case 3:
            printf("Starting JERup variant...\n");
            final_outfilename = outfilename + "_jerUp.root";
            break;
        case 4:
            printf("Starting JERdown variant...\n");
            final_outfilename = outfilename + "_jerDown.root";
            break;
        case 5:
            printf("Starting METup variant...\n");
            final_outfilename = outfilename + "_metUp.root";
            break;
        case 6:
            printf("Starting METdown variant...\n");
            final_outfilename = outfilename + "_metDown.root";
            break;
    }

    Events *outevents = new Events(final_outfilename);

    Int_t* njets_pointers[] = {
        &(infriends->nselectedJets_nominal),
        &(infriends->nselectedJets_jesTotalUp),
        &(infriends->nselectedJets_jesTotalDown),
        &(infriends->nselectedJets_jerUp),
        &(infriends->nselectedJets_jerDown),
        &(infriends->nselectedJets_nominal),
        &(infriends->nselectedJets_nominal)
        };

    Int_t* nbjets_pointers[] = {
        &(infriends->nselectedBJets_nominal_medium),
        &(infriends->nselectedBJets_jesTotalUp_medium),
        &(infriends->nselectedBJets_jesTotalDown_medium),
        &(infriends->nselectedBJets_jerUp_medium),
        &(infriends->nselectedBJets_jerDown_medium),
        &(infriends->nselectedBJets_nominal_medium), 
        &(infriends->nselectedBJets_nominal_medium)
        };

    Float_t* bjets_phi_pointers[] = {
        (infriends->selectedBJets_nominal_medium_phi),
        (infriends->selectedBJets_jesTotalUp_medium_phi),
        (infriends->selectedBJets_jesTotalDown_medium_phi),
        (infriends->selectedBJets_jerUp_medium_phi),
        (infriends->selectedBJets_jerDown_medium_phi),
        (infriends->selectedBJets_nominal_medium_phi),
        (infriends->selectedBJets_nominal_medium_phi)
    };

    Float_t* jets_pt_pointers[] = {
        (infriends->selectedJets_nominal_pt),
        (infriends->selectedJets_jesTotalUp_pt),
        (infriends->selectedJets_jesTotalDown_pt),
        (infriends->selectedJets_jerUp_pt),
        (infriends->selectedJets_jerDown_pt),
        (infriends->selectedJets_nominal_pt),
        (infriends->selectedJets_nominal_pt)
    };

    for (int ievent=0; ievent<intree->GetEntries(); ievent++)
    {
        infriends->GetEntry(ievent);

        // Passes MET filters (AN2017/006)
        if (!infriends->MET_filter) continue;
        // Exactly one muon (JME-18-002)
        if (infriends->ntightRelIso_tightID_Muons != 1) continue;

        // Electron veto (AN2017/006)
        if (infriends->nloose_MVA_Electrons + infriends->nvetoElectrons > 0) continue;

        bool two_or_more_ak4_jets;
        //for (int i=0; i<5; i++) 
        //{
        //    two_or_more_ak4_jets = two_or_more_ak4_jets || (*(njets_pointers[i]) >= 2);
        //    if (two_or_more_ak4_jets) break;
        //}
        switch (uncmode)
        {
            case 1:
                two_or_more_ak4_jets = infriends->nselectedJets_jesTotalUp >= 2;
                break;
            case 2:
                two_or_more_ak4_jets = infriends->nselectedJets_jesTotalDown >= 2;
                break;
            case 3:
                two_or_more_ak4_jets = infriends->nselectedJets_jerUp >= 2;
                break;
            case 4:
                two_or_more_ak4_jets = infriends->nselectedJets_jerDown >= 2;
                break;
            default: two_or_more_ak4_jets = infriends->nselectedJets_nominal >= 2;
        }
        //two_or_more_ak4_jets = two_or_more_ak4_jets || (infriends->nselectedJets_nominal >= 2);
        //two_or_more_ak4_jets = two_or_more_ak4_jets || (infriends->nselectedJets_jesTotalUp >= 2);
        //two_or_more_ak4_jets = two_or_more_ak4_jets || (infriends->nselectedJets_jesTotalDown >= 2);
        //two_or_more_ak4_jets = two_or_more_ak4_jets || (infriends->nselectedJets_jerUp >= 2);
        //two_or_more_ak4_jets = two_or_more_ak4_jets || (infriends->nselectedJets_jerDown >= 2);
        
        // Two or more AK4 jets (JME-18-002)
        //if (infriends->nselectedJets_nominal < 2) continue;
        if (!two_or_more_ak4_jets) continue;

        bool at_least_one_bjet = false;
        //for (int i=0; i<5; i++) 
        //{
        //    at_least_one_bjet = at_least_one_bjet || (*(nbjets_pointers[i]) >= 2);
        //    if (at_least_one_bjet) break;
        //}
        switch (uncmode)
        {
            case 1:
                at_least_one_bjet = infriends->nselectedBJets_jesTotalUp_medium > 0;
                break;
            case 2:
                at_least_one_bjet = infriends->nselectedBJets_jesTotalDown_medium > 0;
                break;
            case 3:
                at_least_one_bjet = infriends->nselectedBJets_jerUp_medium > 0;
                break;
            case 4:
                at_least_one_bjet = infriends->nselectedBJets_jerDown_medium > 0;
                break;
            default: at_least_one_bjet = infriends->nselectedBJets_nominal_medium > 0;
        }
        //at_least_one_bjet = at_least_one_bjet || (infriends->nselectedBJets_nominal_medium > 0);
        //at_least_one_bjet = at_least_one_bjet || (infriends->nselectedBJets_jesTotalUp_medium > 0);
        //at_least_one_bjet = at_least_one_bjet || (infriends->nselectedBJets_jesTotalDown_medium > 0);
        //at_least_one_bjet = at_least_one_bjet || (infriends->nselectedBJets_jerUp_medium > 0);
        //at_least_one_bjet = at_least_one_bjet || (infriends->nselectedBJets_jerDown_medium > 0);

        // At least one b-jet (JME-18-002)
        //if (infriends->nselectedBJets_nominal_medium == 0) continue;
        if (!at_least_one_bjet) continue;

        // Leptonic W pT > 250 GeV (JME-18-002, AN2017/006)
        if (infriends->Leptonic_W_pt < 250) continue;

        // At least one HOTVR jet
        if (infriends->npreselectedHOTVRJets == 0) continue;
        

        // b-jet in the same hemisphere as muon (AN2018/103)
        bool bjet_in_same_hemisphere_as_muon = false;

        //for (int bjet=0; bjet<infriends->nselectedBJets_nominal_medium; bjet++)
        for (int bjet=0; bjet<*(nbjets_pointers[uncmode]); bjet++)
        {
            //Float_t deltaphi_bjet_muon = deltaPhi(infriends->tightRelIso_tightID_Muons_phi[0], infriends->selectedBJets_nominal_medium_phi[bjet]);
            Float_t deltaphi_bjet_muon = deltaPhi(infriends->tightRelIso_tightID_Muons_phi[0], bjets_phi_pointers[uncmode][bjet]);
            bjet_in_same_hemisphere_as_muon = bjet_in_same_hemisphere_as_muon or (deltaphi_bjet_muon < 2);
            if (bjet_in_same_hemisphere_as_muon) break;
        }
        if (!bjet_in_same_hemisphere_as_muon) continue;

        // At least one fat jet away from muon (JME-18-002)
        bool fatjet_away_from_muon = false;
        for (int fjet=0; fjet<infriends->npreselectedHOTVRJets; fjet++)
        {
            Float_t deltaphi_fjet_muon = deltaPhi(infriends->tightRelIso_tightID_Muons_phi[0], infriends->preselectedHOTVRJets_phi[fjet]);
            fatjet_away_from_muon = fatjet_away_from_muon or (deltaphi_fjet_muon > 2);
            if (fatjet_away_from_muon) break;
        }
        if (!fatjet_away_from_muon) continue;

        //printf("Processing event %d\n", ievent);

        Float_t ht = 0.;
        for (int jet=0; jet<*(njets_pointers[uncmode]); jet++) ht += jets_pt_pointers[uncmode][jet];

        Float_t genWeight = isData ? 1 : infriends->genweight/sumgenweight;

        // In case we have jet energy corrections for HOTVR...
        //Float_t fj_1_pt, fj_1_eta, fj_1_phi, fj_1_rawmass, fj_1_sdmass, fj_1_regressed_mass, fj_1_tau21, fj_1_tau32, fj_1_btagcsvv2, fj_1_btagjp, fj_1_deltaR_sj12;
        Float_t met_pt;

        switch (uncmode)
        {
            // This should be changed once we have MET variants...
            case 5:
                met_pt = infriends->MET_pt;
                break;
            case 6:
                met_pt = infriends->MET_pt;
                break;
            default:
                met_pt = infriends->MET_pt;
        }
        
        outevents->run = infriends->run;
        outevents->luminosityBlock = 0;
        outevents->event = 0;
        outevents->genWeight = genWeight;
        outevents->nPSWeight = 0;
        outevents->PSWeight[0] = 0.;
        outevents->PSWeight[1] = 0.;
        outevents->PSWeight[2] = 0.;
        outevents->PSWeight[3] = 0.;
        outevents->LHE_Vpt = 0.;
        outevents->genTtbarId = 0;
        outevents->PV_npvs = infriends->PV_npvs;
        outevents->HLT_Ele27_WPTight_Gsf = true;
        outevents->HLT_Ele32_WPTight_Gsf = true;
        outevents->HLT_Ele35_WPTight_Gsf = true;
        outevents->HLT_Ele32_WPTight_Gsf_L1DoubleEG = true;
        outevents->HLT_IsoMu24 = true;
        outevents->HLT_IsoMu27 = true;
        outevents->HLT_PFHT180 = true;
        outevents->HLT_PFHT250 = true;
        outevents->HLT_PFHT370 = true;
        outevents->HLT_PFHT430 = true;
        outevents->HLT_PFHT510 = true;
        outevents->HLT_PFHT590 = true;
        outevents->HLT_PFHT680 = true;
        outevents->HLT_PFHT780 = true;
        outevents->HLT_PFHT890 = true;
        outevents->HLT_PFHT1050 = true;
        outevents->HLT_PFMET110_PFMHT110_IDTight = true;
        outevents->HLT_PFMET120_PFMHT120_IDTight = true;
        outevents->HLT_PFMET130_PFMHT130_IDTight = true;
        outevents->HLT_PFMET140_PFMHT140_IDTight = true;
        outevents->HLT_PFMET100_PFMHT100_IDTight_CaloBTagCSV_3p1 = true;
        outevents->HLT_PFMET110_PFMHT110_IDTight_CaloBTagCSV_3p1 = true;
        outevents->HLT_PFMET120_PFMHT120_IDTight_CaloBTagCSV_3p1 = true;
        outevents->HLT_PFMET130_PFMHT130_IDTight_CaloBTagCSV_3p1 = true;
        outevents->HLT_PFMET140_PFMHT140_IDTight_CaloBTagCSV_3p1 = true;
        outevents->HLT_PFMET120_PFMHT120_IDTight_PFHT60 = true;
        outevents->HLT_PFMETNoMu120_PFMHTNoMu120_IDTight_PFHT60 = true;
        outevents->HLT_PFMETTypeOne120_PFMHT120_IDTight_PFHT60 = true;
        outevents->HLT_PFMETTypeOne110_PFMHT110_IDTight = true;
        outevents->HLT_PFMETTypeOne120_PFMHT120_IDTight = true;
        outevents->HLT_PFMETTypeOne130_PFMHT130_IDTight = true;
        outevents->HLT_PFMETTypeOne140_PFMHT140_IDTight = true;
        outevents->HLT_PFMETNoMu110_PFMHTNoMu110_IDTight = true;
        outevents->HLT_PFMETNoMu120_PFMHTNoMu120_IDTight = true;
        outevents->HLT_PFMETNoMu130_PFMHTNoMu130_IDTight = true;
        outevents->HLT_PFMETNoMu140_PFMHTNoMu140_IDTight = true;
        outevents->HLT_PFHT350 = true;
        outevents->HLT_PFMET100_PFMHT100_IDTight_PFHT60 = true;
        outevents->HLT_PFMETNoMu100_PFMHTNoMu100_IDTight_PFHT60 = true;
        outevents->HLT_PFMETTypeOne100_PFMHT100_IDTight_PFHT60 = true;
        outevents->year = 2017;
        outevents->lumiwgt = 1.;
        outevents->jetR = 0.0;
        outevents->passmetfilters = infriends->MET_filter;
        outevents->l1PreFiringWeight = 1.;
        outevents->l1PreFiringWeightUp = 1.;
        outevents->l1PreFiringWeightDown = 1.;
        outevents->nlep = infriends->ntightRelIso_tightID_Muons + infriends->ntight_cutBased_Electrons;
        outevents->ht = ht;
        outevents->met = met_pt;
        outevents->metphi = infriends->MET_phi;
        outevents->fj_1_is_qualified = true;
        outevents->fj_1_pt = infriends->preselectedHOTVRJets_pt[0];
        outevents->fj_1_eta = infriends->preselectedHOTVRJets_eta[0];
        outevents->fj_1_phi = infriends->preselectedHOTVRJets_phi[0];
        outevents->fj_1_rawmass = infriends->preselectedHOTVRJets_mass[0];
        outevents->fj_1_sdmass = infriends->preselectedHOTVRJets_mass[0];
        outevents->fj_1_regressed_mass = infriends->preselectedHOTVRJets_mass[0];
        outevents->fj_1_tau21 = infriends->preselectedHOTVRJets_tau2_over_tau1[0];
        outevents->fj_1_tau32 = infriends->preselectedHOTVRJets_tau3_over_tau2[0];
        outevents->fj_1_btagcsvv2 = infriends->preselectedHOTVRJets_btagDeepB[0];
        outevents->fj_1_btagjp = infriends->preselectedHOTVRJets_btagDeepB[0];
        outevents->fj_1_deltaR_sj12 = 0.;
        outevents->fj_1_sj1_pt =      (infriends->npreselectedHOTVRSubJets >= 1) ? infriends->preselectedHOTVRSubJets_pt[1]   : 0.;
        outevents->fj_1_sj1_eta =     (infriends->npreselectedHOTVRSubJets >= 1) ? infriends->preselectedHOTVRSubJets_eta[1]  : 0.;
        outevents->fj_1_sj1_phi =     (infriends->npreselectedHOTVRSubJets >= 1) ? infriends->preselectedHOTVRSubJets_phi[1]  : 0.;
        outevents->fj_1_sj1_rawmass = (infriends->npreselectedHOTVRSubJets >= 1) ? infriends->preselectedHOTVRSubJets_mass[1] : 0.;
        outevents->fj_1_sj1_btagdeepcsv = 0.;
        outevents->fj_1_sj2_pt =      (infriends->npreselectedHOTVRSubJets >= 2) ? infriends->preselectedHOTVRSubJets_pt[1]   : 0.;
        outevents->fj_1_sj2_eta =     (infriends->npreselectedHOTVRSubJets >= 2) ? infriends->preselectedHOTVRSubJets_eta[1]  : 0.;;
        outevents->fj_1_sj2_phi =     (infriends->npreselectedHOTVRSubJets >= 2) ? infriends->preselectedHOTVRSubJets_phi[1]  : 0.;;
        outevents->fj_1_sj2_rawmass = (infriends->npreselectedHOTVRSubJets >= 2) ? infriends->preselectedHOTVRSubJets_mass[1] : 0.;;
        outevents->fj_1_sj2_btagdeepcsv = 0.;
        outevents->fj_1_DeepAK8_TvsQCD = 0.;
        outevents->fj_1_DeepAK8_WvsQCD = 0.;
        outevents->fj_1_DeepAK8_ZvsQCD = 0.;
        outevents->fj_1_DeepAK8_ZHbbvsQCD = 0.;
        outevents->fj_1_DeepAK8MD_TvsQCD = 0.;
        outevents->fj_1_DeepAK8MD_WvsQCD = 0.;
        outevents->fj_1_DeepAK8MD_ZvsQCD = 0.;
        outevents->fj_1_DeepAK8MD_ZHbbvsQCD = 0.;
        outevents->fj_1_DeepAK8MD_ZHccvsQCD = 0.;
        outevents->fj_1_DeepAK8MD_bbVsLight = 0.;
        outevents->fj_1_DeepAK8MD_bbVsTop = 0.;
        outevents->fj_1_ParticleNet_TvsQCD = 0.;
        outevents->fj_1_ParticleNet_WvsQCD = 0.;
        outevents->fj_1_ParticleNet_ZvsQCD = 0.;
        outevents->fj_1_ParticleNetMD_Xbb = 0.;
        outevents->fj_1_ParticleNetMD_Xcc = 0.;
        outevents->fj_1_ParticleNetMD_Xqq = 0.;
        outevents->fj_1_ParticleNetMD_QCD = 0.;
        outevents->fj_1_ParticleNetMD_XbbVsQCD = 0.;
        outevents->fj_1_ParticleNetMD_XccVsQCD = 0.;
        outevents->fj_1_ParticleNetMD_XccOrXqqVsQCD = 0.;
        outevents->fj_1_nbhadrons = 0;
        outevents->fj_1_nchadrons = 0;
        outevents->fj_1_partonflavour = 0;
        outevents->fj_1_sj1_nbhadrons = 0;
        outevents->fj_1_sj1_nchadrons = 0;
        outevents->fj_1_sj1_partonflavour = 0;
        outevents->fj_1_sj2_nbhadrons = 0;
        outevents->fj_1_sj2_nchadrons = 0;
        outevents->fj_1_sj2_partonflavour = 0;
        outevents->fj_1_dr_H = 0.;
        outevents->fj_1_dr_H_daus = 0.;
        outevents->fj_1_H_pt = 0.;
        outevents->fj_1_H_decay = 0;
        outevents->fj_1_dr_Z = 0.;
        outevents->fj_1_dr_Z_daus = 0.;
        outevents->fj_1_Z_pt = 0.;
        outevents->fj_1_Z_decay = 0;
        outevents->fj_1_dr_W = 0.;
        outevents->fj_1_dr_W_daus = 0.;
        outevents->fj_1_W_pt = 0.;
        outevents->fj_1_W_decay = 0;
        outevents->fj_1_dr_T = 0.;
        outevents->fj_1_dr_T_b = 0.;
        outevents->fj_1_dr_T_Wq_max = 0.;
        outevents->fj_1_dr_T_Wq_min = 0.;
        outevents->fj_1_T_Wq_max_pdgId = 0;
        outevents->fj_1_T_Wq_min_pdgId = 0;
        outevents->fj_1_T_pt = 0.;
        outevents->passMuTrig = infriends->SingleMu_Trigger_flag;
        outevents->muon_pt = infriends->tightRelIso_tightID_Muons_pt[0];
        outevents->muon_eta = infriends->tightRelIso_tightID_Muons_eta[0];
        outevents->muon_miniIso = infriends->tightRelIso_tightID_Muons_miniPFRelIso_all[0];
        outevents->leptonicW_pt = infriends->Leptonic_W_pt;
        outevents->puWeight = infriends->puWeight;
        outevents->puWeightUp = infriends->puWeightUp;
        outevents->puWeightDown = infriends->puWeightDown;
        outevents->topptWeight = infriends->TopPtWeight;

        outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->preselectedHOTVRJets_has_hadronicTop_topIsInside[0];
        outevents->preselectedHOTVRJets_has_hadronicW_topIsInside = infriends->preselectedHOTVRJets_has_hadronicW_fromTop_topIsInside[0];
        outevents->preselectedHOTVRJets_scoreBDT = infriends->preselectedHOTVRJets_scoreBDT[0];

        outevents->FillTree();
    }

    printf("Selected %lld events out of %lld events.\n", outevents->fChain->GetEntries(), intree->GetEntries());
    //outevents->fChain->Show(outevents->fChain->GetEntries()-1);

    outevents->WriteFile();
    outevents->outfile->Close();
}