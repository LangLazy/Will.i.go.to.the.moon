#include "Audiofile/Audiofile.h"
#include "hann.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main() {
    const int DAYS = 260;
    const string inputFilePath = "./test-audio.wav";

    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);
    std::vector<std::vector<float>> split = hann(DAYS, a.samples[0]);
    for (int i = 0; i < split.size(); ++i) {
        cout << i << " " << split[i].size() << endl;
    }
    return 0;
}