
import math
from collections import OrderedDict
import numpy as np

from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import \
    Collection
from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module

from gen_helper import isLastCopy
from utils import deltaR


class GenTopModule(Module):

    def __init__(
        self,
        inputGenTopCollection=lambda event: Collection(event, "GenPart"),
        inputFatGenJetCollection=lambda event: Collection(event, "GenJetAK8"),
        inputGenJetCollection=lambda event: Collection(event, "GenJet"),
        inputFatJetCollection=lambda event: Collection(event, "FatJet"),
        inputHOTVRJetCollection=lambda event: Collection(event, "FatJet"),
        inputJetCollection=lambda event: Collection(event, "Jet"),
        inputMuonCollection=lambda event: Collection(event, "Muon"),
        inputElectronCollection=lambda event: Collection(event, "Electron"),
    ):

        self.inputGenTopCollection = inputGenTopCollection
        self.inputFatGenJetCollection = inputFatGenJetCollection
        self.inputGenJetCollection = inputGenJetCollection
        self.inputFatJetCollection = inputFatJetCollection
        self.inputHOTVRJetCollection = inputHOTVRJetCollection
        self.inputJetCollection = inputJetCollection
        self.inputMuonCollection = inputMuonCollection
        self.inputElectronCollection = inputElectronCollection

        self.verbose = False

        self.quarks_list = [1,2,3,4]
        self.leptons_list = [11,13,15]

        self.genTopKeys = [
            'deltaR_hotvr',
            'is_inside_ak8', 'is_inside_ak8_top_tagged', 'inside_nak8', 'min_deltaR_ak8', 'all_decays_inside_ak8', 'max_deltaR_q_ak8',
            'is_inside_hotvr', 'is_inside_hotvr_top_tagged', 'inside_nhotvr', 'is_inside_hotvr_index',
            'is_inside_hotvr_R04', 'is_inside_hotvr_R04_index',
            'min_deltaR_hotvr', 'all_decays_inside_hotvr', 'max_deltaR_q_hotvr', 'two_decays_inside_hotvr',
            'all_decays_inside_hotvr_R04', 'two_decays_inside_hotvr_R04']
        if Module.globalOptions['isSignal']: self.genTopKeys.append('from_resonance')

    def is_genP_inside_genFJet(self, genFJet, genP):
        if deltaR(genFJet, genP)<0.8:
            return True
        else: return False

    def is_genP_inside_hotvr(self, hotvr, genP):
        rho = 600 
        effective_radius = rho / hotvr.pt if rho / hotvr.pt <= 1.5 else 1.5   # parameter defined in the paper: https://arxiv.org/abs/1606.04961
        if deltaR(hotvr, genP) < effective_radius:
            return True
        else: return False

    def deltaPhi(self,phi1, phi2):
        res = phi1-phi2
        while (res > math.pi):
            res -= 2 * math.pi
        while (res <= -math.pi):
            res += 2 * math.pi

        return res

    def relDeltaPt(self,pt1, pt2):
        if pt2 != 0.0:
            return abs((pt1 - pt2) / pt2)
        return 1.

    def beginJob(self):
        pass

    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree

        for genTopKey in self.genTopKeys:
            if 'deltaR' in genTopKey or 'rho_over_pt' in genTopKey: 
                self.out.branch("genTops_"+genTopKey, "F", lenVar="ngenTops")
            else: self.out.branch("genTops_"+genTopKey, "I", lenVar="ngenTops")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""

        genTops = self.inputGenTopCollection(event)
        fatGenJets = self.inputFatGenJetCollection(event)
        fatGenJets = sorted(fatGenJets,key=lambda x: x.pt, reverse=True)
        genJets = self.inputGenJetCollection(event)
        genJets = sorted(genJets,key=lambda x: x.pt, reverse=True)

        # muons = self.inputMuonCollection(event)
        # electrons = self.inputElectronCollection(event)

        fatjets = self.inputFatJetCollection(event)
        hotvrjets = self.inputHOTVRJetCollection(event)
        hotvrjets = sorted(hotvrjets, key=lambda x: x.scoreBDT, reverse=True)

        for genTop in genTops:
            # ---- genStudies with AK8
            setattr(genTop, 'is_inside_ak8', False), setattr(genTop, 'is_inside_ak8_top_tagged', False)
            setattr(genTop, 'inside_nak8', 0) #, setattr(genTop, 'min_deltaR_ak8', -99.)
            setattr(genTop,'all_decays_inside_ak8', False), setattr(genTop,'max_deltaR_q_ak8', -99)

            min_deltaR_ak8_top  = float('inf')
            for ak8 in fatjets:
                if self.verbose: print('------------ Beginning loop over reco ak8 jets (that have a link to genAK8Jet) ------------')
                if self.verbose: print('---- AK8 Number {}'.format((ak8._index)+1))

                associated_genFJet = None
                for genFJet in fatGenJets:
                    if ak8.genJetAK8Idx == genFJet._index:
                        associated_genFJet = genFJet
                    else: continue
                if associated_genFJet == None:
                    if self.verbose: print('No associated genJet')
                    continue

                min_deltaR_ak8_top = min(min_deltaR_ak8_top, deltaR(genFJet, genTop))

                if self.is_genP_inside_genFJet(associated_genFJet, genTop):
                    if self.verbose: print('The genTop is inside an ak8!')
                    setattr(genTop, 'is_inside_ak8', True)
                    setattr(genTop, 'inside_nak8', genTop.inside_nak8+1)

                    max_deltaR_ak8_q = 0.
                    for daughter in genTop.daughters:
                        max_deltaR_ak8_q = max(max_deltaR_ak8_q, deltaR(associated_genFJet, daughter))
                    setattr(genTop, 'max_deltaR_q_ak8', max_deltaR_ak8_q)

                    if max_deltaR_ak8_q < 0.8:
                        if self.verbose: print('All the decays are inside the ak8. The greater dR is {}'.format(max_deltaR_ak8_q))
                        setattr(genTop, 'all_decays_inside_ak8', True)


                    if ak8.particleNet_TvsQCD>0.58:
                        if self.verbose: print('which is top tagged!')
                        setattr(genTop, 'is_inside_ak8_top_tagged', True)
                else: continue
            setattr(genTop, 'min_deltaR_ak8', min_deltaR_ak8_top)
            # ----

            # ---- genStudies with HOTVR
            setattr(genTop, 'deltaR_hotvr', -1)
            setattr(genTop, 'is_inside_hotvr', False), setattr(genTop, 'is_inside_hotvr_index', -99)
            setattr(genTop, 'is_inside_hotvr_R04', False), setattr(genTop, 'is_inside_hotvr_R04_index', -99)
            setattr(genTop, 'is_inside_hotvr_top_tagged', False)
            setattr(genTop, 'inside_nhotvr', 0) #, setattr(genTop, 'min_deltaR_ak8', -99.)
            setattr(genTop, 'all_decays_inside_hotvr', False), setattr(genTop, 'all_decays_inside_hotvr_R04', False)
            setattr(genTop, 'max_deltaR_q_hotvr', -99),
            setattr(genTop, 'two_decays_inside_hotvr', False), setattr(genTop, 'two_decays_inside_hotvr_R04', False)

            min_deltaR_hotvr_top  = float('inf')

            for ihotvr, hotvr in enumerate(hotvrjets):
                # if ihotvr >= 1: continue # check on tt_semilepton (reconstruction with jet of highest score)
                if self.verbose: print('------------ Beginning loop over reco hotvr jets (that have a link to genhotvrJet) ------------')
                if self.verbose: print('---- hotvr Number {}'.format((hotvr._index)+1))

                rho = 600 
                effective_radius = rho / hotvr.pt if rho / hotvr.pt <= 1.5 else 1.5

                min_deltaR_hotvr_top = min(min_deltaR_hotvr_top, deltaR(hotvr, genTop))
                setattr(genTop, 'deltaR_hotvr', deltaR(hotvr, genTop))
                if self.verbose: print('DeltaR(top, hotvr): {}'.format(deltaR(hotvr, genTop)))

                if self.is_genP_inside_hotvr(hotvr, genTop):
                    if self.verbose: print('The genTop is inside an hotvr (R:{})!'.format(effective_radius))
                    setattr(genTop, 'is_inside_hotvr', True)
                    setattr(genTop, 'inside_nhotvr', genTop.inside_nhotvr+1)
                    setattr(genTop, 'is_inside_hotvr_index', hotvr._index)

                    deltaR_daughters_jet = [deltaR(hotvr, daughter) for daughter in genTop.daughters]
                    deltaR_daughters_jet.sort()
                    if self.verbose:
                        print('DeltaR(daughters, jet): {}'.format(deltaR_daughters_jet))

                    if len(deltaR_daughters_jet) == 3 and deltaR_daughters_jet[-1] < effective_radius:
                        if self.verbose:
                            print('All the decays are inside the hotvr. The greatest dR is {}'.format(deltaR_daughters_jet[-1]))
                        setattr(genTop, 'all_decays_inside_hotvr', True)
                        setattr(genTop, 'two_decays_inside_hotvr', True)
                        if deltaR_daughters_jet[-1] < 0.4:
                            setattr(genTop, 'all_decays_inside_hotvr_R04', True)
                            setattr(genTop, 'two_decays_inside_hotvr_R04', True)
                    elif len(deltaR_daughters_jet) >= 2 and deltaR_daughters_jet[-2] < effective_radius:
                        if self.verbose:
                            print('Two of the three decays are inside the hotvr. The second greatest dR is {}'.format(deltaR_daughters_jet[-2]))
                        setattr(genTop, 'two_decays_inside_hotvr', True)
                        if deltaR_daughters_jet[-2] < 0.4:
                            setattr(genTop, 'two_decays_inside_hotvr_R04', True)

                    if hotvr.scoreBDT>0.5: 
                        if self.verbose: print('which is top tagged!')
                        setattr(genTop, 'is_inside_hotvr_top_tagged', True)
                else: continue
            setattr(genTop, 'min_deltaR_hotvr', min_deltaR_hotvr_top)
            # ----

        for genTopKey in self.genTopKeys:
            self.out.fillBranch("genTops_"+genTopKey, map(lambda gentop: getattr(gentop,genTopKey), genTops))

        return True

