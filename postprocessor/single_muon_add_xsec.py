import ROOT as pyr
import argparse
from array import array
import yaml
import os

parser = argparse.ArgumentParser()
#parser.add_argument("filename", help="ROOT file name with TTree to add cross section weight")
#parser.add_argument("xsec", help="Cross section of the process, in pb")
parser.add_argument("specfile", help="YAML spec file path, containing ROOT files and cross section (in pb!), cross section weight will be scaled to 1 fb-1")
parser.add_argument("--treename", help="TTree name to add a new branch", default="Events")

args = parser.parse_args()
with open(args.specfile) as yamlfile:
    yamlspec = yaml.safe_load(yamlfile)

for process in yamlspec.keys():
    print(f"Working with {process}")
    print(yamlspec[process])
    for filename in yamlspec[process].keys():
        xsec = float(yamlspec[process][filename])
        print(f"Adding cross section of {xsec} to {filename}")
        rootfile = pyr.TFile(filename, "UPDATE")
        roottree = rootfile.Get(args.treename)

        xsec_in_fb = array('f', [0])
        b = roottree.Branch("xsecWeight", xsec_in_fb, "xsecWeight/F")
        xsec_in_fb[0] = xsec*1000

        #b.SetBasketSize(roottree.GetEntries() * 2)  # be sure we do not trigger flushing
        #for i in range(roottree.GetEntries()):
        #    b.Fill()
        for _ in range(roottree.GetEntries()): b.Fill()

        b.ResetAddress()
        roottree.Write(args.treename, pyr.TObject.kOverwrite)
        rootfile.Close()

    print(f"Writing {process}")
    #outrootfile = pyr.TFile(process, "RECREATE")
    outchain = pyr.TChain(args.treename)
    for filename in yamlspec[process].keys(): outchain.Add(filename)
    outchain.Merge(process)