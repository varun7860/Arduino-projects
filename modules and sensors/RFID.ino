#include<Servo.h>
#include<MFRC522.h>
#include<SPI.h>

Servo servo;
MFRC522 mfrc522(53, 5);  // for Arduino Mega
 int sp =9;

 String tagUID =  "BC 3B B5 C3" ;
//other spare card UID (86 62 D0 1F)


void setup() 
{
  Serial.begin(9600);
  servo.attach(sp);
  servo.write(0);
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() 
{
  if(!mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial())
  {
    return;
  }

//Reading the Card

  String tag ="";
  for(byte i =0; i<mfrc522.uid.size; i++)
  {
    tag.concat(String(mfrc522.uid.uidByte[i]< 0x10 ? "0" : " "));
    tag.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  tag.toUpperCase();

  //how to check the Card
  
   if(tag.substring(1) == String(tagUID) )
   {
    Serial.print("\n access granted");
    servo.write(180);
    delay(2000);
    servo.write(0);
   }

     else 
     {
       //Serial.println( tag.substring(1));
       Serial.print(  "\n access denied");
     }

  
}
