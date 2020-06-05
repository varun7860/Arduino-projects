#include<Servo.h>
#include<RH_ASK.h>
#include<SPI.h> //Serial peripheral interface library


RH_ASK rf_driver;
Servo servo;

String accel;
String str_out;

int ax;  // create the variables for storing int values of string(accel) and string(gyro)
char* a;
int i;
int j;
 

void setup() 
{
  rf_driver.init();
  Serial.begin(9600);
  servo.attach(9);

}

void loop() 
{
    // Set buffer to size of expected message
    uint8_t buf[24];
    uint8_t buflen = sizeof(buf);
 
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {
      
      // Message received with valid checksum
      servo.attach(9);
      Serial.print("The Value of ax: ");
      a = ((char*)buf);
      accel = String(a);
      ax = accel.toInt();
      Serial.println(ax);
    
     
      //Serial.println((char*)buf);          
    }

     if(ax>600)
      {
        Serial.println("Opening the Door");
        servo.write(i);
        delay(1000);
        servo.detach();
      }
      

      else if(ax<600)
      {
       
        Serial.println("Door closed");
        servo.write(180);
        delay(1000);
        servo.detach();
      }
  
}
