from PhysicsTools.NanoAODTools.postprocessing.framework.eventloop import Module
from PhysicsTools.NanoAODTools.postprocessing.framework.datamodel import Collection
import ROOT
import os
from itertools import chain
from collections import OrderedDict

ROOT.PyConfig.IgnoreCommandLineOptions = True

class ElectronSFProducer(Module):
    """Calculate electron scale factors
    """

    def __init__(
            self, sfFileName=None,
            inputElectronCollection = None,
            nosyst = False,
            verbose=0,
            outputName='',
            WP='',
            ID=''
    ):

        self.inputElectronCollection = inputElectronCollection
        self.nosyst = nosyst
        self.sfFileName = sfFileName
        self.verbose = verbose
        self.outputName = outputName
        self.WP = WP.capitalize()
        self.ID = ID

        self.sys = ['nominal', 'up', 'down']

    def beginJob(self):
        # initialize ElectronCorrlibReader
        self.corrlibreader = ROOT.ElectronCorrlibReader()
        self.corrlibreader.loadCorrections(self.sfFileName)
 
    def endJob(self):
        pass

    def beginFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        self.out = wrappedOutputTree

        for sys in self.sys:
            self.out.branch(self.outputName+"_weight_id_"+sys,"F")
            # for reco_type in ['PtAbove20','PtBelow20']:
            #     self.out.branch(self.outputName+"_weight_recoPt"+reco_type+"_"+sys,"F")    
            self.out.branch(self.outputName+"_weight_recoPt_"+sys,"F")

    def endFile(self, inputFile, outputFile, inputTree, wrappedOutputTree):
        pass

    def getSFs(self, reader, type, year, syst, wp, leptons):
        for idx, lep in enumerate(leptons):
            # evaluate SF
            sf = None
            sf = reader.evaluateElectronSF(type, year, syst, wp, lep.eta, lep.pt)
            # check if SF is OK
            
            if sf < 0.01:
                if self.verbose > 0:
                    print("electron #%i: pT = %1.1f, eta = %1.1f" % (
                        idx, lep.pt, lep.eta))
                sf = 1.
            yield sf

    def analyze(self, event):
        """process event, return True (go to next module) or False (fail, go to next event)"""
        # jets = Collection(event, "Jet")
        corrlibreader = self.corrlibreader 
        electrons = self.inputElectronCollection(event)

        year = self.sfFileName.rsplit('/')[-2]

        if self.WP == 'Loose' and self.ID == 'MVA': self.WP = 'wploose'
        if self.WP == 'Medium' and self.ID == 'MVA': self.WP = 'wp90iso'
        if self.WP == 'Tight' and self.ID == 'MVA': self.WP = 'wp80iso'

        for sys, sys_type in zip(self.sys, ['sf','sfup','sfdown']):
            ev_weight_id, ev_weight_reco_pt = 1., 1. 
            if self.WP == 'wploose':  #SF not calculated for MVA WP LOOSE
                scale_factors_id = list(map(lambda electron: 1., electrons))
            else:
                scale_factors_id = list(self.getSFs(corrlibreader, 'UL-Electron-ID-SF', year, sys_type, self.WP, electrons))   

            electrons_pt_above20 = filter(lambda electron: electron.pt >= 20., electrons) 
            scale_factors_reco_pt_above20 = list(self.getSFs(corrlibreader, 'UL-Electron-ID-SF', year, sys_type, 'RecoAbove20', electrons_pt_above20))
            electrons_pt_below20 = filter(lambda electron: electron.pt < 20., electrons)
            scale_factors_reco_pt_below20 = list(self.getSFs(corrlibreader, 'UL-Electron-ID-SF', year, sys_type, 'RecoBelow20', electrons_pt_below20))
        
            for sf_id, sf_reco_pt_above20, sf_reco_pt_below20 in zip(scale_factors_id, scale_factors_reco_pt_above20, scale_factors_reco_pt_below20): 
                ev_weight_id *= sf_id
                # ev_weight_reco_pt_above20 *= sf_reco_pt_above20 
                ev_weight_reco_pt *= (sf_reco_pt_below20 * sf_reco_pt_above20)

            self.out.fillBranch(self.outputName+"_weight_id_"+sys, ev_weight_id)
            self.out.fillBranch(self.outputName+"_weight_recoPt_"+sys, ev_weight_reco_pt)

        return True

