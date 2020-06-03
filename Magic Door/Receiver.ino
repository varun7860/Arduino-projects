#include<RH_ASK.h>
#include<SPI.h>
#include<Servo.h>

Servo servo;
RH_ASK driver;
int v;

//strings
String str_out;
String axis;


void setup() 
{
  driver.init();
  Serial.begin(9600);
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
          axis=str_out.substring(0,i);
          break;
        }
        Serial.print("J1:");
        Serial.println(axis);
     }
  }

  v=axis.toInt();

  if(v >0)
  {
    servo.write(180);
  }

  else
  {
    servo.write(0);
  }
}
