# Gesture Controlled Bot
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Gesture%20Controlled%20Car/Images/Gesture%20Controlled%20Car.jpg" width="504" height="317"/>

## Description
This is kind of car that can be controlled by just hand gestures. This project has tremendous applications especially in health domain. For example, a person who is disabled and is on wheelchair can control his wheelchair just by using hand gestures. We know how dangerous it can be to meet a covid-19 positive patient. This project can be used there as well to open doors wirelessly, to supply food to patients through robot or robotic car just by using hand gestures.

## Hardware Required

1. MPU-6050(x1): This is a 3-axis accelerometer(AX, AY, AZ) + 3 axis gyroscope module(GX, GY GZ). In this project we have only made use of accelerometer.
2. Chassis(x1): This is the body of the Robotic Car
3. Arduino Pro Mini (x2): This is the brain of the Transmitter as well as receiver. One Arduino is used for receiving the data while on the other hand one Arduino is used for Transmitting the data.
4. 433Mhz TX RX Module: This module will be used for transmitting and receiving the data from MPU-6050.
5. Other Necessary Components : Jumper Wires, Mini Breadboard, Wheels, Right hand Glove.
6. L298N: This is the Motor Driver to drive the motors of the Car.

## Block Diagram

<img src="https://github.com/varun7860/Arduino-projects/blob/master/Gesture%20Controlled%20Car/Images/Block%20Diagram.jpg" width="582" height="224"/>

## Working

<img src="https://github.com/varun7860/Arduino-projects/blob/master/Gesture%20Controlled%20Car/Images/Gestures.jpg" width="207" height="207"/>

- The above is the figure of the gestures I have used to control the car. When a gesture is made by the user the MPU-6050 values are mapped by Arduino pro mini(Transmitter). 
- The transmitter controller encodes this value as string and transmits it to Receiving Arduino through 433MHZ transmitter module. 
- The receiving Arduino receives the data through 433MHZ Receiver module. When the data is received its in-String Format. 
- The controller converts this “String” into “INT”and then as per the program it controls the car “FORWARD”, “BACKWARD”, “LEFT”, Or “RIGHT”.

## ASK – Amplitude Shift Keying

<img src="https://github.com/varun7860/Arduino-projects/blob/master/Gesture%20Controlled%20Car/Images/ASK.jpg" width="316" height="179"/>

- Amplitude Shift Keying or ASK. This is a simpler method, like Amplitude Modulation or AM radio. Because these modules are very simple, we have used “ASK” in our Code.

- In Amplitude Shift Modulation the amplitude (i.e. the level) of the carrier wave is changed in response to the incoming data signal. This is sometimes called Binary Amplitude Shift Modulation as there really are only two levels to be concerned with:

    - Digital 1 – This drives the carrier at full strength.
    - Digital 0 – This cuts the carrier off completely.

## Advantages
- Operation Of the system Is simple.
- The production cost of the robot is very low
- Low Maintenance is Required
- Operation Is Completely Wireless
- Simple, Fast and Easy Installation

Applications
- Wireless Controlled Robots are very useful in many applications like Remote Surveillance military applications, Bomb Diffusion Robots, etc.
- Hand Gestures controlled robots can be used by Physically challenged in wheelchairs
- Hand Gesture controlled industrial grade robotic arms can be developed.
- These robots can also be used on construction Fields and civil works.

## Code Explanation
## Working Video
