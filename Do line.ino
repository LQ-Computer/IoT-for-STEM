// CHƯƠNG TRÌNH THỬ ĐẶC TÍNH CỦA CẢM BIẾN DÒ LINE
 #include <Wire.h> 
 #include <LiquidCrystal_I2C.h>
 #define den 8 // Sử dụng chân 8 để điều khiển đèn led
 #define tinhieu 2 //Chân S của cảm biến nối với chân 2 trên mạch Arduino
 int x;//Tên biến chứa giá trị của cảm biến dò đường
 LiquidCrystal_I2C lcd(0x3F,16,2);// dia chi của i2c lcd
 void setup()
 {
   Serial.begin(9600);//Đưa dữ liệu lên máy tính để quan sát
   pinMode(den,OUTPUT);//Định nghĩa chân ra để điều khiển đèn led
   pinMode(tinhieu,INPUT);//Định nghỉa chân 2 là chân lấy tín hiệu vào của cảm biến
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  lcd.print("CB DO LINE");
 }
 void loop()
 {
 x=digitalRead(tinhieu);
 Serial.println(x);
 lcd.setCursor(0, 1);
 lcd.print("x =");
 lcd.setCursor(5, 1);
 lcd.print(x);
 if(x==HIGH)//nếu x=1 (gặp màu đen) thì đèn tắt
 {
   digitalWrite(den,LOW);
 }
 if(x==LOW)//Nếu x=0 (gặp màu trắng) thì đèn sáng
 {
   digitalWrite(den,HIGH);
 }
 delay(1000);//Chờ 1 giây để hệ thống đáp ứng
 }

