import os, sys, shutil
from multiprocessing import Pool

from argparse import ArgumentParser

from pathlib import Path
from typing import Optional, List

import numpy as np
import pandas as pd

from plotting_utils import plot_variable_distributions, pT_plot
from resample import resample

inputs = [
    'fractional_subjet_pt', 'min_pairwise_subjets_mass', 'mass', 
    'nsubjets', 'tau3_over_tau2',  'pt'
] #'tau2_over_tau1',

binning = np.arange(0., 10000, 20) #np.logspace(0, 4, 200)#

resampling = True
pT_distribution_plot = True
feautures_distribution_plots = True

def read_and_filter(file):
    df = pd.read_hdf(file)
    # df = df.fillna(False)

    # update min-pair wise subjets mass to -99 in case of nsubjet < 3
    df.loc[df['nsubjets'] < 3, 'min_pairwise_subjets_mass'] = -1
    # filtering only jets with even run number to avoid overtraining during evaluation
    # df = df[df['run_number'] % 2 == 0] 

    # skimming the df sgn/bkg -> pure hadronic jets/pure qcd
    if 'ttX_mass' in str(file) or 'TTZprimeToTT' in str(file):
        # for signal: has_top_fromResonance, has_hadronicTop_topIsInside -> pure hadronic and jet from resonance
        df = df[df['has_top_fromResonance'] & df['has_hadronicTop_topIsInside'] ]
        df = df[inputs]
        df['label'] = 1
    elif 'qcd' in str(file):
        if 'has_other' not in df.columns: df['has_other'] = False
        # for background: 
        #   -'has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop' -> pure QCD in case of samples with top
        df = df[df['has_gluon_or_quark_not_fromTop'] | df['has_other']]
        df = df[inputs]
        df['label'] = 0
    elif 'tt_dilepton' in str(file):
        # for tt dilepton: 
        #   -'has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop' -> pure QCD in case of samples with top
        #   -'has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop' (7.7% of total jets in samples without trigger selection) -> fraction of hadr. of b from t inside [top not inside] + QCD
        df = df[df['has_noTopDaughters_topIsNotInside_and_has_gluon_or_quark_not_fromTop'] | df['has_other_topIsNotInside_and_has_gluon_or_quark_not_fromTop']]# | 
            #df['has_gluon_or_quark_not_fromTop'] | df['has_other'] | df['has_noTopDaughters_topIsNotInside'] | df['has_other_topIsInside']]
        df = df[inputs]
        df['label'] = 0
    else: df = pd.DataFrame()

    return df

def loading_and_processing_h5(files, output_dir, chunk_size=50):
    # process the files in chunks and save each merged DataFrame to a temporary .h5 file
    current_chunk = 1
    total_chunks = len(files) // chunk_size + (1 if len(files) % chunk_size else 0)
    
    for idx_file in range(0, len(files), chunk_size):
        print(f"Processing files-chunk n.{current_chunk} out of {total_chunks}")
        file_list = files[idx_file:idx_file + chunk_size]

        # creating a pool of processes to speed up the loading/processing of the .h5 files
        with Pool() as p:
            dfs = p.map(read_and_filter, file_list)

        merged_df = pd.concat(dfs, ignore_index=True)
        # Save the merged DataFrame to a temporary .h5 file
        temp_dir = output_dir / 'temp' 
        temp_dir.mkdir(parents=True, exist_ok=True)
        # temp_dir.chmod(0o777)
        fpath = temp_dir / f'temp_{idx_file}.h5'
        merged_df.to_hdf(fpath, key='df')

        current_chunk += 1

    # Concatenate the temporary .h5 files into a single file
    temp_files = [temp_dir / f'temp_{idx_file}.h5' for idx_file in range(0, len(files), chunk_size)]
    dfs = [pd.read_hdf(file) for file in temp_files]
    df = pd.concat(dfs, ignore_index=True)
    df = df.fillna(False)

    # Save the final DataFrame to a .h5 file
    fpath = output_dir / 'all_jets.h5'
    df.to_hdf(fpath, key='df')

    # Delete the temp directory
    shutil.rmtree(temp_dir)

    return

