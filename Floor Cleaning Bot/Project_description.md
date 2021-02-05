# Floor Cleaning Bot

## Description 
-This is a Semi Autonomous Robotic car that cleans floors using water and soup. The main purpose of making this project to solve the problem of time consuming tiring, tedious and monotonous job of cleaning of Floors. It has two modes:

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
-A Bluetooth technology is a high speed low powered wireless technology link that is designed to connect phones or other portable equipment together. It is a specification (IEEE 802.15.1) for the use of low power radio communications to link phones, computers and other network devices over short distance without wires. Wireless signals transmitted with Bluetooth cover short distances, typically up to 30 feet (10 meters).
-It is achieved by embedded low cost transceivers into the devices. It supports on the frequency band of 2.45GHz and can support upto 721KBps along with three voice channels. This frequency band has been set aside by international agreement for the use of industrial, scientific and medical devices (ISM).rd-compatible with 1.0 devices.
Bluetooth can connect upto "8 devices" simultaneously and each device offers a unique 48 bit address from IEEE 802 standard with connections being made from point to point or multipoint.

## How Bluetooth Works?
-Bluetooth Network consists of a Personal Area Network or a piconet which contains a minimum of 2 to maximum of 8 bluetooth peer devices- Usually a single master and upto 7 slaves.
-A master is the device which initiates communication with other devices. The master device governs the communications link and trafﬁc between itself and the slave devices associated with it.
-A slave device is the device that responds to the master device. Slave devices are required to synchronize their transmit/receive timing with that of the masters. In addition, transmissions by slave devices are governed by the master device (i.e., the master device dictates when a slave device may transmit). Speciﬁcally, a slave may only begin its transmissions in a time slot immediately following the time slot in which it was addressed by the master, or in a time slot explicitly reserved for use by the slave device.
-The frequency hopping sequence is defined by the Bluetooth device address (BD_ADDR) of the master device. The master device first sends a radio signal asking for response from the particular slave devices within the range of addresses. The slaves respond and synchronize their hop frequency as well as clock with that of the master device.
-Scatternets are created when a device becomes an active member of more than one piconet. Essentially, the adjoining device shares its time slots among the different piconets.

## Working of the Floor Cleaner Robot
First you select on the app which mode you want to put your bot in. if you put it in Semi autonomous mode(SAM) then that's it! you don't have to do anything just watch the cool robot cleaning up your house floors. The reason why this is called semi autonomous is because once put in SAM the bot doesn't know when to stop. you have to manually stop it.
If you select the manual mode you have to control it with arrow keys on the app.

