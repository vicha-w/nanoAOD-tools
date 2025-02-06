import pandas as pd

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

from gen_helper import *
from utils import deltaR

class HOTVR_MVA(Module):
    def __init__(
            self,
            globalOptions={"isData":False}, 
            outputName=None,
            inputHOTVRJetCollection=lambda event: Collection(event, "preselectedHOTVRJets"),
            inputSubHOTVRJetCollection= lambda event: Collection(event, "preselectedHOTVRSubJets"),
            inputGenParticleCollections={},
        ):
        self.globalOptions = globalOptions
        self.outputName = outputName
        self.inputHOTVRJetCollection = inputHOTVRJetCollection
        self.inputSubHOTVRJetCollection = inputSubHOTVRJetCollection
        self.inputGenParticleCollections = inputGenParticleCollections
        
        self.hotvrjets_df_list = []

        self.hotvr_vars = [
            'pt', 'eta', 'phi', 'mass', 'nsubjets', 'tau3_over_tau2', 
            'fractional_subjet_pt', 'min_pairwise_subjets_mass',
            'tau2_over_tau1'
            ]

        self.quarks_list = [1, 2, 3, 4]
        self.leptons_list = [11, 13, 15]
        self.neutrinos_list = [12, 14, 16]

        self.MVA_keys = ['has_gluon_or_quark_not_fromTop']
        self.MVA_keys.extend(['has_other'])
        for flag_top_inside in ['topIsInside','topIsNotInside','topIsNotInside_and_has_gluon_or_quark_not_fromTop']:
            self.MVA_keys.append('has_hadronicTop_'+flag_top_inside)
            self.MVA_keys.append('has_other_'+flag_top_inside)
            self.MVA_keys.append('has_noTopDaughters_'+flag_top_inside)
            for top_label in ['fromTop','not_fromTop']:
                self.MVA_keys.append('has_leptonicW_'+top_label+'_'+flag_top_inside)
                self.MVA_keys.append('has_hadronicW_'+top_label+'_'+flag_top_inside)
                self.MVA_keys.append('has_b_plus_quark_'+top_label+'_'+flag_top_inside)
                self.MVA_keys.append('has_b_plus_lepton_'+top_label+'_'+flag_top_inside)
                self.MVA_keys.append('has_b_'+top_label+'_'+flag_top_inside)
                self.MVA_keys.append('has_quark_fromW_'+top_label+'_'+flag_top_inside)
        # --- special case, samples without top and samples like tW, ttH
        self.MVA_keys.append('has_leptonicW_not_fromTop')
        self.MVA_keys.append('has_hadronicW_not_fromTop')
        self.MVA_keys.append('has_b_plus_quark_not_fromTop')
        self.MVA_keys.append('has_b_plus_lepton_not_fromTop')
        self.MVA_keys.append('has_b_not_fromTop')
        self.MVA_keys.append('has_quark_fromW_not_fromTop')

        for var in self.hotvr_vars:
            self.MVA_keys.append(var)
        self.MVA_keys.append('run_number')

        if Module.globalOptions['isSignal']: 
            self.MVA_keys.append('has_top_fromResonance')

        self.print_out = False

    def is_inside_hotvr(self, jet, hotvr):
        rho = 600 
        effective_radius = rho / hotvr.pt if rho / hotvr.pt <= 1.5 else 1.5   # parameter defined in the paper: https://arxiv.org/abs/1606.04961
        if deltaR(jet, hotvr)< effective_radius:
            return True
        else: return False

    def is_quark_lepton_gluon(self, genP):
        if genP.pdgId in self.quarks_list or genP.pdgId in self.leptons_list or genP.pdgId == 21:
            return True
        else: return False


    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree
        if self.outputName is not None:
            self.out.branch(self.outputName, "I")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        if len(self.hotvrjets_df_list)!=0:
            tot_hotvrjets_df = pd.concat(self.hotvrjets_df_list, ignore_index=True, sort=False)
            tot_hotvrjets_df.to_hdf(outputFile.GetName().replace('.root','.h5'), key='hotvrjets_dataset', mode='w')

    def analyze(self, event):

        hotvrjets = self.inputHOTVRJetCollection(event)
        subhotvrjets = self.inputSubHOTVRJetCollection(event)
        gentops = self.inputGenParticleCollections['gentops'](event)
        genWs_not_from_top = self.inputGenParticleCollections['genWs_not_from_top'](event)
        genbs_not_from_top = self.inputGenParticleCollections['genbs_not_from_top'](event)
        genparticles_not_from_top = self.inputGenParticleCollections['genparticles_not_from_top'](event)

        if self.print_out: print('\n############# HOTVR_MVA module - ev. number {}'.format(event.run))
        
        for ihotvr, hotvr in enumerate(hotvrjets):
            if self.print_out: print('HOTVR N. {}'.format(ihotvr+1))
            effective_radius = 600./ hotvr.pt if 600./ hotvr.pt <= 1.5 else 1.5

            subjets_in_hotvr = []
            for hotvr_subjet in subhotvrjets:
                if (hotvr.subJetIdx1 == hotvr_subjet._index or 
                    hotvr.subJetIdx2 == hotvr_subjet._index or 
                    hotvr.subJetIdx3 == hotvr_subjet._index or 
                    (hasattr(hotvr, 'subJetIdx4') and hotvr.subJetIdx4 == hotvr_subjet._index)):
                    subjets_in_hotvr.append(hotvr_subjet)
            subjets_in_hotvr = sorted(subjets_in_hotvr, key=lambda x: x.pt, reverse=True)

            # --- initializing the dictionary
            hotvr_dict = dict()
            for key in self.MVA_keys:
                hotvr_dict[key] = False
            # ---

            for var in self.hotvr_vars:
                hotvr_dict[var] = getattr(hotvr, var)
            
            # saving run number so the training will be performed on jets with odd event number
            # while the evaluation on jets with even number to avoid overtraining 
            hotvr_dict['run_number'] = event.run

            # --- check on top
            if len(gentops) != 0:
                closest_gentop = min(gentops, key=lambda gentop: deltaR(gentop,hotvr))
                if self.print_out: 
                    print('Closest genTop idx.{}'.format(closest_gentop._index))

                top_daughters_inside_hotvr = []
                for top_daughter in closest_gentop.daughters:
                    if deltaR(top_daughter, hotvr) < effective_radius:
                        top_daughters_inside_hotvr.append(top_daughter)
                if self.print_out: 
                    print('Daugthers inside {}'.format(list(map(lambda daughter: daughter.pdgId, top_daughters_inside_hotvr))))

                if deltaR(closest_gentop, hotvr) < effective_radius:
                    if Module.globalOptions['isSignal']: 
                        if closest_gentop.from_resonance: 
                            hotvr_dict['has_top_fromResonance'] = True
                    if self.print_out: 
                        print('Closest genTop [idx. {}] inside HOTVR'.format(closest_gentop._index))
                    substr_flag = gentop_substructures_check(
                        closest_gentop, 
                        top_daughters_inside_hotvr, 
                        flag_is_top_inside='topIsInside'
                    )
                else: 
                    if self.print_out: 
                        print('Daugthers {} inside HOTVR of a closed genTop NOT inside HOTVR [deltaR {} > rho/pt {}]'.format(list(map(lambda daughter: daughter.pdgId, top_daughters_inside_hotvr)), deltaR(closest_gentop,hotvr), effective_radius))

                    # --- special case of tW processes -> the hotvr comes from the W not from the top
                    if len(genWs_not_from_top) != 0:
                        closest_genW = min(genWs_not_from_top, key=lambda genW: deltaR(genW,hotvr))
                        if deltaR(closest_genW, hotvr) < effective_radius:
                            if self.print_out: 
                                print('Closest genW not from top inside hotvr')
                            W_daughters_inside_hotvr = []
                            for W_daughter in closest_genW.daughters:
                                if deltaR(W_daughter, hotvr) < effective_radius:
                                    W_daughters_inside_hotvr.append(W_daughter)
                            if self.print_out: 
                                print('Daugthers inside {}'.format(list(map(lambda daughter: daughter.pdgId, W_daughters_inside_hotvr))))
                            substr_flag = genW_substructures_check(W_daughters_inside_hotvr)
                            hotvr_dict[substr_flag] = True
                        else: 
                            hotvr_dict['has_other'] = True
                            continue

                    # ---
                    # --- special case of ttH, H->bb -> the hotvr comes from the b from the Higgs
                    elif len(genbs_not_from_top) != 0:
                        closest_genb = min(genbs_not_from_top, key=lambda genb: deltaR(genb,hotvr))
                        if deltaR(closest_genb,hotvr) < effective_radius:
                            if self.print_out: print('Closest b not from inside hotvr')
                            hotvr_dict['has_b_not_fromTop'] = True
                            continue
                        else: 
                            hotvr_dict['has_other'] = True
                            continue
                    # ---
                    # --- special case: daughters are inside but also gluon radiation (which represents the biggest contribution)
                    elif any(self.is_inside_hotvr(genp, hotvr) for genp in list(filter(self.is_quark_lepton_gluon, genparticles_not_from_top))):
                        substr_flag = gentop_substructures_check(
                            closest_gentop, 
                            top_daughters_inside_hotvr, 
                            flag_is_top_inside='topIsNotInside_and_has_gluon_or_quark_not_fromTop'
                        )
                    # --- very rare case 
                    else: 
                        substr_flag = gentop_substructures_check(
                            closest_gentop, 
                            top_daughters_inside_hotvr, 
                            flag_is_top_inside='topIsNotInside'
                        )
                hotvr_dict[substr_flag] = True
            # ---

            # --- check on W, b, others not from top 
            elif len(genWs_not_from_top) != 0:
                closest_genW = min(genWs_not_from_top, key=lambda genW: deltaR(genW,hotvr))
                if deltaR(closest_genW,hotvr) < effective_radius:
                    if self.print_out: 
                        print('Closest genW not from top inside hotvr')
                    W_daughters_inside_hotvr = []
                    for W_daughter in closest_genW.daughters:
                        if deltaR(W_daughter, hotvr) < effective_radius:
                            W_daughters_inside_hotvr.append(W_daughter)
                    if self.print_out: 
                        print('Daugthers inside {}'.format(list(map(lambda daughter: daughter.pdgId, W_daughters_inside_hotvr))))
                    substr_flag = genW_substructures_check(W_daughters_inside_hotvr)
                    hotvr_dict[substr_flag] = True
                else: 
                    hotvr_dict['has_other'] = True 

            elif len(genbs_not_from_top) != 0:
                closest_genb = min(genbs_not_from_top, key=lambda genb: deltaR(genb,hotvr))
                if deltaR(closest_genb,hotvr) < effective_radius:
                    if self.print_out: print('Closest b not from inside hotvr')
                    hotvr_dict['has_b_not_fromTop'] = True
                else: 
                    hotvr_dict['has_other'] = True 
                
            elif any(self.is_inside_hotvr(genp, hotvr) for genp in list(filter( self.is_quark_lepton_gluon, genparticles_not_from_top))):
                if self.print_out: print('Quarks/Gluons not from top inside hotvr')
                hotvr_dict['has_gluon_or_quark_not_fromTop'] = True

            else: 
                hotvr_dict['has_other'] = True 

            hotvr_df = pd.DataFrame(hotvr_dict, index=[hotvr_dict['run_number']])

            self.hotvrjets_df_list.append(hotvr_df)

        return True
