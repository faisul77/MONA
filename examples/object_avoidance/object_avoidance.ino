//include the robot's header file
#include <MONA.h>
//initialise an object calle mona using the MONA structure
MONA mona;

//make an array to store the proximity sensor data
int16_t proxData[3];

void setup() {
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
}

void loop() {
  // put your main code here, to run repeatedly:
  //read the proximity sensor data as a pointer and store in the proxData array 
  mona.readAllSensors(&proxData[0]);
  //if the robot does not see anything close to it, go forwards
  if(proxData[0]>700 && proxData[1]>700 && proxData[2]>700){
      mona.setRMotorPWM(255,FW);
      mona.setLMotorPWM(255,FW);
    }
  //if the front sensor detects something, avoid fast
  else if(proxData[1]<700){
      mona.setRMotorPWM(255,BW);
      mona.setLMotorPWM(255,FW);
    }
  //if the right sensor detects somethig, avoid, but no so fast
  else if(proxData[0]<950){
      mona.setRMotorPWM(200,FW);
      mona.setLMotorPWM(255,BW);
      delay(500);
    }
  //if the left sensor detects something, also avoid duh    
  else if(proxData[2]<950){
      mona.setRMotorPWM(255,BW);
      mona.setLMotorPWM(200,FW);
      delay(500);
    }

}
