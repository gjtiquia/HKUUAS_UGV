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
        void setMotorLeftSpeedPin(int pin);

        void setMotorRightPin1(int pin);
        void setMotorRightPin2(int pin);
        void setMotorRightSpeedPin(int pin);

        void setTxPin(int pin);
        void setRxPin(int pin);

        void setTrigPin(int pin);
        void setEchoPin(int pin);

        void setGroundThreshold(float threshold);
        void setRotationThreshold(float deg);
        void setRotationSpeed(int speed);
        void setMovementSpeed(int speed);

        void setGPSBaudRate(int baudRate);

        void setTargetCoordinate(Coordinate coordinate);
        void setOnLocationThreshold(float threshold);
        
        // Getters
        int getMotorLeftPin1();
        int getMotorLeftPin2();
        int getMotorLeftSpeedPin();

        int getMotorRightPin1();
        int getMotorRightPin2();
        int getMotorRightSpeedPin();

        int getTxPin();
        int getRxPin();

        int getTrigPin();
        int getEchoPin();

        float getGroundThreshold();
        float getRotationThreshold();
        int getRotationSpeed();
        int getMovementSpeed();

        int getGPSBaudRate();

        Coordinate getTargetCoordinate();
        float getOnLocationThreshold();

    private:
        int _motorLeftPin1 = 2;
        int _motorLeftPin2 = 3;
        int _motorLeftSpeedPin = 10;

        int _motorRightPin1 = 4;
        int _motorRightPin2 = 5;
        int _motorRightSpeedPin = 11;

        int _txPin = 6;
        int _rxPin = 7;
        int _trigPin = 8;
        int _echoPin = 9;

        float _groundThreshold = 100;
        float _rotationThreshold = 3;
        int _rotationSpeed = 255;
        int _movementSpeed = 255;
        int _gpsBaudRate = 9600;
        Coordinate _targetCoordinate = Coordinate(0, 0);
        float _onLocationThreshold = 3; // Competition requires UGV to be within 10ft (~3m)
};

#endif