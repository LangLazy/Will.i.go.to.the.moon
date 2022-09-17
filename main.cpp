#include <iostream>
#include "Audiofile/Audiofile.h"
#include <cmath>
#include <math.h>
using namespace std;

int main() {
    const string inputFilePath = "./test-audio.wav";
    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);

    long interval = floor(a.getNumSamplesPerChannel()/260);
    vector<vector<float>> split;
    for (int i = 0; i < 260; i++){
        vector<float> curVec;
        if (i != 259){
            for (int x = 0; x < interval; x++) {
                double multiplier = 0.5 * (1 - cos(2*M_PI*x/interval));
                curVec.push_back(multiplier * a.samples[0][i*interval + x]);
            }
            split.push_back(curVec);
        } else{ 
            long newInterval = a.samples[0].size() - i*interval;
            for (int x = 0; x < newInterval; x++) {
                double multiplier = 0.5 * (1 - cos(2*M_PI*x/newInterval));
                curVec.push_back(multiplier * a.samples[0][i*interval + newInterval]);
            }
            split.push_back(curVec);
        }        
    }
    for (int i = 0; i < split.size(); ++i) {
        cout << i << " " << split[i].size() << endl;
    }
    return 0;
}