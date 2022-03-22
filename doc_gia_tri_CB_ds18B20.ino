#include <OneWire.h>
#include <DallasTemperature.h>
 // Chân nối với Arduino
#define ONE_WIRE_BUS 2       //Thiết đặt thư viện onewire
OneWire oneWire(ONE_WIRE_BUS);
//Mình dùng thư viện DallasTemperature để đọc 
DallasTemperature sensors(&oneWire);
 void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
}
void loop(void)
{ 
  sensors.requestTemperatures();  
  Serial.print("Nhiet do");
  Serial.println(sensors.getTempCByIndex(0)); // Vì chỉ 1cảm biến nên dùng 0
  //chờ 1 s rồi đọc giá trị cảm biến
  delay(1000);
}

