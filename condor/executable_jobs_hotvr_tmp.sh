#!/bin/bash

# Load necessary environment variables
source /cvmfs/grid.desy.de/etc/profile.d/grid-ui-env.sh
source /cvmfs/cms.cern.ch/cmsset_default.sh
export VO_CMS_SW_DIR=/cvmfs/cms.cern.ch
source $VO_CMS_SW_DIR/cmsset_default.sh
export CMSSW_GIT_REFERENCE=/cvmfs/cms.cern.ch/cmssw.git.daily
source $VO_CMS_SW_DIR/cmsset_default.sh

# Set the X509 proxy
export X509_USER_PROXY=/afs/desy.de/user/g/gmilella/.globus/x509 

echo "ARGS: $@"

# Construct the command to run inside Singularity
COMMAND="source /cvmfs/cms.cern.ch/cmsset_default.sh &&
    cd /afs/desy.de/user/g/gmilella/ttx3_analysis/CMSSW_11_1_7/src/PhysicsTools/NanoAODTools/processors/ &&
    eval \$(scramv1 runtime -sh) &&
    hostname &&
    date &&
    pwd &&
    echo \$@ &&
    python /afs/desy.de/user/g/gmilella/ttx3_analysis/CMSSW_11_1_7/src/PhysicsTools/NanoAODTools/processors/ttX3_hotvr.py \$@ --year YEAR"

# Execute the script inside the Singularity container with the bind mounts
singularity exec --bind /nfs:/nfs --bind /pnfs:/pnfs /cvmfs/unpacked.cern.ch/registry.hub.docker.com/cmssw/slc7-installer:latest bash -c "$COMMAND" -- "$@"
