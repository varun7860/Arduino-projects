# Floor Cleaning Bot

<img align="center" width="700" height="475" src="https://github.com/varun7860/Arduino-projects/blob/master/Floor%20Cleaning%20Bot/Images/Floor%20Cleaning%20Bot.jpg"> 

## Description 
-This is a Semi Autonomous Robotic car that cleans floors using water and soap. The main purpose of making this project is to solve the problem of time consuming tiring, tedious and monotonous job of cleaning of Floors. It has two modes:

 - 1.Semi Autonomous Mode
 - 2.Manual mode

## Hardware Description
- 1.Bluetooth Module(HC-05): This module will help for wireless communication between Arduino and any Bluetooth application. I have used Blynk as my Bluetooth application because its very easy to use.
- 2.Relay Module : This module has an important role in controlling Water Pump Motor and Cleaning Motor. we will be using 1 Relay for each motor.
Motor Driver(L298N/L293D): This will be used for controlling the speed and direction of two motors
- 3.BLYNK APP: This will be used for controlling the Robot Manually as well as to switch its modes i.e from manual to autonomous or vice versa. if you dont know anything about this app check for its tutorial at this link
- Link:https://www.hackster.io/nhuberfeely/arduino-101-blynk-bluetooth-tutorial-cb4c5d

Note : you can also use 2 channel relay instead of 2 individual 1 channel Relay modules.

Note : I have used L298N in this project. you can use L293D if you want but let me remind you L293D provides less output current compared to L298N so use it with proper power requirements.

## What is Bluetooth?
- A Bluetooth technology is a high speed low powered wireless technology link that is designed to connect phones or other portable equipment together. It is a specification (IEEE 802.15.1) for the use of low power radio communications to link phones, computers and other network devices over short distance without wires. Wireless signals transmitted with Bluetooth cover short distances, typically up to 30 feet (10 meters).
- It is achieved by embedded low cost transceivers into the devices. It supports on the frequency band of 2.45GHz and can support upto 721KBps along with three voice channels. -- This frequency band has been set aside by international agreement for the use of industrial, scientific and medical devices (ISM).rd-compatible with 1.0 devices.
- Bluetooth can connect upto "8 devices" simultaneously and each device offers a unique 48 bit address from IEEE 802 standard with connections being made from point to point or multipoint.

## How Bluetooth Works?
<img align="center" width="448" height="284" src="https://github.com/varun7860/Arduino-projects/blob/master/Floor%20Cleaning%20Bot/Images/Bluetooth.jpg"> 

- Bluetooth Network consists of a Personal Area Network or a piconet which contains a minimum of 2 to maximum of 8 bluetooth peer devices- Usually a single master and upto 7 slaves.
- A master is the device which initiates communication with other devices. The master device governs the communications link and trafﬁc between itself and the slave devices associated with it.
- A slave device is the device that responds to the master device. Slave devices are required to synchronize their transmit/receive timing with that of the masters. In addition, transmissions by slave devices are governed by the master device (i.e., the master device dictates when a slave device may transmit). Speciﬁcally, a slave may only begin its transmissions in a time slot immediately following the time slot in which it was addressed by the master, or in a time slot explicitly reserved for use by the slave device.
- The frequency hopping sequence is defined by the Bluetooth device address (BD_ADDR) of the master device. The master device first sends a radio signal asking for response from the particular slave devices within the range of addresses. The slaves respond and synchronize their hop frequency as well as clock with that of the master device.
- Scatternets are created when a device becomes an active member of more than one piconet. Essentially, the adjoining device shares its time slots among the different piconets.

## Custom Circuit made for the project
<img align="center" width="281" height="300" src="https://github.com/varun7860/Arduino-projects/blob/master/Floor%20Cleaning%20Bot/Images/PCB.jpg">
<img align="center" width="281" height="555" src="https://github.com/varun7860/Arduino-projects/blob/master/Floor%20Cleaning%20Bot/Images/PCB%20Backside.jpg"> 

