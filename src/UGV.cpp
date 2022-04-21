#include <UGV.h>

UGV::UGV() {}

UGV::UGV(UGVParameters &parameters, SoftwareSerial &ss, HCSR04 &hc, QMC5883LCompass &compass) {
    _parameters = parameters;
    _leftMotor = Motor(_parameters.getMotorLeftPin1(), _parameters.getMotorLeftPin2(), _parameters.getMotorLeftSpeedPin());
    _rightMotor = Motor(_parameters.getMotorRightPin1(), _parameters.getMotorRightPin2(), _parameters.getMotorRightSpeedPin());
    stop();
    Serial.println("Motors initialized");

    // GPS Module Setup
    ss = SoftwareSerial(_parameters.getRxPin(), _parameters.getTxPin());
    Serial.println("GPS Serial(Rx = Pin " 
                    + String(_parameters.getRxPin()) 
                    + ", Tx = Pin" 
                    + String(_parameters.getTxPin()) 
                    + ")"
                    );
    ss.begin(_parameters.getGPSBaudRate());
    Serial.println("GPS Serial begin at baudrate = " + String(_parameters.getGPSBaudRate()));

    // Ultrasonic Sensor Setup
    hc = HCSR04(_parameters.getTrigPin(), _parameters.getEchoPin());
    Serial.println("HC-SR04 Ultrasonic Sensor(Trig = Pin " 
                    + String(_parameters.getTrigPin())
                    + ", Echo = Pin "
                    + String(_parameters.getEchoPin())
                    + ")"
                    );

    // Compass Setup
    Wire.begin();
    compass.init();
    compass.setCalibration(-1225, 1605, 0, 3366, -1205, 1372); // Calibration outside InnoWing
    Serial.println("Compass initialized and calibrated.");
}


// Movement Functions

void UGV::stop() {
    _leftMotor.stop();
    _rightMotor.stop();
}

void UGV::moveForward(int speed) {
    _leftMotor.moveForward(speed);
    _rightMotor.moveForward(speed);
}

void UGV::moveBackward(int speed) {
    _leftMotor.moveBackward(speed);
    _rightMotor.moveBackward(speed);
}

void UGV::rotateCW(int speed) {
    _leftMotor.moveForward(speed);
    _rightMotor.moveBackward(speed);
}

void UGV::rotateCCW(int speed) {
    _leftMotor.moveBackward(speed);
    _rightMotor.moveForward(speed);
}


// Distance Sensor

float UGV::getDistanceToGround(HCSR04 &hc) {
    float distance = hc.dist();
    delay(60); // prevent trigger signal to the echo signal
    return distance;
}

bool UGV::isOnGround(HCSR04 &hc) {
    float distance = getDistanceToGround(hc);
    if (distance < _parameters.getGroundThreshold()) {
        return true;
    }
    return false;
}


// Compass

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

int UGV::getDirection(QMC5883LCompass &compass) {
    compass.read();
    return compass.getAzimuth();
}

float UGV::calculateBearing(Coordinate a, Coordinate b) {
    // Reference: https://towardsdatascience.com/calculating-the-bearing-between-two-geospatial-coordinates-66203f57e4b4 
    float dL = b.getLon() - a.getLon();
    float X = cos(b.getLat()) * sin(dL);
    float Y = cos(a.getLat()) * sin(b.getLat()) - sin(a.getLat()) * cos(b.getLat()) * cos(dL);
    float bearing = atan2(X,Y);
    
    // Restrict value between [0, 360)
    if (bearing < 0) {
        bearing = 360 + bearing;
    }

    return bearing;
}

bool UGV::isOnRightDirection(TinyGPSPlus &gps, SoftwareSerial &ss, QMC5883LCompass &compass) {
    // TODO
    int currentDirection = getDirection(compass);

    Coordinate currentLocation = getCurrentLocation(gps, ss);
    Coordinate targetLocation = _parameters.getTargetCoordinate();
    float targetDirection = calculateBearing(currentLocation, targetLocation);

    // Check if within threshold
    if (abs(currentDirection - targetDirection) < _parameters.getRotationThreshold())
        return true;
    return false;
}

void UGV::rotateToTargetDirection(HCSR04 &hc, TinyGPSPlus &gps, SoftwareSerial &ss, QMC5883LCompass &compass) {
    Serial.println("Rotating to Target Direction...");
    int rotationSpeed = _parameters.getRotationSpeed();
    if (isOnGround(hc) && !isOnRightDirection(gps, ss, compass))
        rotateCW(rotationSpeed);

    while (isOnGround(hc) && !isOnRightDirection(gps, ss, compass)) {}
    stop();

    Serial.println("Finished rotation");
}


// GPS

void UGV::updateGPS(TinyGPSPlus &gps, SoftwareSerial &ss) {
    while (ss.available() > 0) {
        gps.encode(ss.read());
        // Serial.write(ss.read()); // cannot use together with gps.encode()
    }
}

Coordinate UGV::getCurrentLocation(TinyGPSPlus &gps, SoftwareSerial &ss) {
    updateGPS(gps, ss);
    if (gps.location.isValid()) {
        return Coordinate(gps.location.lat(), gps.location.lng());
    }
    return Coordinate(NULL, NULL);
}

bool UGV::isOnCorrectLocation(TinyGPSPlus &gps, SoftwareSerial &ss) {
    Coordinate targetLocation = _parameters.getTargetCoordinate();
    float distance = getCurrentLocation(gps, ss).distanceTo(targetLocation);

    if (distance <= _parameters.getOnLocationThreshold()) return true;
    return false;
}

void UGV::moveToLocation(HCSR04 &hc, TinyGPSPlus &gps, SoftwareSerial &ss, QMC5883LCompass &compass, Coordinate coordinate) {
    if (!isOnGround(hc)) return;

    float distance = getCurrentLocation(gps, ss).distanceTo(coordinate);
    int movementSpeed = _parameters.getMovementSpeed();
    moveForward(movementSpeed);
    while (distance > _parameters.getOnLocationThreshold()) {
        if (!isOnRightDirection(gps, ss, compass)) {
            stop();
            rotateToTargetDirection(hc, gps, ss, compass);
            moveForward(movementSpeed);
        }

        distance = getCurrentLocation(gps, ss).distanceTo(coordinate);
    }
    stop();
}

void UGV::moveToTargetLocation(HCSR04 &hc, TinyGPSPlus &gps, SoftwareSerial &ss, QMC5883LCompass &compass) {
    moveToLocation(hc, gps, ss, compass, _parameters.getTargetCoordinate());
}





