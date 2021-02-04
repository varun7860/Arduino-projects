# Object Detection Device for Blind 


## Problem Statement (Description) 
Blind people often face the problem of colliding to walls or obstacles. I have created a simple embedded system that help them.

## What it does?

It’s an embedded device which will guide blind people about the obstacles and objects nearby as well as warn them of about dangers.

This platform will use powerful image processing Algorithms and object detection techniques that will help the blind to survive in real life time based environments.

## Why the Need of such device?

- Blind people often tackle with issues such as crossing road in a very traffic based area and often collide with obstacles.
- This makes them vulnerable to injury or sometimes even death.
- There is no device to guide these people to cross roads in very congested traffic based environment.

## Implementation and Working of the Device:
The device looks like a spectacle which has to worn by the user just as we wear any kind of goggles or spectacles.
when the person is about to hit a wall or a person the obstacle avoiding sensor will detect it and buzzer will beep.
This will let the user understand that there is something ahead of him/her and save him/her by colliding to it.
Note: The obstacle avoiding sensor (HC-SR04) should be used only for testing purposes as it not highly accurateand precise. For detecting Obstacles accurately I recommend usng Lidar sensor which works 10 times better than HC-SR04.

## Advantagesof such device:

- Easy to use and wear.
- very cheap and cost effective
- light weight and Robust

## Future Scope of the Device:
Arduino will be replaced by Raspberry Pi and camera module will be added which will perform image processing for detecting difference between humans and Obstacles.Vibration Motor can also be added for increasing sensitivity.
The device will look like a strap which has be worn side by head.
While crossing if an obstacle is detected by the device then the vibration motor beneath it will vibrate which will make the user to stop walking and stay still.
The obstacle or signal on road will be detected by camera module. The data will be sent to Raspberry pi which will command the motor to vibrate if an obstacle is detected. Gps module will guide them to reach their destination as well as to their homes.
