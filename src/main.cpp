#include <Arduino.h>
#include <UGV.h>

#define LED_PIN 13

// UGV Hardware
UGV ugv;
UGVParameters parameters;

// GPS Module Communication
SoftwareSerial ss(0,0);
TinyGPSPlus gps;

// Distance Sensor
HCSR04 hc(0, 0);

// Compass Sensor
// Must connect SCL at Pin A5, SDA at Pin A4
// Remember to first calibrate the compass (refer to QMC5883LCompass GitHub README)
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
  parameters.setMotorLeftSpeedPin(10); // MUST BE PWM PIN

  parameters.setMotorRightPin1(6);
  parameters.setMotorRightPin2(7);
  parameters.setMotorRightSpeedPin(11); // MUST BE PWM PIN

  // Tx and Rx Pin for GPS Module
  // CANNOT BE ON PIN 0 and PIN 1
  parameters.setTxPin(2);
  parameters.setRxPin(3);

  // GPS baud rate
  parameters.setGPSBaudRate(9600);

  // Movement speed
  parameters.setMovementSpeed(150); // [0, 255]

  // Trig and Echo Pin for Ultrasonic Distance Sensor (HC-SR04)
  parameters.setTrigPin(9);
  parameters.setEchoPin(8);
  parameters.setGroundThreshold(10);

  // For Compass
  // MUST connect
  // SCL --> Pin A5
  // SDA --> Pin A4
  parameters.setRotationThreshold(3);
  parameters.setRotationSpeed(100); // [0, 255]

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server

  // Set UGV Parameters
  ugv = UGV(parameters, ss, hc, compass);

  Serial.println("UGV initialized");
}

void loop() {
  ugv.updateGPS(gps, ss);
  if (!ugv.isOnGround(hc)) return;
  if (!ugv.isOnRightDirection(gps, ss, compass))
    ugv.rotateToTargetDirection(hc, gps, ss, compass);
  if (!ugv.isOnCorrectLocation(gps, ss))
    ugv.moveToTargetLocation(hc, gps, ss, compass);
}