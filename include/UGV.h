#ifndef UGV_h
#define UGV_h
#include <UGVParameters.h>
#include <Motor.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <HCSR04.h>

class UGV {
    public:
        UGV();

        // Contructor, pass parameters by reference
        UGV(UGVParameters &parameters, SoftwareSerial &ss);

        // Movement Functions
        void stop();
        void moveForward();
        void moveBackward();
        void rotateCW();
        void rotateCCW();

        // Autonomous Functions
        float getDistanceToGround(HCSR04 &hc);
        bool isOnGround(HCSR04 &hc);
        bool isOnRightDirection();
        bool isOnCorrectLocation();
        void updateGPS(TinyGPSPlus &gps, SoftwareSerial &ss);
        Coordinate getCurrentLocation();
        void rotateToTargetDirection();
        void moveToLocation(Coordinate coordinate);
        void moveToTargetLocation();

    private:
        UGVParameters _parameters;
        Motor _leftMotor = Motor(1, 2);
        Motor _rightMotor = Motor(3, 4);
};

#endif