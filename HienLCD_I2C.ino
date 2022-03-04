//CHƯƠNG TRÌNH HIỂN THỊ LCD QUA GIAO TIẾP I2C
#include <LiquidCrystal_I2C.h>    //Include the I2C protocol LCD1602 Lib
#include <Wire.h>                 // Include I2C Lib
LiquidCrystal_I2C lcd(0x27,16,2); // Define LCD1602

void setup() 
{
      lcd.init();
      delay(10); 
      lcd.backlight();
      lcd.clear(); 
      lcd.backlight();
      lcd.clear();
      lcd.home();
      lcd.backlight(); //Turn the Backlight on
      lcd.print("Arduino"); //Display Arduino
} 
void loop() { }
