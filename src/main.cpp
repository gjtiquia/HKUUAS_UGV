#include <Arduino.h>
#include <UGV.h>

UGVParameters parameters;
SoftwareSerial ss(0,0);
UGV ugv;

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

  // GPS baud rate
  parameters.setGPSBaudRate(9600);

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server

  // Set UGV Parameters
  ugv = UGV(parameters, ss);

  // UGV Initial State
  ugv.stop();

  Serial.println("UGV initialized");
}

void loop() {
  ugv.updateGPS(ss);
}