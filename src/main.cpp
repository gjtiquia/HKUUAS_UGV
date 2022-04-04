#include <Arduino.h>
#include <UGVParameters.h>
#include <UGV.h>

using namespace std;

UGVParameters parameters;
UGV ugv(parameters);

void setup() {
  parameters.setMotorFrontLeftPin(1);
  parameters.setMotorBackLeftPin(2);
  parameters.setMotorFrontRightPin(3);
  parameters.setMotorBackRightPin(4);
  parameters.setGPSPin(5);
}

void loop() {

}