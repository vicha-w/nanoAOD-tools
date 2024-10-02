import os, sys, shutil
import time, re

import numpy as np
import pandas as pd

from argparse import ArgumentParser

from pathlib import Path
from typing import Optional, List

import matplotlib.pyplot as plt
import seaborn as sns

def parse_name(file):
    info_tokens = {}

    # Regular expression pattern to extract the numbers
    pattern = r"nTrees(\d+)_maxDepth(\d+)_learningRate(\d+\.\d+)_minChildWeight(\d+\.\d+)"    
    match = re.search(pattern, str(file))
    
    if match:
        info_tokens['n_trees'] = int(match.group(1))
        info_tokens['max_depth'] = int(match.group(2))
        info_tokens['learning_rate'] = float(match.group(3))
        info_tokens['min_child_weight'] = float(match.group(4))
    else: 
        print("Parsing failed")

    return info_tokens


def main(
        input_dir,
        output_dir,
        year):

    # Ensure input/output dirs are Path instances.
    input_dir = Path(input_dir)
    output_dir = Path(output_dir)

    fnames = sorted(
        input_dir.glob(f"plots_and_stats_pT_range_200_To_400/*.csv"))  #

    dfs = pd.DataFrame()
    for idx_file, fname in enumerate(fnames):
        info = parse_name(fname)
        
        df = pd.read_csv(fname)
        if df.empty: 
            print(f"File {fname} is empty...")
            sys.exit()

        df['n_trees'] = info['n_trees']
        df['max_depth'] = info['max_depth']
        df['learning_rate'] = info['learning_rate']
        df['min_child_weight'] = info['min_child_weight']

        dfs = dfs.append(df)

    ####### Filter and find max test_AUC for each n_trees value
    # print(dfs)

    n_trees_values = [200, 500, 1000]
    result = []

    print('Filter and find max test_AUC for each n_trees value')
    for n_trees in n_trees_values:
        filtered_df = dfs[dfs['n_trees'] == n_trees]
        max_auc_row = filtered_df[filtered_df['test_AUC'] == filtered_df['test_AUC'].max()].copy()
        result.append(max_auc_row)

    # Concatenate the results into a single DataFrame
    final_result = pd.concat(result, ignore_index=True)
    print(final_result[['test_AUC','n_trees','max_depth','learning_rate','min_child_weight']])
    #######

    ####### Filter and find max signal efficiency at fixed bkg rate for each n_trees value
    print('\nFilter and find max signal efficiency at fixed bkg rate for each n_trees value')
    fake_rate_values = [10, 1] #30.0, 20.0, 10.0, 5.0, 1.0]
    result = []

    for n_trees in n_trees_values:
        for fake_rate in fake_rate_values:
            filtered_df = dfs[(dfs['n_trees'] == n_trees)]
            max_eff_row = filtered_df[filtered_df[f"sig_eff_at_{fake_rate}_bkg_rate"] == filtered_df[f"sig_eff_at_{fake_rate}_bkg_rate"].max()].copy()
            max_eff_row['background_fake_rate'] =  fake_rate
            max_eff_row['signal_efficiency'] =  max_eff_row[f"sig_eff_at_{fake_rate}_bkg_rate"]
            result.append(max_eff_row)

    # Concatenate the results into a single DataFrame
    final_result = pd.concat(result, ignore_index=True)
    print(final_result[['n_trees','max_depth','learning_rate','min_child_weight', 'background_fake_rate', 'signal_efficiency', 'test_AUC']])
    # print(dfs[(dfs['n_trees'] == 1000) & (dfs['learning_rate'] == 0.03) & (dfs['max_depth'] == 3) & (dfs['min_child_weight'] == 1)][['test_AUC','sig_eff_at_10_bkg_rate','sig_eff_at_1_bkg_rate']])
    # print(dfs[(dfs['n_trees'] == 500) & (dfs['learning_rate'] == 0.08) & (dfs['max_depth'] == 3) & (dfs['min_child_weight'] == 1)][['test_AUC','sig_eff_at_10_bkg_rate','sig_eff_at_1_bkg_rate']])
    #######

    ####### highest signal efficiency for same cut-based bkg rate
    print('\nHighest signal efficiency for same cut-based bkg rate')
    result = []
    for n_trees in n_trees_values:
        filtered_df = dfs[dfs['n_trees'] == n_trees]
        max_auc_row = filtered_df[filtered_df['sig_eff_at_cut_based_bkg_rate'] == filtered_df['sig_eff_at_cut_based_bkg_rate'].max()].copy()
        result.append(max_auc_row)

    # Concatenate the results into a single DataFrame
    final_result = pd.concat(result, ignore_index=True)
    print(final_result[['n_trees','max_depth','learning_rate','min_child_weight','sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])
    print("\nOther paramters results: ")
    print(dfs[(dfs['n_trees'] == 500) & (dfs['learning_rate'] == 0.03) & (dfs['max_depth'] == 5) & (dfs['min_child_weight'] == 0.5)][['sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])
    print(dfs[(dfs['n_trees'] == 500) & (dfs['learning_rate'] == 0.05) & (dfs['max_depth'] == 5) & (dfs['min_child_weight'] == 0.5)][['sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])
    print(dfs[(dfs['n_trees'] == 500) & (dfs['learning_rate'] == 0.08) & (dfs['max_depth'] == 5) & (dfs['min_child_weight'] == 0.5)][['sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])
    print('\n')
    print(dfs[(dfs['n_trees'] == 1000) & (dfs['learning_rate'] == 0.03) & (dfs['max_depth'] == 5) & (dfs['min_child_weight'] == 0.5)][['sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])
    print(dfs[(dfs['n_trees'] == 1000) & (dfs['learning_rate'] == 0.05) & (dfs['max_depth'] == 5) & (dfs['min_child_weight'] == 0.5)][['sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])
    print(dfs[(dfs['n_trees'] == 1000) & (dfs['learning_rate'] == 0.08) & (dfs['max_depth'] == 5) & (dfs['min_child_weight'] == 0.5)][['sig_eff_at_cut_based_bkg_rate','cut_based_fake_bkg_rate','cut_based_eff']])

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

    args = parser.parse_args(argv)

    # If output directory is not provided, assume we want the output to be
    # alongside the input directory.
    if args.output_dir is None:
        args.output_dir = args.input_dir

    # Return the options as a dictionary.
    return vars(args)


if __name__ == "__main__":
    main(**parse_args())
