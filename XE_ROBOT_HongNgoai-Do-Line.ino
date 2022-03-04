//XE ROBOT HỒNG NGOẠI + DÒ LINE (NHẤN Phím * để chuyển chế độ dò đường)
/*****************************/

#include <Servo.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "UCNEC.h"
int32_t temp = 0;
UCNEC   myIR(14);

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Nối chân L298N với shield V5.0
const int enAPin = 6; // (V5) chân 6 - ENA (L298N)
const int in1Pin = 7; // (V5) chân 7 - IN1 (L298N)
const int in2Pin = 5; // (V5) chân 5 - IN2 (L298N)
const int in3Pin = 4; // (V5) chân 4 - IN3 (L298N)
const int in4Pin = 2; // (V5) chân 2 - IN4 (L298N)
const int enBPin = 3; // (V5) chân 3 - ENB (L298N)


/***********************IRcode Definition  *************************/
#define F 16718055
#define B 16732845
#define L 16713975
#define R 16734885
#define S 16719075

#define track       16717545           //line-tracking routing press [*]
#define ultra       16718310           //Ultrasonics press [0]
#define ble         16715250           //Bluetooth run press [#]

/*************************Define Line Track pins************************************/
//Line Tracking IO define
#define LT_R digitalRead(8)  
#define LT_M digitalRead(9)   
#define LT_L digitalRead(10)

#define READING_LT_R  1
#define READING_LT_L -1
int previousReading = 0;

/*************************Define IR pins************************************/

void setup()
{
      pinMode(enAPin, OUTPUT);    //Motor init
      pinMode(in1Pin, OUTPUT);
      pinMode(in2Pin, OUTPUT);
      pinMode(in3Pin, OUTPUT);
      pinMode(in4Pin, OUTPUT);
      pinMode(enBPin, OUTPUT);

      Serial.begin(9600);          //Init Serial port rate set to 9600
      
      lcd.begin();
      delay(10); 
      lcd.backlight();
      lcd.clear();
      lcd.backlight();
      lcd.clear();

      myIR.begin();

      pinMode(LT_R,INPUT);
      pinMode(LT_M,INPUT);
      pinMode(LT_L,INPUT);

}

void loop()
{
  /*************************Init with read from sensor**********************************/
       //       lcd.clear();

      if(myIR.available())
      {
            temp =  myIR.read();
            Serial.println(temp);
            lcd.setCursor(0, 0);
            lcd.write("IR: ");
            lcd.setCursor(5, 0);
            lcd.print(temp);
      }
             
      if (temp == F){goAhead(160);} 
      else if (temp == B) {goBack(160);} 
      else if (temp == L) {turnLeft(200,200);} 
      else if (temp == R) {turnRight(200,200);} 
      else if (temp == S) {stopRobot();temp=0;}
      else if (temp == track) 
      {  
          while(temp == track)
          {
              if(LT_M){
              goAhead(150);
              }
              else if(LT_R) {
                  previousReading = READING_LT_R;
                  turnRight(150,150);
                  while(LT_R);                             
              }   
              else if(LT_L) {
                  previousReading = READING_LT_L;
                  turnLeft(150,150);
                  while(LT_L);  
              } 
              else if (previousReading == READING_LT_R){
                  turnRight(100,100);
              } 
              else if (previousReading == READING_LT_L){
                  turnLeft(100,100);
              }    

              if(myIR.available())
              {
                temp =  myIR.read();
              }  
           }
        }
        else 
        {
            stopRobot();
            temp=0;
        }

}


void goAhead(int speedCar){ 

      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);

  }

void goBack(int speedCar){ 
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
  }

void turnRight(int speedCar,int speedCar2){ 
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);          // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar2);

  }

void turnLeft(int speedCar,int speedCar2){
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar2);
      
  }

void goAheadRight(int speedCar,int speedCar2){      //vua tien - vua quay phai
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar2);  //banh phai quay cham hon
            
  }

void goAheadLeft(int speedCar, int speedCar2){
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);   //banh trai quay cham hon
      analogWrite(enBPin, speedCar2);
 
  }

void goBackRight(int speedCar, int speedCar2){     //vua lui - vua quay phai
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar2);  //banh phai quay cham hon

  }

void goBackLeft(int speedCar, int speedCar2){ 
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar);//banh trai quay cham hon
      analogWrite(enBPin, speedCar2);  

  }

void stopRobot(){  
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,LOW);      
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,LOW);         
      analogWrite(enAPin, 0);
      analogWrite(enBPin, 0);  
  }
