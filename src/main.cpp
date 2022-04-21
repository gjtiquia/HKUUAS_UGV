#include <Arduino.h>
#include <UGV.h>

#define LED_PIN 13

// UGV Hardware
UGV ugv;
UGVParameters parameters;

// GPS Module Communication
SoftwareSerial ss(0,0);
TinyGPSPlus gps;
TinyGPSCustom antennaStatus(gps, "GPTXT", 4);

TinyGPSCustom signalStatus1(gps, "GNRMC", 2);
TinyGPSCustom latDirection1(gps, "GNRMC", 4);
TinyGPSCustom latCoordinate(gps, "GNRMC", 3);
TinyGPSCustom lonDirection1(gps, "GNRMC", 6);
TinyGPSCustom lonCoordinate(gps, "GNRMC", 5);

TinyGPSCustom signalStatus2(gps, "GNGLL", 6);

// Distance Sensor
HCSR04 hc(0, 0);

// Compass Sensor
// Must connect SCL at Pin A5, SDA at Pin A4
// Remember to first calibrate the compass
QMC5883LCompass compass;

bool signal1 = false;
bool signal2 = false;

void setup() {
  // Serial Monitor
  Serial.begin(9600);
  Serial.println("Setting up...");

  // Pins
  parameters.setMotorLeftPin1(4);
  parameters.setMotorLeftPin2(5);
  parameters.setMotorRightPin1(6);
  parameters.setMotorRightPin2(7);

  // Tx and Rx Pin for GPS Module
  parameters.setTxPin(2);
  parameters.setRxPin(3);

  // Trig and Echo Pin for Ultrasonic Distance Sensor (HC-SR04)
  parameters.setTrigPin(9);
  parameters.setEchoPin(8);
  parameters.setGroundThreshold(10);

  // GPS baud rate
  parameters.setGPSBaudRate(9600);

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server

  // Set UGV Parameters
  ugv = UGV(parameters, ss, hc, compass);

  // UGV Initial State
  ugv.stop();

  Serial.println("UGV initialized");
}

void loop() {
  // Serial.println("On Ground: " + String(ugv.isOnGround(hc)));

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

  // ugv.updateGPS(gps, ss);

  // // Check antenna status
  // if (antennaStatus.isUpdated()) {
  //   Serial.println(antennaStatus.value());
  // }

  // // Check if have valid GPS signal (V = Void, A = Active)
  // if (signalStatus1.isUpdated()) {
  //   if (String(signalStatus1.value()).equals("V")) {
  //     signal1 = false;
  //     Serial.println("Signal 1: Void");
  //   }
  //   else if (String(signalStatus1.value()).equals("A")) {
  //     signal1 = true;
  //     Serial.println("Signal 1: Active");
  //   }
  // }
  // if (signalStatus2.isUpdated()) {
  //   if (String(signalStatus2.value()).equals("V")) {
  //     signal1 = false;
  //     Serial.println("Signal 2: Void");
  //   }
  //   else if (String(signalStatus2.value()).equals("A")) {
  //     signal2 = true;
  //     Serial.println("Signal 2: Active");
  //   }
  // }

  // // Get GPS location if valid
  // if (signal1 && signal2) {
  //   if (gps.location.isValid()) {
  //     Serial.print(gps.location.lat(), 6);
  //     Serial.print(F(","));
  //     Serial.print(gps.location.lng(), 6);
  //   }
  // }
}