void setup() {
  Serial.begin(9600); // Bạn khởi tạo một cổng Serial tại baudrate 9600. 
}
 
int Step = 0;
 
void loop() {
  if (Step == 0) {
    Serial.println("LED_RED 1"); // Đèn đỏ sáng. 1 == HIGH
  } else if (Step == 1) {
    Serial.println("LED_RED 0"); // Đèn đỏ tắt . 0 == LOW
  } 
  Step = (Step + 1) % 2; //Step sẽ tuần tự tuần hoàn các giá trị trong khoảng từ 0 --> 1
  delay(500);    // Dừng 1/2 giây giữa các lần gửi
}

