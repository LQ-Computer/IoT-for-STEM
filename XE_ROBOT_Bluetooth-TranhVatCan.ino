//XE ROBOT ĐIỀU KHIỂN BLUETOOTH + TRÁNH VẬT CẢN (NHẤN TAM GIÁC TRÊN APP BLUETOOTH)
/*****************************/

//Ket noi Bluetooth HC-06,HC-05 (neu HC-05 chi dung 4 pin: +5V,GND,TX,RX)
// Bluetooth HC-06/HC-05   <----> Arduino SENSor Shield V5.0 (4pin TX,RX,-,+)
//      RX                 -NOI-            TX
//      TX                 -NOI-            RX
//      GND                -NOI-            -
//      +5V                -NOI-            +

#include <Wire.h> //Includes I2C Lib 
#include <NewPing.h>
#include <Servo.h>

#define ECHO_PIN 12   //chân ECHO của siêu âm - nối 12 Shield V5.0 
#define TRIG_PIN 13   // chân ECHO của siêu âm - nối 13 Shield V5.0         
#define MAX_DISTANCE 200 
#define MAX_SPEED 235 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20
             
Servo myservo;

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
boolean goesForward=false;
int distance = 100;
int speedSet = 0;

int       dugme=1;

// Nối chân L298N với shield V5.0
const int enAPin = 6; // (V5) chân 6 - ENA (L298N)
const int in1Pin = 7; // (V5) chân 7 - IN1 (L298N)
const int in2Pin = 5; // (V5) chân 5 - IN2 (L298N)
const int in3Pin = 4; // (V5) chân 4 - IN3 (L298N)
const int in4Pin = 2; // (V5) chân 2 - IN4 (L298N)
const int enBPin = 3; // (V5) chân 3 - ENB (L298N

int command;               //bien luu trang thai Bluetooth
int speedCar    = 220;     // toc do 50 - 255.
int speed_Coeff = 4;       // he so suy giam <=> giam may lan toc do

void setup() {
  
      pinMode(enAPin, OUTPUT);
      pinMode(in1Pin, OUTPUT);
      pinMode(in2Pin, OUTPUT);
      pinMode(in3Pin, OUTPUT);
      pinMode(in4Pin, OUTPUT);
      pinMode(enBPin, OUTPUT);

      Serial.begin(9600); //Init Serial port rate set to 9600
      
      myservo.attach(11);         //servo nối chân số 11 Shield V5.0
      myservo.write(95);          //Góc ban đầu Servo, nếu nó lệch (không thẳng) bạn chỉnh giá trị khác tăng hoặc giảm
      delay(2000);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);
      distance = readPing();
      delay(100);

}

void loop() {

  if (Serial.available() > 0) {
      command = Serial.read();
      stopRobot();      //Initialize with motors stopped.
      Serial.println(command);
      
      switch (command) {
          case 'F':goAhead();break;
          case 'B':goBack();break;
          case 'L':goLeft();break;
          case 'R':goRight();break;
          case 'I':goAheadRight();break;
          case 'G':goAheadLeft();break;
          case 'J':goBackRight();break;
          case 'H':goBackLeft();break;
            case 'X':  avoiding();break;
            case 'x':  stopAvoiding();break;
          case '0':speedCar = 100;break;
          case '1':speedCar = 115;break;
          case '2':speedCar = 130;break;
          case '3':speedCar = 145;break;
          case '4':speedCar = 160;break;
          case '5':speedCar = 175;break;
          case '6':speedCar = 190;break;
          case '7':speedCar = 205;break;
          case '8':speedCar = 220;break;
          case '9':speedCar = 235;break;
          case 'q':speedCar = 255;break;
          
       }
  }

}

void goAhead(){ 

      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);

  }

void goBack(){ 
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
  }

void goRight(){ 
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);          // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);

  }

void goLeft(){
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
      
  }

void goAheadRight(){      //vua tien - vua quay phai
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar/speed_Coeff);  //banh phai quay cham hon
            
  }

void goAheadLeft(){
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar/speed_Coeff);   //banh trai quay cham hon
      analogWrite(enBPin, speedCar);
 
  }

void goBackRight(){     //vua lui - vua quay phai
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar/speed_Coeff);  //banh phai quay cham hon

  }

void goBackLeft(){ 
      digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar/speed_Coeff);//banh trai quay cham hon
      analogWrite(enBPin, speedCar);  

  }

void stopRobot(){  
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,LOW);      
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,LOW);         
      analogWrite(enAPin, 0);
      analogWrite(enBPin, 0);  
  }

  void stopAvoiding()
{
      dugme=0;
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,LOW);      
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,LOW);         
      analogWrite(enAPin, 0);
      analogWrite(enBPin, 0); 
}
int lookRight()
{
      myservo.write(40); 
      delay(500);
      int distance = readPing();
      delay(100);
      myservo.write(95);               //cái này chỉnh cho thẳng
      return distance;
}
int lookLeft()
{
      myservo.write(150); 
      delay(500);
      int distance = readPing();
      delay(100);
      myservo.write(95);             //cái này chỉnh cho thẳng
      return distance;
      delay(100);
}
int readPing() { 
    delay(70);
    int cm = sonar.ping_cm();
    if(cm==0)
    {
      cm = 250;
    }
    return cm;
}
void avoiding()
{
    long duration, distance;
    int distanceR = 0;
    int distanceL =  0;
    while(dugme==1)
     { 
         distance = readPing();
         delay(40);
         if(distance<=30)
         {
              stopRobot();
              delay(100);
              goBack();
              delay(200);
              stopRobot();
              delay(200);
              distanceR = lookRight();
              delay(200);
              distanceL = lookLeft();
              delay(200);
              if(distanceR>=distanceL)
              {
                goRight();
                delay(300);
                stopRobot();
                delay(100);
              }else
              {
                goLeft();
                delay(300);
                stopRobot();
                delay(100);
              }
         }else
         {
          goAhead();
         }
         
     }
         
}
