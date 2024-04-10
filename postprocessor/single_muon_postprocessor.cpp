#include <stdio.h>
#include <stdlib.h>
#include "Friends.C"
#include "Friends_data.C"
#include "Events.C"
#include <TMath.h>
#include <glob.h>
#include <TError.h>

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
    gErrorIgnoreLevel = kFatal;
    //enum class Unctype = { nominal, jesup, jesdown, jerup, jerdown, metdown, metup };

    Float_t genEventCount = 0;
    Float_t sumgenweight = 0;
    Float_t sumgenweight2 = 0;
    Float_t LHEScaleWeightNorm[9];
    int file_count = 0;

    TChain *intree = new TChain("Friends");

    if (!isData)
    {
        TH1D *hist_genweight_lhe[9];
        //for (int i=0; i<9; i++) hist_genweight_lhe[i] = new TH1D("hist_genweight_lhe_" + str(i), "hist_genweight_lhe_" + str(i), 1, 0, 10);
        for (int i=0; i<9; i++) LHEScaleWeightNorm[i] = 0;
        for (const auto &filename : glob(infilename.Data())) 
        {
            //chain->Add(filename.c_str());
            TFile *infile = new TFile(filename.c_str());
            if (infile->IsZombie()) 
            {
                printf("File %s is zombie, skipping arrrr.\n", filename.c_str());
                continue;
            }
            if (!infile->Get("Friends"))
            {
                printf("File %s does not contain Friends tree, skipping.\n", filename.c_str());
                continue;
            }
            if (!infile->Get("sumGenWeights"))
            {
                printf("File %s does not contain sumGenWeights, skipping.\n", filename.c_str());
                continue;
            }
            file_count += 1;
            //TTree *intree = infile->Get("Friends");
            //if (!infile->Get("sumGenWeights")) break;

            TParameter<float> *genEventCount_obj = (TParameter<float>*) infile->Get("genEventCount");
            TParameter<float> *sumgenweight_obj  = (TParameter<float>*) infile->Get("sumGenWeights");
            TParameter<float> *sumgenweight2_obj = (TParameter<float>*) infile->Get("sumGenWeights2");

            Float_t genEventCount_thisfile = genEventCount_obj->GetVal();
            genEventCount += genEventCount_thisfile;
            sumgenweight  += sumgenweight_obj->GetVal();
            sumgenweight2 += sumgenweight2_obj->GetVal();

            LHEScaleWeightNorm[0] += ((TParameter<float>*) infile->Get("LHEScaleSumw_0"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[1] += ((TParameter<float>*) infile->Get("LHEScaleSumw_1"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[2] += ((TParameter<float>*) infile->Get("LHEScaleSumw_2"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[3] += ((TParameter<float>*) infile->Get("LHEScaleSumw_3"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[4] += ((TParameter<float>*) infile->Get("LHEScaleSumw_4"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[5] += ((TParameter<float>*) infile->Get("LHEScaleSumw_5"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[6] += ((TParameter<float>*) infile->Get("LHEScaleSumw_6"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[7] += ((TParameter<float>*) infile->Get("LHEScaleSumw_7"))->GetVal() * genEventCount_thisfile;
            LHEScaleWeightNorm[8] += ((TParameter<float>*) infile->Get("LHEScaleSumw_8"))->GetVal() * genEventCount_thisfile;
            //for (int i=0; i<9; i++) intree->Project("hist_genweight_lhe_" + to_string(i), '1.0', 'LHEScaleSumw[%d]*genEventSumw')
            
            infile->Close();
            intree->Add(filename.c_str());
        }
        printf("Walked through %d files.\n", file_count);
        printf("sumgenweight = %f\n", sumgenweight);
        for (int i=0; i<9; i++) LHEScaleWeightNorm[i] = LHEScaleWeightNorm[i]/genEventCount;
    }
    else 
    {
        printf("Data mode activated. No files walked for sumGenWeights.\n");
        for (int i=0; i<9; i++) LHEScaleWeightNorm[i] = 1;
        intree->Add(infilename);
    }

    if (isData && (uncmode!=0))
    {
        printf("Uncertainties are not supported while isData is true.\n");
        printf("uncmode = %d\n", uncmode);
        return;
    }

    //TFile *infile = new TFile(infilename);
    //TTree *intree = (TTree*) infile->Get("Friends");

    printf("Found %lld events.\n", intree->GetEntries());

    //Friends *infriends_MC;
    //Friends_data *infriends_data;
    //
    //if (isData) *infriends_data = new Friends_data(intree);
    //else *infriends_MC = new Friends(intree);
    //auto infriends = isData ? infriends_data : infriends_MC;

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
        
    Int_t* nhotvr_pointers[] = {
        &(infriends->nselectedHOTVRJets_nominal),
        &(infriends->nselectedHOTVRJets_jesTotalUp),
        &(infriends->nselectedHOTVRJets_jesTotalDown),
        &(infriends->nselectedHOTVRJets_jerUp),
        &(infriends->nselectedHOTVRJets_jerDown),
        &(infriends->nselectedHOTVRJets_nominal),
        &(infriends->nselectedHOTVRJets_nominal)
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

    Float_t* jets_pt_pointers[] = {
        (infriends->selectedJets_nominal_pt),
        (infriends->selectedJets_jesTotalUp_pt),
        (infriends->selectedJets_jesTotalDown_pt),
        (infriends->selectedJets_jerUp_pt),
        (infriends->selectedJets_jerDown_pt),
        (infriends->selectedJets_nominal_pt),
        (infriends->selectedJets_nominal_pt)
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
    
    Float_t* hotvrjets_pt_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_pt),
        (infriends->selectedHOTVRJets_jesTotalUp_pt),
        (infriends->selectedHOTVRJets_jesTotalDown_pt),
        (infriends->selectedHOTVRJets_jerUp_pt),
        (infriends->selectedHOTVRJets_jerDown_pt),
        (infriends->selectedHOTVRJets_nominal_pt),
        (infriends->selectedHOTVRJets_nominal_pt)
    };
    
    Float_t* hotvrjets_eta_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_eta),
        (infriends->selectedHOTVRJets_jesTotalUp_eta),
        (infriends->selectedHOTVRJets_jesTotalDown_eta),
        (infriends->selectedHOTVRJets_jerUp_eta),
        (infriends->selectedHOTVRJets_jerDown_eta),
        (infriends->selectedHOTVRJets_nominal_eta),
        (infriends->selectedHOTVRJets_nominal_eta)
    };
    
    Float_t* hotvrjets_phi_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_phi),
        (infriends->selectedHOTVRJets_jesTotalUp_phi),
        (infriends->selectedHOTVRJets_jesTotalDown_phi),
        (infriends->selectedHOTVRJets_jerUp_phi),
        (infriends->selectedHOTVRJets_jerDown_phi),
        (infriends->selectedHOTVRJets_nominal_phi),
        (infriends->selectedHOTVRJets_nominal_phi)
    };
    
    Float_t* hotvrjets_mass_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_mass),
        (infriends->selectedHOTVRJets_jesTotalUp_mass),
        (infriends->selectedHOTVRJets_jesTotalDown_mass),
        (infriends->selectedHOTVRJets_jerUp_mass),
        (infriends->selectedHOTVRJets_jerDown_mass),
        (infriends->selectedHOTVRJets_nominal_mass),
        (infriends->selectedHOTVRJets_nominal_mass)
    };
    
    Float_t* hotvrjets_tau1_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_tau1),
        (infriends->selectedHOTVRJets_jesTotalUp_tau1),
        (infriends->selectedHOTVRJets_jesTotalDown_tau1),
        (infriends->selectedHOTVRJets_jerUp_tau1),
        (infriends->selectedHOTVRJets_jerDown_tau1),
        (infriends->selectedHOTVRJets_nominal_tau1),
        (infriends->selectedHOTVRJets_nominal_tau1)
    };

    Float_t* hotvrjets_tau2_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_tau2),
        (infriends->selectedHOTVRJets_jesTotalUp_tau2),
        (infriends->selectedHOTVRJets_jesTotalDown_tau2),
        (infriends->selectedHOTVRJets_jerUp_tau2),
        (infriends->selectedHOTVRJets_jerDown_tau2),
        (infriends->selectedHOTVRJets_nominal_tau2),
        (infriends->selectedHOTVRJets_nominal_tau2)
    };

    Float_t* hotvrjets_tau3_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_tau3),
        (infriends->selectedHOTVRJets_jesTotalUp_tau3),
        (infriends->selectedHOTVRJets_jesTotalDown_tau3),
        (infriends->selectedHOTVRJets_jerUp_tau3),
        (infriends->selectedHOTVRJets_jerDown_tau3),
        (infriends->selectedHOTVRJets_nominal_tau3),
        (infriends->selectedHOTVRJets_nominal_tau3)
    };

    Float_t* hotvrjets_btagDeepFlavB_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_btagDeepFlavB),
        (infriends->selectedHOTVRJets_jesTotalUp_btagDeepFlavB),
        (infriends->selectedHOTVRJets_jesTotalDown_btagDeepFlavB),
        (infriends->selectedHOTVRJets_jerUp_btagDeepFlavB),
        (infriends->selectedHOTVRJets_jerDown_btagDeepFlavB),
        (infriends->selectedHOTVRJets_nominal_btagDeepFlavB),
        (infriends->selectedHOTVRJets_nominal_btagDeepFlavB)
    };

    Int_t* hotvrjets_nsubjets_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_nsubjets),
        (infriends->selectedHOTVRJets_jesTotalUp_nsubjets),
        (infriends->selectedHOTVRJets_jesTotalDown_nsubjets),
        (infriends->selectedHOTVRJets_jerUp_nsubjets),
        (infriends->selectedHOTVRJets_jerDown_nsubjets),
        (infriends->selectedHOTVRJets_nominal_nsubjets),
        (infriends->selectedHOTVRJets_nominal_nsubjets)
    };

    Float_t* hotvrjets_subJetIdx1_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_subJetIdx1),
        (infriends->selectedHOTVRJets_jesTotalUp_subJetIdx1),
        (infriends->selectedHOTVRJets_jesTotalDown_subJetIdx1),
        (infriends->selectedHOTVRJets_jerUp_subJetIdx1),
        (infriends->selectedHOTVRJets_jerDown_subJetIdx1),
        (infriends->selectedHOTVRJets_nominal_subJetIdx1),
        (infriends->selectedHOTVRJets_nominal_subJetIdx1)
    };

    Float_t* hotvrjets_subJetIdx2_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_subJetIdx2),
        (infriends->selectedHOTVRJets_jesTotalUp_subJetIdx2),
        (infriends->selectedHOTVRJets_jesTotalDown_subJetIdx2),
        (infriends->selectedHOTVRJets_jerUp_subJetIdx2),
        (infriends->selectedHOTVRJets_jerDown_subJetIdx2),
        (infriends->selectedHOTVRJets_nominal_subJetIdx2),
        (infriends->selectedHOTVRJets_nominal_subJetIdx2)
    };

    Float_t* hotvrjets_subJetIdx3_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_subJetIdx3),
        (infriends->selectedHOTVRJets_jesTotalUp_subJetIdx3),
        (infriends->selectedHOTVRJets_jesTotalDown_subJetIdx3),
        (infriends->selectedHOTVRJets_jerUp_subJetIdx3),
        (infriends->selectedHOTVRJets_jerDown_subJetIdx3),
        (infriends->selectedHOTVRJets_nominal_subJetIdx3),
        (infriends->selectedHOTVRJets_nominal_subJetIdx3)
    };

    Float_t* hotvrjets_min_pairwise_subjet_mass_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_min_pairwise_subjets_mass),
        (infriends->selectedHOTVRJets_jesTotalUp_min_pairwise_subjets_mass),
        (infriends->selectedHOTVRJets_jesTotalDown_min_pairwise_subjets_mass),
        (infriends->selectedHOTVRJets_jerUp_min_pairwise_subjets_mass),
        (infriends->selectedHOTVRJets_jerDown_min_pairwise_subjets_mass),
        (infriends->selectedHOTVRJets_nominal_min_pairwise_subjets_mass),
        (infriends->selectedHOTVRJets_nominal_min_pairwise_subjets_mass)
    };

    Float_t* hotvrjets_fractional_subjet_pt[] = {
        (infriends->selectedHOTVRJets_nominal_fractional_subjet_pt),
        (infriends->selectedHOTVRJets_jesTotalUp_fractional_subjet_pt),
        (infriends->selectedHOTVRJets_jesTotalDown_fractional_subjet_pt),
        (infriends->selectedHOTVRJets_jerUp_fractional_subjet_pt),
        (infriends->selectedHOTVRJets_jerDown_fractional_subjet_pt),
        (infriends->selectedHOTVRJets_nominal_fractional_subjet_pt),
        (infriends->selectedHOTVRJets_nominal_fractional_subjet_pt),
    };
    
    Float_t* hotvrjets_tau3_over_tau2_pointers[] = {
        (infriends->selectedHOTVRJets_nominal_tau3_over_tau2),
        (infriends->selectedHOTVRJets_jesTotalUp_tau3_over_tau2),
        (infriends->selectedHOTVRJets_jesTotalDown_tau3_over_tau2),
        (infriends->selectedHOTVRJets_jerUp_tau3_over_tau2),
        (infriends->selectedHOTVRJets_jerDown_tau3_over_tau2),
        (infriends->selectedHOTVRJets_nominal_tau3_over_tau2),
        (infriends->selectedHOTVRJets_nominal_tau3_over_tau2)
    };

    Float_t* subjets_pt_pointers[] = {
        (infriends->selectedHOTVRSubJets_nominal_pt),
        (infriends->selectedHOTVRSubJets_jesTotalUp_pt),
        (infriends->selectedHOTVRSubJets_jesTotalDown_pt),
        (infriends->selectedHOTVRSubJets_jerUp_pt),
        (infriends->selectedHOTVRSubJets_jerDown_pt),
        (infriends->selectedHOTVRSubJets_nominal_pt),
        (infriends->selectedHOTVRSubJets_nominal_pt)
    };
    Float_t* subjets_eta_pointers[] = {
        (infriends->selectedHOTVRSubJets_nominal_eta),
        (infriends->selectedHOTVRSubJets_jesTotalUp_eta),
        (infriends->selectedHOTVRSubJets_jesTotalDown_eta),
        (infriends->selectedHOTVRSubJets_jerUp_eta),
        (infriends->selectedHOTVRSubJets_jerDown_eta),
        (infriends->selectedHOTVRSubJets_nominal_eta),
        (infriends->selectedHOTVRSubJets_nominal_eta)
    };
    Float_t* subjets_phi_pointers[] = {
        (infriends->selectedHOTVRSubJets_nominal_phi),
        (infriends->selectedHOTVRSubJets_jesTotalUp_phi),
        (infriends->selectedHOTVRSubJets_jesTotalDown_phi),
        (infriends->selectedHOTVRSubJets_jerUp_phi),
        (infriends->selectedHOTVRSubJets_jerDown_phi),
        (infriends->selectedHOTVRSubJets_nominal_phi),
        (infriends->selectedHOTVRSubJets_nominal_phi)
    };
    Float_t* subjets_mass_pointers[] = {
        (infriends->selectedHOTVRSubJets_nominal_mass),
        (infriends->selectedHOTVRSubJets_jesTotalUp_mass),
        (infriends->selectedHOTVRSubJets_jesTotalDown_mass),
        (infriends->selectedHOTVRSubJets_jerUp_mass),
        (infriends->selectedHOTVRSubJets_jerDown_mass),
        (infriends->selectedHOTVRSubJets_nominal_mass),
        (infriends->selectedHOTVRSubJets_nominal_mass)
    };
    Float_t* leptonic_w_pt_pointers[] = {
        &(infriends->Leptonic_W_pt_nominal),
        &(infriends->Leptonic_W_pt_jesTotalUp),
        &(infriends->Leptonic_W_pt_jesTotalDown),
        &(infriends->Leptonic_W_pt_jerUp),
        &(infriends->Leptonic_W_pt_jerDown),
        &(infriends->Leptonic_W_pt_nominal),
        &(infriends->Leptonic_W_pt_nominal)
    };

    for (int ievent=0; ievent<intree->GetEntries(); ievent++)
    {
        infriends->GetEntry(ievent);

        // Passes MET filters (AN2017/006)
        if (!infriends->MET_filter) continue;
        // Exactly one muon (JME-18-002)
        if (infriends->ntightRelIso_tightID_Muons != 1) continue;

        // Electron veto (AN2017/006)
        if (infriends->nloose_MVA_Electrons > 0) continue;

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
        if (*leptonic_w_pt_pointers[uncmode] < 250) continue;

        // At least one HOTVR jet
        bool at_least_one_hotvr_jet = false;
        switch (uncmode)
        {
            case 1:
                at_least_one_hotvr_jet = infriends->nselectedHOTVRJets_jesTotalUp > 0;
                break;
            case 2:
                at_least_one_hotvr_jet = infriends->nselectedHOTVRJets_jesTotalDown > 0;
                break;
            case 3:
                at_least_one_hotvr_jet = infriends->nselectedHOTVRJets_jerUp > 0;
                break;
            case 4:
                at_least_one_hotvr_jet = infriends->nselectedHOTVRJets_jerDown > 0;
                break;
            default: at_least_one_hotvr_jet = infriends->nselectedHOTVRJets_nominal > 0;
        }

        //if (infriends->npreselectedHOTVRJets == 0) continue;
        if (!at_least_one_hotvr_jet) continue;
        
        Float_t met_pt, met_phi;
        switch (uncmode)
        {
            case 1:
                met_pt  = infriends->MET_jesTotalUp_pt;
                met_phi = infriends->MET_jesTotalUp_phi;
                break;
            case 2:
                met_pt  = infriends->MET_jesTotalDown_pt;
                met_phi = infriends->MET_jesTotalDown_phi;
                break;
            case 3:
                met_pt  = infriends->MET_jerUp_pt;
                met_phi = infriends->MET_jerUp_phi;
                break;
            case 4:
                met_pt  = infriends->MET_jerDown_pt;
                met_phi = infriends->MET_jerDown_phi;
                break;
            case 5:
                met_pt  = infriends->MET_unclEnUp_pt;
                met_phi = infriends->MET_unclEnUp_phi;
                break;
            case 6:
                met_pt  = infriends->MET_unclEnDown_pt;
                met_phi = infriends->MET_unclEnDown_phi;
                break;
            default:
                met_pt  = infriends->MET_nominal_pt;
                met_phi = infriends->MET_nominal_phi;
        }
        // MET pT >= 50 (JME-18-002)
        if (met_pt < 50) continue;

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
        int num_HOTVRJets = 0;
        switch(uncmode)
        {
            case 1:
                num_HOTVRJets = infriends->nselectedHOTVRJets_jesTotalUp;
                break;
            case 2:
                num_HOTVRJets = infriends->nselectedHOTVRJets_jesTotalDown;
                break;
            case 3:
                num_HOTVRJets = infriends->nselectedHOTVRJets_jerUp;
                break;
            case 4:
                num_HOTVRJets = infriends->nselectedHOTVRJets_jerDown;
                break;
            default: num_HOTVRJets = infriends->nselectedHOTVRJets_nominal;
        }
        for (int fjet=0; fjet<num_HOTVRJets; fjet++)
        {
            //Float_t deltaphi_fjet_muon = deltaPhi(infriends->tightRelIso_tightID_Muons_phi[0], infriends->preselectedHOTVRJets_phi[fjet]);
            Float_t deltaphi_fjet_muon = deltaPhi(infriends->tightRelIso_tightID_Muons_phi[0], hotvrjets_phi_pointers[uncmode][fjet]);
            fatjet_away_from_muon = fatjet_away_from_muon or (deltaphi_fjet_muon > 2);
            if (fatjet_away_from_muon) break;
        }
        if (!fatjet_away_from_muon) continue;

        //printf("Processing event %d\n", ievent);

        Float_t ht = 0.;
        for (int jet=0; jet<*(njets_pointers[uncmode]); jet++) ht += jets_pt_pointers[uncmode][jet];

        Float_t genWeight = isData ? 1 : infriends->genweight/sumgenweight;

        // In case we have jet energy corrections for HOTVR...
        Float_t fj_1_pt, fj_1_eta, fj_1_phi, fj_1_rawmass, fj_1_sdmass, fj_1_regressed_mass, fj_1_tau21, fj_1_tau32, fj_1_btagcsvv2, fj_1_btagjp, fj_1_deltaR_sj12;
        
        outevents->run = infriends->run;
        outevents->luminosityBlock = infriends->luminosityBlock;
        outevents->event = infriends->eventID;
        outevents->genWeight = genWeight;
        outevents->nPSWeight = 4;
        for (int i=0; i<4; i++) outevents->PSWeight[i] = isData ? 1 : infriends->PSWeight[i];
        outevents->LHE_Vpt = 0.;
        for (int i=0; i<9; i++)
        {
            outevents->LHEScaleWeight[i] = infriends->LHEScaleWeight[i];
            outevents->LHEScaleWeightNorm[i] = LHEScaleWeightNorm[i];
        }
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
        outevents->nlep = infriends->ntightRelIso_tightID_Muons;
        outevents->ht = ht;
        outevents->met = met_pt;
        outevents->metphi = met_phi;

        if (*(nhotvr_pointers[uncmode]) >= 1)
        {
            outevents->fj_1_is_qualified = true;
            outevents->fj_1_pt = hotvrjets_pt_pointers[uncmode][0];
            outevents->fj_1_eta = hotvrjets_eta_pointers[uncmode][0];
            outevents->fj_1_phi = hotvrjets_phi_pointers[uncmode][0];
            outevents->fj_1_rawmass = hotvrjets_mass_pointers[uncmode][0];
            outevents->fj_1_sdmass = hotvrjets_mass_pointers[uncmode][0];
            outevents->fj_1_regressed_mass = hotvrjets_mass_pointers[uncmode][0];
            outevents->fj_1_tau21 = hotvrjets_tau1_pointers[uncmode][0] != 0 ? hotvrjets_tau2_pointers[uncmode][0]/hotvrjets_tau1_pointers[uncmode][0] : -1;
            outevents->fj_1_tau32 = hotvrjets_tau2_pointers[uncmode][0] != 0 ? hotvrjets_tau3_pointers[uncmode][0]/hotvrjets_tau2_pointers[uncmode][0] : -1;
            outevents->fj_1_btagcsvv2 = hotvrjets_btagDeepFlavB_pointers[uncmode][0];
            outevents->fj_1_btagjp = hotvrjets_btagDeepFlavB_pointers[uncmode][0];
            outevents->fj_1_deltaR_sj12 = 0.;

            outevents->preselectedHOTVRJets_fractional_subjet_pt = hotvrjets_fractional_subjet_pt[uncmode][0];
            outevents->preselectedHOTVRJets_min_pairwise_subjets_mass = hotvrjets_min_pairwise_subjet_mass_pointers[uncmode][0];
            outevents->preselectedHOTVRJets_mass = hotvrjets_mass_pointers[uncmode][0];
            outevents->preselectedHOTVRJets_nsubjets = hotvrjets_nsubjets_pointers[uncmode][0];
            outevents->preselectedHOTVRJets_tau3_over_tau2 = hotvrjets_tau3_over_tau2_pointers[uncmode][0];

            if (hotvrjets_nsubjets_pointers[uncmode][0] >= 1)
            {
                outevents->fj_1_sj1_pt =      subjets_pt_pointers[uncmode][int(hotvrjets_subJetIdx1_pointers[uncmode][0])];
                outevents->fj_1_sj1_eta =     subjets_eta_pointers[uncmode][int(hotvrjets_subJetIdx1_pointers[uncmode][0])];
                outevents->fj_1_sj1_phi =     subjets_phi_pointers[uncmode][int(hotvrjets_subJetIdx1_pointers[uncmode][0])];
                outevents->fj_1_sj1_rawmass = subjets_mass_pointers[uncmode][int(hotvrjets_subJetIdx1_pointers[uncmode][0])];
            }
            else
            {
                outevents->fj_1_sj1_pt      = 0;
                outevents->fj_1_sj1_eta     = 0;
                outevents->fj_1_sj1_phi     = 0;
                outevents->fj_1_sj1_rawmass = 0;
            }
            outevents->fj_1_sj1_btagdeepcsv = 0.;
            if (hotvrjets_nsubjets_pointers[uncmode][0] >= 2)
            {
                outevents->fj_1_sj2_pt =      subjets_pt_pointers[uncmode][int(hotvrjets_subJetIdx2_pointers[uncmode][0])];
                outevents->fj_1_sj2_eta =     subjets_eta_pointers[uncmode][int(hotvrjets_subJetIdx2_pointers[uncmode][0])];
                outevents->fj_1_sj2_phi =     subjets_phi_pointers[uncmode][int(hotvrjets_subJetIdx2_pointers[uncmode][0])];
                outevents->fj_1_sj2_rawmass = subjets_mass_pointers[uncmode][int(hotvrjets_subJetIdx2_pointers[uncmode][0])];
            }
            else
            {
                outevents->fj_1_sj2_pt =      0;
                outevents->fj_1_sj2_eta =     0;
                outevents->fj_1_sj2_phi =     0;
                outevents->fj_1_sj2_rawmass = 0;
            }
            outevents->fj_1_sj2_btagdeepcsv = 0.;
        }
        else
        {
            outevents->fj_1_is_qualified = false;
            outevents->fj_1_pt  = 0.;
            outevents->fj_1_eta = 0.;
            outevents->fj_1_phi = 0.;
            outevents->fj_1_rawmass = 0.;
            outevents->fj_1_sdmass  = 0.;
            outevents->fj_1_regressed_mass = 0.;
            outevents->fj_1_tau21 = -1;
            outevents->fj_1_tau32 = -1;
            outevents->fj_1_btagcsvv2 = 0.;
            outevents->fj_1_btagjp = 0.;
            outevents->fj_1_deltaR_sj12 = 0.;
            outevents->fj_1_sj1_pt =      0;
            outevents->fj_1_sj1_eta =     0;
            outevents->fj_1_sj1_phi =     0;
            outevents->fj_1_sj1_rawmass = 0;
            outevents->fj_1_sj1_btagdeepcsv = 0.;
            outevents->fj_1_sj2_pt =      0;
            outevents->fj_1_sj2_eta =     0;
            outevents->fj_1_sj2_phi =     0;
            outevents->fj_1_sj2_rawmass = 0;
            outevents->fj_1_sj2_btagdeepcsv = 0.;
        }
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
        outevents->leptonicW_pt = *leptonic_w_pt_pointers[uncmode];
        outevents->puWeight = infriends->puWeight;
        outevents->puWeightUp = infriends->puWeight_up;
        outevents->puWeightDown = infriends->puWeight_down;
        
        if (infriends->fChain->GetListOfBranches()->FindObject("TopPtWeight")) outevents->topptWeight = infriends->TopPtWeight;
        else outevents->topptWeight = 1.;

        //outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->selectedHOTVRJets_nominal_has_hadronicTop_topIsInside[0];
        //outevents->preselectedHOTVRJets_has_hadronicW_topIsInside = infriends->selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside[0];
        //outevents->preselectedHOTVRJets_scoreBDT = infriends->selectedHOTVRJets_nominal_scoreBDT[0]; 
        switch (uncmode)
        {
            case 1:
                outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->selectedHOTVRJets_jesTotalUp_has_hadronicTop_topIsInside[0];
                outevents->preselectedHOTVRJets_has_hadronicW_topIsInside   = infriends->selectedHOTVRJets_jesTotalUp_has_hadronicW_fromTop_topIsInside[0];
                outevents->preselectedHOTVRJets_scoreBDT                    = infriends->selectedHOTVRJets_jesTotalUp_scoreBDT[0];
                break;
            case 2:
                outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->selectedHOTVRJets_jesTotalDown_has_hadronicTop_topIsInside[0];
                outevents->preselectedHOTVRJets_has_hadronicW_topIsInside   = infriends->selectedHOTVRJets_jesTotalDown_has_hadronicW_fromTop_topIsInside[0];
                outevents->preselectedHOTVRJets_scoreBDT                    = infriends->selectedHOTVRJets_jesTotalDown_scoreBDT[0];
                break;
            case 3:
                outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->selectedHOTVRJets_jerUp_has_hadronicTop_topIsInside[0];
                outevents->preselectedHOTVRJets_has_hadronicW_topIsInside   = infriends->selectedHOTVRJets_jerUp_has_hadronicW_fromTop_topIsInside[0];
                outevents->preselectedHOTVRJets_scoreBDT                    = infriends->selectedHOTVRJets_jerUp_scoreBDT[0];
                break;
            case 4:
                outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->selectedHOTVRJets_jerDown_has_hadronicTop_topIsInside[0];
                outevents->preselectedHOTVRJets_has_hadronicW_topIsInside   = infriends->selectedHOTVRJets_jerDown_has_hadronicW_fromTop_topIsInside[0];
                outevents->preselectedHOTVRJets_scoreBDT                    = infriends->selectedHOTVRJets_jerDown_scoreBDT[0];
                break;
            default:
                outevents->preselectedHOTVRJets_has_hadronicTop_topIsInside = infriends->selectedHOTVRJets_nominal_has_hadronicTop_topIsInside[0];
                outevents->preselectedHOTVRJets_has_hadronicW_topIsInside   = infriends->selectedHOTVRJets_nominal_has_hadronicW_fromTop_topIsInside[0];
                outevents->preselectedHOTVRJets_scoreBDT                    = infriends->selectedHOTVRJets_nominal_scoreBDT[0];
                break;
        }

        bool passedHOTVRCut = true;
        passedHOTVRCut = passedHOTVRCut and (hotvrjets_mass_pointers[uncmode][0] > 140) and (hotvrjets_mass_pointers[uncmode][0] < 220);
        passedHOTVRCut = passedHOTVRCut and (hotvrjets_nsubjets_pointers[uncmode][0] >= 3);
        passedHOTVRCut = passedHOTVRCut and (hotvrjets_min_pairwise_subjet_mass_pointers[uncmode][0] > 50);
        passedHOTVRCut = passedHOTVRCut and (hotvrjets_fractional_subjet_pt[uncmode][0] < 0.8);
        passedHOTVRCut = passedHOTVRCut and (hotvrjets_tau3_over_tau2_pointers[uncmode][0] < 0.56);
        outevents->passedHOTVRCut = passedHOTVRCut;

        outevents->FillTree();
    }

    printf("Selected %lld events out of %lld events.\n", outevents->fChain->GetEntries(), intree->GetEntries());
    //outevents->fChain->Show(outevents->fChain->GetEntries()-1);

    outevents->WriteFile();
    outevents->outfile->Close();
}