#include <LiquidCrystal.h> 
int Contrast=75; //set the contrast for lcd 
 LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  

 void setup()
 {
    analogWrite(6,Contrast); // contast value 75b is stored in variable 'contrast'
     lcd.begin(16, 2);  // Because LCD is 16x2
  } 
     void loop()
 { 
     lcd.setCursor(0, 0);
     lcd.print("Hello customer");
   
    lcd.setCursor(0, 1);
     lcd.print("get coupons here");

 }