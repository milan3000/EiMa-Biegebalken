#include <Arduino.h>
#include <Stepper.h>

Stepper stepper(800, 2, 3, 4, 5);

int stepperSpeed = 100; //in rpm

int pinSensor = A0;
int pinButton = 8;
int pinLimitSwitch = 9;

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
float currentMeasurement = 0; //in mm

void setup() {
  Serial.begin(9600);
  pinMode(pinSensor, INPUT);
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLimitSwitch, INPUT_PULLUP);
  stepper.setSpeed(stepperSpeed);
}

bool checkForButtonPress(){
  return true;
}

void moveToStartPosition(){
  while(digitalRead(pinLimitSwitch) == HIGH){
    stepper.step(-100);
  }
  stepper.step(400);
}

void measureDistance(){
  currentMeasurement = minimumDistance + 0.01953 * analogRead(pinSensor); //the factor 0.01953 comes from the measureable istance of 20mm divided by the adc-resolution of 1024
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