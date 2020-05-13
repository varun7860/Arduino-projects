#include<Servo.h>
Servo servo;

int sp =5;
int TS = 7;
int led = 13;
int detect;

void setup()
{
  pinMode(TS, INPUT);
  pinMode(led, OUTPUT);
  servo.attach(sp);
}

void loop() 
{
  detect=digitalRead(TS);
  if(detect==HIGH)
  {
    digitalWrite(led, HIGH);
    servo.write(180);
  }
  else 
  {
    digitalWrite(led,LOW);
    servo.write(0);
  }
}
