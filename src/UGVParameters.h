#ifndef UGVParameters_h
#define UGVParameters_h
#include "Arduino.h"

class UGVParameters {
    public:
        // Contructor
        UGVParameters();

        // Setters
        void setMotorFrontLeftPin(int pin);
        void setMotorBackLeftPin(int pin);
        void setMotorFrontRightPin(int pin);
        void setMotorBackRightPin(int pin);
        void setGPSPin(int pin);
        
        // Getters
        int getMotorFrontLeftPin();
        int getMotorBackLeftPin();
        int getMotorFrontRightPin();
        int getMotorBackRightPin();
        int getGPSPin();

    private:
        int _motorFrontLeftPin;
        int _motorBackLeftPin;
        int _motorFrontRightPin;
        int _motorBackRightPin;
        int _gpsPin;
};

#endif