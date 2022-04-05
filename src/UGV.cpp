#include <UGV.h>

UGV::UGV() {}

UGV::UGV(UGVParameters &parameters) {
    _parameters = parameters;
    _leftMotor = Motor(_parameters.getMotorLeftPin1(), _parameters.getMotorLeftPin2());
    _rightMotor = Motor(_parameters.getMotorRightPin1(), _parameters.getMotorRightPin2());

    // TODO: setup GPS modules with Tx and Rx pins
}

void UGV::stop() {
    _leftMotor.stop();
    _rightMotor.stop();
}

void UGV::moveForward() {
    _leftMotor.moveForward();
    _rightMotor.moveForward();
}

void UGV::moveBackward() {
    _leftMotor.moveBackward();
    _rightMotor.moveBackward();
}

void UGV::rotateCW() {
    _leftMotor.moveForward();
    _rightMotor.moveBackward();
}

void UGV::rotateCCW() {
    _leftMotor.moveBackward();
    _rightMotor.moveForward();
}

bool UGV::isOnGround() {
    // TODO
    return true;
}

bool UGV::isOnRightDirection() {
    // TODO
    return true;
}

bool UGV::isOnCorrectLocation() {
    Coordinate targetLocation = _parameters.getTargetCoordinate();
    float distance = getCurrentLocation().distanceTo(targetLocation);

    if (distance <= _parameters.getOnLocationThreshold()) return true;
    return false;
}

void UGV::rotateToTargetDirection() {
    // TODO
}

void UGV::moveToLocation(Coordinate coordinate) {
    float distance = getCurrentLocation().distanceTo(coordinate);
    moveForward();
    while (distance <= _parameters.getOnLocationThreshold()) {
        distance = getCurrentLocation().distanceTo(coordinate);
    }
    stop();
}

void UGV::moveToTargetLocation() {
    moveToLocation(_parameters.getTargetCoordinate());
}

Coordinate UGV::getCurrentLocation() {
    return Coordinate(0, 0);
}