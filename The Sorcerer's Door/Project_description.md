# The Sorcerer's Door

<img src="https://github.com/varun7860/Arduino-projects/blob/master/The%20Sorcerer's%20Door/Images/The%20Sorcerer's%20Door.jpg"  width="312" height="555"/>


## Description

- Simple Project that allows you to open door without touching it. Guess how? shuusssh! its Magic!!!

## Harware Requirements

1. Arduino Pro Mini (x2).
2. RF-433 Mhz Transreceiver module (x1).
3. Glove (x1) : Left handed or Right handed your choice.
4. 9V Rechargable Battery.
5. General purpose PCB (x2).
6. MG-995 Servo Motor (x1).
7. Mpu-6050 (x1).
8. Little strong thread or rope to tie shaft of servo motor and knob of the door.

## Hand tools and fabrication machines

1. Soldering Iron
2. Soldering Wire : Lead free 
3. Soldering Flux
4. Desoldering Pump
5. Wire stripper and cutter
6. Jumper wire kit.

## Software Requirements
- Arduino IDE

## Working of Sorcerer's Door Step by Step:
1. Basically there are two arduinos used. Arduino pro mini will be used for transmitting data and Arduino Uno will be used for receiving data.

2. Rf 433 Mhz module allows the wireless transmission between two arduinos. Basically the Transmitter Encodes the data and Receiver decodes the data and feeds it to arduino Uno.

3. Mpu 6050 is 6 axis Accelerometer + Gyroscope. In this project I have used only accelerometer values (ax).

4. Basically Accelerometer measures the ax value and sends it to arduino pro mini. Arduino pro mini receives it and sends it to Rf 433 Mhz Transmitter. The transmitter encodes these values and sends it to Rf 433 Mhz Receiver.

5. The Receiver Decodes it and then sends it to Arduino Uno which is responsible for controlling the Servo Motor. The servo Motor is actuated by Arduino due to which door's knob moves and Door is opened.


## Code Explanation

- Transmitter Code Explanation

  1. Import the necessary libraries and define the pins
  
  ```
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

  //variables for storing int values of ax and ay as string
  String accel; 
  String str_out;
  ```
  
  2. Initialize the modules in `void setup` function.
  
  ```
  void setup() 
  {
    // Initialize mpu-6050 and I2C Communication protocol.
    mpu.initialize(); 
    Wire.begin();
    
    // Make an instance of ASK.
    rf_driver.init(); 
    
    // Set the serial monitor baud rate.
    Serial.begin(9600); setting up Baud Rate as 9600
  }
  ```
  
  3. Get the Accelerometer in `X-Direction` value using `mpu.getMotion6()` function.
  
  ```
  void loop() 
  {
   delay(100);
   mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  // get the values of ax, ay, az and gx, gy, gz

   X = map(az, -17000, 17000, 300, 600);    //Send X axis data

   ax =  X; //reset the ax value
  ```

  4. Convert the `Int` value to `String`
  
  ```
  accel = String(ax); //int to String Conversion
  str_out = accel; 
  ```
  
  5. Send the data to `Receiver Arduino`
  
  ```
  static char*msg = str_out.c_str();  // store it as msg

  rf_driver.send((uint8_t*)msg,strlen(msg)); // function to send data
  rf_driver.waitPacketSent();
  delay(1000);
 
  Serial.print("\n \r X:"); //Print the Values on Serial Monitor
  Serial.print(String(ax));
  ```
  
- Receiver Code Explanation

  1. Import the necessary libraries and define the pins
  
  ```
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
  ```
  
  2. Initialize the modules in `void setup` function.
 
  ```
  void setup() 
  {
   rf_driver.init();
   Serial.begin(9600);
   servo.attach(9);
  }
  ```
 
  3. Set the buffer to match the size of incoming message.
 
  ```
  uint8_t buf[24];
  uint8_t buflen = sizeof(buf);
  ```
 
  4. Receive the message and check if the size of message is correct. 
 
  ```
  if (rf_driver.recv(buf, &buflen))
   {
      
    // Message received with valid checksum
    servo.attach(9);
    Serial.print("The Value of ax: ");
    a = ((char*)buf);
  ```
 
  5. Convert the value to `String` and then convert it to `Int`
 
  ```
   accel = String(a);
   ax = accel.toInt();
  }
  ```
 
  6. Put the condition to open the door.
 
  ```
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
  ```
 
 

## Demonstration Video.

[![alt text][1]][2]

[1]: https://github.com/varun7860/Arduino-projects/blob/master/The%20Sorcerer's%20Door/Images/Output%20Video.jpg
[2]: https://youtu.be/RCHOyj8d-fY
