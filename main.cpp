#include "Audiofile/Audiofile.h"
#include "hann.h"
#include "fft_settings.h"
#include "fft.h"
#include <iostream>
#include <string>

int main() {
    const int DAYS = 260;
    const std::string inputFilePath = "./test-audio.wav";
    const char * error = NULL;
    typedef float real_type;
    typedef std::complex<float> complex_type;
    typedef std::vector<real_type> RealArray1D;
    typedef std::vector<complex_type>  ComplexArray1D;

    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);
    std::vector<std::vector<float>> split = hann(DAYS, a.samples[0]);
    std::vector<std::vector<std::complex<float>>> fourierSplit;
    for (int i = 0; i < split.size(); ++i) {
        std::vector<std::complex<float>> l;
        std::vector<float> m = split[i];
        bool b;
        l.resize(split[i].size());
        b = simple_fft::FFT<RealArray1D, ComplexArray1D>(&m, &l, m.size(), error);
        fourierSplit.push_back(l);
        // b = simple_fft::FFT<std::vector<real_type>, std::vector<complex_type>(split[i], fourierSplit[i], split[i].size(), error);
    }
    return 0;
}