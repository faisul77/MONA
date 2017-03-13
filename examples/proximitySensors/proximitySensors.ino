//include the robot's header file
#include <MONA.h>
//initialise an object calle mona using the MONA structure
MONA mona;

//make an array to store the proximity sensor data
uint16_t proxData[3];



void setup() {
  // put your setup code here, to run once:
  //setup the serial port to use 9600 bauds
  Serial.begin(9600);
  //initialise the proximity sensors
  mona.initProxSensor();
}

void loop() {
  // put your main code here, to run repeatedly:
  //Read all the proximity sensors at once, use the proxData array
  mona.readAllSensors(&proxData[0]);
  //Display all proximity sensors value
  Serial.print("  FrontMiddle : ");
  Serial.print(proxData[1]);
  Serial.print("  FrontRight : ");
  Serial.print(proxData[0]);
  Serial.print("  FrontLeft: ");
  Serial.println(proxData[2]);

  //An other way to do this is:
  //read the Front Right proximity sensor
  proxData[0] = mona.readFRSensor();
  //read the Front Middle proximity sensor
  proxData[1] = mona.readFMSensor();
  //read the Front Left proximity sensor
  proxData[2] = mona.readFLSensor();

  //Turn off the IR emiter to off the proximity sensors
  mona.stopProxSensors();
  //Tis is useful to measure the 'ambient IR 'light'
  //useful for calibration routines
  //have a small delay to let the IR sensor turn off
  delay(50);

  mona.readAllSensors(&proxData[0]);

  //Display the ambient IR 'light'
  Serial.println("Ambien IR");
  Serial.print("  FrontMiddle : ");
  Serial.print(proxData[1]);
  Serial.print("  FrontRight : ");
  Serial.print(proxData[0]);
  Serial.print("  FrontLeft: ");
  Serial.println(proxData[2]);

  //A small delay to avoid Printing too fast on the Serial console
  delay(50);
}
