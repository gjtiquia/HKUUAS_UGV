#include <UGV.h>

UGV::UGV() {}

UGV::UGV(UGVParameters &parameters) {
    _parameters = parameters;
    _leftMotor = Motor(_parameters.getMotorLeftPin1(), _parameters.getMotorLeftPin2());
    _rightMotor = Motor(_parameters.getMotorRightPin1(), _parameters.getMotorRightPin2());

    // TODO: setup GPS modules with Tx and Rx pins
    _gpsSerial = SoftwareSerial(_parameters.getRxPin(), _parameters.getTxPin());
    _gpsSerial.begin(_parameters.getGPSBaudRate());
    Serial.println("GPS Serial begin at baudrate = " + String(_parameters.getGPSBaudRate()));
    Serial.println("Rx Pin: " + String(_parameters.getRxPin()) + ", Tx Pin: " + String(_parameters.getTxPin()));
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

TinyGPSPlus UGV::updateGPS() {
    while (_gpsSerial.available() > 0) {
        Serial.write(_gpsSerial.read());
    }
    return _gps;
}

Coordinate UGV::getCurrentLocation() {
    float lat = _gps.location.lat();
    float lon = _gps.location.lng();
    return Coordinate(lat, lon);
}