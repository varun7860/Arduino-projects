# COVID'19 Electronic Gesture Controlled Mask
This is a COVID'19 Mask which can be controlled by hand gestures.This mask can recognize two kinds of gestures which are 
"UP" and "DOWN". UP gesture is used for covering up the face (making mask move up) and DOWN gesture is used to expose the 
face (making the mask go down).

## Hardware Used
1. Arduino Pro Mini(x1): This will be brain of the device. It will be used to control all the parts of the device.
2. Ice Cream Sticks(x12): Will be used for constructing chassis.
3. Gesture Sensor(x1): Will be used to recognize gestures performed by the user.
4. Servo Motors(x2): These will be used to move the mask up or down.
5. Dumy spectacles as chassis(x1):This completely optional. You can use any custom chassis you want.

## Software Used
Only one software which is Arduino IDE is used in this project. If you want you can use additional softwares to expand
the capability of this project. New ideas are always welcomed:)

## Interfacing Diagram

## Working
- Whenever the user makes a gesture the PAJ9760 captures those gestures and sends them in a form of unique signal 
  to arduino.
- Based on gestures performed by the user ("UP" or "DOWN") the arduino sends the appropriate PWM signals to Servo 
  Motors.
- The result is the movement of mask going up or down.

## Learning Modules
These are some of the learning modules you will need to get grasp of before doing this project.

1. Object Oriented C++ Programming(Optional : You can use structured programming as well but I recommend OOP anytime.)
2. Servo Motors.
3. Arduino.

## Device in Action (Working Video)
