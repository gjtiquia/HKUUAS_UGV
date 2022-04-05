#include <Motor.h>
#include <Arduino.h>

Motor::Motor(int pin1, int pin2) {
    _pin1 = pin1;
    _pin2 = pin2;

    // Set pinMode
    pinMode(_pin1, OUTPUT);
    pinMode(_pin2, OUTPUT);
}

void Motor::stop() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, LOW);
}

void Motor::moveForward() {
    digitalWrite(_pin1, HIGH);
    digitalWrite(_pin2, LOW);
}

void Motor::moveForward() {
    digitalWrite(_pin1, LOW);
    digitalWrite(_pin2, HIGH);
}