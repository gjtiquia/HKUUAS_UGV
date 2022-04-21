#ifndef UGV_h
#define UGV_h
#include <UGVParameters.h>
#include <Motor.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <HCSR04.h>
#include <Wire.h>
#include <QMC5883LCompass.h>


class UGV {
    public:
        UGV();

        // Contructor, pass parameters by reference
        UGV(UGVParameters &parameters, SoftwareSerial &ss, HCSR04 &hc, QMC5883LCompass &compass);

        // Movement Functions
        void stop();
        void moveForward();
        void moveBackward();
        void rotateCW();
        void rotateCCW();

        // Autonomous Functions
        float getDistanceToGround(HCSR04 &hc);
        bool isOnGround(HCSR04 &hc);

        void readCompass(QMC5883LCompass &compass);
        int getDirection(QMC5883LCompass &compass);
        bool isOnRightDirection(QMC5883LCompass &compass);
        void rotateToTargetDirection(QMC5883LCompass &compass);

        bool isOnCorrectLocation(TinyGPSPlus &gps, SoftwareSerial &ss);
        void updateGPS(TinyGPSPlus &gps, SoftwareSerial &ss);
        Coordinate getCurrentLocation(TinyGPSPlus &gps, SoftwareSerial &ss);

        void moveToLocation(TinyGPSPlus &gps, SoftwareSerial &ss, Coordinate coordinate);
        void moveToTargetLocation(TinyGPSPlus &gps, SoftwareSerial &ss);



    private:
        UGVParameters _parameters;
        Motor _leftMotor = Motor(1, 2);
        Motor _rightMotor = Motor(3, 4);
};

#endif