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

        // Movement
        // Speed = [0, 255]
        void stop();
        void moveForward(int speed);
        void moveBackward(int speed);
        void rotateCW(int speed);
        void rotateCCW(int speed);


        // Distance Sensor
        float getDistanceToGround(HCSR04 &hc);
        bool isOnGround(HCSR04 &hc);

        // Compass
        void readCompass(QMC5883LCompass &compass);
        int getDirection(QMC5883LCompass &compass);
        float calculateBearing(Coordinate coor1, Coordinate coo2); // returns [0, 360)
        bool isOnRightDirection(TinyGPSPlus &gps, SoftwareSerial &ss, QMC5883LCompass &compass);
        void rotateToTargetDirection(HCSR04 &hc, TinyGPSPlus &gps, SoftwareSerial &ss, QMC5883LCompass &compass);

        // GPS
        void updateGPS(TinyGPSPlus &gps, SoftwareSerial &ss);
        bool isOnCorrectLocation(TinyGPSPlus &gps, SoftwareSerial &ss);
        Coordinate getCurrentLocation(TinyGPSPlus &gps, SoftwareSerial &ss);
        void moveToLocation(TinyGPSPlus &gps, SoftwareSerial &ss, Coordinate coordinate);
        void moveToTargetLocation(TinyGPSPlus &gps, SoftwareSerial &ss);



    private:
        UGVParameters _parameters;
        Motor _leftMotor = Motor(1, 2, 255);
        Motor _rightMotor = Motor(3, 4, 255);
};

#endif