#include<SoftwareSerial.h>
String voice;
int Tx=0;
int Rx=1;
int led=13;
SoftwareSerial bluetooth(Tx,Rx);
void setup() 

{
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() 
{
  while(Serial.available())
  {
    delay(10);
    char c = Serial.read();
    if(c=='#')
    {
      break;
    }
    voice += c;
  }
    if(voice.length()>0)
    
    {

     Serial.println(voice);
      if(voice=="*LED")
      {
        Serial.print("led turns on");
        digitalWrite(led,HIGH);
      }
      voice="";
    }
}
