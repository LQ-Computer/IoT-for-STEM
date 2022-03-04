//CHƯƠNG TRÌNH ĐIỀU KHIỂN ĐỘNG CƠ BƯỚC BẰNG JOYSTICK
#include <Stepper.h>
// Xác định số bước cho mỗi lần quay
#define STEPS 32
//Chân 8,9,10,11 tương ứng với IN1, IN2, IN3, IN4 mạch đệm ULN2003
#define IN1  11
#define IN2  10
#define IN3   9
#define IN4   8
// Khởi tạo đối tượng
Stepper stepper(STEPS, IN4, IN2, IN3, IN1);
// joystick kết nối chân A0
#define joystick  A0
void setup()
{
}
void loop()
{
  // đọc giá trị từ joystick
  int val = analogRead(joystick);
  // nếu cần điều khiển ở giữa ===> dừng motor
  if(  (val > 500) && (val < 523) )
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
  }
  else
  {
  // Di chuyển động cơ theo hướng đầu tiên
    while (val >= 523)
    {
      // chuyển giá trị analog joystick (523-1023) đọc được sang 5 và 500 rpm
      int speed_ = map(val, 523, 1023, 5, 500);
      // Đặt tốc độ motor
      stepper.setSpeed(speed_);
      // Di chuyển motor (1 step)
      stepper.step(1);
      val = analogRead(joystick);
    }
    // Di chuyển động cơ theo hướng ngược lại
    while (val <= 500)
    {
      // chuyển giá trị analog joystick (500-0) đọc được sang 5 và 500 rpm
      int speed_ = map(val, 500, 0, 5, 500);
      // Đặt tốc độ motor
      stepper.setSpeed(speed_);
      // Di chuyển motor (1 step)
      stepper.step(-1);
      val = analogRead(joystick);
    }
  }
}
