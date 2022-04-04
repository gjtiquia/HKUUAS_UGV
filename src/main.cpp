#include <Arduino.h>
#include <UGVParameters.h>
#include <UGV.h>

using namespace std;

UGVParameters parameters;
UGV ugv(parameters);

void setup() {
  parameters.motorFrontLeftPin = 1;
  parameters.motorBackLeftPin = 2;
  parameters.motorFrontRightPin = 3;
  parameters.motorBackRightPin = 4;
  parameters.gpsPin = 5;
}

void loop() {
  // put your main code here, to run repeatedly:
}

int main() {
  setup();
  
}