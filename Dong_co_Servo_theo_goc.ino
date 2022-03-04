//CHƯƠNG TRÌNH ĐIỀU KHIỂN ĐỘNG CƠ SERVO THEO GÓC
#include <Servo.h> //khai báo thư viện servo
Servo myservo; //khai báo đối tượng myservo để điều khiển servo
int servoPin = 9; //khai báo chân điều khiển servo
int angle = 0; //đặt vị trí ban đầu của servo theo độ
void setup() {
  myservo.attach(servoPin); // cho biết động cơ servo được gắn vào servoPin
}
void loop() {
  for (angle = 0; angle <= 180; angle += 1) { //đi từ 0 độ đến 180 độ mỗi bước là 1 độ
    myservo.write(angle); // làm cho servo đi đến vị trí trong biến 'angle'
    delay(15); // đợi 15ms để servo đạt được vị trí đó
  }
  for (angle = 180; angle >= 0; angle -= 1) { // đi từ 180 độ đến 0 độ mỗi bước là 1 độ
    myservo.write(angle); // làm cho servo đi đến vị trí trong biến 'angle'
    delay(15); // đợi 15ms để servo đạt được vị trí đó
  }
}
