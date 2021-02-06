# Smart Segregator

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

- step1: Waste is put and lands on moisture sensor.
- Step2: Depending upon the Threshold set Moisture sensor classifies it as dry or wet.
- Step3: As soon step 2 is done Servo Motor runs to either direction depending upon the type of waste and the waste goes in the appropriate compartment.
- step4: The whole process is autonomous and Continuous.

## Code Explanation

## Working Video
