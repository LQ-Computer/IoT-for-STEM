// CHƯƠNG TRÌNH THỬ ĐẶC TÍNH CỦA CẢM BIẾN DÒ LINE
#define den 13 // Sử dụng chân 13 để điều khiển đèn led
#define tinhieu 2 //Chân S của cảm biến nối với chân 2 trên mạch Arduino
int a;//Tên biến chứa giá trị của cảm biến dò line
void setup()
{
  Serial.begin(9600);//Đưa dữ liệu lên máy tính để quan sát
  pinMode(den,OUTPUT);//Định nghĩa chân ra để điều khiển đèn led
  pinMode(tinhieu,INPUT);//Định nghĩa chân 2 là chân lấy tín hiệu vào của cảm biến
}
void loop()
{
  a=digitalRead(tinhieu);
  Serial.println(a);
  if(a==HIGH)//nếu a=1 (gặp màu đen) thì đèn tắt
  {
    digitalWrite(den,LOW);
  }
  if(a==LOW)//Nếu a=0 (gặp màu trắng) thì đèn sáng
  {
    digitalWrite(den,HIGH);
  }
  delay(1000);//Chờ 1 giây để hệ thống đáp ứng
}
