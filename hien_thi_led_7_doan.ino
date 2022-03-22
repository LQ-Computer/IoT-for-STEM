 // mở code này trên phien bản ide 1.0.6 để tránh bị lổi
 #include "SevSeg.h"    //Include thư viện SevSeg
 SevSeg myDisplay;    // Khai báo biến myDisplay là đối tượng của thư viện SegSev
 int bientro = A0;
 void setup() {               //Hàm Setup
  Serial.begin(9600);      //Bật cổng Serial ở mức Baudrate là 9600
  Serial.println("Ready");
  int displayType = COMMON_ANODE; 
  int digit1 = 8;   //chân số 8 của arduino  nối chân 12 của  led 7 đoạn
  int digit2 = 12; 
  int digit3 = 13; 
  int digit4 = 2; 
  int segA = 9; 
  int segB = 11; 
  int segC = 4; 
  int segD = 6; 
  int segE = 7; 
  int segF = 10; 
  int segG = 3; 
  int segDP= 5;
  int numberOfDigits = 4;   // số dấu chấm

 myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);      // Bắt đầu cho phép giao tiếp 
myDisplay.SetBrightness(100);              //điều chỉnh độ sáng của Module LED
 }
void loop(){

  myDisplay.DisplayString("AbcD", 0b00001000);    // Thể hiện chữ AbcD ra bảng LED, và dãy số 0b00001000 là vị trí dấu chấm. Bạn hãy thử thay những số 0 bằng số 1 hoặc ngược lại để kiểm nghiệm
  myDisplay.SetBrightness(getBrightness()); //độ sáng
}

  int getBrightness() { // Hàm đọc giá trị độ sáng từ biến trở
  int value = analogRead(bientro); // Đọc giá trị biến trở và đưa vào biến value
  value = map(value,0,1023,0,100); // Chuyển đổi giá trị trong thang đo 0-1023 về thang đo 0 - 180
  return value; // Trả về giá trị độ sáng
}

