//Đây là mã Code của chương trình. 
#define ENA 8  //enable A on pin 8 
#define ENB 3  //enable B on pin 3 
#define IN1 7  //IN1 on pin 7 
#define IN2 6  //IN2 on pin 6 
#define IN3 5  //IN3 on pin 5 
#define IN4 4  //IN4 on pin 4 
void setup()
{
  //set all of the outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}
void loop()
{
  motorA(1, 25);  //cho motor A chạy 25% tốc độ CHẠY THUẬN
  delay(5000);  //chạy 25% trong 5 s
  motorA(3, 100);  //thắng động cơ A
  motorB(1, 25);  //cho motor B chạy 25% tốc độ.
  delay(5000);  //chạy 25% trong 5 s
  motorA(2, 25);// cho motor A chạy 25% tốc độ CHẠY NGHỊCH
  delay(5000);  //let motor A and motor B run for 5 seconds
  motorB(3, 50);  //thắng động cơ B
  motorA(0, 100);  //dừng động cơ A
  delay(5000);  //wait 5 seconds
}
//****************   Motor A control   *****************
void motorA(int mode, int percent)
{
  //change the percentage range of 0 -> 100 into the PWM
  //range of 0 -> 255 using the map function
  int duty = map(percent, 0, 100, 0, 255);
  switch(mode)
  {
    case 0:  
      digitalWrite(ENA, LOW);  //set enable low to disable A
      break;   
    case 1:  
      digitalWrite(IN1, HIGH);   
      digitalWrite(IN2, LOW);  
      analogWrite(ENA, duty);  
       break;
     case 2:  
      
      digitalWrite(IN1, LOW);   
      digitalWrite(IN2, HIGH);  
      analogWrite(ENA, duty);  
        break;
     case 3:  
     digitalWrite(IN1, LOW);   
     digitalWrite(IN2, LOW);  
     analogWrite(ENA, duty);  
     break;
  }
}
//****************   Motor B control   *****************
  void motorB(int mode, int percent)
{
  //change the percentage range of 0 -> 100 into the PWM
  //range of 0 -> 255 using the map function
  int duty = map(percent, 0, 100, 0, 255);
  switch(mode)
  {
    case 0:  //disable/coast
      digitalWrite(ENB, LOW);  //set enable low to disable B
      break;
      
    case 1:  
     digitalWrite(IN3, HIGH);   
     digitalWrite(IN4, LOW);  
     analogWrite(ENB, duty);  
      break;
   case 2:
     digitalWrite(IN3, LOW);   
     digitalWrite(IN4, HIGH);  
     analogWrite(ENB, duty);  
          break;     
    case 3: 
    digitalWrite(IN3, LOW);   
    digitalWrite(IN4, LOW);  
    analogWrite(ENB, duty);  
         break;
  }
}

