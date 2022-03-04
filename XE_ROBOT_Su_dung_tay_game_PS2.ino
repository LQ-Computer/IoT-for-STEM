/*****************************/
// CHUONG TRINH DIEU KHIEN ROBOTICS THPT NGUYEN DU
// Create by Le Quyen
// Date: 23/04/2021
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
#include <PS2X_lib.h>

#define PS2_DAT 13 // data
#define PS2_CMD 11 //command
#define PS2_SEL 10 // attention
#define PS2_CLK 12 //clock
#define SERVO1_PIN 9   //Chân servo điều khiển cánh tay - nối 9 Shield V5.0 
#define SERVO2_PIN 8  //Chân servo điều khiển tay kẹp - nối 8 Shield V5.0         
#define MAX_DISTANCE 200 
#define MAX_SPEED 235 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20
             
Servo myservo1;     //Servo điều khiển cánh tay
Servo myservo2;     //Servo điều khiển tay kẹp
PS2X ps2x;

// Nối chân L298N với shield V5.0
const int enAPin = 6; // (V5) chân 6 - ENA (L298N)
const int in1Pin = 7; // (V5) chân 7 - IN1 (L298N)
const int in2Pin = 5; // (V5) chân 5 - IN2 (L298N)
const int in3Pin = 4; // (V5) chân 4 - IN3 (L298N)
const int in4Pin = 2; // (V5) chân 2 - IN4 (L298N)
const int enBPin = 3; // (V5) chân 3 - ENB (L298N

int command;               //bien luu trang thai Bluetooth
int speedCar    = 100;     // toc do 50 - 255.
int speed_Coeff = 4;       // he so suy giam <=> giam may lan toc do
//int setservo1 = 0;
//int setservo2 = 0;
int error = 0; 
byte type = 0;
byte vibrate = 0;

void setup() {
  
      pinMode(enAPin, OUTPUT);
      pinMode(in1Pin, OUTPUT);
      pinMode(in2Pin, OUTPUT);
      pinMode(in3Pin, OUTPUT);
      pinMode(in4Pin, OUTPUT);
      pinMode(enBPin, OUTPUT);
      //Dừng cả 2 mô tơ
      Serial.begin(9600); //Init Serial port rate set to 9600
      
      //myservo1.attach(SERVO1_PIN);         //servo1 nối chân số 9 Shield V5.0
      //myservo2.attach(SERVO2_PIN);         //servo2 nối chân số 8 Shield V5.0
     //myservo2.write(0);
      error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT,false, false);   //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error

 // Check for error
 if(error == 0){
  Serial.println("Found Controller, configured successful");
 }
   
 else if(error == 1)
  Serial.println("No controller found, check wiring or reset the Arduino");
   
 else if(error == 2)
  Serial.println("Controller found but not accepting commands");
  
 else if(error == 3)
  Serial.println("Controller refusing to enter Pressures mode, may not support it.");
   
 // Check for the type of controller
 type = ps2x.readType();
 switch(type) {
  case 0:
    Serial.println("Unknown Controller type");
    break;
  case 1:
    Serial.println("DualShock Controller Found");
    break;
  case 2:
    Serial.println("GuitarHero Controller Found");
    break;
  }
}

void loop() {
  //if (Serial.available() > 0) {
  //    command = Serial.read();
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,LOW);      
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,LOW);         
      analogWrite(enAPin, 0);
      analogWrite(enBPin, 0);       //Initialize with motors stopped.
      //Serial.println(command);
      
     /* switch (command) {
          case 'F':goAhead();break;
          case 'B':goBack();break;
          case 'L':goLeft();break;
          case 'R':goRight();break;
          case 'I':goAheadRight();break;
          case 'G':goAheadLeft();break;
          case 'J':goBackRight();break;
          case 'H':goBackLeft();break;
          case 'S': stopRobot();break;
          case '1':nang();break;
          case '2':ha();break;
          case '3':nha();break;
          case '4':kep();break;
          //case '5':speedCar = 175;break;
          //case '6':speedCar = 190;break;
          //case '7':speedCar = 205;break;
          //case '8':speedCar = 220;break;
          //case '9':speedCar = 235;break;
          //case 'q':speedCar = 255;break;
          
       }
  }*/
if(error == 1) //skip loop if no controller found
  return; 
  
