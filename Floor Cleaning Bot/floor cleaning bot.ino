#include<SoftwareSerial.h>
int TX=0;
int RX=1;
SoftwareSerial Blue(TX,RX);
String button;
int Rp1=9;//cleaning motor pin
int Rp2=10;//water pump pin
const int M1=2;
const int M2=3;
const int M3=4;
const int M4=5;
//const int ENA=9;
//const int ENB=10;

void setup() 
{
  Serial.begin(9600);
  pinMode(Rp1,OUTPUT);
  pinMode(Rp2,OUTPUT);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  digitalWrite(Rp1,HIGH);
  digitalWrite(Rp2,HIGH);
  //pinMode(ENA,OUTPUT);
  //pinMode(ENB,OUTPUT);
}

void forward()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
}

void backward()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
}

void right()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
}

void left()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
}

void pause()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  digitalWrite(Rp1,HIGH);
  digitalWrite(Rp2,HIGH);
}

void clean()
{
  
}

void Autonomous()

{
  forward();
  clean();
  forward();
  clean();
  forward();
  clean();
  
}

void loop() 
{
  while (Serial.available())//Check if there is an available byte to read
  { 
    delay(10); //Delay added to make thing stable 
    char c = Serial.read(); //Conduct a serial read
    if (c == '#') 
    {
      break; //Exit the loop when the # is detected after the word
    } 
    button += c; //Shorthand for voice = voice + c
  }
  
  if(button.length()>0)
  {
    Serial.println(button);

    
    if(button=="*front")
    {
      Serial.println("go forward");
      forward();
    }
     if(button=="*back")
     {
       Serial.println("GO backward");
       backward();
     }
     if(button=="*right")
     {
       Serial.println("GO right");
       right();
     }

     if(button=="*left")
     {
       Serial.println("GO left");
       left();
     }

     if(button=="*water")
     {
       Serial.println("Turn the pump on");
       digitalWrite(Rp2,LOW);
     }

     if(button=="*clean")
     {
       Serial.println("Turn the cleaning motor on");
       digitalWrite(Rp1,LOW);
     }

     
     if(button=="*Autonomous")
     {
       Serial.println("Entered Autonomous Mode");
       Autonomous();
     }

     if(button=="*pause")
     {
       Serial.println("Entered Autonomous Mode");
       pause();
     }
      button = "";
    }
  }
