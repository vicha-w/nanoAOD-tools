#!/bin/bash

# Load necessary environment variables
source /cvmfs/grid.desy.de/etc/profile.d/grid-ui-env.sh

# Set the X509 proxy
export X509_USER_PROXY=/afs/desy.de/user/g/gmilella/.globus/x509 

echo "ARGS: $@"

# Use the CMSSW-specific Singularity container (cmssw-el7)
cmssw-el7 <<EOF

# Inside the container, set up the CMSSW environment
source /cvmfs/cms.cern.ch/cmsset_default.sh
cd /afs/desy.de/user/g/gmilella/ttx3_analysis/CMSSW_11_1_7/src/PhysicsTools/NanoAODTools/processors
cmsenv

# Debugging information
hostname
date
pwd
echo "Executing Python script with arguments: $@"

# Execute the Python script
python /afs/desy.de/user/g/gmilella/ttx3_analysis/CMSSW_11_1_7/src/PhysicsTools/NanoAODTools/processors/ttX3_hotvr.py $@

EOF
