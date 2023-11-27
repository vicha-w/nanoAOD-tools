function run_test()
{
    cd ~
    source /cvmfs/cms.cern.ch/cmsset_default.sh
    export SCRAM_ARCH=slc7_amd64_gcc820 || return 1
    echo
    echo "==================== setup CMSSW ==============="
    scramv1 project CMSSW CMSSW_11_1_7 || return 1
    cd CMSSW_11_1_7/src || return 1
    eval `scram runtime -sh` || return 1
    mkdir -p PhysicsTools/NanoAODTools
    rsync -r --stats /scripts/ PhysicsTools/NanoAODTools/. || return 1
    echo
    echo "==================== compiling ================"
    scram b || return 1
    
    echo
    echo "==================== MC ==============="
    python PhysicsTools/NanoAODTools/processors/ttX3_hotvr.py --year 2018 -i PhysicsTools/NanoAODTools/test/test_files/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8_2018_hotvr.root --maxEvents 1000 . || return 1

    echo "==================== data ==============="
    python PhysicsTools/NanoAODTools/processors/ttX3_hotvr.py --year 2018 -i PhysicsTools/NanoAODTools/test/test_files/DoubleMuon_Run2018A_hotvr.root --isData --trigger mumu --maxEvents 1000 . || return 1

    echo "==================== signal ==============="
    python PhysicsTools/NanoAODTools/processors/ttX3_hotvr.py --year 2018 -i PhysicsTools/NanoAODTools/test/test_files/TopPhilic_tttt_mass1000_relwidth4_2018_hotvr.root --isSignal --maxEvents 1000 . || return 1

    
    echo "==================== done ====================="
}

run_test
