//Arduino GND to breadboard Negative power rail (All black wires goes to this rail)
//Arduino 5V to breadboard Positive power rail (All deep-blue wires goes to this rail)
//DHT11 Positive pin to breadboard positive power rail
//DHT11 Negative pin to breadboard negative power rail
//DHT11 Signal pin to Arduino Analog A0 (this feeds data from DHT11 to Arduino)
//LCD 1 to breadboard Negative power rail
//LCD 2 to breadboard Positive power rail
//LCD 3 to breadboard Negative power rail (if you connect this to a potentiometer, this helps to change the LCD brightness)
//LCD 4 to Arduino Digital Pin 12 (LCD character coordinates)
//LCD 5 to breadboard Negative power rail
//LCD 6 to Arduino Digital Pin 11 (LCD initiate command)
//LCD 11 to Arduino Digital Pin 5
//LCD 12 to Arduino Digital Pin 4
//LCD 13 to Arduino Digital Pin 3
//LCD 14 to Arduino Digital Pin 2
//LCD 15 to breadboard Positive power rail
//LCD 16 to breadboard Negative power rail
//Cold/Green LED Positive Pin to Arduino Digital Pin 7 (negative pin to breadboard negative rail)

//Hot/Yellow LED Positive Pin to Arduino Digital Pin 8 (negative pin to breadboard negative rail)

//Extreme/Red LED Positive Pin to Arduino Digital Pin 9 (negative pin to breadboard negative rail)

#include <LiquidCrystal.h>

#include <DHT.h>

#include "DHT.h"

#define DHTPIN A0     // what pin we're connected to

#define DHTTYPE DHT11   // we are using the DHT11 sensor

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  for (int DigitalPin = 7; DigitalPin <= 9; DigitalPin++) 
 {
  pinMode(DigitalPin, OUTPUT);
 }
  lcd.begin(16,2);  //16 by 2 character display
  
dht.begin();
}
 
void loop()
{
  delay(1000);
  // Reading temperature or humidity takes about 250 milliseconds!
  float h = dht.readHumidity();
  
  float t = dht.readTemperature();  // Read temperature as Celsius (the default)

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);  //printing temperarture to the LCD display


  lcd.print("'C");
  
  lcd.setCursor(0,1);
  lcd.print("Humid: ");
  lcd.print(h);  //printing humidity to the LCD display
  lcd.print("%");
}
  
