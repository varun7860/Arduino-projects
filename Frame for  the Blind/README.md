# Object Detection Device for Blind 
<img align="center" width="563" height="539" src="https://github.com/varun7860/Arduino-projects/blob/master/Frame%20for%20%20the%20Blind/Images/Obstacle%20Detection%20Device%20for%20the%20Blind.jpg"> 

## Problem Statement (Description) 
Blind people often face the problem of colliding to walls or obstacles. I have created a simple embedded system that help them.

## What it does?

- It’s an special device for blind people which will alert them about the nearby obstacles.
- The obstacles can be walls or any other object to which the user can collide with.

## Hardware Used

1. Arduino Pro mini: You can use any arduino but the arduino pro mini will be best suitable for this project due to its compact size.
2. Ultrasonic Sensor (HC-SR04): This sensor will detect obstacles that are in front of the person.
3. General purpose PCB: This will be used to the circuit and mount the arduino on it.
4. DC Buzzer: The buzzer will beep and alert the user when the obstacle is detected.
5. Power Supply: Power supply in this case will be a battery. Lithium Ion battery is recommended for this project.

## Software Used
- Arduino IDE: The only software used in this project is Arduino Ide which will be used for burning the code to Arduino.

## Why the Need of such device?

- Blind people often tackle with issues such as crossing road in a very traffic based area and often collide with obstacles.
- This makes them vulnerable to injury or sometimes even death.
- There is no device to guide these people to cross roads in very congested traffic based environment.

## Implementation and Working of the Device:
- The device looks like a spectacle which has to worn by the user just as we wear any kind of goggles or spectacles.
when the person is about to hit a wall or a person the obstacle avoiding sensor will detect it and buzzer will beep.
This will let the user understand that there is something ahead of him/her and save him/her by colliding to it.
 - Note: The obstacle avoiding sensor (HC-SR04) should be used only for testing purposes as it not accurate or precise. For detecting Obstacles accurately I recommend using Lidar sensor which works 10 times better than HC-SR04.

## Advantages of such devices:

- Easy to use and wear.
- Very cheap and cost effective
- Light weight and Robust

## Future Scope of the Device:
- Arduino will be replaced by Raspberry Pi and camera module will be added which will perform image processing for detecting difference between humans and Obstacles.Vibration   Motor can also be added for increasing sensitivity.
- The device will look like a strap which has be worn side by head.
While crossing if an obstacle is detected by the device then the vibration motor beneath it will vibrate which will make the user to stop walking and stay still.
- The obstacle or signal on road will be detected by camera module. The data will be sent to Raspberry pi which will command the motor to vibrate if an obstacle is detected. Gps module will guide them to reach their desired destination.

## Code Explanation

1. Declare the necessary pins
   ```
   //Ultrasonic Sensor Pins
   int Trigpin = 5; 
   int Echopin = 4; 
   
   // DC Buzzer Pin
   const int buzzer= 10;
   
   //Formula Variables
   long duration;
   int distance;
   ```
2. Set the pins as input or output in `void setup` Function.
   ```
   void setup() 
   {
    Serial.begin(9600);
    pinMode(Echopin,INPUT);
    pinMode(Trigpin,OUTPUT);
    pinMode(buzzer,OUTPUT);
   }
   ```
3. Send the ultrasonic sound wave from Trig pin of ultrasonic distance sensor

    ```
    void loop()
    {
     digitalWrite(Trigpin, LOW);
     delayMicroseconds(2);
     digitalWrite(Trigpin, HIGH);
     delayMicroseconds(10);
     digitalWrite(Trigpin, LOW);
     }
    ```
  
4. The Echo pin will receive the wave at some point of time. Lets calculate this time and then the distance using `distance = speed * time`
    ```
    duration = pulseIn(Echopin,HIGH);
    distance = (duration*0.034)/2;
    ```

5. Finally put the condition of beeping the buzzer if the user is close to the obstacle.
   ```   
   if (distance<30&&distance>1)
    {
     digitalWrite(buzzer,HIGH); // Buzzer will beep for 3 secs and then stop.
     delay(3000);
     digitalWrite(buzzer,LOW);
    }

   else
    {
    digitalWrite(buzzer,LOW); // Turn the Buzzer off the user goes away from the obstacle.
    }
   }
   ```
   
## Demonstration Video
