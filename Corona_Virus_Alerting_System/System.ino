//////Necessary Libraries/////////
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/FreeSerif9pt7b.h>
///////////End///////////////////

/////Define pin Numbers/////////
#define screen_width 128 
#define screen_height 64 
#define DHTPIN A0   
#define DHTTYPE DHT11   
#define led 4
////////////End////////////////

/////////////////Create the Objects and Instances////////////////
Adafruit_SSD1306 display(screen_width, screen_height, &Wire, -1);
DHT dht(DHTPIN, DHTTYPE);
////////////////////////////End/////////////////////////////////

///DHT Variables////
float h;
float t;
////////End////////

void setup() 
{
 
  Serial.begin(115200);
  dht.begin();

  pinMode(led,OUTPUT);
  
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

}

void Alert_Message()
{
  delay(500);
  display.setFont(&FreeSerif9pt7b);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,12);
  
  ///////Display static text///////
  display.println("Humidity :  " );
  display.setCursor(80,12);
  display.print(h);
  display.setCursor(0,40);
  display.println("Corona Alert");
  display.setCursor(0,62);
  display.println("Take Care Varun");
  /////////////End////////////////
  
  display.display(); 
  delay(100);
}


void loop() 
{
   h = dht.readHumidity();
   t = dht.readTemperature(); 

  if(h>65)
  {
    Alert_Message();
    digitalWrite(led,HIGH);
    Serial.println(h);
  }

  else
  {
    display.clearDisplay();
    display.display();
    digitalWrite(led,LOW);
  }

}
