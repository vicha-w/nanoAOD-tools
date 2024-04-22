import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from pathlib import Path
import numpy as np

from scipy.interpolate import interp1d
import xgboost 
from xgboost import plot_importance

variables_binning = {
    'fractional_subjet_pt': np.arange(0., 1.02, 0.02), 'min_pairwise_subjets_mass': np.arange(0., 312., 2.),
    'mass': np.arange(0., 612., 2.), 'nsubjets': np.arange(0., 5., 1.), 'tau3_over_tau2': np.arange(0., 1.02, 0.02),
} #'tau2_over_tau1': np.arange(0., 1.02, 0.02)

def plot_variable_distributions(features, labels, output_dir, variable_names, year='2018'):
    output_dir = Path(output_dir)
    for i, variable in enumerate(variable_names):
        plt.figure(figsize=(10, 7))  
        # Create separate arrays for labels 0 and 1
        bkg_values = features[labels == 0, i]
        sgn_values = features[labels == 1, i]
        
        plt.hist(bkg_values, bins=variables_binning[variable], alpha=0.5, label=f"Pure QCD: {len(bkg_values)}", density=True)
        plt.hist(sgn_values, bins=variables_binning[variable], alpha=0.5, label=f"Hadronic top: {len(sgn_values)}", histtype='step', color='red', linewidth=2, density=True)

        # Customize the x-axis label based on the variable
        if variable == 'nsubjets':
            plt.xlabel('$N_{subjets}$', fontsize='large')
        elif variable == 'min_pairwise_subjets_mass':
            plt.xlabel('$mass_{min ij}$', fontsize='large')
            plt.xlim(0, 140)
        elif variable == 'tau3_over_tau2':
            plt.xlabel('$tau_{32}$', fontsize='large')
        elif variable == 'fractional_subjet_pt':
            plt.xlabel('$f_{pT}$', fontsize='large')
        elif variable == 'mass':
            plt.xlabel('mass', fontsize='large')
            plt.xlim(0, 300)

        plt.ylabel('Normalized Counts', fontsize='large')
        plt.title(f"{year} CMS Simulation ")

        if 'mass' in variable: plt.legend(fontsize='large', loc='upper right')
        else: plt.legend(fontsize='large', loc='upper left')

        plt.tick_params(axis='both', which='major', labelsize='large')

        plt.tight_layout(rect=[0, 0, 0.85, 1])  

        fpath_png = output_dir / (variable + "_distribution.png")
        fpath_pdf = output_dir / (variable + "_distribution.pdf")
        plt.savefig(fpath_png)
        plt.savefig(fpath_pdf)
        plt.close()
        print(f"Saving file: {fpath_pdf}")


def pT_plot(ptBkg, ptSig, fpath, binning=np.arange(0.,10000,200), year='2018'):
    plt.figure()
    plt.hist(ptBkg, bins=binning, alpha=0.5, label=f"Pure QCD Jets: {len(ptBkg)}", density=True)
    plt.hist(ptSig, bins=binning, alpha=0.5, label=f"Hadronic Top Jets: {len(ptSig)}", density=True, histtype='step', color='red', linewidth=2)
    plt.legend(fontsize='large')  
    
    plt.xlim(0, 2000)

    plt.xlabel('HOTVR pT', fontsize='large')  
    plt.ylabel('Normalized Counts', fontsize='large') 

    plt.title(f"{year} CMS Simulation ")

    plt.tick_params(axis='both', which='major', labelsize='large')
    
    plt.tight_layout()

    plt.savefig(fpath, dpi=300)
    print(f"Saving file: {fpath}")


def draw_loss(path, results, **kwargs,):
    plt.figure()
    plt.plot(np.arange(kwargs['n_estimators']),results['validation_0']['logloss'],color='darkgray',linewidth=2, linestyle='-',label='Train')
    plt.plot(np.arange(kwargs['n_estimators']),results['validation_1']['logloss'],color='royalblue',linewidth=3, linestyle='--',label='Test')
    plt.ylabel("log(Loss)", fontsize='large')
    # plt.yscale('log')
    plt.xlabel("Number of trees", fontsize='large')
    # plt.title((f"nTrees: {kwargs['xgboost_params']['n_estimators']}, learning rate {kwargs['xgboost_params']['learning_rate']}, "
    #        f"maxDepth {kwargs['xgboost_params']['max_depth']}, minChildWeight {kwargs['xgboost_params']['min_child_weight']}"))
    # plt.legend(ncol=2, bbox_to_anchor=(0.5, 1.05), loc="lower left")
    plt.title((f"{kwargs['year']} CMS Simulation - Learning rate {kwargs['xgboost_params']['learning_rate']}, "
           f"Maximum Depth {kwargs['xgboost_params']['max_depth']}"))
    plt.legend(fontsize='large', loc='upper right')  
    plt.tick_params(axis='both', which='major', labelsize='large')
    plt.tight_layout()
    plt.savefig(path)
    plt.close()
    print(f"Saving file: {path}")
    path.chmod(0o777)

