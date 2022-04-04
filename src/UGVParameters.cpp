#include <Arduino.h>
#include <UGVParameters.h>

UGVParameters::UGVParameters() {}

void UGVParameters::setMotorFrontLeftPin(int pin) {
    pinMode(pin, OUTPUT);
    _motorFrontLeftPin = pin;
}

void UGVParameters::setMotorBackLeftPin(int pin) {
    pinMode(pin, OUTPUT);
    _motorBackLeftPin = pin;
}

void UGVParameters::setMotorFrontRightPin(int pin) {
    pinMode(pin, OUTPUT);
    _motorFrontRightPin = pin;
}

void UGVParameters::setMotorBackRightPin(int pin) {
    pinMode(pin, OUTPUT);
    _motorBackRightPin = pin;
}

void UGVParameters::setGPSPin(int pin) {
    pinMode(pin, OUTPUT);
    _gpsPin = pin;
}

int UGVParameters::getMotorFrontLeftPin() {
    return _motorFrontLeftPin;
}

int UGVParameters::getMotorBackLeftPin() {
    return _motorBackLeftPin;
}

int UGVParameters::getMotorFrontRightPin() {
    return _motorFrontRightPin;
}

int UGVParameters::getMotorBackRightPin() {
    return _motorBackRightPin;
}

int UGVParameters::getGPSPin() {
    return _gpsPin;
}