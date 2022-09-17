#include<vector>
#include <cmath>

std::vector<std::vector<float>> hann(int dayCount, std::vector<float> samples) {
    std::vector<std::vector<float>> split;
    long interval = floor(samples.size()/dayCount);
    for (int i = 0; i < dayCount; i++){
        long numRepeats = interval;
        if (i == dayCount -1){
            numRepeats = samples.size() - i*interval;
        }
        std::vector<float> curVec;
        for (int x = 0; x < numRepeats; x++) {
            double multiplier = 0.5 * (1 - cos(2*M_PI*x/interval));
            curVec.push_back(multiplier * samples[i*interval + x]);
        }
        split.push_back(curVec); 
    }
    return split;
}
