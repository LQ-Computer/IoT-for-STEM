//CHƯƠNG TRÌNH CHO CẢM BIẾN BÁO CHÁY
//Cách nối dây: chân G nối GND, chân V+ nối nguồn 5V
//Chân AO (Analog Output-tín hiệu ra Analog) nối chân A1
//Chân DO (Digital Output - tín hiệu ra on/off) nối chân 4
#define ChanAO 1//Chân A1 là chân để đọc tính hiệu Analog AO
#define ChanDO 4//Chân 4 (bên digital) là chân để đọc tín hiệu Digital DO
#define baochay 12//Chân để điều khiển đèn led báo cháy
float giatriAO;//Biến chứa giá trị Analog AO
float giatriDO;//Biến chứa giá trị Digital DO
void setup(){
  Serial.begin(9600);//Giao tiếp với máy tính
  pinMode(ChanDO, INPUT);//Định nghĩa chanDO (chân 4) là chân đọc tính hiệu vào
  pinMode(baochay,OUTPUT);//Định nghĩa chân báo cháy (chân 12) là chân xuất tín hiệu ra cho đèn led
}
void loop(){
  giatriAO=analogRead(ChanAO);//Đọc giá trị Analog từ ChanAO
  giatriDO=digitalRead(ChanDO);//Đọc giá trị digital từ ChanDO
  Serial.print("Gia tri Chan Analog: ");//In giá trị Analog ra màn hình
  Serial.print(giatriAO);
  Serial.print(" Gia tri chan Digital: ");//In giá trị digital ra màn hình
  Serial.println(giatriDO);
  if (giatriAO<900) //Điều kiện để phát tín hiệu cháy (do ngƣời dùng tự đặt)
  {
    Serial.println("Chay nha");//Báo cháy
    digitalWrite(baochay,HIGH);//Bật đèn sáng
  }
  else//Ngược lại
  {
    digitalWrite(baochay,LOW);//Tắt đèn
  }
  delay(1000);//Cập nhật giá trị sau 1s
}
