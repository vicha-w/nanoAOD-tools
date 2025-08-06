#!/bin/bash
echo "Currently at" $(pwd)

export STARTDIR=/afs/cern.ch/user/v/vwachira/CMSSW_11_1_7/src/PhysicsTools/NanoAODTools
cd /afs/cern.ch/user/v/vwachira/CMSSW_11_1_7/src
#eval `scramv1 runtime -sh`

echo "Contents in /cvmfs/cms.cern.ch/common/"
ls -l /cvmfs/cms.cern.ch/common/
echo

/cvmfs/cms.cern.ch/common/scramv1 runtime -sh
eval `/cvmfs/cms.cern.ch/common/scramv1 runtime -sh`

cd $STARTDIR

YEAR=$5
INDIR=$1
OUTDIR=/eos/home-v/vwachira/HOTVR_nanoaod_output/$YEAR/batchprocessor_output/$2
ISDATA=$3
UNCMODE=$4

mkdir -p $(dirname $OUTDIR)

echo "Processing" $INDIR
echo "Writing inputs to" $OUTDIR
echo "isData =" $ISDATA
echo "uncmode =" $UNCMODE

echo "Starting at" $(date)
root -l "postprocessor/single_muon_postprocessor.cpp(\"${INDIR}/NANO*.root\", \"${OUTDIR}\", ${ISDATA}, ${UNCMODE})" -q
echo "Finished at" $(date)
