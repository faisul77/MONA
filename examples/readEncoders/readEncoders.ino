//include the robot's header file
#include <MONA.h>
//initialise an object calle mona using the MONA structure
MONA mona;

int32_t right_encoder = 0;
int32_t left_encoder = 0;



void setup() {
  // put your setup code here, to run once:
  //setup the serial port to use 9600 bauds
  Serial.begin(9600);
  //initialise the motors
  mona.initMotors();
  //initialise the ecoder interrupt polling routine
  //if left blank, the ecoders will be red 100 times each second / value in ms
  mona.initEncoders(10);
  //move the motor Forward
  //the first value is the PWM value and the second value can be FW or BW, which are 1 and 0 respectively
  mona.setRMotorPWM(255,FW);
  mona.setLMotorPWM(255,FW);
}

void loop() {
  // put your main code here, to run repeatedly:
  //to read each encoder by itself we use
  right_encoder = mona.readREncoder();
  left_encoder = mona.readLEncoder();

  Serial.print("  Right encoder: ");
  Serial.print(right_encoder);
  Serial.print(" Left Encoer: ");
  Serial.println(left_encoder);
  //if you need to reset the encoders you can use:
  //resetEcoders(); -->reset both encoders
  //resetREncoder(); -->resets only the Right encoders
  //resetLEncoder(); --> resets only the Left encoder
  //it is important to note that each wheel has 12 'ticks' per full rotation

  delay(50);
}