def creating_training_data(arrays, fpath):

    np.savez_compressed(fpath,features=arrays[0],labels=arrays[1])

    return

def main(
        input_dir,
        output_dir,
        year,
        ):
    
    # Ensure input/output dirs are Path instances.
    input_dir = Path(input_dir)
    output_dir = output_dir / str(year)
    output_dir = Path(output_dir)

    ######### LOADING/PROCESSING THE DATAFRAME
    # Given the large number of files to be processed, the total df (all jets with inputs/labels) is available as 'all_jets.h5'
    # if it is not, the total df is generated and saved as 'all_jets.h5'
    if os.path.exists(output_dir / 'all_jets.h5') == 0:
        # Glob the files, and convert to a sorted list.
        # sgn and bkg files in separated list so it is easy to filter them when needed
        fnames_sgn = sorted(input_dir.glob(f"sgn_{year}_central_hotvr_h5/*Width4_h5/*.h5"))
        fnames_bkg = sorted(input_dir.glob(f"bkg_{year}_hotvr_h5/qcd*/*.h5"))  # preliminary study with only QCD files 
        fnames =  fnames_sgn + fnames_bkg
        print(f"Found {len(fnames)} files in {input_dir}")
        # files are read and processed in chunk and save in temp files that are then deleted
        loading_and_processing_h5(fnames, output_dir)

    # reading "all_jets.h5" if exists
    dfs = pd.read_hdf(output_dir / 'all_jets.h5')
    if dfs.empty: 
        print("Unable to find 'all_jets.h5' or unable to process the individual files")
        sys.exit()

    print('### Successfully loaded the h5 with all the jets')
    # Shuffle the dataframe
    dfs = dfs.sample(frac=1).reset_index(drop=True)
    selected_columns = inputs + ['label']
    new_dfs = dfs[selected_columns]
    print(new_dfs)
    #########

    output_dir = output_dir / 'trainBDT_outputs'
    output_dir.mkdir(parents=True, exist_ok=True)
    output_dir.chmod(0o777)

    ######### TRAINING-TEST SPLITTING
    # create the training set if does not exist
    print('\n### Train-test splitting')
    features_array, label_array = {}, {}
    # for pt_range in pT_ranges:
    #     features_array[pt_range], label_array[pt_range] = [], []

    if resampling: fpath = output_dir / 'trainData_resampled.npz'
    else: fpath = output_dir / 'trainData.npz'

    if os.path.exists(fpath) == 0:
        print('### Creating training dataset...')
        features_array, label_array = [], []
        if resampling:
            print('### RE-SAMPLING')
            # jets resampling by pT
            ptSig = dfs[dfs['label']==1]['pt'].values
            # ptSig = np.random.choice(ptSig, 300000, replace=False) #forcing to have similar statistics as bkg
            ptBkg = dfs[dfs['label']==0]['pt'].values
            # ptBkg = np.random.choice(ptBkg, 300000, replace=False) #forcing to have similar statistics as bkg
            print(f"Pre-resampling [SGN]: {ptSig.shape[0]}")
            print(f"Pre-resampling [BKG]: {ptBkg.shape[0]}")

            pT_plot(ptBkg, ptSig, output_dir / f"pT_distribution_SGNvsBKG_pre_sampling.png", binning=binning, year=year)
            pT_plot(ptBkg, ptSig, output_dir / f"pT_distribution_SGNvsBKG_pre_sampling.pdf", binning=binning, year=year)

            if feautures_distribution_plots:
                input_without_pt = [input for input in inputs if input != 'pt']
                bkg_data = dfs[dfs['label'] == 0][[input for input in inputs]].values
                sgn_data = dfs[dfs['label'] == 1][[input for input in inputs]].values
                
                features_array = np.vstack((bkg_data[:, : len(input_without_pt)], sgn_data[:, : len(input_without_pt)]))
                label_array = np.concatenate((np.zeros(len(bkg_data)), np.ones(len(sgn_data))))

                print(f"\nPlotting the features for sgn/bkg pre-resampling{features_array.shape}")
                features_plot_dir = output_dir / 'features_distributions_total_pre-resampling'
                features_plot_dir.mkdir(parents=True, exist_ok=True)
                plot_variable_distributions(features_array, label_array, features_plot_dir, [input for input in inputs if input != 'pt'], year=year)

            # the target distribution is the sgn pT
            # additional info on the resample in "resample.py"
            targetHist, _ = np.histogram(ptSig, bins=binning)

            pt_list_resampled, idx_list_resampled = resample([ptBkg,ptSig],targetHist,binning)
            ptBkg_resampled = pt_list_resampled[0]
            ptSig_resampled = pt_list_resampled[1]

            idxBkg_resampled = idx_list_resampled[0]
            idxSgn_resampled = idx_list_resampled[1]

            # Separating background (bkg) features from signal (sgn) features
            bkg_data_resampled = dfs[dfs['label'] == 0].reset_index(drop=True).iloc[idxBkg_resampled][[input for input in inputs]].values
            sgn_data_resampled = dfs[dfs['label'] == 1].reset_index(drop=True).iloc[idxSgn_resampled][[input for input in inputs]].values

            print(f"Post-resampling [SGN]: {sgn_data_resampled.shape[0]}")
            print(f"Post-resampling [BKG]: {bkg_data_resampled.shape[0]}")

            ptSig = sgn_data_resampled[:, inputs.index('pt')]
            ptBkg = bkg_data_resampled[:, inputs.index('pt')]
            pT_plot(ptBkg, ptSig, output_dir / f"pT_distribution_SGNvsBKG_post_sampling.png", binning=binning, year=year)
            pT_plot(ptBkg, ptSig, output_dir / f"pT_distribution_SGNvsBKG_post_sampling.pdf", binning=binning, year=year)

            features_array = np.vstack((bkg_data_resampled[:, : len(inputs)], sgn_data_resampled[:, : len(inputs)]))
            label_array = np.concatenate((np.zeros(len(bkg_data_resampled)), np.ones(len(sgn_data_resampled))))

            creating_training_data((features_array, label_array), output_dir/f"trainData_resampled.npz")

        else:
            # Separating background (bkg) features from signal (sgn) features
            bkg_data_resampled = dfs[dfs['label'] == 0].reset_index(drop=True)[[input for input in inputs]].values
            sgn_data_resampled = dfs[dfs['label'] == 1].reset_index(drop=True)[[input for input in inputs]].values
            input_without_pt = [input for input in inputs if input != 'pt']
            features_array = np.vstack((bkg_data[:, : len(input_without_pt)], sgn_data[:, : len(input_without_pt)]))
            label_array = np.concatenate((np.zeros(len(bkg_data)), np.ones(len(sgn_data))))

            print(f"HOTVR Jets [SGN]: {sgn_data_resampled.shape[0]}")
            print(f"HOTVR Jets [BKG]: {bkg_data_resampled.shape[0]}")

            features_array = np.vstack((bkg_data_resampled[:, : len(input_without_pt)], sgn_data_resampled[:, : len(input_without_pt)]))
            label_array = np.concatenate((np.zeros(len(bkg_data_resampled)), np.ones(len(sgn_data_resampled))))

            creating_training_data((features_array, label_array), output_dir / f"trainData.npz")

    else:
        print(f'Training dataset already exists: {fpath}')
        sys.exit()

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

    args = parser.parse_args(argv)

    # If output directory is not provided, assume we want the output to be
    # alongside the input directory.
    if args.output_dir is None:
        args.output_dir = args.input_dir

    # Return the options as a dictionary.
    return vars(args)


if __name__ == "__main__":
    main(**parse_args())