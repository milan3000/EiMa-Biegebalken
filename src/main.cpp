#include <Arduino.h>
#include <Stepper.h>

int pinSensor = A0;
int pinButton = 8;

const int stepsPerRevolution = 800;
const int microSteppingFactor = 1;
const int spindlePitch = 3; //in mm
const int trackLength = 350; //in mm
const float resolution = 1; //in mm
int numberOfDataPoints = trackLength/resolution;
int stepsPerDataPoint = resolution * (stepsPerRevolution / spindlePitch);

int xAxisZeroOffset = 20; //in mm
int xAxisIndex = 0; 

int minimumDistance = 30; //in mm
float measurement = 0;

void setup() {
  Serial.begin(9600);
}

bool checkForButtonPress(){
  return true;
}

void moveToStartPosition(){

}

void measureDistance(){

}

void sendDistanceOverSerial(){

}

void moveStepper(){

}

void runMeasurementSequence(){
  moveToStartPosition();
  while(xAxisIndex < numberOfDataPoints){
    measureDistance();
    sendDistanceOverSerial();
    moveStepper();
  }
}

void loop() {
  if(checkForButtonPress() == true){
    runMeasurementSequence();
  }
}