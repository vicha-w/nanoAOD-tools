import os
import sys
import math
import ROOT
import random
import numpy as np


class PhysicsObject(object):
    def __init__(self, obj=None, pt=0., eta=0., phi=0., mass=0., keys=[]):
        self._obj = obj
        if obj!=None:
            self._index = self._obj._index
        self.__dict__["pt"] = pt
        self.__dict__["eta"] = eta
        self.__dict__["phi"] = phi
        self.__dict__["mass"] = mass
        for k in keys:
            if k in ['pt','eta','phi','mass']:
                raise Exception("ERROR - cannot store key in PhysicsObject: "+k)
            self.__dict__[k] = getattr(obj, k)

    def p4(self):
        ret = ROOT.TLorentzVector()
        ret.SetPtEtaPhiM(self.pt, self.eta, self.phi, self.mass)
        return ret

    def originalP4(self):
        if self._obj==None:
            print "ERROR - object does not dependent on nanoaod object"
            sys.exit(1)
        return self._obj.p4()

    def __str__(self):
        if self._obj==None:
            print "ERROR - object does not dependent on nanoaod object"
            sys.exit(1)
        return self._obj.__str__()


def deltaPhi(x, y):
    phi1 = x
    if hasattr(x,'phi'):
        phi1 = x.phi
    phi2 = y
    if hasattr(y,'phi'):
        phi2 = y.phi
    res = phi1-phi2
    while (res > math.pi):
        res -= 2 * math.pi
    while (res <= -math.pi):
        res += 2 * math.pi

    return res


def deltaR(j1, j2):
    return math.sqrt(
        (j1.eta-j2.eta)**2 +
        deltaPhi(j1.phi, j2.phi)**2
    )

def deltaPt(j1,j2):
	return abs((j1.pt-j2.pt)/j2.pt)


def getHist(relFileName, histName):
    #rootFile = ROOT.TFile(os.path.expandvars("$CMSSW_BASE/src/"+relFileName))
    rootFile = ROOT.TFile(relFileName)
    hist = rootFile.Get(histName)
    if not hist:
        raise Exception("Hist file '"+histName +
                        "' not found in file '"+relFileName+"'")
    hist = hist.Clone(histName+str(random.random()))
    hist.SetDirectory(0)
    rootFile.Close()
    return hist


def getGraph(relFileName, graphName):
    #rootFile = ROOT.TFile(os.path.expandvars("$CMSSW_BASE/src/"+relFileName))
    rootFile = ROOT.TFile(relFileName)
    graph = rootFile.Get(graphName)
    if not graph:
        raise Exception("Graph file '"+graphName +
                        "' not found in file '"+relFileName+"'")
    graph = graph.Clone(graphName+str(random.random()))
    rootFile.Close()
    return graph


def combineHist2D(hist1, hist2, w1, w2):
    result = hist1.Clone(hist1.GetName()+hist2.GetName())
    result.SetDirectory(0)
    for ibin in range(hist1.GetNbinsX()):
        for jbin in range(hist2.GetNbinsX()):
            result.SetBinContent(ibin+1, jbin+1,
                                 w1*hist1.GetBinContent(ibin+1, jbin+1) +
                                 w2*hist2.GetBinContent(ibin+1, jbin+1)
                                 )
            result.SetBinError(ibin+1, jbin+1,
                               math.sqrt(
                                (w1*hist1.GetBinError(ibin+1, jbin+1))**2 +
                                (w2*hist2.GetBinError(ibin+1, jbin+1))**2
                                )
                               )
    return result


def getX(hist, x):
    xbin = hist.GetXaxis().FindBin(x)
    return hist.GetBinContent(xbin), hist.GetBinError(xbin)


def getSFXY(hist, x, y):
    xBin = hist.GetXaxis().FindBin(x)
    yBin = hist.GetYaxis().FindBin(y)

    if xBin == 0:
        xBin = 1
    if xBin > hist.GetNbinsX():
        xBin = hist.GetNbinsX()

    if yBin == 0:
        yBin = 1
    if yBin > hist.GetNbinsY():
        yBin = hist.GetNbinsY()

    return hist.GetBinContent(xBin, yBin), hist.GetBinError(xBin, yBin)

