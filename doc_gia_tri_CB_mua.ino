int rainSensor = 6; // Chân tín hiệu cảm biến mưa ở chân digital 6 (arduino)
void setup() {
  pinMode(rainSensor,INPUT);// Đặt chân cảm biến mưa là INPUT, vì tín hiệu sẽ được truyền đến cho Arduino
  Serial.begin(9600);// Khởi động Serial ở baudrate 9600
}
void loop() {
  int value = digitalRead(rainSensor);  //Đọc tín hiệu cảm biến mưa
  if (value == HIGH) {                        // Cảm biến đang không mưa
    Serial.println("Khong mua");
  }
 else 
{
    Serial.println("Dang mua");
  }
  delay(1000); // Đợi 1 giây cho lần kiểm tra tiếp theo. 
}

