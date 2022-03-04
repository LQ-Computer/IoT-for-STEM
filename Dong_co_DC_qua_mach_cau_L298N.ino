//CHƯƠNG TRÌNH VÍ DU VỀ SỬ DUNG MẠCH CẦU H - MẠCH CẦU L298N, 1 ĐỘNG CƠ
#define ENA 10 //Xác định ENA là chân 10
#define IN1 11 // Xác định IN1 là chân 11
#define IN2 12 // Xác định IN2 chân 12
void setup()
{
  pinMode(ENA, OUTPUT); //Xác định kiểu chân ENA là chân xuất tín hiệu ra (OUTPUT)
  pinMode(IN1, OUTPUT); // Xác định kiểu chân IN1 là chân xuất tín hiệu ra (OUTPUT)
  pinMode(IN2, OUTPUT); // Xác định kiểu chân IN2 là chân xuất tín hiệu ra (OUTPUT)
}
void loop()
{
  //Ban đầu cho động cơ thắng (phanh) lại
  digitalWrite(IN1, LOW); //Cho chân IN1 ở trạng thái LOW
  digitalWrite(IN2, LOW); //Cho chân IN2 ở trạng thái LOW
  analogWrite(ENA, 255); //Tốc độ là 100% (255)
  delay(1000); //Chờ 1 giây
  //Cho động cơ chạy tới
  digitalWrite(IN1, HIGH); //Cho chân IN1 ở trạng thái HIGH
  digitalWrite(IN2, LOW); //Cho chân IN2 ở trạng thái LOW
  analogWrite(ENA, 120); //Tốc độ là 120/255
  delay(3000); //cho chạy trong 3 giây (chờ trong 3 giây)
  //Dừng lại để đảo chiều, nếu không dừng lại mà đảo chiều vẫn được, nhưng về lâu dài không tốt cho động cơ
  digitalWrite(IN1, LOW); //Cho chân IN1 ở trạng thái LOW
  digitalWrite(IN2, LOW); //Cho chân IN2 ở trạng thái LOW
  analogWrite(ENA, 255); // Tốc độ là 100% (255)
  delay(1000); //Chờ trong 1 s
  //Cho động cơ chạy lui, trạng thái của IN1 và IN2 trong phần chạy lui sẽ ngược với trạng thái chạy tới.
  digitalWrite(IN1, LOW);//Cho chân IN1 ở trạng thái LOW
  digitalWrite(IN2, HIGH); //Cho chân IN2 ở trạng thái HIGH
  analogWrite(ENA, 255); //Chạy 100% tốc động (255 xung)
  delay(3000); //Chạy trong 3s (chờ 3s)
}
