import os, sys, shutil
import time

from plotting_utils import plot_variable_distributions, draw_loss, draw_roc, draw_score, draw_importance

import numpy as np
import pandas as pd

import sklearn
import sklearn.ensemble
import sklearn.metrics 
import sklearn.externals
import sklearn.model_selection

from argparse import ArgumentParser

from pathlib import Path
from typing import Optional, List

import xgboost
from xgboost import plot_importance
import gc

import matplotlib
import matplotlib.pyplot as plt

matplotlib.use('Agg')


inputs = [
    'fractional_subjet_pt', 'min_pairwise_subjets_mass', 'mass', 
    'nsubjets', 'tau3_over_tau2',  'pt'
] #'tau2_over_tau1',

feautures_distribution_plots = True
resampling = True

binning = np.arange(0., 10000, 20) #np.logspace(0,4,100)

pT_ranges = [[200, 400], [400, 800], [800]]#['200_To_400', '400_To_800', 'from_800']

computational_time = {
    'training': 0., 'inference_train': 0., 'inference_test': 0.
}

def cut_based_tagger_ROC(features, label):
    frac_pt_thr, min_mass_pair_thr, mass_thr, nsubj_thr, tau3VStau2_thr = 0.8, 50, [140.,220.], 3, 0.56

    true_positive_array = features[
        (features[:,0]<frac_pt_thr) & (features[:,1]>min_mass_pair_thr)  
        & (features[:,2]>min(mass_thr)) & (features[:,2]<max(mass_thr)) 
        & (features[:,3]>=nsubj_thr) & (features[:,4]<tau3VStau2_thr) & (label==1)
    ]
    all_true = label[label==1]

    false_positive_array = features[
        (features[:,0]<frac_pt_thr) & (features[:,1]>min_mass_pair_thr) 
        & (features[:,2]>min(mass_thr)) & (features[:,2]<max(mass_thr)) 
        & (features[:,3]>=nsubj_thr) & (features[:,4]<tau3VStau2_thr) & (label==0)
    ]
    all_false = label[label==0]

    return true_positive_array.shape[0]/all_true.shape[0], false_positive_array.shape[0]/all_false.shape[0]


