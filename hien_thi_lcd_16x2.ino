#include <LiquidCrystal.h>      //Khai báo thư viện cho LCD ( Thư viện đã có sẵn)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);     //noi voi chan LCD LAN LUOT : Rs, E, D4, D5, D6, D7
 void setup() {
  //Thông báo đây là LCD 1602
  lcd.begin(16, 2);
  lcd.print("DIEN – DIEN TU!");  //In ra màn hình lcd dòng chữ DIEN – DIEN TU

}
 
void loop() {
  lcd.setCursor(0, 1);  // đặt con trỏ vào cột 0, dòng 1
  lcd.print("   TDHShop");  // In ra dong chu
}