def draw_roc(path, rates, **kwargs):
    plt.figure()
    plt.plot(rates['true_positive_train'], rates['false_positive_train'], color='darkgray',linewidth=2, linestyle='-',label="Train")
    plt.plot(rates['true_positive_test'], rates['false_positive_test'], color='royalblue',linewidth=3, linestyle='--',label="Test")
    if 'cut_based_efficiencies' in kwargs.keys(): 
        plt.scatter(kwargs['cut_based_efficiencies'][0], kwargs['cut_based_efficiencies'][1], color='red', marker='*', s=150, label='Cut based tagger')   
    
    f = interp1d(rates['true_positive_test'], rates['false_positive_test'], kind='linear', fill_value='extrapolate')
    y_train_at_cut_based_eff = f(kwargs['cut_based_efficiencies'][0]).item()
    # print(y_train_at_cut_based_eff)

    # Add the y-values to the y-ticks - DOES NOT WORK ?!
    # yticks = list(plt.gca().get_yticks())
    # yticks.extend(list(rates['false_positive_train'].flatten()))
    # yticks.extend([y_train_at_cut_based_eff, kwargs['cut_based_efficiencies'][1]])
    # yticks = sorted(list(set(yticks)))
    # special_ticks = list(rates['false_positive_train'].flatten()) + [y_train_at_cut_based_eff, kwargs['cut_based_efficiencies'][1]]
    # plt.yticks(yticks, [f'{tick:.3f}' if tick in special_ticks else '' for tick in yticks])

    # Draw horizontal lines
    plt.axhline(y=y_train_at_cut_based_eff, color='red', linestyle='--')
    plt.axhline(y=kwargs['cut_based_efficiencies'][1], color='red', linestyle='--')
    # plt.title((f"nTrees: {kwargs['xgboost_params']['n_estimators']}, learning rate {kwargs['xgboost_params']['learning_rate']}, "
    #        f"maxDepth {kwargs['xgboost_params']['max_depth']}, minChildWeight {kwargs['xgboost_params']['min_child_weight']}"))
    if 'pt_range_label' in kwargs.keys():
        if kwargs['pt_range_label'] == '200_To_400':
            plt.title(f"{kwargs['year']} CMS Simulation - 200 < $p_{{T}}$ < 400 GeV")
        if kwargs['pt_range_label'] == '400_To_800':
            plt.title(f"{kwargs['year']} CMS Simulation - 400 < $p_{{T}}$ < 800 GeV")
        if kwargs['pt_range_label'] == 'from_800':
            plt.title(f"{kwargs['year']} CMS Simulation - $p_{{T}}$ > 800 GeV")
    plt.legend(loc="upper left", fontsize='large')#ncol=2, bbox_to_anchor=(0.5, 1.05), )
    plt.xlim([0.0,1.0])
    plt.ylim([1e-3,1.0])
    plt.yscale('log')
    plt.xlabel("Signal efficiency $\epsilon_{S}$", fontsize='large')
    plt.ylabel("Mistag rate $\epsilon_{B}$", fontsize='large')
    plt.tick_params(axis='both', which='major', labelsize='large')
    plt.tight_layout()
    plt.savefig(path)
    plt.close()
    print(f"Saving file: {path}")
    path.chmod(0o777)

def draw_score(path, predictions, **kwargs):
    plt.figure(figsize=[7.3, 7.5])
    plt.hist(predictions['train_bkg'], bins=40, range=[0,1], histtype='stepfilled', color='cornflowerblue', label="Train bkg", alpha=0.6)
    plt.hist(predictions['train_sgn'], bins=40, range=[0,1], histtype='stepfilled', color='gold', label="Train sig", alpha=0.6)
    plt.hist(predictions['test_bkg'], bins=40, range=[0,1], histtype='step', color='royalblue', linewidth=2, linestyle='--', label="Test bkg")
    plt.hist(predictions['test_sgn'], bins=40, range=[0,1], histtype='step', color='orange', linewidth=2, linestyle='--', label="Test sig")
    plt.xlim([0.0,1.0])
    plt.xlabel("Score")
    plt.ylabel("Normalized events")
    plt.title((f"nTrees: {kwargs['xgboost_params']['n_estimators']}, learning rate {kwargs['xgboost_params']['learning_rate']}, "
           f"maxDepth {kwargs['xgboost_params']['max_depth']}, minChildWeight {kwargs['xgboost_params']['min_child_weight']}"))
    plt.legend(ncol=2, bbox_to_anchor=(0.5, 1.05), loc="lower left")
    plt.savefig(path)
    plt.close()
    print(f"Saving file: {path}")
    path.chmod(0o777)

def draw_importance(path, importances, **kwargs):
    indices = np.argsort(importances)[::-1]
    sorted_importances = [importances[i] for i in indices]
    sorted_features = [[variable for variable in variables_binning.keys()][i] for i in indices]

    custom_labels = {
        'nsubjets': '$N_{sub}$', 'fractional_subjet_pt': '$f_{p_{T}}$', #'$f_{p_{T}}=p_{T}^{sub1}/p_{T}^{jet}$',
        'min_pairwise_subjets_mass': '$m_{min} ij$',
        'mass': '$m_{jet}$',
        'tau3_over_tau2': r'$\tau_{3}/\tau_{2}$'
    }
    sorted_features_labels = [custom_labels[feature] for feature in sorted_features]

    fig, ax = plt.subplots()
    fig.subplots_adjust(left=0.15)
    ax.barh(range(len(sorted_importances)), sorted_importances, align='center')
    ax.set_yticks(range(len(sorted_importances)))
    # ax.set_yticklabels(sorted_features)
    ax.invert_yaxis()
    ax.set_yticklabels(sorted_features_labels, rotation=45, fontsize=12)  
    ax.set_xlabel("Importance [Gain]", fontsize=12)  # Adjust the fontsize for x-label
    plt.title((f"{kwargs['year']} CMS Simulation - Learning rate {kwargs['xgboost_params']['learning_rate']}, "
           f"Maximum Depth {kwargs['xgboost_params']['max_depth']}"), fontsize=12)
    fig.savefig(path)
    plt.close(fig)
    print(f"Saving file: {path}")
    path.chmod(0o777)


