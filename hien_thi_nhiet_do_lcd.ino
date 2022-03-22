#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
int sensorPin = A0;    // chân analog kết nối tới cảm biến LM35
LiquidCrystal_I2C lcd(0x3F,16,2);  
void setup()
{
  Serial.begin(9600);    //Khởi động Serial ở mức baudrate 9600
  lcd.init();                      
  lcd.backlight();
  lcd.print("NHIET DO");
}
void loop()
{
  //đọc giá trị từ cảm biến LM35
   int reading = analogRead(sensorPin);  
  //tính ra giá trị hiệu điện thế (đơn vị Volt) từ giá trị cảm biến
   float voltage = reading * 5.0 / 1024.0; 
   // cứ mỗi 10mV = 1 độ C.
   // Vì vậy nếu biến voltage là biến lưu hiệu điện thế (đơn vị Volt)
    float temp = voltage * 100.0;
   Serial.println(temp);
   lcd.setCursor(0, 1);
   lcd.print("T =");
   lcd.setCursor(5, 1);
   lcd.print(temp);
   delay(1000);    //đợi 1 giây cho lần đọc tiếp theo
}

