//Chương trình đọc quang trở dạng module
int cambien = 10;// khai báo chân digital 10 cho cảm biến
int Led = 8;//kháo báo chân digital 8 cho đèn LED
void setup (){
  pinMode(Led,OUTPUT);//pinMode xuất tín hiệu đầu ra cho led
  pinMode(cambien,INPUT);//pinMode nhận tín hiệu đầu vào cho cảm biến
}
void loop (){
  int value = digitalRead(cambien);//lưu giá trị cảm biến vào biến value
  digitalWrite(Led,value);//xuất giá trị ra đèn LED
}
