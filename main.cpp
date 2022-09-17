#include <iostream>
#include "AudioFile.h"

int main() {
    const std::string inputFilePath = "./test-audio.wav";
    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);
    for (int i = 0; i < a.getNumSamplesPerChannel(); i++){
        std::cout << a.samples[0][i] << std::endl;
    }
    return 0;
}