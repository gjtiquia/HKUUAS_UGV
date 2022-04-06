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

void UGVParameters::setTxPin(int pin) {
    _txPin = pin;
}

void UGVParameters::setRxPin(int pin) {
    _rxPin = pin;
}

void UGVParameters::setTargetCoordinate(Coordinate coordinate) {
    _targetCoordinate = coordinate;
}

void UGVParameters::setOnLocationThreshold(float threshold) {
    _onLocationThreshold = threshold;
}

void UGVParameters::setGPSBaudRate(int baudRate) {
    _gpsBaudRate = baudRate;
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

int UGVParameters::getTxPin() {
    return _txPin;
}

int UGVParameters::getRxPin() {
    return _rxPin;
}

int UGVParameters::getGPSBaudRate() {
    return _gpsBaudRate;
}

Coordinate UGVParameters::getTargetCoordinate() {
    return _targetCoordinate;
}

float UGVParameters::getOnLocationThreshold() {
    return _onLocationThreshold;
}
