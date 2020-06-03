#include <RH_ASK.h>
#include <SPI.h> //Serial peripheral interface library
#include <Servo.h>

Servo servo;
RH_ASK rf_driver;

String accel;
String str_out;

int ax; // create the variables for storing int values of string(accel) and string(gyro)


void setup() 
{
  rf_driver.init();
  Serial.begin(9600);
  servo.attach(9);

}

void loop() 
{
  uint8_t buf[7];  // mention the size of the data... depends on how much data is sent. In this case [7].
  uint8_t buflen = sizeof(buf); // store the whole data ...depends on the user .. if you want you can store  specific part of data.
  if(rf_driver.recv(buf, &buflen))
   {
    str_out = String((char*)buf); //Again recover and seperate the values which were combined in the transmitter program.
    
      for(int i=0; i<str_out.length(); i++)
      {
        if(str_out.substring(i,i+1)==",")
          {
            accel =str_out.substring(0,i);  // create seperate substrings to store the values of accel and gyro
            break;
          }
    Serial.print("X:");  //Print the values
    Serial.println(accel);
      
      }
   }

    ax= accel.toInt(); //Convert the Received string values to Int values.
    
  if(ax>0)
  {
   servo.write(180);
  }
  
  else
  {
    servo.write(0);
  }
    
}  
