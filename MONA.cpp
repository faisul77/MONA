/***************************************************
  This is a library for the MONA educational mobile robot
  Designed specifically to work with the MONA platform
  ----> http://www.mona.uk
  Written by Jose Espinosa/Farshad Arvid for The University of Manchester.
  TODO:ADDlicense
 ****************************************************/
#include "MONA.h"

MONA::MONA(){
}

void MONA::initMotors(void){
  //setup the pin mode for all the motor related pins
  pinMode(motorEnable, OUTPUT);
  pinMode(motorRightA, OUTPUT);
  pinMode(motorRightB, OUTPUT);
  pinMode(motorLeftA, OUTPUT);
  pinMode(motorLeftB, OUTPUT);
  //enable the use of the motors
  digitalWrite(motorEnable,HIGH);
  //halt the motors
  digitalWrite(motorRightA,LOW);
  digitalWrite(motorRightB,LOW);
  digitalWrite(motorLeftA,LOW);
  digitalWrite(motorLeftB,LOW);

}

void MONA::setRMotorPWM(uint8_t pwm,boolean dir){
  if(dir>0){
    digitalWrite(motorRightB,0);
    analogWrite(motorRightA,pwm);
  }
  else{
    digitalWrite(motorRightA,0);
    analogWrite(motorRightB,pwm);
  }
}

void MONA::setLMotorPWM(uint8_t pwm,boolean dir){
  if(dir>0){
    digitalWrite(motorLeftB,0);
    analogWrite(motorLeftA,pwm);
  }
  else{
    digitalWrite(motorLeftA,0);
    analogWrite(motorLeftB,pwm);
  }
}

void MONA::initProxSensor(void){ //start the proximity sensor IR
  pinMode(proxEnable, OUTPUT); //Enabel IR emiters
  digitalWrite(proxEnable, HIGH); //Enabel IR emiters
}

void MONA::stopProxSensor(void){ //start the proximity sensor IR
  pinMode(proxEnable, LOW); //Disabel IR emiters
}

int16_t MONA::readFRSensor(void){ //retrieve the Front Right distance sensor
  int value = analogRead(proxFRight);
  return value;
}

int16_t MONA::readFMSensor(void){ //retrieve the Front Centre distance sensor
  int value = analogRead(proxFront);
  return value;
}

int16_t MONA::readFLSensor(void){ //retrieve the Front Left distance sensor
  int value = analogRead(proxFLeft);
  return value;
}

void MONA::readAllSensors(int16_t *proxSensors){

  proxSensors[0] = analogRead(proxFRight);
  proxSensors[1] = analogRead(proxFront);
  proxSensors[2] = analogRead(proxFLeft);

}
