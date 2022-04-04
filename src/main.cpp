#include <Arduino.h>
#include <UGVParameters.h>
#include <UGV.h>

UGVParameters parameters;
UGV ugv(parameters);

void setup() {
  // Pins
  parameters.setMotorFrontLeftPin(1);
  parameters.setMotorBackLeftPin(2);
  parameters.setMotorFrontRightPin(3);
  parameters.setMotorBackRightPin(4);
  parameters.setGPSPin(5);

  // Set Target Coordinates
  parameters.setTargetCoordinate(Coordinate(22, 114)); // Update from Interoperability Server
}

void loop() {
  if (!ugv.isOnGround()) return;
  if (!ugv.isOnRightDirection()) return;
  if (!ugv.isOnCorrectLocation()) {
    ugv.moveToTargetLocation();
  }
}