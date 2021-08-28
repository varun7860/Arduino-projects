# Smart Security Device
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Smart%20Security%20Device/Images/Smart%20Security%20Device.jpg" width="312" height="555"/>

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

## MIT App Inventor Setup Steps

## Google Firebase

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

#define FIREBASE_HOST " " //Put the HOST Key here
#define FIREBASE_AUTH "  " // Put the Authentication Key here.
const char *ssid =  " "; // Put your WiFi SSID here.     
const char *pass =  " ";  //Put your WiFi Password here.
char server[] = "mail.smtp2go.com"; //This is name of the server.
WiFiClient client;
WiFiClient espClient;

float Lat = 0;
float Lon = 0;
int firebase_button=0;

static const int RXPin =5, TXPin = 4;
static const uint32_t GPSBaud =9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

SoftwareSerial mySerial(12,13);
```

2. Initialize everything in `void setup` Function.

```
void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(buzzer,OUTPUT);
  pinMode(button,INPUT);
  digitalWrite(button,LOW);
  
  ////////////////////////////////////GPS Module//////////////////////////////////////////////////
  ss.begin(GPSBaud);
  Serial.println(F("DeviceExample.ino"));
  Serial.println(F("A simple demonstration of TinyGPS++ with an attached GPS module"));
  Serial.print(F("Testing TinyGPS++ library v. ")); 
  Serial.println(TinyGPSPlus::libraryVersion());
  Serial.println(F("by Mikal Hart"));
  Serial.println();
  delay(10);
 ////////////////////////////////////////End/////////////////////////////////////////////////////// 

 /////////////////////////////////////WiFi Connection//////////////////////////////////////////////
 Serial.println("Connecting to ");
       Serial.println(ssid); 
 
       WiFi.begin(ssid, pass); 
       while (WiFi.status() != WL_CONNECTED) 
          {
            delay(500);
            Serial.print(".");
          }
      Serial.println("");
      Serial.println("WiFi connected"); 
      Serial.println("NodeMCU IP Address:  ");
      Serial.println(WiFi.localIP());
/////////////////////////////////////////End/////////////////////////////////////////////////////////

/////////////////////////GSM Module Setup///////////////////////
  Serial.println("Initializing..."); 
  delay(1000);
  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
///////////////////////////End////////////////////////////////////

 Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH); //Firebase Setup
}
```

3. Create all the necessary functions for the device. Here we need functions for `Sending Email`, `Sending Text`, `Sending the Location` of the Victim.

```
//This Function is responsible for sending Text.
void Gsm_module()
{
  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"<RELATIVE'S PHONE NUMBER>\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("<TEXT TO SEND>"); //text content
  updateSerial();
  mySerial.write(26);
  mySerial.end();
}

//
void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(mySerial.available()) 
  {
    Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
  }
}

//This Function will get the Location of the Victim.
void Gps_module()
{
  while (ss.available() > 0)
  {
    if (gps.encode(ss.read()))
    {
      Lat = gps.location.lat();
      Lon = gps.location.lng();
      Serial.println(Lat);
      Serial.println(Lon);
      delay(2000);
    }
      //Firebase.setFloat("Em_lat",Lat);
      //Firebase.setFloat("Em_lon",Lon);
  }
  if(millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(millis());
    Serial.println(gps.charsProcessed());
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
}


void displayInfo()
{
  Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Serial.print(gps.location.lat(), 4);
    Serial.print(F(","));
    Serial.print(gps.location.lng(), 4);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
  }

//This Function will send mail to Victim's Relatives and Friends.
byte sendEmail()
{
  if (espClient.connect(server, 2525) == 1) 
  {
    Serial.println(F("connected"));
  } 
  else 
  {
    Serial.println(F("connection failed"));
    return 0;
  }
  if (!emailResp()) 
    return 0;
  //
  Serial.println(F("Sending EHLO"));
  espClient.println("EHLO www.example.com");
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending auth login"));
  espClient.println("AUTH LOGIN");
  if (!emailResp()) 
    return 0;
  //  
  Serial.println(F("Sending User"));
  // Change this to your base64, ASCII encoded username
 
  espClient.println("d2FsaW1iZTM0QGdtYWlsLmNvbQ=="); //base64, ASCII encoded Username
  if (!emailResp()) 
    return 0;
  //
  Serial.println(F("Sending Password"));
  // change to your base64, ASCII encoded password
  /*
  For example, if your password is "testpassword" (excluding the quotes),
  it would be encoded as dGVzdHBhc3N3b3Jk
  */
  espClient.println("VmFydW5ANzc0MSMq");//base64, ASCII encoded Password
  if (!emailResp()) 
    return 0;
  //
  Serial.println(F("Sending From"));
  // change to sender email address
  espClient.println(F("MAIL From: <VICTIM'S EMAIL ADDRESS>"));
  if (!emailResp()) 
    return 0;
  // change to recipient address
  Serial.println(F("Sending To"));
  espClient.println(F("RCPT To: <RELATIVE'S EMAIL ADDRESS>"));
  if (!emailResp()) 
    return 0;
  //
  Serial.println(F("Sending DATA"));
  espClient.println(F("DATA"));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending email"));
  // change to recipient address
  espClient.println(F("To: <RELATIVE'S EMAIL ADDRESS>"));
  // change to your address
  espClient.println(F("From: <VICTIM'S EMAIL ADDRESS>"));
  espClient.println(F("Subject: ESP8266 test e-mail\r\n"));
  espClient.println(F("This is a test e-mail sent from ESP8266.\n"));
  espClient.println(F("HEY this is Varun."));
  espClient.println(F("I am in danger."));
  //
  espClient.println(F("."));
  if (!emailResp()) 
    return 0;
  //
  Serial.println(F("Sending QUIT"));
  espClient.println(F("QUIT"));
  if (!emailResp()) 
    return 0;
  //
  espClient.stop();
  Serial.println(F("disconnected"));
  WiFi.mode(WIFI_OFF);
  return 1;
}

//This function is used for debugging.
byte emailResp()
{
  byte responseCode;
  byte readByte;
  int loopCount = 0;

  while (!espClient.available()) 
  {
    delay(1);
    loopCount++;
    if (loopCount > 20000) 
    {
      espClient.stop();
      Serial.println(F("\r\nTimeout"));
      return 0;
    }
  }

  responseCode = espClient.peek();
  while (espClient.available())
  {
    readByte = espClient.read();
    Serial.write(readByte);
  }

  if (responseCode >= '4')
  {
    return 0;
  }
  return 1;
}

```

4. Write your logic in main function. Here the logic is if the Victim presses button the device for 2 secs then an Email, Text and Location will be sent to Victim's Family.
```
void loop() 
{
  button_press = digitalRead(button);//safety Button Press
  firebase_button = digitalRead(button);
  //Firebase.setInt("Button",firebase_button);
  //Firebase.setFloat("Em_lat",Lat);
  //Firebase.setFloat("Em_lon",Lon);
  delay(50);
  if(button_press==HIGH )
  { 
    //digitalWrite(buzzer,HIGH);
    //Firebase.setInt("Button",firebase_button); 
    if(flag<1)
    {
     Gsm_module();
     byte ret = sendEmail();
     flag++;
    }
  }
  
    if(flag==1)
     {
      digitalWrite(buzzer,LOW);
      Gps_module();
     }  
  delay(1);
}
```

## Demonstration Video

[![alt text][1]][2]

[1]: https://github.com/varun7860/Arduino-projects/blob/master/Smart%20Security%20Device/Images/Video%20Thumbnail.jpg
[2]: https://youtu.be/ocBE0eq15g8

