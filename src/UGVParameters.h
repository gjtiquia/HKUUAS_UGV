#ifndef UGVParameters_h
#define UGVParameters_h
#include <Arduino.h>
#include <Coordinate.h>

class UGVParameters {
    public:
        UGVParameters();

        // Setters
        void setMotorLeftPin1(int pin);
        void setMotorLeftPin2(int pin);

        void setMotorRightPin1(int pin);
        void setMotorRightPin2(int pin);

        void setGPSPin(int pin);
        void setTargetCoordinate(Coordinate coordinate);
        void setOnLocationThreshold(float threshold);
        
        // Getters
        int getMotorLeftPin1();
        int getMotorLeftPin2();

        int getMotorRightPin1();
        int getMotorRightPin2();

        int getGPSPin();

        Coordinate getTargetCoordinate();
        float getOnLocationThreshold();

    private:
        int _motorLeftPin1 = 1;
        int _motorLeftPin2 = 2;
        int _motorRightPin1 = 3;
        int _motorRightPin2 = 4;
        int _gpsPin = 5;
        Coordinate _targetCoordinate = Coordinate(0, 0);
        float _onLocationThreshold = 3; // Competition requires UGV to be within 10ft (~3m)
};

#endif