else { //DualShock Controller
  
     ps2x.read_gamepad(false, vibrate); // disable vibration of the controller   
    // MOVE FORWARD
     if(ps2x.Button(PSB_PAD_UP)) {
        digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
        Serial.println("MOVE FORWARD");
      }
      // TURN RIGHT
      if(ps2x.Button(PSB_PAD_RIGHT)){
        digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);          // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
        Serial.println("Turn right");
      }
      // TURN LEFT
      if(ps2x.Button(PSB_PAD_LEFT)){
        digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
        Serial.println("Turn left");
      }
      // MOVE BACK
      if(ps2x.Button(PSB_PAD_DOWN)){
       digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);         
        Serial.println("Move back");
      }  
      if (ps2x.ButtonPressed(PSB_GREEN)) {
        myservo1.attach(SERVO1_PIN);
       int setservo1 = 140;
        setservo1 = map(setservo1,180,0,225,0);
        myservo1.write(setservo1);
        delay(200);
        myservo1.detach();
        delay(200);
        Serial.println("Nâng");
      }
       if (ps2x.ButtonPressed(PSB_BLUE)) {
        myservo1.attach(SERVO1_PIN);  
       int setservo1 = 30;
        setservo1 = map(setservo1,0,180,0,225);
        myservo1.write(setservo1);
        delay(200);
        myservo1.detach();
        delay(200);
        Serial.println("Hạ");
      }
       if (ps2x.ButtonPressed(PSB_PINK)) {
        myservo2.attach(SERVO2_PIN);
        int setservo2 = 82;
        setservo2 = map(setservo2,180,0,225,0);
        myservo2.write(setservo2);
        delay(1000);
        myservo2.detach();
        delay(200);
        Serial.println("Kẹp");
        Serial.println(setservo2);
      }
      
       if (ps2x.ButtonPressed(PSB_RED)) {
         myservo2.attach(SERVO2_PIN);  
        int setservo2 = 45;
        setservo2 = map(setservo2,0,180,0,225);
        myservo2.write(setservo2);
        delay(200);
        myservo2.detach();
        delay(200);
        Serial.println("Nhả");
        Serial.println(setservo2);
      }
     if (ps2x.ButtonPressed(PSB_R1)) {
        myservo2.attach(SERVO2_PIN);
        int setservo2 = 98;
        setservo2 = map(setservo2,180,0,225,0);
        myservo2.write(setservo2);
        delay(200);
        myservo2.detach();
        delay(200);
        Serial.println("Kẹp cờ");
        }
     int rx = ps2x.Analog(PSS_RX);
     if (rx > 129){
        digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);          // RIGHT lui
      analogWrite(enAPin, rx);
      analogWrite(enBPin, rx);
        Serial.println("Turn right");
      Serial.println("Stick phải");
     }
     if (rx < 127){
        digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, speedCar);
      analogWrite(enBPin, speedCar);
        Serial.println("Stick trái");
     }
     int ly = ps2x.Analog(PSS_LY);
     if (ly < 127){
       digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,HIGH);         // LEFT tien
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,HIGH);         // RIGHT tien
      analogWrite(enAPin, 255-ly);
      analogWrite(enBPin, 255-ly);
       Serial.println("Stick lên");
     }
     if (ly > 129){
       digitalWrite(in1Pin,HIGH);      
      digitalWrite(in2Pin,LOW);         // LEFT lui
      digitalWrite(in3Pin,HIGH);      
      digitalWrite(in4Pin,LOW);         // RIGHT lui
      analogWrite(enAPin, ly);
      analogWrite(enBPin, ly);         
        Serial.println("Move back");
      Serial.println("Stick xuống");
     }
     /*if ((lx < 127) and (ly < 127)){
      Serial.println("Stick lên trái");
     }
       if ((lx > 129) and (ly < 127)){
      Serial.println("Stick lên phải");
     }*/
     
      if (!ps2x.Button(PSB_PAD_DOWN) && !ps2x.Button(PSB_PAD_UP) && !ps2x.Button(PSB_PAD_RIGHT) && !ps2x.Button(PSB_PAD_LEFT) && (rx >= 127) && (rx <=129) && (ly >=127) && (ly <= 129)){
      digitalWrite(in1Pin,LOW);      
      digitalWrite(in2Pin,LOW);      
      digitalWrite(in3Pin,LOW);      
      digitalWrite(in4Pin,LOW);         
      analogWrite(enAPin, 0);
      analogWrite(enBPin, 0); 
      }
      
 delay(50);
 }
 
}   
  
