



void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); //Enabel IR emiters
  pinMode(3, OUTPUT); //L motor direction
  pinMode(4, OUTPUT); //R motor direction
  pinMode(5, OUTPUT); //L motor speed?
  pinMode(6, OUTPUT); //R motor speed?
  pinMode(7, OUTPUT); //motor enable
  pinMode(9, INPUT); //Rmotor encoder
  pinMode(10, INPUT); //Lmotor encoder

  digitalWrite(2,HIGH); //Enable IR emitters
  digitalWrite(3,0); //FW L motor
  digitalWrite(4,0); //FW L motor
  digitalWrite(5,0); //FW L motor
  digitalWrite(6,0); //FW R motor  
  digitalWrite(7,HIGH); //turn on the motors

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //lets move the motors
  for(int i=0;i<250;i=i+10){
  analogWrite(3,i);
  analogWrite(4,i);
  Serial.println(i);
  delay(200);
  }
  for(int i=250;i>0;i=i-10){
  analogWrite(3,i);
  analogWrite(4,i);
  
  Serial.println(i);
  delay(200);
  }
  
  //digitalWrite(13,HIGH);
  //digitalWrite(8,HIGH);


  //sensor read
  Serial.print("Front: ");
  Serial.print(analogRead(A2));
  Serial.print("  FrontRight : ");
  Serial.print(analogRead(A1));
  Serial.print("  FrontLeft: ");
  Serial.print(analogRead(A3));
  Serial.print("  Rightwheel: ");
  Serial.print(digitalRead(9));
  Serial.print("  Leftwheel: ");
  Serial.println(digitalRead(10));
  delay(100);
}
