#include<RH_ASK.h>
#include<SPI.h>

RH_ASK driver;
int v1;
int v2;

//integers
int M1=3;
int M2=4;
int M3=5;
int M4=6;
int ENA=9;
int ENB=10;

//strings
String str_out;
String axis1;
String axis2;

void setup() 
{
  driver.init();
  Serial.begin(9600);
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
}

void forward()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
}

void backward()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
  analogWrite(ENA,255);
  analogWrite(ENB,255);
}

void right()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  analogWrite(ENA,255);
  analogWrite(ENB,0);
}

void left()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
  analogWrite(ENA,0);
  analogWrite(ENB,255);
}

void pause()
{
  analogWrite(ENA,0);
  analogWrite(ENB,0);
}

void loop() 
{
  uint8_t buf[7];
  uint8_t buflen =sizeof(buf);
  if(driver.recv(buf,&buflen))
  {
    str_out =String((char*)buf);

     for(int i=0; i<str_out.length(); i++)
     {
      if(str_out.substring(i,i+1)==",")
        {
          axis1=str_out.substring(0,i);
          axis2=str_out.substring(i+1);
          break;
        }
        Serial.print("J1:");
        Serial.println(axis1);
        Serial.print("J2:");
        Serial.println(axis2);
     }
  }

  v1=axis1.toInt();
  v2=axis2.toInt();

   if(v1==0 && v2>307)
  {
    forward();
  }

   else if(v1>202&&v2<311)
  {
    backward();
  }


  else if(v1>100&&v2<11)
  {
    right();
  }

  else if(v1>100&&v2>610)
  {
    left();
   
  }

  else
  {
    pause();
  }

}