## Working of the Floor Cleaner Robot
- First you select on the app which mode you want to put your bot in. if you put it in Semi autonomous mode(SAM) then that's it! you don't have to do anything just watch the cool robot cleaning up your house floors. 
- The reason why this is called semi autonomous is because once put in SAM the bot doesn't know when to stop. you will have to manually stop it.
- If you select the manual mode you have to control it with arrow keys on the app.

## Code Explanation Step by Step

1. Include the necessary Library and define the pins.

```
#include<SoftwareSerial.h>
SoftwareSerial Blue(TX,RX); // Instance of the defined library

//Bluetooth Module Pins
int TX=0;
int RX=1;

//Relay Pins
int Rp1=9;//cleaning motor pin
int Rp2=10;//water pump pin

String button;

//Motor Driver Pins(L298N)
const int M1=2;
const int M2=3;
const int M3=4;
const int M4=5;

/*Use these pins 
if you want a specific speed
for the robot/*
//const int ENA=9; 
//const int ENB=10;
```

2. Initialize everything in `void setup` function.

```
void setup() 
{
  Serial.begin(9600);
  
  //set relay pins as output
  pinMode(Rp1,OUTPUT);
  pinMode(Rp2,OUTPUT);
  
  //Set motor pins as uutput
  pinMode(M1,OUTPUT);
  pinMode(M2,OUTPUT);
  pinMode(M3,OUTPUT);
  pinMode(M4,OUTPUT);
  
  //Make the relay pins as HIGH at start.
  digitalWrite(Rp1,HIGH);
  digitalWrite(Rp2,HIGH);
  
  //Set the PWM Pins as output
  //pinMode(ENA,OUTPUT);
  //pinMode(ENB,OUTPUT);
}
```

3. Make the necessary functions which the robot will use while operating.

```
//This will allow robot to go forward.
void forward()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
}

//This will allow robot to go backward or reverse.
void backward()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,HIGH);
  digitalWrite(M3,HIGH);
  digitalWrite(M4,LOW);
}

//This will allow robot to turn right.
void right()
{
  digitalWrite(M1,HIGH);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
}

//This will allow robot to turn left.
void left()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,HIGH);
}

//This will stop the robot
void pause()
{
  digitalWrite(M1,LOW);
  digitalWrite(M2,LOW);
  digitalWrite(M3,LOW);
  digitalWrite(M4,LOW);
  digitalWrite(Rp1,HIGH);
  digitalWrite(Rp2,HIGH);
}

//This will make the robot to clean the floors
void clean()
{
  <Put Your Logic here>
}

//Make an function that will make the robot to work autonomously.
void Autonomous()

{
  forward();
  clean();
  forward();
  clean();
  forward();
  clean();
  
}
```

4. Find out if any button press is detected by the `HC-05` Module in the start of `void loop` function.

```
void loop()
{
 while (Serial.available())//Check if there is an available byte to read
  { 
    delay(10);  
    char c = Serial.read(); 
    if (c == '#') 
    {
      break; //Exit the loop when the # is detected after the word
    } 
    button += c; //Shorthand for button = button + c
  }
```

5. Add your condition for the robot to operate after the button press is detected.

```
if(button.length()>0)
  {
    Serial.println(button);
    
    if(button=="*front")
    {
      Serial.println("go forward");
      forward();
    }
     if(button=="*back")
     {
       Serial.println("GO backward");
       backward();
     }
     if(button=="*right")
     {
       Serial.println("GO right");
       right();
     }

     if(button=="*left")
     {
       Serial.println("GO left");
       left();
     }

     if(button=="*water")
     {
       Serial.println("Turn the pump on");
       digitalWrite(Rp2,LOW);
     }

     if(button=="*clean")
     {
       Serial.println("Turn the cleaning motor on");
       digitalWrite(Rp1,LOW);
     }

     
     if(button=="*Autonomous")
     {
       Serial.println("Entered Autonomous Mode");
       Autonomous();
     }

     if(button=="*pause")
     {
       Serial.println("Entered Autonomous Mode");
       pause();
     }
      button = "";
    }
  }
```

## Working Video

