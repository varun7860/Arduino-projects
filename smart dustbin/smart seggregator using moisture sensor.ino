#include<Servo.h>
Servo myServo;

int WET= 1; // Wet Indicator at Digital pin D1
int DRY= 3;  // Dry Indicator at Digital pin D3
int sense_Pin = 0; // sensor input at Analog pin A0
int trigPin = 7; // digitalpin at D13
int echoPin = 8; //digitalpin at D15
long duration, dist, average;
long aver[3];


int value = 0;
void setup() 
{
   Serial.begin(9600);
   pinMode(WET, INPUT);
   pinMode(DRY, INPUT);
   pinMode(echoPin, INPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(LED_BUILTIN, OUTPUT);
   delay(2000);
   myServo.attach(2);
}

 void measure()
 {
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dist = (duration/2) /29.1;//obtaining distance
 }

void loop() 
{
  for(int i=0;i<=2;i++) //average distance
  {
    measure();
    aver[i]= dist;
    delay(10); //delay between measurements
  }
   dist = (aver[0]+aver[1]+aver[2])/3;

   Serial.print("MOISTURE LEVEL : ");
   value= analogRead(sense_Pin);
   value= value/10;
   Serial.println(value);

        if(value<102&&dist<10)
        {
            digitalRead(WET);
            digitalRead(echoPin);
            myServo.write(0);
            delay(3000);
            myServo.write(90);
        }
       else if(value==102&&dist<10)
       {
           digitalRead(DRY);
           digitalRead(echoPin);
           myServo.write(180);
           delay(3000);
           myServo.write(90);
       }
       else 
       {
         myServo.write(90);
}
         
       delay(2000);

     //  digitalRead(WET);
      // digitalRead(DRY);
       digitalWrite(trigPin, LOW);
       Serial.print(dist);
}

