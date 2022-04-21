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

        void setTxPin(int pin);
        void setRxPin(int pin);

        void setTrigPin(int pin);
        void setEchoPin(int pin);

        void setGroundThreshold(float threshold);

        void setGPSBaudRate(int baudRate);

        void setTargetCoordinate(Coordinate coordinate);
        void setOnLocationThreshold(float threshold);
        
        // Getters
        int getMotorLeftPin1();
        int getMotorLeftPin2();

        int getMotorRightPin1();
        int getMotorRightPin2();

        int getTxPin();
        int getRxPin();

        int getTrigPin();
        int getEchoPin();

        float getGroundThreshold();

        int getGPSBaudRate();

        Coordinate getTargetCoordinate();
        float getOnLocationThreshold();

    private:
        int _motorLeftPin1 = 2;
        int _motorLeftPin2 = 3;
        int _motorRightPin1 = 4;
        int _motorRightPin2 = 5;
        int _txPin = 6;
        int _rxPin = 7;
        int _trigPin = 8;
        int _echoPin = 9;

        float _groundThreshold = 100;
        int _gpsBaudRate = 9600;
        Coordinate _targetCoordinate = Coordinate(0, 0);
        float _onLocationThreshold = 3; // Competition requires UGV to be within 10ft (~3m)
};

#endif