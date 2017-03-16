//include the robot's header file
#include <MONA.h>
//initialise an object calle mona using the MONA structure
MONA mona;
int lapse = 0;
int32_t right_encoder = 0;
int32_t left_encoder = 0;

void setup() {
  // put your setup code here, to run once:
    // put your setup code here, to run once:
  //setup the serial port to use 9600 bauds
  Serial.begin(9600);
  Serial.println("Motor Characterisation routine" );
  Serial.println("initialising motors..." );
  //initialise the motors
  mona.initMotors();
    Serial.println("initialising encodrs..." );
  //initialise the ecoder interrupt polling routine
  //if left blank, the ecoders will be red 100 times each second / value in ms
  mona.initEncoders(10);
  //move the motor Forward
  //the first value is the PWM value and the second value can be FW or BW, which are 1 and 0 respectively
  Serial.println("Stopping the motors..." );
  mona.setRMotorPWM(0,FW);
  mona.setLMotorPWM(0,BW);
  //make sure the encoders are reseted
  mona.resetEncoders();

}

void loop() {
  int rPWM = 180;
  int lPWM = 180;
  int delay_time = 10000;
  delay(1000);
  Serial.println("Starting the motors going FW..." );
  mona.setRMotorPWM(rPWM,FW);
  mona.setLMotorPWM(lPWM,FW);
  Serial.println("Reading encoders..." );
  //wait some time, if going slow, wait even more time
  delay(delay_time);
  right_encoder = mona.readREncoder();
  left_encoder = mona.readLEncoder();
  
  mona.setRMotorPWM(0,BW);
  mona.setLMotorPWM(0,BW);
  
  Serial.print("--> Right encoder ticks going FW @ ");
  Serial.print(rPWM);
  Serial.print(": ");
  Serial.print(right_encoder);
  Serial.print(" Rpm: ");
  Serial.println((right_encoder/6.0/(delay_time/1000.0)));
  Serial.print("--> Left encoder ticks going FW @ ");
  Serial.print(lPWM);
  Serial.print(": ");
  Serial.print(left_encoder);
  Serial.print(" Rpm: ");
  Serial.println((left_encoder/6.0/(delay_time/1000.0)));
  
  //reset the encoders and wait some time before the next test  
  Serial.println("Stopping motors and changing direction");
  mona.resetEncoders();
  delay(1000);
  
  Serial.println("Starting the motors going BW..." );
  mona.setRMotorPWM(rPWM,BW);
  mona.setLMotorPWM(lPWM,BW);
  Serial.println("Reading encoders..." );
  //wait some time, if going slow, wait even more time
  delay(delay_time);
  right_encoder = mona.readREncoder();
  left_encoder = mona.readLEncoder();
  
  mona.setRMotorPWM(0,BW);
  mona.setLMotorPWM(0,BW);
  
  
  Serial.print("--> Right encoder ticks going BW @ ");
  Serial.print(rPWM);
  Serial.print(": ");
  Serial.print(right_encoder);
  Serial.print(" Rpm: ");
  Serial.println((right_encoder/6.0/(delay_time/1000.0)));
  Serial.print("--> Left encoder ticks going BW @ ");
  Serial.print(lPWM);
  Serial.print(": ");
  Serial.print(left_encoder);
  Serial.print(" Rpm: ");
  Serial.println((left_encoder/6.0/(delay_time/1000.0)));
 
  //print to the elapsed time of the sketch
  // put your main code here, to run repeatedly:
  //never ending loop
  while(1){}

}
