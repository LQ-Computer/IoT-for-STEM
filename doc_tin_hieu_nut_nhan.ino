int nutnhan = 2; // khai bao chan nut nhấn là chân D2
void setup() {
  Serial.begin(9600);   //Mở cổng Serial ở baudrate 9600 để giao tiếp với máy tính
  pinMode(nutnhan, INPUT);  //Cài đặt chân D2 ở trạng thái đọc dữ liệu
}
void loop() {
  int buttonStatus = digitalRead(nutnhan);    //Đọc trạng thái button
  Serial.println(buttonStatus);              //Xuất trạng thái button
  delay(200);                                //Chờ 200ms
}

