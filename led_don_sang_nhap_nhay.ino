/*
  Đoạn code làm nhấp nháy một đèn LED cho trước
 */
 // Hàm setup chạy một lần duy nhất khi khởi động chương trình
void setup() {                
  pinMode(12, OUTPUT);    
}
 // Hàm loop chạy mãi mãi sau khi kết thúc hàm setup()
void loop() {
  digitalWrite(12, HIGH);   // bật đèn led sáng
  delay(5000);       // dừng chương trình trong 5 giây => thây đèn sáng được 5 giây
  digitalWrite(12, LOW);    // tắt đèn led
  delay(2000);        // dừng chương trình trong 2 giây => thấy đèn tối được 2 giây
}

