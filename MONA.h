#ifndef MONA_H
#define MONA_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"

#include "wire.h"

//activate debugging mode
#define MONA_DEBUG 0 //1 on;0 off

#define MotorEnable 7 //1 on;0 off
//MONA motor configuration
//A PWM has to be set on the A or B
//pins for each motor, depending the direction wanted
#define MotorLeftA 3 //A+!B->FW
#define MotorLeftB 5 //!A+B->BW
#define MotorRightA 4 //A+!B->FW
#define MotorRightB 6 //!A+B->BW
#define FW 1
#define BW 0
#define TopLED 8
#define BottomLED 13

#define EncoderRight 9
#define EncoderLeft 10

#define ProxEnable 2 //1 on;0 off
#define ProxFront A2
#define ProxFRight A1
#define ProxFLeft A3


class MONA{
public:
  MONA();

  void initProxSensor(void); //start the proximity sensor IR
  void stopProxSensor(void); //stop the proximity sensor IR
  int16_t readFRSensor(void); //retrieve the Front Right distance sensor
  int16_t readFMSensor(void); //retrieve the Front distance sensor
  int16_t readFLSensor(void); //retrieve the Front Left distance sensor

  void SetRMotorPWM(uint8_t pwm = 0,boolean dir = FW); //Set Right motor speed and direction
  void SetLMotorPWM(uint8_t pwm = 0,boolean dir = BW); //Set Left motor speed and direction

  void beginEncoders(void); //begin the encoder pulling routine
  void stopEncoders(void); //stop the encoder pulling routine
  boolean readREconder(void); //read the value of the right encoder
  boolean readLEncoder(void); //read the value of the left EncoderLeft
  int32_t rightETicks(void); //read the number of total ticks on the right encoder
  int32_t leftETicks(void); //read the number of total ticks on the left encoder
  void resetREncoder(void); //reset the tick cound for the right encoder
  void resetLEncoder(void); //reset the tick count for the left encoder
  void resetEcoders(void); //reset both encoders' tick counts

}
