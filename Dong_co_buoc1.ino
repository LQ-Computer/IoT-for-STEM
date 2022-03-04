//CHƯƠNG TRÌNH ĐIỀU KHIỂN ĐỘNG CƠ BƯỚC
#include <Stepper.h>
const int stepsPerRevolution = 4096;  // Số bước thật = 64 * 64 = 4096
//Chân 8,9,10,11 tương ứng với IN1, IN2, IN3, IN4 mạch đệm ULN2003
Stepper myStepper(vong, 8, 9, 10, 11); 
void setup() {
  myStepper.setSpeed(60);
  Serial.begin(9600);
}
void loop() {
  Serial.println("Quay theo chieu kim dong ho");
  myStepper.step(vong);
  delay(500);
  Serial.println("Quay nguoc chieu kim dong ho");
  myStepper.step(-vong);
  delay(500);
}
