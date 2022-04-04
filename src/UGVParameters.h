#ifndef UGVParameters_h
#define UGVParameters_h
#include "Arduino.h"

class UGVParameters {
    public:
        // Contructor
        UGVParameters();
        
        // Public variables
        int motorFrontLeftPin;
        int motorBackLeftPin;
        int motorFrontRightPin;
        int motorBackRightPin;

        int gpsPin;

    private:
};

#endif