
const int RED_PIN = 9;    // led đỏ
const int GREEN_PIN = 10; // led xanh lá
const int BLUE_PIN = 11;  // led xanh dương
 
int DELAY_TIME = 500;  // đơn vị là mili giây 
 
void setup()
{
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}
void loop()
{
  // Gọi hàm maucoban để thể hiện toàn bộ các màu cơ bản !
   maucoban();
 }
// Cài đặt hàm maucoban
 void maucoban()
{
  // Tắt toàn bộ các led 
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(DELAY_TIME);
   // Chỉ bật led đỏ
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(DELAY_TIME);
   // Chỉ bật led xanh lá
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(DELAY_TIME);
   // Chỉ bật led xanh dương
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DELAY_TIME);
   // Bật màu vàng bắng cách bật led đỏ và xanh
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(DELAY_TIME);
  // Xanh lam (Cyan) bằng cách bật led xanh lá và xanh dương
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DELAY_TIME);
   // Tím (đỏ - xanh dương)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(DELAY_TIME);
  // Màu trắng (tất cả các led)
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
   delay(DELAY_TIME);
}
 

 
 

