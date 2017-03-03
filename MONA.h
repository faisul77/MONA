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

#define MotorLeftDir 3 //1 fw;0 bw
#define MotorRightDir 4 //1 fw;0 bw

#define MotorLeftSpeed 5 //0-255
#define MotorRightSpeed 6 //0-255

#define TopLED 8
#define BottomLED 13

#define EncoderRight 9
#define EncoderLeft 10

#define ProxEnable 2 //1 on;0 off
#define ProxFront A2
#define ProxFRight A1
#define ProxFLeft A3
