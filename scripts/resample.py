import numpy as np
import matplotlib.pyplot as plt

#resampling with the pT distribution of the signal as the target distribution
#weights are calculated per bin as the ratio between the frequency of the target
#and the frequency from the distribution to be resampled
#the resampling is done randomly depending on the weights

def resample(sampleList,targetHist,binning,oversample=1., threshold=10):
    hists = []
    weightList = []
    
    for sample in sampleList:
        hist, _ = np.histogram(sample,bins=binning)
        hists.append(hist)
        weight = np.zeros(len(binning)-1)
        for i in range(len(hist)):
            #require number of events to be above a certain threshold
            ntarget = targetHist[i]
            if ntarget<threshold:
                continue
            nsample = hist[i]
            if nsample<threshold:
                continue
            
            #calculate resample weight
            weight[i] = 1.*ntarget/nsample
        weightList.append(weight)
    
    #need to rescale such that events are not oversampled
    maxweight = max(map(lambda x: max(x),weightList))
    for weights in weightList:
        weights *= oversample/maxweight
    
    resampledList, resampledList_idx = [], []
    for sample, weights in zip(sampleList,weightList):
        resampled = []
        resampled_idx = []
        for idx, pt in enumerate(sample):   
            ibin = np.digitize(pt,binning)
            if ibin<0 or ibin>=len(binning):
                continue
            
            #oversample in case weights>1
            for _ in range(int(weights[ibin-1])):
                resampled.append(pt)
                resampled_idx.append(idx)
                
            #randomly resample depending on weight
            if np.random.uniform(0,1)>weights[ibin-1]-int(weights[ibin-1]):
                continue
                
            resampled.append(pt)
            resampled_idx.append(idx)
            
        resampledList.append(resampled)
        resampledList_idx.append(resampled_idx)
    return resampledList, resampledList_idx
