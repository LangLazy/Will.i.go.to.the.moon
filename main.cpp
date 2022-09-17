#include "Audiofile/Audiofile.h"
#include "hann.h"
#include <iostream>
#include <string>
#include <sstream> 

std::vector<std::string> getAllTickers(std::string path);

void printStocks(std::string startDate);
struct {             // Structure declaration
  float price;         // Member (int variable)
  std::string ticker;   // Member (string variable)
} choiceStruct;


int main() {
    const int DAYS = 260;
    const std::string inputFilePath = "./test-audio.wav";
    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);
    std::vector<std::vector<float>> split = hann(DAYS, a.samples[0]);
    std::vector<std::string> tickers = getAllTickers("tickers.csv");
    std::cout << tickers.size() << std::endl;
    return 0;
}

std::vector<std::string> getAllTickers(std::string path){
    std::ifstream file(path);
    std::string holder;
    std::vector<std::string> ans;
    while (std::getline(file, holder, ',')){
        ans.push_back(holder);
    }
    return ans;
}

// std::vector<choiceStruct> getTwo(){

// }