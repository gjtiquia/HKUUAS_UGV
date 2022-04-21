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

  // For Compass
  // MUST connect
  // SCL --> Pin A5
  // SDA --> Pin A4

  // GPS baud rate
  parameters.setGPSBaudRate(9600);

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server

  // Set UGV Parameters
  ugv = UGV(parameters, ss, hc, compass);

  Serial.println("UGV initialized");
}

void loop() {
  ugv.updateGPS(gps, ss);
  if (!ugv.isOnGround(hc)) return;
  if (!ugv.isOnRightDirection(compass))
    ugv.rotateToTargetDirection(compass);
  
}