# Smart Segregator
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Smart%20Segregator/Images/Smart%20Segregator.jpg" width="548" height="411"/>

## Description
This segregator can separate dry waste and wet waste successfully.

Note: It cannot segregate plastic or metal. For that you have to use additional Sensors and modules

## Construction
1. I have used 2 acrylic sheets as body of my segregator

2. Servo motor is used as an actuator which will rotate depending on the type of waste (dry or wet)

3. I have used very low cost stationary Scale /Ruler as the shaft of my servo motor. This connects the upper base and servo Motor. I have used Glue gun to stick it.
   - Note: you can also use feviquick as your glue but its risky so use it carefully.
   
4. Moisture sensor is sticked on to upper part of segregator such that when is waste is put it directly lands on sensor. There is also a touch sensor besides it to detect dry waste. This Completes the construction of this project.

## Why touch Sensor when moisture sensor can alone classify the type of waste?
yes its true that moisture can classify wet waste. but it cannot classify dry waste. why? imagine you want to have a neutral state when there is no waste put on the sensor. No matter how much you try you wont be able to achieve this neutral state. The moisture sensor will always be in a dry state. To overcome this problem Touch Sensor is used.

## Working of Smart Segregator Step by Step:

- Step1: Waste is put and lands on moisture sensor.
- Step2: Depending upon the Threshold set Moisture sensor classifies it as dry or wet.
- Step3: As soon step 2 is done Servo Motor runs to either direction depending upon the type of waste and the waste goes in the appropriate compartment.
- Step4: The whole process is autonomous and Continuous.

## Code Explanation

1. Include the necessary Library. Library in C++ is included by `#include<LIBRARY_NAME`. Also create the object of the `Servo Class`

  ```
  #include <Servo.h>
  Servo servo;
  ```

2. Define the I/O pins.
  ```
  //Servo Motor Pin
  int servoPin = 7;

  //Touch Sensor Pin
  int touch_sensor = 2;

  //Moisture Sensor Pin
  int moisture_sensor = 8;
  
  //Formula Variables
  long duration, dist, average;
  long aver[3];
  ```
  
3. Initialize all the I/O Pins in the `void setup()` Function.

 ```
 void setup() 
{
  Serial.begin(9600); //This is used to check Output in serial monitor.
  servo.attach(servoPin); //servo.attach makes servo pin available for signals from Arduino.
  pinMode(touch_sensor, OUTPUT); //Pin mode is used for setting pins as output or input.
  pinMode(moisture_sensor, INPUT);
  servo.write(0); // servo.write rotates the servo motor
  delay(100);
  servo.detach(); // servo.detach() is opposite of servo.attach() function
}
 ```
 
4. Create a function to measure the distance.


## Working Video

[![alt text][1]][2]

[1]: https://github.com/varun7860/Arduino-projects/blob/master/Smart%20Segregator/Images/Output%20Video.jpg
[2]: https://youtu.be/CMIy7llAGi4
