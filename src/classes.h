#include "PhysicsTools/NanoAODTools/interface/PyJetResolutionWrapper.h"
#include "PhysicsTools/NanoAODTools/interface/PyJetResolutionScaleFactorWrapper.h"
#include "PhysicsTools/NanoAODTools/interface/PyJetParametersWrapper.h"
#include "PhysicsTools/NanoAODTools/interface/WeightCalculatorFromHistogram.h"
#include "PhysicsTools/NanoAODTools/interface/ReduceMantissa.h"

#include "PhysicsTools/NanoAODTools/src/BTagCorrlibReader.h"
#include "PhysicsTools/NanoAODTools/src/MuonCorrlibReader.h"
#include "PhysicsTools/NanoAODTools/src/MuonCorrlibReader_Run3.h"
#include "PhysicsTools/NanoAODTools/src/ElectronCorrlibReader.h"
#include "PhysicsTools/NanoAODTools/src/HOTVRCorrlibReader.h"
#include "PhysicsTools/NanoAODTools/src/JetVetolibReader.h"

PyJetResolutionWrapper jetRes;
PyJetResolutionScaleFactorWrapper jetResScaleFactor;
PyJetParametersWrapper jetParams;
WeightCalculatorFromHistogram wcalc;
ReduceMantissaToNbitsRounding red(12);

BTagCorrlibReader btagSFReader;
MuonCorrlibReader muonSFReader;
MuonCorrlibReader_Run3 muonSFReader_Run3;
ElectronCorrlibReader electronSFReader;
HOTVRCorrlibReader hotvrSFReader;
JetVetolibReader jetVetoReader;