#include <UGV.h>


UGV::UGV() {}


UGV::UGV(UGVParameters &parameters, SoftwareSerial &ss, HCSR04 &hc, QMC5883LCompass &compass) {
    _parameters = parameters;
    _leftMotor = Motor(_parameters.getMotorLeftPin1(), _parameters.getMotorLeftPin2());
    _rightMotor = Motor(_parameters.getMotorRightPin1(), _parameters.getMotorRightPin2());

    // GPS Module Setup
    ss = SoftwareSerial(_parameters.getRxPin(), _parameters.getTxPin());
    Serial.println("SoftwareSerial(Rx = " + String(_parameters.getRxPin()) + ", Tx = " + String(_parameters.getTxPin()) + ")");
    ss.begin(_parameters.getGPSBaudRate());
    Serial.println("GPS Serial begin at baudrate = " + String(_parameters.getGPSBaudRate()));

    // Ultrasonic Sensor Setup
    hc = HCSR04(_parameters.getTrigPin(), _parameters.getEchoPin());
    Serial.println("HC-SR04 Ultrasonic Sensor(Trig = " 
                    + String(_parameters.getTrigPin())
                    + ", Echo = "
                    + String(_parameters.getEchoPin())
                    );

    // Compass Setup
    Wire.begin();
    compass.init();
    compass.setCalibration(-1225, 1605, 0, 3366, -1205, 1372); // Calibration outside InnoWing
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

void UGV::readCompass(QMC5883LCompass &compass) {
    int x, y, z, a, b;
	char myArray[3];
	
	compass.read();
  
	x = compass.getX();
	y = compass.getY();
	z = compass.getZ();
	
	a = compass.getAzimuth();
	
	b = compass.getBearing(a);

	compass.getDirection(myArray, a);
  
  
	Serial.print("X: ");
	Serial.print(x);

	Serial.print(" Y: ");
	Serial.print(y);

	Serial.print(" Z: ");
	Serial.print(z);

	Serial.print(" Azimuth: ");
	Serial.print(a);

	Serial.print(" Bearing: ");
	Serial.print(b);

	Serial.print(" Direction: ");
	Serial.print(myArray[0]);
	Serial.print(myArray[1]);
	Serial.print(myArray[2]);

	Serial.println();

	delay(250);
}
