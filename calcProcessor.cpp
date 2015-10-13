#include "calcProcessor.h"
#include <cmath>

const float thPow3 = 1000000000;

calcProcessor::calcProcessor()
{
    //ctor
}

calcProcessor::~calcProcessor()
{
    //dtor
}

// 1m, 2 ==> 100 cm
float parseDecScale (float value, int scale) {
    return (value * pow(10, scale));
}

// 1karc, 1 == > 1000arc
float parseThScale (float value, int scale) {
    return (value * pow(1000, scale));
}

//base, mm, mm, g, arc, kg
// -### means error - will be used in gui to display bar message
float calcProcessor (float *wReturn, float hLenght, float hWidth, float hGram, float hCount, float hWeight) {
    if (hLenght == -1) {
        if (hWidth <= 0 || hGram <= 0 || hCount <= 0 || hWeight <= 0) return -200;
        *wReturn = ((hWeight * thPow3) / (hWidth * hGram * hCount));
    } else if (hWidth == -1) {
        if (hLenght <= 0 || hGram <= 0 || hCount <= 0 || hWeight <= 0) return -200;
        *wReturn = ((hWeight * thPow3) / (hLenght * hGram * hCount));
    } else if (hGram == -1) {
        if (hWidth <= 0 || hLenght <= 0 || hCount <= 0 || hWeight <= 0) return -200;
        *wReturn = ((hWeight * thPow3) / (hLenght * hWidth * hCount));
    } else if (hCount == -1) {
        if (hWidth <= 0 || hGram <= 0 || hLenght <= 0 || hWeight <= 0) return -200;
        *wReturn = ((hWeight * thPow3) / (hLenght * hWidth * hGram));
    } else if (hWeight == -1) {
        if (hWidth <= 0 || hGram <= 0 || hCount <= 0 || hLenght <= 0) return -200;
        *wReturn = ((hLenght * hWidth * hGram * hCount) / thPow3);
    } else {
        *wReturn = -199;
    }
}
