# The Sorcerer's Door
- Simple Project that allows you to open door without touching it. Guess how? shuusssh! its Magic!!!

<img src="https://github.com/varun7860/Arduino-projects/blob/master/The%20Sorcerer's%20Door/Images/The%20Sorcerer's%20Door.jpg"  width="504" height="317"/>


## Description

- This is just a simple cool project by which you can open door without Touching it.

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

## Working of Sorcerer's Door Step by Step:
1. Basically there are two arduinos used. Arduino pro mini will be used for transmitting data and Arduino Uno will be used for receiving data.

2. Rf 433 Mhz module allows the wireless transmission between two arduinos. Basically the Transmitter Encodes the data and Receiver decodes the data and feeds it to arduino Uno.

3. Mpu 6050 is 6 axis Accelerometer + Gyroscope. In this project I have used only accelerometer values (ax).

4. Basically Accelerometer measures the ax value and sends it to arduino pro mini. Arduino pro mini receives it and sends it to Rf 433 Mhz Transmitter. The transmitter encodes these values and sends it to Rf 433 Mhz Receiver.

5. The Receiver Decodes it and then sends it to Arduino Uno which is responsible for controlling the Servo Motor. The servo Motor is actuated by Arduino due to which door's knob moves and Door is opened.


## Code Explanation


## Demonstration Video.

