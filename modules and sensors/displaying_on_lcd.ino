#include <LiquidCrystal.h> 
int Contrast=75;  // 75 is the contrast we are setting for LCD . You can set any value you want. Dont set it too high or low
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

 void setup()
 {
    analogWrite(6,Contrast);
     lcd.begin(16, 2); // we are using 16*2 LCD
  } 
     void loop()
 { 
     lcd.setCursor(0, 0); //first line of LCD
     lcd.print("Hello customer");
   
    lcd.setCursor(0, 1);// second line of LCD
     lcd.print("get coupons here");

 }

