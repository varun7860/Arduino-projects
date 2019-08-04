#include <RH_ASK.h> //Radio head ASK Library
#include <SPI.h>
#include <Wire.h>       //For communicate
#include <I2C.h>     //For communicate with MPU6050
#include <MPU6050.h>  //The main library of the MPU6050

RH_ASK rf_driver; 
MPU6050 mpu;       // Instance of MPU6050
int16_t ax, ay, az;
int16_t gx, gy, gz;

int X =0;  // variables  for storing  values of ax and ay
int Y =0;

//variables for storing int values of ax and ay as string
String accel; 
String gyro;
String str_out;

void setup() 
{
  mpu.initialize(); // wake up MPU6050
  Wire.begin();     //  necessary for I2C communication
  rf_driver.init();  Instance of ASK
  Serial.begin(9600); setting up Baud Rate as 9600
}

void loop() 
{
  delay(100);
   mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  // get the values of ax, ay, az and gx, gy, gz

  X = map(az, -17000, 17000, 300, 600);    //Send X axis data
  Y = map(ay, -17000, 17000, 0, 300);     //Send Y axis data

  ax =  X; 
  ay =  Y;

  accel = String(ax); //int to String Conversion
  gyro =  String(ay);
  str_out = accel + "," + gyro; //combine the values for sending to other Arduino

  static char*msg = str_out.c_str();  // store it as msg

  rf_driver.send((uint8_t*)msg,strlen(msg)); // function to send data
  rf_driver.waitPacketSent();
  delay(1000);
 
  Serial.print("\n \r X:"); //Print the Values on Serial Monitor
  Serial.print(String(ax));
  Serial.print("\n \r Y:");
  Serial.print(String(ay));
}
