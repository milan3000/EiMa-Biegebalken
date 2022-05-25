#include <Arduino.h>
#include <Stepper.h>

int stepsPerRevolution = 800;
int microSteppingFactor = 1;
int trackLength = 350; //in milimeters
int lengthResolution = 1; //in milimeters

int minimumDistance = 30; //in milimeters
float measurement = 0;

void setup() {
  // put your setup code here, to run once:
}

bool checkForButtonPress(){
  return true;
}

void moveToStartPosition(){

}

void runMeasurementSequence(){
  moveToStartPosition();
}

void loop() {
  if(checkForButtonPress() == true){
    runMeasurementSequence();
  }
}