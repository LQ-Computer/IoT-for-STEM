//  Code này sử dụng cho role mức cao
int role = 3;// sử dụng chân 3 để điều khiển rơ le đóng ngắt cuộn từ của công tắc tơ
void setup() {
    pinMode(role, OUTPUT); // role được khai báo là chân ra
                   }
void loop() {
  digitalWrite(role, HIGH);   // bật role trong 10 giây cũng như cấp điện cho cuộn từ 10 s
  delay(10000);              
  digitalWrite(role, LOW); // tắt role trong 10 giây cũng như ngắt điện cho cuộn từ 10 s
  delay(10000);               
}   // trong phần sau chúng ta sử dụng nút nhấn để bật tắt role đóng ngắt cuộn từ của công tắc tơ

