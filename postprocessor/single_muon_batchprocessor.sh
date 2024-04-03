#!/bin/bash
export STARTDIR=/afs/cern.ch/user/v/vwachira/CMSSW_11_1_7/src/PhysicsTools/NanoAODTools
cd /afs/cern.ch/user/v/vwachira/CMSSW_11_1_7/src
eval `scramv1 runtime -sh`

cd $STARTDIR

INDIR=$1
OUTDIR=/eos/home-v/vwachira/HOTVR_nanoaod_output/2017/batchprocessor_output/$2.root
ISDATA=$3
UNCMODE=$4

echo "Processing" $INDIR
echo "Writing inputs to" $OUTDIR
echo "isData =" $ISDATA
echo "uncmode =" $UNCMODE

echo "Starting at" $(date)
root -l "postprocessor/single_muon_postprocessor.cpp(\"${INDIR}/NANO*.root\", \"${OUTDIR}\", ${ISDATA}, ${UNCMODE})" -q
echo "Finished at" $(date)