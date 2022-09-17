

for (int i = 0; i < 2048; i++) {
    double multiplier = 0.5 * (1 - cos(2*PI*i/2047));
    dataOut[i] = multiplier * dataIn[i];
}