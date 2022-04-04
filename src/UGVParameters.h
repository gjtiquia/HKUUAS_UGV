#ifndef UGVParameters_h
#define UGVParameters_h
#include <Arduino.h>
#include <Coordinate.h>

class UGVParameters {
    public:
        UGVParameters();

        // Setters
        void setMotorFrontLeftPin(int pin);
        void setMotorBackLeftPin(int pin);
        void setMotorFrontRightPin(int pin);
        void setMotorBackRightPin(int pin);
        void setGPSPin(int pin);
        void setTargetCoordinate(Coordinate coordinate);
        void setOnLocationThreshold(float threshold);
        
        // Getters
        int getMotorFrontLeftPin();
        int getMotorBackLeftPin();
        int getMotorFrontRightPin();
        int getMotorBackRightPin();
        int getGPSPin();
        Coordinate getTargetCoordinate();
        float getOnLocationThreshold();

    private:
        int _motorFrontLeftPin = 1;
        int _motorBackLeftPin = 2;
        int _motorFrontRightPin = 3;
        int _motorBackRightPin = 4;
        int _gpsPin = 5;
        Coordinate _targetCoordinate = Coordinate(0, 0);
        float _onLocationThreshold = 3; // Competition requires UGV to be within 10ft (~3m)
};

#endif