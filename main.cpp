#include "Audiofile/Audiofile.h"
#include "hann.h"
#include <iostream>
#include <string>
#include <complex>
#include "PGFFT.h"

int main() {
    const int DAYS = 260;
    const std::string inputFilePath = "./test-audio.wav";

    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);
    std::vector<std::vector<float>> split = hann(DAYS, a.samples[0]);
    
    std::vector<std::vector<std::complex<double>>> splitComplex;
    for (int i = 0; i < split.size(); ++i) {
      std::vector<std::complex<double>> splitComplexCandidate;
      for (int j = 0; j < split[i].size(); ++j) {
        std::complex<double> toAdd ((double) split[i][j], 0);
        splitComplexCandidate.push_back(toAdd);
      }
      splitComplex.push_back(splitComplexCandidate);
    }

    std::vector<std::vector<std::complex<double>>> fftComplex;
    // CHANGE 1 BELOW TO splitComplex.size()
    for (int i = 0; i < splitComplex.size(); ++i) {
      PGFFT fft(splitComplex[i].size());
      fft.apply(&(splitComplex[i][0]), &(splitComplex[i][0]));
    }

    std::vector<bool> finalSplit;
    for (int j = 0; j < splitComplex.size(); ++j) {
      double rmax = 0;
      double imax = 0;
      for (int i = 0; i < splitComplex[j].size(); ++i) {
        double absR = std::abs(splitComplex[j][i].real());
        double absI = std::abs(splitComplex[j][i].imag());
        if (absR > rmax) {
          rmax = absR;
        }
        if (absI > imax) {
          imax =  absI;
        } 
      }
      if (rmax >= imax) {
        finalSplit.push_back(true);
      } else {
        finalSplit.push_back(false);
      }
    }
    for (int i = 0; i < finalSplit.size(); ++i) {
      std::cout << finalSplit[i] << std::endl;
    }
    std::cout << finalSplit.size() << std::endl;
    
    return 0;
}