def main(
        input_dir,
        output_dir,
        year,
        n_trees,
        learning_rate,
        max_depth,
        min_child_weight):

    # Ensure input/output dirs are Path instances.
    input_dir = Path(input_dir)
    output_dir = output_dir / str(year)
    output_dir = Path(output_dir)

    output_dir = output_dir / 'trainBDT_outputs_no_mass_in_training'
    output_dir.mkdir(parents=True, exist_ok=True)
    output_dir.chmod(0o777)

    if resampling: fpath = output_dir / 'trainData_resampled.npz'
    else: fpath = output_dir / 'trainData.npz'
    
    if os.path.exists(fpath) == 0:    
        print('Training dataset does not exist...Run "generating_samples_training.py"')

    else: 
        fpath = ''
        if resampling: fpath = output_dir / 'trainData_resampled.npz'
        else: fpath = output_dir / 'trainData.npz'

        loaded = np.load(fpath)
        features_array = loaded['features']
        label_array = loaded['labels']

    indices = np.arange(features_array.shape[0])
    train_idx, test_idx, trainLabel, testLabel = sklearn.model_selection.train_test_split(
    indices, label_array, test_size=0.2, shuffle=True, random_state=24155
    )

    # removing the last dimension --> pt
    features_array_no_pt = features_array[..., :len(inputs)-1]
    print(features_array_no_pt)
    # features_array_no_pt = features_array[:, [0, 1, 3, 4]] # and no mass
    trainFeatures = features_array_no_pt[train_idx]
    testFeatures = features_array_no_pt[test_idx]

    train_pt = features_array[train_idx, ..., -1]
    test_pt = features_array[test_idx, ..., -1]

    # trainFeatures,testFeatures,trainLabel,testLabel, = sklearn.model_selection.train_test_split(
    #     #features_array[pt_range], label_array[pt_range], test_size=0.2, shuffle=True, random_state=24155
    #     features_array_no_pt, label_array, test_size=0.2, shuffle=True, random_state=24155
    # )

    print(f"\nTotal samples {features_array_no_pt.shape}")
    print(f"Split samples -> train: {trainFeatures.shape}, test: {testFeatures.shape}")
    
    # use test=train for testing
    # testFeatures = trainFeatures
    # testLabel = trainLabel

    # ensure a one-dimensional array (*, )
    trainLabel = trainLabel.ravel()
    testLabel = testLabel.ravel()

    #plotting the features for sgn/bkg 
    if feautures_distribution_plots:
        print(f"\nPlotting the features for sgn/bkg {features_array.shape}")
        features_plot_dir = output_dir / 'features_distributions_total'
        features_plot_dir.mkdir(parents=True, exist_ok=True)
        plot_variable_distributions(features_array, label_array, features_plot_dir, [input for input in inputs if input != 'pt'], year=year)

        features_plot_dir = output_dir / 'features_distributions_train'
        features_plot_dir.mkdir(parents=True, exist_ok=True)
        plot_variable_distributions(trainFeatures, trainLabel, features_plot_dir, [input for input in inputs if input != 'pt'], year=year)

        features_plot_dir = output_dir / 'features_distributions_test'
        features_plot_dir.mkdir(parents=True, exist_ok=True)
        plot_variable_distributions(testFeatures, testLabel, features_plot_dir, [input for input in inputs if input != 'pt'], year=year)

    del features_array, label_array, features_array_no_pt
    gc.collect()
    # sys.exit()
    #########


    start_time = time.time()
    ######### XGBOOST 
    xgboost_params = {
    'n_estimators': n_trees, 'learning_rate': learning_rate, 'max_depth': max_depth, 'min_child_weight': min_child_weight
    }
    print(f"\nXGBOOST PARAMETERS: {xgboost_params}")

    bdt = xgboost.XGBClassifier(
    #loss='deviance', #=for logistic regression
    n_estimators=xgboost_params['n_estimators'], 
    learning_rate=xgboost_params['learning_rate'],
    max_depth=xgboost_params['max_depth'], 
    min_child_weight=xgboost_params['min_child_weight'],
    # reg_lambda = 4,
    use_label_encoder = False,
    verbose=2,
    objective='binary:logistic',
    n_jobs=1,
    subsample=0.75, # default value... it might need to be changed
    importance_type='gain',
    booster='gbtree',
    tree_method='approx', 
    )

    bdt.fit(
        trainFeatures, trainLabel, 
        eval_metric=["error", "logloss"], 
        eval_set=[(trainFeatures, trainLabel), (testFeatures, testLabel)], 
        verbose=False
    )
    end_time = time.time()
    elapsed_time = end_time - start_time
    computational_time['training'] = elapsed_time
    # print(f"Elapsed time: {elapsed_time} seconds")

    ################################
    sub_dir = output_dir / f"plots_and_stats"
    sub_dir.mkdir(parents=True, exist_ok=True)
    sub_dir.chmod(0o777)
    fpath = sub_dir / f"hadronicTopVSQCD_bdt_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.bin"
    bdt._Booster.save_model(str(fpath))

    results = bdt.evals_result()

    trainPred = bdt.predict_proba(trainFeatures)[:,1]
    testPred = bdt.predict_proba(testFeatures)[:,1]
    fprTrain, tprTrain, thresTrain = sklearn.metrics.roc_curve(trainLabel, trainPred)
    fprTest, tprTest, thresTest = sklearn.metrics.roc_curve(testLabel, testPred)
    rates = {
        'false_positive_train': fprTrain, 'true_positive_train': tprTrain,
        'false_positive_test': fprTest, 'true_positive_test': tprTest,
    }

    predTrainBkg = trainPred[trainLabel<0.5]
    predTrainSig = trainPred[trainLabel>0.5]
    predTestBkg = testPred[testLabel<0.5]
    predTestSig = testPred[testLabel>0.5]
    predictions = {
        'train_bkg': predTrainBkg, 'train_sgn': predTrainSig,
        'test_bkg': predTestBkg, 'test_sgn': predTestSig,
    }

    aucTrain, aucTest = sklearn.metrics.auc(fprTrain, tprTrain), sklearn.metrics.auc(fprTest, tprTest)
    accTrain = sklearn.metrics.accuracy_score(trainLabel, 1.*(trainPred>0.5), normalize=True)
    accTest = sklearn.metrics.accuracy_score(testLabel, 1.*(testPred>0.5), normalize=True)
    print(f"\nAUC: {aucTrain} {aucTest}")
    print(f"Accuracy: {accTrain} {accTest}\n")

    ######### Cut-based top tagger: https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#Working_point_and_scale_factors
    cut_based_efficiencies = cut_based_tagger_ROC(testFeatures, testLabel)
    #########
    for bkgFrac in [0.3, 0.2, 0.1, 0.05, round(cut_based_efficiencies[1], 4), 0.01]:
        bkgIdx = np.argmin(np.abs(fprTest-bkgFrac))
        print(f"Bkg {100.*bkgFrac}% -> Sigeff = {100.*tprTest[bkgIdx]}, Thres = {thresTest[bkgIdx]}")

    fpath = output_dir / f"hadronicTopVSQCD_stat_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.csv"
    
    stats = {
        'train_last_logloss': [results['validation_0']['logloss'][-1]], 'test_last_logloss': [results['validation_1']['logloss'][-1]],
        'train_AUC': [aucTrain], 'test_AUC': [aucTest], 'train_accuracy': [100.*accTrain], 'test_accuracy': [100.*accTest],
        'execution_time': [elapsed_time]
    }
    df_stats = pd.DataFrame(stats)
    df_stats.to_csv(fpath, index=False)
    print(f"Saving stats file: {fpath}")

    fpath = sub_dir / f"hadronicTopVSQCD_lr_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.pdf"
    draw_loss(fpath, results, n_estimators=n_trees, xgboost_params=xgboost_params, year=year)
    fpath = sub_dir / f"hadronicTopVSQCD_lr_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.png"
    draw_loss(fpath, results, n_estimators=n_trees, xgboost_params=xgboost_params, year=year)

    fpath = output_dir / f"hadronicTopVSQCD_roc_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.pdf"
    draw_roc(fpath, rates, cut_based_efficiencies=cut_based_efficiencies, xgboost_params=xgboost_params)
    fpath = output_dir / f"hadronicTopVSQCD_roc_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.png"
    draw_roc(fpath, rates, cut_based_efficiencies=cut_based_efficiencies, xgboost_params=xgboost_params)

    fpath = output_dir / f"hadronicTopVSQCD_dist_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.pdf"
    draw_score(fpath, predictions, xgboost_params=xgboost_params)
    fpath = output_dir / f"hadronicTopVSQCD_dist_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.png"
    draw_score(fpath, predictions, xgboost_params=xgboost_params)
    ################################

    ################################
    # evaluation of the performance in different pT ranges
    testFeatures_pT_ranges, trainFeatures_pT_ranges = {}, {}
    testLabel_pT_ranges, trainLabel_pT_ranges = {}, {}
    for pt_range, pt_label in zip(pT_ranges, ['200_To_400', '400_To_800', 'from_800']):
        print(f"\n#### pT range: {pt_range}")

        if len(pt_range)>1:
            test_jets_skimmed = (test_pt >= pt_range[0]) & (test_pt < pt_range[1])
            train_jets_skimmed = (train_pt >= pt_range[0]) & (train_pt < pt_range[1])
        else: 
            test_jets_skimmed = test_pt >= pt_range[0]
            train_jets_skimmed = train_pt >= pt_range[0]

        testFeatures_pT_ranges[pt_label] = testFeatures[test_jets_skimmed]
        testLabel_pT_ranges[pt_label] = testLabel[test_jets_skimmed]

        trainFeatures_pT_ranges[pt_label] = trainFeatures[train_jets_skimmed]
        trainLabel_pT_ranges[pt_label] = trainLabel[train_jets_skimmed]
        
        print(f"Split samples -> train: {trainFeatures_pT_ranges[pt_label].shape}, test: {testFeatures_pT_ranges[pt_label].shape}")

        # prediction and evaluation 
        trainPred = bdt.predict_proba(trainFeatures_pT_ranges[pt_label])[:, 1]
        testPred = bdt.predict_proba(testFeatures_pT_ranges[pt_label])[:, 1]
        # start_time = time.time()
        # end_time = time.time()
        # computational_time['inference_test'] = end_time - start_time

        fprTrain, tprTrain, thresTrain = sklearn.metrics.roc_curve(trainLabel_pT_ranges[pt_label], trainPred)
        fprTest, tprTest, thresTest = sklearn.metrics.roc_curve(testLabel_pT_ranges[pt_label], testPred)
        rates = {
            'false_positive_train': fprTrain, 'true_positive_train': tprTrain,
            'false_positive_test': fprTest, 'true_positive_test': tprTest,
        }

        predTrainBkg = trainPred[trainLabel_pT_ranges[pt_label]<0.5]
        predTrainSig = trainPred[trainLabel_pT_ranges[pt_label]>0.5]
        predTestBkg = testPred[testLabel_pT_ranges[pt_label]<0.5]
        predTestSig = testPred[testLabel_pT_ranges[pt_label]>0.5]
        predictions = {
            'train_bkg': predTrainBkg, 'train_sgn': predTrainSig,
            'test_bkg': predTestBkg, 'test_sgn': predTestSig,
        }


        aucTrain, aucTest = sklearn.metrics.auc(fprTrain, tprTrain), sklearn.metrics.auc(fprTest, tprTest)
        accTrain = sklearn.metrics.accuracy_score(trainLabel_pT_ranges[pt_label], 1.*(trainPred>0.5), normalize=True)
        accTest = sklearn.metrics.accuracy_score(testLabel_pT_ranges[pt_label], 1.*(testPred>0.5), normalize=True)
        print(f"\nAUC: {aucTrain} {aucTest}")
        print(f"Accuracy: {accTrain} {accTest}\n")


        ######### Cut-based top tagger: https://twiki.cern.ch/twiki/bin/viewauth/CMS/JetTopTagging#Working_point_and_scale_factors
        cut_based_efficiencies = cut_based_tagger_ROC(testFeatures_pT_ranges[pt_label], testLabel_pT_ranges[pt_label])
        #########
        print('\n### Cut-based efficiencies')
        print(f"Signal efficiency: {cut_based_efficiencies[0]}; Background efficiency: {cut_based_efficiencies[1]}")

        sig_eff_at_fixed_bkg_rate = {
            '30.0': 0., '20.0': 0., '10.0': 0., '1.0': 0., 
        }
        for bkgFrac in [0.3, 0.2, 0.1, 0.05, round(cut_based_efficiencies[1], 4), 0.01]:
            bkgIdx = np.argmin(np.abs(fprTest-bkgFrac))
            sig_eff_at_fixed_bkg_rate[str(100.*bkgFrac)] = 100.*tprTest[bkgIdx]
            print(f"Bkg {100.*bkgFrac}% -> Sigeff = {100.*tprTest[bkgIdx]:.3f}, Thres = {thresTest[bkgIdx]:.3f}")

        sub_dir = output_dir / f"plots_and_stats_pT_range_{pt_label}"
        sub_dir.mkdir(parents=True, exist_ok=True)
        sub_dir.chmod(0o777)
        fpath = sub_dir / f"hadronicTopVSQCD_stat_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.csv"
        
        stats = {
            'train_last_logloss': [results['validation_0']['logloss'][-1]], 'test_last_logloss': [results['validation_1']['logloss'][-1]],
            'train_AUC': [aucTrain], 'test_AUC': [aucTest], 'train_accuracy': [100.*accTrain], 'test_accuracy': [100.*accTest], 
            'sig_eff_at_30_bkg_rate': sig_eff_at_fixed_bkg_rate['30.0'], 
            'sig_eff_at_20_bkg_rate': sig_eff_at_fixed_bkg_rate['20.0'], 
            'sig_eff_at_10_bkg_rate': sig_eff_at_fixed_bkg_rate['10.0'],
            'sig_eff_at_5_bkg_rate': sig_eff_at_fixed_bkg_rate['5.0'], 
            'sig_eff_at_1_bkg_rate': sig_eff_at_fixed_bkg_rate['1.0'], 
            'sig_eff_at_cut_based_bkg_rate': sig_eff_at_fixed_bkg_rate[f"{100.*round(cut_based_efficiencies[1], 4)}"],
            'cut_based_eff': 100.*cut_based_efficiencies[0], 'cut_based_fake_bkg_rate':100.*cut_based_efficiencies[1]
        }
        #'training_time': [computational_time['training']], 'inference_train_time': [computational_time['inference_train']],
        #'inference_test_time': [computational_time['inference_test']],

        df_stats = pd.DataFrame(stats)
        df_stats.to_csv(fpath, index=False)
        print(f"Saving stats file: {fpath}")

        fpath = sub_dir / f"hadronicTopVSQCD_roc_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.pdf"
        draw_roc(fpath, rates, cut_based_efficiencies=cut_based_efficiencies, xgboost_params=xgboost_params, pt_range=pt_range, year=year, pt_range_label=pt_label)

        fpath = sub_dir / f"hadronicTopVSQCD_dist_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.pdf"
        draw_score(fpath, predictions, xgboost_params=xgboost_params, pt_range=pt_range)

        fpath = sub_dir / f"hadronicTopVSQCD_roc_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.png"
        draw_roc(fpath, rates, cut_based_efficiencies=cut_based_efficiencies, xgboost_params=xgboost_params, pt_range=pt_range, year=year, pt_range_label=pt_label)

        fpath = sub_dir / f"hadronicTopVSQCD_dist_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.png"
        draw_score(fpath, predictions, xgboost_params=xgboost_params, pt_range=pt_range)

    importances = bdt.feature_importances_ 
    for importance, input in zip(importances, [input for input in inputs if input != 'pt']):
        print(f"Importance of {input}: {importance:.4f}")
    sub_dir = output_dir / f"plots_and_stats"
    fpath = sub_dir / f"hadronicTopVSQCD_importance_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.pdf"
    
    draw_importance(fpath, importances, xgboost_params=xgboost_params, year=year)

    fpath = sub_dir / f"hadronicTopVSQCD_importance_nTrees{xgboost_params['n_estimators']}_maxDepth{xgboost_params['max_depth']}_learningRate{xgboost_params['learning_rate']}_minChildWeight{xgboost_params['min_child_weight']}.png"
    
    draw_importance(fpath, importances, xgboost_params=xgboost_params, year=year)


#################################################

def parse_args(argv: Optional[List[str]] = None):
    parser = ArgumentParser()

    parser.add_argument('--input_dir', type=Path, required=True,
        help="Input directory, where to find the h5 files")
    parser.add_argument('--output_dir', type=Path,
        help="Top-level output directory. "
             "Will be created if not existing. "
             "If not provided, takes the input dir.")
    parser.add_argument('--year', type=str, required=True,
        help='Year of the samples.')
    # xgboost parameters
    parser.add_argument('--n_trees', type=int, default=2,
        help='Number of estimators.')
    parser.add_argument('--learning_rate', type=float, default=.03,
        help='Learning Rate.')
    parser.add_argument('--max_depth', type=int, default=5,
        help='Maximum Depth.')
    parser.add_argument('--min_child_weight', type=float, default=.5,
        help='Minimum child weight.')

    args = parser.parse_args(argv)

    # If output directory is not provided, assume we want the output to be
    # alongside the input directory.
    if args.output_dir is None:
        args.output_dir = args.input_dir

    # Return the options as a dictionary.
    return vars(args)


if __name__ == "__main__":
    main(**parse_args())
