#include "MONA.h"
MONA mona;

uint16_t data[3];

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  digitalWrite(2,1);
  Serial.begin(9600);
  mona.initMotors();
  mona.initEncoders(10);//if left blank, the ecoders will be red 100 times each second / value in ms
  mona.initProxSensor();
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //mona.setRMotorPWM(200,BW);
  //mona.setLMotorPWM(255,BW);
  mona.readAllSensors(&data[0]);
  Serial.println(mona.readLEncoder());
  //Serial.print("Front: ");
  //Serial.print(data[1]);
  //Serial.print("  FrontRight : ");
  //Serial.print(data[0]);
  //Serial.print("  FrontLeft: ");
  //Serial.println(data[2]);
  
  delay(1000);
}
