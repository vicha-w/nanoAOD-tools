mkdir -p batchprocessor_output
for d in $(ls ../HOTVR_nanoaod/2017_newcuts/*/ -d)
do
    echo "Processing" $(basename $d)
    root -l "postprocessor/single_muon_postprocessor.cpp(\"$d/NANO*.root\", \"batchprocessor_output/$(basename $d).root\")" -q
done