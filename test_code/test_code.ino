#include "MONA.h"
MONA mona;

uint16_t data[3];

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  digitalWrite(2,1);
  mona.initMotors();
  //mona.initProxSensor();
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //lets move the motors
  mona.readAllSensors(&data[0]);
  Serial.print("Front: ");
  Serial.print(data[1]);
  Serial.print("  FrontRight : ");
  Serial.print(data[0]);
  Serial.print("  FrontLeft: ");
  Serial.println(data[2]);
  delay(100);
}
