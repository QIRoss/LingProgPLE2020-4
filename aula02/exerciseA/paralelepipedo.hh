#include <iostream>
using namespace std;

#ifndef PARALELEPIPEDO_HH
#define PARALELEPIPEDO_HH

class Paralelepipedo {
    public:
        Paralelepipedo (double, double, double);

        void setDimX (double);
        void setDimY (double);
        void setDimZ (double);

        double getVolume ();
    private:
        double dimX, dimY, dimZ;
        double computeVolume ();
};

#endif