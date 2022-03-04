#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
#include "DHT.h"           
#define DHTTYPE DHT11
#define dht_dpin 14 //chân tín hiệu cảm biến DHT11 nối với D5(ESP8266)
DHT dht(dht_dpin, DHTTYPE);
int nhietdo,doam,giatri,doamdat;

char auth[] = "VGWKvKDjm5VkC9h4vCNrTeRNrbBdMAxc";//mã token app
char ssid[] = "LEQUYEN";//tên wifi
char pass[] = "7777777@@@";//mật khẩu wifi

int bom=16;//bơm nối với D0(ESP8266)
int den=12;//đèn nối với D6(ESP8266)
int quat=13;//bơm nối với D7(ESP8266)

int vbom,vden,vquat,vtudong,vset;
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  lcd.begin();                    
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.setCursor(5,0);
  lcd.print("H:");
  lcd.setCursor(10,0);
  lcd.print("SET:");
  lcd.setCursor(0,1);
  lcd.print("SHUMI:");
  pinMode(bom,OUTPUT);
  digitalWrite(bom,HIGH);
  pinMode(den,OUTPUT);
  digitalWrite(den,HIGH);
  pinMode(quat,OUTPUT);
  digitalWrite(quat,HIGH);
  dht.begin();
  pinMode(A0,INPUT);
}


       //HÀM THỰC HIỆN CHỨC NĂNG HIỂN THỊ CÁC GIÁ TRỊ CẢM BIẾN LÊN MÀN HÌNH LCD
void hienthicambien()
{
   doam = dht.readHumidity();//đọc độ ẩm môi trường
   nhietdo = dht.readTemperature();//đọc nhiệt độ môi trường
   giatri=analogRead(A0);//đọc giá trị chân A0
   doamdat=100-map(giatri,0,1023,0,100);//giá trị độ ẩm đất
  lcd.setCursor(2,0);
  lcd.print(nhietdo);
  lcd.setCursor(7,0);
  lcd.print(doam);
  if(doamdat <10)
  {
  lcd.setCursor(6,1);
  lcd.print("0");
  lcd.setCursor(7,1);
  lcd.print(doamdat);
  }
  else
  {
    lcd.setCursor(6,1);
  lcd.print(doamdat);
  }
}

               //HÀM THỰC HIỆN CHỨC NĂNG GỬI CÁC DỮ LIỆU CẢM BIẾN HIỂN THỊ TRÊN APP
void guidulieulenapp()
{
  Blynk.virtualWrite(V6, nhietdo);
  Blynk.virtualWrite(V7, doam);
  Blynk.virtualWrite(V8, doamdat);
}

 //LẤY GIÁ TRỊ TỪ NÚT NHẤN V0 TRÊN APP VỀ ĐỂ XỬ LÝ
BLYNK_WRITE(V0)
{
   vbom= param.asInt(); 
}

BLYNK_WRITE(V1)
{
   vden= param.asInt(); 
}

BLYNK_WRITE(V2)
{
   vquat= param.asInt(); 
}

BLYNK_WRITE(V3)
{
   vtudong= param.asInt(); 
}

BLYNK_WRITE(V5)
{
   vset= param.asInt(); 
}

void loop()
{
  hienthicambien();
  guidulieulenapp();
  if(vtudong == 0)//CHẾ ĐỘ ĐIỀU KHIỂN BẰNG TAY
  //HIỂN THỊ GIÁ TRỊ SET CHUẨN TRÊN MÀN HÌNH LCD
  {
    if(vset < 10 )
  {
    lcd.setCursor(14,0);
    lcd.print("0");
    lcd.setCursor(15,0);
    lcd.print(vset);
  }
  else
  {
    lcd.setCursor(14,0);
    lcd.print(vset);
  }
    lcd.setCursor(10,1);
    lcd.print("MANUAL");
  if(vbom == 1)
  {
    digitalWrite(bom,LOW);
  }
  else
  {
    digitalWrite(bom,HIGH);
  }

  if(vquat == 1)
  {
    digitalWrite(quat,LOW);
  }
  else
  {
    digitalWrite(quat,HIGH);
  }

  if(vden == 1)
  {
    digitalWrite(den,LOW);
  }
  else
  {
    digitalWrite(den,HIGH);
  }
}
else //CHẾ ĐỘ TỰ ĐỘNG
{
  if(vset < 10 )
  {
    lcd.setCursor(14,0);
    lcd.print("0");
    lcd.setCursor(15,0);
    lcd.print(vset);
  }
  else
  {
    lcd.setCursor(14,0);
    lcd.print(vset);
  }
  lcd.setCursor(10,1);
  lcd.print("AUTO  ");
  //NẾU ĐỘ ẨM ĐẤT < ĐỘ ẨM SET THÌ BƠM SẼ TỰ KÍCH HOẠT VÀ NGƯỢC LẠI
  if(doamdat<vset)
  {
    digitalWrite(bom,LOW);
  }
  else
  {
   digitalWrite(bom,HIGH); 
  }
}
}
