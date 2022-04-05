#ifndef UGV_h
#define UGV_h
#include <UGVParameters.h>
#include <Motor.h>

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
        Motor _leftMotor = Motor(1, 2);
        Motor _rightMotor = Motor(3, 4);
};

#endif