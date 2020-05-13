#include<Servo.h>
Servo servo;
int tp=7;
int detect;
int i;
void setup() 
{
  Serial.begin(9600);
  pinMode(tp,INPUT);
  servo.attach(6);
  
}

void loop() 
{ 
    detect=digitalRead(tp);
    Serial.print(detect);
  delay(500);
  while(i++<=180&&detect==LOW)
  {
    delay(30);
    detect=digitalRead(tp);
    Serial.print(detect);
    if(detect==HIGH)
    {
      break;
    }
    else if(detect==LOW)
    {
      servo.write(i);
    }
  }
    while(i-->=0 &&detect==LOW)
    {
      delay(30);
      detect=digitalRead(tp);
      Serial.print(detect);
      if(detect==HIGH) 
      {
        break;
      }
      else if(detect==LOW)
      {
        servo.write(i);
      }
  }
  
}
