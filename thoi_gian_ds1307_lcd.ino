#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2); // 0x27 là địa chỉ của lcd 16x2
RTC_DS1307 RTC;
 
void setup () {
lcd.init(); 
lcd.backlight(); // bật đèn nền LCD 
// cài đặt số cột và số dòng 
lcd.begin(16, 2);
lcd.setCursor(0, 0);
lcd.print("H:");
lcd.setCursor(0, 1);
lcd.print("D:");
Serial.begin(9600);
Wire.begin();
Wire.beginTransmission(0x68);// địa chỉ của ds1307
Wire.write(0x07); // 
Wire.write(0x10); // 
Wire.endTransmission();
RTC.begin();
  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
//    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
}
 
void loop () {
   DateTime now = RTC.now();
   lcd.setCursor(4, 0);
   lcd.print(now.hour(), DEC);
   lcd.print(":");
   lcd.print(now.minute(), DEC);
   lcd.print(":");
   lcd.print(now.second(), DEC);
   lcd.print(" "); 
   
   Serial.print(now.hour(), DEC);
   Serial.print(":");
   Serial.print(now.minute(), DEC);
   Serial.print(":");
   Serial.print(now.second(), DEC);
   Serial.print(" "); 

  
   Serial.print(now.day(), DEC);
   Serial.print("/");
   Serial.print(now.month(), DEC);
   Serial.print("/");
   Serial.print(now.year(), DEC);
   Serial.print(""); 
   Serial.println();

   
   lcd.setCursor(4, 1);
   lcd.print(now.day(), DEC);
   lcd.print("/");
   lcd.print(now.month(), DEC);
   lcd.print("/");
   lcd.print(now.year(), DEC);
   lcd.print(""); 
  
   delay(1000);
}
