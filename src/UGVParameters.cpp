#include <Arduino.h>
#include <UGVParameters.h>

UGVParameters::UGVParameters() {}


// Setters

void UGVParameters::setMotorLeftPin1(int pin) {
    _motorLeftPin1 = pin;
}

void UGVParameters::setMotorLeftPin2(int pin) {
    _motorLeftPin2 = pin;
}

void UGVParameters::setMotorRightPin1(int pin) {
    _motorRightPin1 = pin;
}

void UGVParameters::setMotorRightPin2(int pin) {
    _motorRightPin2 = pin;
}

void UGVParameters::setGPSPin(int pin) {
    pinMode(pin, INPUT);
    _gpsPin = pin;
}

void UGVParameters::setTargetCoordinate(Coordinate coordinate) {
    _targetCoordinate = coordinate;
}

void UGVParameters::setOnLocationThreshold(float threshold) {
    _onLocationThreshold = threshold;
}


// Getters

int UGVParameters::getMotorLeftPin1() {
    return _motorLeftPin1;
}

int UGVParameters::getMotorLeftPin2() {
    return _motorLeftPin2;
}

int UGVParameters::getMotorRightPin1() {
    return _motorRightPin1;
}

int UGVParameters::getMotorRightPin2() {
    return _motorRightPin2;
}

int UGVParameters::getGPSPin() {
    return _gpsPin;
}

Coordinate UGVParameters::getTargetCoordinate() {
    return _targetCoordinate;
}

float UGVParameters::getOnLocationThreshold() {
    return _onLocationThreshold;
}
