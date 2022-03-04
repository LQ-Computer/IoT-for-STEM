//ĐỌC NHIỆT ĐỘ VÀ ĐỘ ẨM TỪ DHT11 VÀ HIỂN THỊ TRÊN LCD
//Gọi thư viện DHT11
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal.h>
const int DHTPIN = 8; //Đọc dữ liệu từ DHT11 ở chân 8 trên UNO
const int DHTTYPE = DHT11; //Khai báo loại cảm biến, có 2 loại là DHT11 và DHT12
DHT dht(DHTPIN,DHTTYPE);
byte degree[8]={
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
};
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  lcd.begin(16,2);
  //lcd.setBacklightPin(3,POSITIVE);
  //lcd.setBacklight(HIGH);
  
  lcd.home();
  lcd.print("Nhiet do: ");
  lcd.setCursor(0,1);
  lcd.print("Do am: ");
  lcd.createChar(1,degree);
  //Serial.begin(9600);
  dht.begin();// Khởi động cảm biến
}

void loop() {
  delay(1000);
  float h=dht.readHumidity(); //Đọc độ ẩm
  float t=dht.readTemperature(); //Đọc nhiệt độ
 if (isnan(t) || isnan(h)) {//Kiểm tra xem thử việc đọc giá trị có bị thất bại hay không. Hàm isnan tham khảo google
    lcd.setCursor(10,0);
    lcd.print ("False");
    return;
  }
  else {
 
    lcd.setCursor(10,0);
    lcd.print(round(t));
    lcd.print(" ");
    lcd.write(1);
    lcd.print("C");
    
    lcd.setCursor(10,1);
    lcd.print(round(h));
    lcd.print(" %");
  }
 }
