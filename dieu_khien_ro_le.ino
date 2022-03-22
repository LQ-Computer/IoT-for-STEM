//  Code này sử dụng cho role mức cao
int role = 11;  // có thể sử dụng chân khác của arduino để điều khiển rơ le
void setup() {
    pinMode(role, OUTPUT); // role được khai báo là chân ra
                   }
void loop() {
  digitalWrite(role, HIGH);   // bật role trong 10 giay
  delay(10000);              
  digitalWrite(role, LOW);    // tắt role trong 4 giây
  delay(4000);               
}

