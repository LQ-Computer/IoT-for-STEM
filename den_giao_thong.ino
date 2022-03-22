// chương trình điều khiển đèn giao thông
int red = 8;
int yellow = 9;
int green = 10;
void setup(){
pinMode(red,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(green,OUTPUT);
}
void loop(){
dengiaothong();
delay(15000);
}
void dengiaothong(){
digitalWrite(yellow,LOW);
digitalWrite(green,LOW);
digitalWrite(red,HIGH);
delay(10000);// den đỏ sáng 10 giây.

digitalWrite(green,LOW);
digitalWrite(red,LOW);
digitalWrite(yellow,HIGH);
delay(2000);  // đèn vàng sáng 2 giây.

digitalWrite(yellow,LOW);
digitalWrite(red,LOW);
digitalWrite(green,HIGH); // den xanh sang 15 s
}

