#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F,16,2);  // lưu ý ở đây có 2 địa chỉ ( 0x27) hoặc (0x3F) 
void setup()
{
  lcd.init();                      
  lcd.backlight();
  lcd.print("TDHshop.com.vn");
}
void loop()
{
}

