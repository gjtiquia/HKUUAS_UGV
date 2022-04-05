#include <Arduino.h>
#include <UGV.h>

UGVParameters parameters;
UGV ugv;

void setup() {
  // Pins
  parameters.setMotorLeftPin1(1);
  parameters.setMotorLeftPin2(2);
  parameters.setMotorRightPin1(3);
  parameters.setMotorRightPin2(4);
  parameters.setGPSPin(5);

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server

  // Set UGV Parameters
  ugv = UGV(parameters);

  // UGV Initial State
  ugv.stop();
}

void loop() {
  if (!ugv.isOnGround()) 
    return;

  if (!ugv.isOnRightDirection()) {
      ugv.rotateToTargetDirection();
  }

  if (!ugv.isOnCorrectLocation()) {
    ugv.moveToTargetLocation();
  }
}