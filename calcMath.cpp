#include <cmath>

const float thPow3 = 1000000000;

// 1m, 2 ==> 100 cm
float parseDecScale (float value, int scale) {
    return (value * pow(10, scale));
}

// 1karc, 1 == > 1000arc
float parseThScale (float value, int scale) {
    return (value * pow(1000, scale));
}

//base, mm, mm, g, arc, kg
void calcProcessor (float *wReturn, float hLenght, float hWidth, float hGram, float hCount, float hWeight) {
   if (hLenght == -1) {
        *wReturn = ((hWeight * thPow3) / (hWidth * hGram * hCount));
    } else if (hWidth == -1) {
        *wReturn = ((hWeight * thPow3) / (hLenght * hGram * hCount));
    } else if (hGram == -1) {
        *wReturn = ((hWeight * thPow3) / (hLenght * hWidth * hCount));
    } else if (hCount == -1) {
        *wReturn = ((hWeight * thPow3) / (hLenght * hWidth * hGram));
    } else if (hWeight == -1) {
        *wReturn = ((hLenght * hWidth * hGram * hCount) / thPow3);
    } else {
        *wReturn = -1;
    }
}
