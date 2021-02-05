#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>

/////////////////////Button Variables///////////////////////////
int buzzer =14;
const int button=16;
int button_press=0;
int flag = 0;
int Timer=0;
int acc_flag=0;

///////////////////////////End//////////////////////////////////

//////////////////Firebase Parameteres//////////////////////////
#define FIREBASE_HOST " "
#define FIREBASE_AUTH "  "
const char *ssid =  " ";     
const char *pass =  " ";
char server[] = "mail.smtp2go.com";
WiFiClient client;
WiFiClient espClient;

float Lat = 0;
float Lon = 0;
int firebase_button=0;
////////////////////////End////////////////////////////////////


///////////////////////////Gps/////////////////////////////////
static const int RXPin =5, TXPin = 4;
static const uint32_t GPSBaud =9600;
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);
/////////////////////////End///////////////////////////////////


/////////////////////////GSM Module////////////////////////////
SoftwareSerial mySerial(12,13);
//////////////////////////////End/////////////////////////////

//////////////////////////Accelerometer///////////////////////
//const int xPin = 1;    //x-axis of the Accelerometer
int button_state=0;
//////////////////////////End////////////////////////////////


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
  Serial.print(F("Testing TinyGPS++ library v. ")); Serial.println(TinyGPSPlus::libraryVersion());
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

///////////////////////Firebase Setup////////////////////////////
 //Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);

/////////////////////////End////////////////////////////////////

/////////////////////////GSM Module Setup///////////////////////
/*Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();*/
///////////////////////////End////////////////////////////////////

}


void Gsm_module()
{
  Serial.println("Initializing..."); 
  delay(1000);

  mySerial.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();

  mySerial.println("AT+CMGF=1"); // Configuring TEXT mode
  updateSerial();
  mySerial.println("AT+CMGS=\"+918850874890\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
  updateSerial();
  mySerial.print("Hey I am in Danger"); //text content
  updateSerial();
  mySerial.write(26);
  mySerial.end();
}



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
  espClient.println(F("MAIL From: <walimbe34@gmail.com>"));
  if (!emailResp()) 
    return 0;
  // change to recipient address
  Serial.println(F("Sending To"));
  espClient.println(F("RCPT To: <varun.walimbe16@siesgst.ac.in>"));
  if (!emailResp()) 
    return 0;
  //
  Serial.println(F("Sending DATA"));
  espClient.println(F("DATA"));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending email"));
  // change to recipient address
  espClient.println(F("To: <varun.walimbe16@siesgst.ac.in>"));
  // change to your address
  espClient.println(F("From: <walimbe34@gmail.com>"));
  espClient.println(F("Subject: ESP8266 test e-mail\r\n"));
  espClient.println(F("This is is a test e-mail sent from ESP8266.\n"));
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
