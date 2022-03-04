//CHƯƠNG TRÌNH ĐIỀU KHIỂN ĐỘNG CƠ SERVO THEO GIÁ TRỊ BIẾN TRỞ
#include <Servo.h> //khai báo thư viện servo
Servo servo;       //khởi tạo thư viện servo
int servoPin = 9; //điểu khiển servo qua chân số 9 của Arduino
int potPin = 0; // chân analog được kết nối với biến trở
int val; // biến để đọc giá trị analog từ chân analog
int angle; // biến cho góc mà chúng ta sẽ tính toán
void setup() {
  servo.attach(servoPin); // cho biết động cơ servo được gắn vào servoPin
}
void loop() {
  val = analogRead(potPin); // đọc giá trị của biến trở (giá trị từ 0 đến 1023)
  angle = map(val, 0, 1023, 0, 180); // chuyển giá trị analog (0-1023) đọc được từ biến trở sang số đo độ (0-180 độ)
  // dùng để điều khiển góc quay cho servo
  servo.write(angle); // cho servo quay một góc là angle độ
  delay(15); // 
}
