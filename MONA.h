#ifndef MONA_H
#define MONA_H

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif
#include "Wire.h"

#include "wire.h"

#define MONA_DEBUG 0 //1 on;0 off

#define MotorEnable 7 //1 on;0 off
//MONA motor configuration
//A PWM has to be set on the A or B
//pins for each motor, depending the direction wanted
#define MotorLeftA 3 //A+!B->FW
#define MotorLeftB 5 //!A+B->BW
#define MotorRightA 4 //A+!B->FW
#define MotorRightB 6 //!A+B->BW

#define TopLED 8
#define BottomLED 13

#define EncoderRight 9
#define EncoderLeft 10

#define ProxEnable 2 //1 on;0 off
#define ProxFront A2
#define ProxFRight A1
#define ProxFLeft A3
