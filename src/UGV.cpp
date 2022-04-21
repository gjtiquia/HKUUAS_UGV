#include <UGV.h>


UGV::UGV() {}


UGV::UGV(UGVParameters &parameters, SoftwareSerial &ss) {
    _parameters = parameters;
    _leftMotor = Motor(_parameters.getMotorLeftPin1(), _parameters.getMotorLeftPin2());
    _rightMotor = Motor(_parameters.getMotorRightPin1(), _parameters.getMotorRightPin2());

    // TODO: setup GPS modules with Tx and Rx pins
    ss = SoftwareSerial(_parameters.getRxPin(), _parameters.getTxPin());
    Serial.println("SoftwareSerial(" + String(_parameters.getRxPin()) + ", " + String(_parameters.getTxPin()) + ")");
    ss.begin(_parameters.getGPSBaudRate());
    Serial.println("GPS Serial begin at baudrate = " + String(_parameters.getGPSBaudRate()));
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

bool UGV::isOnGround(HCSR04 &hc) {
    float distance = getDistanceToGround(hc);
    
    if (distance < _parameters.getGroundThreshold()) {
        return true;
    }

    return false;
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

void UGV::updateGPS(TinyGPSPlus &gps, SoftwareSerial &ss) {
    // Serial.println(_gpsSerial.isListening());
    while (ss.available() > 0) {
        gps.encode(ss.read());
        // Serial.write(ss.read()); // cannot use together with gps.encode()
    }
}

Coordinate UGV::getCurrentLocation() {
    // TODO
}

float UGV::getDistanceToGround(HCSR04 &hc) {
    float distance = hc.dist();
    delay(60); // prevent trigger signal to the echo signal
    return distance;
}