def processLabels(label):
    process_labels = {
        'DYJetsToLL_0J': 'dy_to_ll_0J',
        'DYJetsToLL_1J': 'dy_to_ll_1J',
        'DYJetsToLL_2J': 'dy_to_ll_2J',
        'DYJetsToLL_M-10to50': 'dy_m-10_50',
        'ST_tW_antitop_5f_NoFullyHadronicDecays': 'tbarW', 
        'TWminusto2L2Nu': 'tW_dilepton',
        'TbarWplusto2L2Nu': 'tbarW_dilepton',
        'ST_tW_top_5f_NoFullyHadronicDecays': 'tW',
        'TTLL_MLL-4to50': 'ttll_m-4-50_dilepton',
        'TTLL_MLL-50': 'ttll_m-50_dilepton',
        'TTLNu-1Jets': 'ttlnu_1J_dilepton',
        'TTTo2L2Nu': 'tt_dilepton', 
        'TTto2L2Nu': 'tt_dilepton',
        'TTToHadronic': 'tt_hadronic',
        'TTToSemiLeptonic': 'tt_semilepton', 
        'TTtoLNu2Q': 'tt_semilepton',
        'DYto2L-4Jets_MLL-50': 'dy_to2L_m-50',
        'DYto2L-4Jets_MLL-50_1J': 'dy_to2L_m-50_1J',
        'DYto2L-4Jets_MLL-50_2J': 'dy_to2L_m-50_2J',
        'DYto2L-4Jets_MLL-50_3J': 'dy_to2L_m-50_3J',
        'DYto2L-4Jets_MLL-50_4J': 'dy_to2L_m-50_4J',
        'DYJetsToLL_M-50': 'dy_m-50',
        'DYJetsToLL_M-50_HT-70to100': 'dy_ht_100', 
        'DYJetsToLL_M-50_HT-100to200': 'dy_ht_200',
        'DYJetsToLL_M-50_HT-200to400': 'dy_ht_400', 
        'DYJetsToLL_M-50_HT-400to600': 'dy_ht_600', 
        'DYJetsToLL_M-50_HT-600to800': 'dy_ht_800', 
        'DYJetsToLL_M-50_HT-800to1200': 'dy_ht_1200',
        'DYJetsToLL_M-50_HT-1200to2500': 'dy_ht_2500', 
        'DYJetsToLL_M-50_HT-2500toInf': 'dy_ht_inf',
        'ttHTobb_M125': 'ttH_HTobb', 
        'TTH_Hto2B_M-125': 'ttH_HTobb', 
        'ttHToNonbb_M125': 'ttH_HToNonbb', 
        'TTHtoNon2B_M-125': 'ttH_HToNonbb', 
        'TTH_Hto2B': 'ttH_HTobb',  
        'TTH_HtoNon2B': 'ttH_HToNonbb',
        'TTTJ': 'tttj', 
        'TTTT': 'tttt', 
        'TTTW': 'tttw',
        'QCD_HT1000to1500': 'qcd_ht_1500',
        'QCD_HT1500to2000': 'qcd_ht_2000',
        'QCD_HT2000toInf': 'qcd_ht_inf',
        'QCD_HT200to300': 'qcd_ht_300',
        'QCD_HT300to500': 'qcd_ht_500',
        'QCD_HT500to700': 'qcd_ht_700',
        'QCD_HT700to1000': 'qcd_ht_1000',
        'QCD-4Jets_HT-600to800': "qcd_4j_ht_600_800",
        'QCD-4Jets_HT-800to1000': 'qcd_4j_ht_800_1000',
        'QCD-4Jets_HT-1000to1200': 'qcd_4j_ht_1000_1200', 
        'QCD-4Jets_HT-1200to1500': 'qcd_4j_ht_1200_1500', 
        'QCD-4Jets_HT-1500to2000': 'qcd_4j_ht_1500_2000',
        'QCD-4Jets_HT-2000': 'qcd_4j_ht_2000',
    }

    MASS_VALUES = ['500', '750', '1000', '1250', '1500', '1750', '2000', '2500', '3000', '4000']
    RELWIDTH_VALUES = ['4','10','20','50']

    for mass in MASS_VALUES:
        for relwidth in RELWIDTH_VALUES:
            process_labels['TTZprimeToTT_M-{}_Width{}'.format(mass, relwidth)] = 'TTZprimeToTT_M-{}_Width{}'.format(mass, relwidth)

    if label in process_labels.keys():
        return process_labels[label]
    else: 
        return None