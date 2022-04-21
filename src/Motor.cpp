#include <Motor.h>
#include <Arduino.h>

Motor::Motor(int pin1, int pin2, int speedPin) {
    _pin1 = pin1;
    _pin2 = pin2;
    _speedPin = speedPin;

    // Set pinMode
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
    pinMode(_speedPin, OUTPUT);
}

void Motor::stop() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
}

void Motor::moveForward(int speed) {
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
    analogWrite(_speedPin, speed);
}

void Motor::moveBackward(int speed) {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
    analogWrite(_speedPin, speed);
}