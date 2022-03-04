//CHƯƠNG TRÌNH THỬ ĐẶC TÍNH CỦA CẢM BIẾN ÂM THANH
//Dây G nối với chân GND, dây + nối với chân 5V
//Dây AO (dây tín hiệu Analog) nối với chân A1
//Dây DO (dây tín hiệu digital) nối với chân 4
#define Analog 1
#define Digital 4
int den=12;
float tinhieuAO;
float tinhieuDO;
void setup()
{
  Serial.begin(9600);
  pinMode(Digital,INPUT);
  pinMode(den, OUTPUT);
}
void loop()
{
  tinhieuAO=analogRead(Analog);
  tinhieuDO=digitalRead(Digital);
  Serial.print("Gia tri Analog: ");
  Serial.print(tinhieuAO);
  Serial.print(" Gia tri Digital: ");
  Serial.println(tinhieuDO);
  if(tinhieuAO>28)
  {
    digitalWrite(den,HIGH);
  }
  else
  {
    digitalWrite(den,LOW);
  }
  delay(50);
}
