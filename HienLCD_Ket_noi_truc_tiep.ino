//CHƯƠNG TRÌNH HIỂN THỊ LCD TRỰC TIẾP
//Them thu vien LiquidCrystal.h. Day la thu vien co san
#include <LiquidCrystal.h>
  //Khoi tao cac chan
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // Thong bao day la LCD 1602
  lcd.begin(16,2);
  // In ra man hinh LCD dong chu
  lcd.print("Toi yeu Arduino!");
}

void loop() {
  // Dat con tro vao cot 0, dong 1. Dong cot LCD bat dau tu 0
  lcd.setCursor(0,1);
  // In ra man hinh LCD dong chu
  lcd.print("Arduino");
}
