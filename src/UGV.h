#ifndef UGV_h
#define UGV_h
#include <Arduino.h>
#include <UGVParameters.h>
#include <Coordinate.h>

class UGV {
    public:
        UGV();

        // Contructor, pass parameters by reference
        UGV(UGVParameters &parameters);

        // Movement Functions
        void stop();
        void moveForward();
        void rotateCW();
        void rotateCCW();

        // Autonomous Functions
        bool isOnGround();
        bool isOnRightDirection();
        bool isOnCorrectLocation();
        Coordinate getCurrentLocation();
        void rotateToTargetDirection();
        void moveToLocation(Coordinate coordinate);
        void moveToTargetLocation();

    private:
        UGVParameters _parameters;
};

#endif