//Chương trình ĐỌC DỮ LIÊU TỪ CẢM BIẾN ĐO ĐỘ ẨM ĐẤT
int  CBDoAm = A1; //Nối chân ra của cảm biến đo độ ẩm với chân A1
#define  role   12        //Chân nối với role 12
float doamdat;      //Biến độ ẩm đất
void setup()
{
  Serial.begin(9600);
  //Khai báo các chân
  pinMode(role,OUTPUT);
}
void loop()
{
  doamdat=analogRead(CBDoAm);
  Serial.print("Do am la:");
  Serial.print(doamdat);     //In ra độ ẩm đất (serial monitor)
  //Bơm nước khi đất khô( thông qua role)
  if(doamdat<200)
  {
  digitalWrite(role,HIGH);   //Bat role de tuoi cay,…
  Serial.println("Tuoi cay");
    }
  //Ngưng bơm khi đất ướt
    else
    {
      digitalWrite(role,LOW);
      Serial.println("Cay du nuoc");
      }
   delay(1000);
}

