#include<vector>
#include <cmath>

std::vector<std::vector<float>> hann(int dayCount, std::vector<float> samples) {
    std::vector<std::vector<float>> split;
    for (int i = 0; i < dayCount; i++){
        long interval = (i != dayCount - 1) ? floor(samples.size()/dayCount) : samples.size() - i*interval;
        std::vector<float> curVec;
        for (int x = 0; x < interval; x++) {
            double multiplier = 0.5 * (1 - cos(2*M_PI*x/interval));
            curVec.push_back(multiplier * samples[i*interval + x]);
        }
        split.push_back(curVec); 
    }
    return split;
}
