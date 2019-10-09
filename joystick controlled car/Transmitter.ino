#include<RH_ASK.h>
#include<SPI.h>
RH_ASK driver;
 int x=A0;
 int y=A1;
 int sw=2;
int v1=0;
int v2=0;
int X;
int Y;

//make 3 Strings variables to send
String axis1;
String axis2;
String str_out;

void setup() 
{
 Serial.begin(9600);
 driver.init();
 pinMode(x,INPUT);
 pinMode(y,INPUT);
 digitalWrite(sw,HIGH);
}

void loop() 
{
  delay(100);
  v1=analogRead(x);
  v1=map(v1,0,500,0,100);
  v2=analogRead(y);
  v2=map(v2,0,1000,0,600);

  X=v1;
  Y=v2;

  axis1=String(X);
  axis2=String(Y);
  str_out = axis1 + "," + axis2;

  static char*msg =str_out.c_str();
  driver.send((uint8_t*)msg,strlen(msg)); // function to send data
  driver.waitPacketSent();
  delay(1000);

  
  Serial.print("\n \r J1:"); //Print the Values on Serial Monitor
  Serial.print(String(X));
  Serial.print("\n \r J2:");
  Serial.print(String(Y));
}
