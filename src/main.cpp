#include <Arduino.h>
#include <UGV.h>

UGVParameters parameters;
UGV ugv;

void setup() {
  // Serial Monitor
  Serial.begin(9600);

  // Pins
  parameters.setMotorLeftPin1(4);
  parameters.setMotorLeftPin2(5);
  parameters.setMotorRightPin1(6);
  parameters.setMotorRightPin2(7);

  // Tx and Rx Pin for GPS Module
  parameters.setTxPin(1);
  parameters.setRxPin(0);

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server

  // Set UGV Parameters
  ugv = UGV(parameters);

  // UGV Initial State
  ugv.stop();
}

void loop() {
  // if (!ugv.isOnGround()) 
  //   return;

  // if (!ugv.isOnRightDirection()) {
  //     ugv.rotateToTargetDirection();
  // }

  // if (!ugv.isOnCorrectLocation()) {
  //   ugv.moveToTargetLocation();
  // }
  delay(2000);
  
  ugv.moveForward();
  Serial.println("Move Forward");
  delay(2000);
  Serial.println("Stop");
  ugv.stop();
  delay(2000);

  Serial.println("Move Backward");
  ugv.moveBackward();
  delay(2000);
  Serial.println("Stop");
  ugv.stop();
  delay(2000);

  ugv.rotateCW();
  delay(2000);
  ugv.stop();
  delay(2000);

  ugv.rotateCCW();
  delay(2000);
  ugv.stop();
  delay(2000);
}