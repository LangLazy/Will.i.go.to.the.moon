#include <iostream>
#include "Audiofile.h"
using std::cout;
using std::endl;

int main() {
    const std::string inputFilePath = "./test-audio.wav";
    std::cout << "Hello world!" << std::endl;
        
    AudioFile<float> a;
    bool loadedOK = a.load (inputFilePath);
    
    /** If you hit this assert then the file path above
     probably doesn't refer to a valid audio file */
    assert (loadedOK);
}