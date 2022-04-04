#include <Arduino.h>
#include <UGVParameters.h>
#include <UGV.h>
#include <Coordinate.h>

UGV::UGV(UGVParameters &parameters) {
    _parameters = parameters;
}

void UGV::stop() {
    // All motors stop
}

void UGV::moveForward() {
    // All motors rotate forward
}

void UGV::rotateCW() {
    // Left motors rotate forward
    // Right motors rotate backwards
}

void UGV::rotateCCW() {
    // Left motors rotate backwards
    // Right motors rotate forwards
}

bool UGV::isOnGround() {
    return true;
}

bool UGV::isOnRightDirection() {
    return true;
}

bool UGV::isOnCorrectLocation() {
    Coordinate targetLocation = _parameters.getTargetCoordinate();
    float distance = getCurrentLocation().distanceTo(targetLocation);

    if (distance <= _parameters.getOnLocationThreshold()) return true;
    return false;
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