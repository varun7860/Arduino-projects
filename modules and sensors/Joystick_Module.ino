#include <Servo.h>
Servo servo;
const int x = A0;
const int y = A1;
const int sw = 2;
int val;

void setup() 
{
 pinMode(x, INPUT);
 pinMode(y, INPUT);
 digitalWrite(sw, HIGH);
 servo.attach(5);
}

void loop() 
{
  val = analogRead(y);
  val = map(val, 0, 1023, 0, 180);
  servo.write(val);
  delay(15);
}
