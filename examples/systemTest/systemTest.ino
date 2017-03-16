//include the robot's header file
#include <MONA.h>
//initialise an object calle mona using the MONA structure
MONA mona;

int16_t proxData[3];
int32_t right_encoder = 0;
int32_t left_encoder = 0;

void setup() {
  // put your setup code here, to run once:
    // put your setup code here, to run once:
  //setup the serial port to use 9600 bauds
  Serial.begin(9600);
  //initialise the motors
  mona.initMotors();
  //initialise the ecoder interrupt polling routine
  //if left blank, the ecoders will be red 100 times each second / value in ms
  mona.initEncoders(10);
  //initialise the proximity sensors
  mona.initProxSensor();
  //move the motor Forward
  //the first value is the PWM value and the second value can be FW or BW, which are 1 and 0 respectively
  mona.setRMotorPWM(255,FW);
  mona.setLMotorPWM(0,BW);

}

void loop() {
    // put your main code here, to run repeatedly:
  //to read each encoder by itself we use
  right_encoder = mona.readREncoder();
  left_encoder = mona.readLEncoder();

  Serial.print("  Right encoder: ");
  Serial.print(right_encoder);
  Serial.print(" Left Encoder: ");
  Serial.println(left_encoder);  
  
  mona.readAllSensors(&proxData[0]);
  //Display all proximity sensors value
  Serial.println("  IR intensity");
  Serial.print("  FrontMiddle : ");
  Serial.print(proxData[1]);
  Serial.print("  FrontRight : ");
  Serial.print(proxData[0]);
  Serial.print("  FrontLeft: ");
  Serial.print(proxData[2]);
  delay(50);
  // put your main code here, to run repeatedly:

}
