# Smart Security Device

## Description
- Citizens are already grappling with many urban challenges on a regular basis. Rapid urbanization is bringing along more challenges, including cities becoming more vulnerable to crime. Safety and security was a key issue raised in the Citizen Engagement survey. Crimes such as rape, theft, sexual assault is becoming very common in india nowadays. 
- Due to this security of citizens has became a priority. we aspire to create a zero-crime area: a secure city that is safe for all sections of the society, particularly women,  children and senior citizens.
- Smart security button will resolve these issues. There has always been delay in finding the criminal and as well as providing help to the victim. Smart security button quickly connects the citizen to the command and control centre. This will ensure the immediate help of the citizen also decrease in rate of crimes due to increased security.

## Hardware Requirements
1. Node MCU
2. GPS Module
3. DC Buzzer
4. GSM Module
5. Touch sensor (or button your choice)
6. General Purpose PCB
7. DC Power supply

## Hand Tools and Fabrication Machines
1. Soldering Iron 
2. Soldering Flux
3. Soldering wire
4. Desoldering Pump
5. Wire Stripper
6. Jumper wire set

## Software Requirements
1. Arduino IDE
2. Google Firebase
3. MIT App Inventor

## Implementation
1. Node Mcu will act as interface between the control centre and citizen.
2. When the user presses the button the his/her location as well as an email to all his/her family members and control centre will be sent. 
3. In case internet connectivity is not available text will be sent to his /her family members. 
4. This connection between control center and citzen will ensure his/her safety. Also there will be a personal app which will connect the user and his/her family members.

## Code Explanation

1. Include the necessary libraries and define the pins
```
#include <TinyGPS++.h> //GPS Module Library
#include <SoftwareSerial.h> //This library will be used for GSM Module
#include <FirebaseArduino.h> // Google Firebase Library
#include <ESP8266WiFi.h> //Wifi Library for Node Mcu

int buzzer =14; // buzzer pin
const int button=16; //button pin
int button_press=0; //This will detect button press
int flag = 0;
int Timer=0; //Will be used to calculate time in seconds
int acc_flag=0; 
```

## Demonstration Video

