/*setting pwm of the motor to 255
we can change the speed of rotaion
by changing pwm input but we are only
using arduino so we are using higest
value to driver the motor  */

#include<Servo.h>
#include <SoftwareSerial.h>
String voice;
Servo myServo; 
int TxD = 0;
int RxD = 1;  
SoftwareSerial bluetooth(TxD,RxD); //TX, RX respetively        
int motorPin1 = 3;
int motorPin2 = 4;
int motorPin3 = 5;
int motorPin4 = 6;
int servoPin = 7;
int ENA1 = 9;
int ENA2 = 10;

void setup() 
{
  //BT.begin(9600);
  bluetooth.begin(9600);
  Serial.begin(9600);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(ENA1, OUTPUT);
  pinMode(ENA2, OUTPUT);
  myServo.write(90);
  myServo.attach(7);
}


void forward()
{
  delay(100);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(ENA1, 255);
  analogWrite(ENA2, 255);
  delay(2000);
  pause();
}


void backward()
{
  delay(100);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(ENA1, 255);
  analogWrite(ENA2, 255);
  delay(2000);
  pause();
}


void pause()
{
  delay(100);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
} 

void right()
{
  myServo.write(0);
  delay(1000);
  myServo.write(90);
  delay(1000);
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, LOW);
  analogWrite(ENA1, 255);
  analogWrite(ENA2,0);
  delay(2000);
  pause();
}

void left()

{
  myServo.write(180);
  delay(1000);
  myServo.write(90);
  delay(1000);
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(ENA1,0);
  analogWrite(ENA2, 255);
  delay(2000);
  pause();
}


void loop() 
{
  while (Serial.available())//Check if there is an available byte to read
  { 
     delay(10);  //Delay added to make thing stable 
    char c = Serial.read();  //Conduct a serial read
    if (c == '#') 
    {
      break; //Exit the loop when the # is detected after the word
    } 
    voice += c; 
  }
  
  if(voice.length()>0)
  {
    Serial.println(voice);

    
    if(voice=="*forward")
    {
      Serial.println("move forward");
      forward();
    }

       if(voice=="*backward")
    {
      Serial.println("move backward");
      backward();
    }
       if(voice=="*right")
    {
      Serial.println("right");
      right();
    }
       if(voice=="*left")
    {
      Serial.println("left");
      left();
    }
    if(voice=="*stop")
    {
      Serial.println("stop");
      pause();
    }

    voice = ""; //Reset the variable after initiating
  }
}
