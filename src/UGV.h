#ifndef UGV_h
#define UGV_h
#include "Arduino.h"
#include "UGVParameters.h"

class UGV {
    public:
        // Contructor
        UGV(UGVParameters parameters);

    private:
        UGVParameters _parameters;
};

#endif