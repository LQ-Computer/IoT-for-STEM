// Khai báo chân
const int G = 8; // G= Arduino chân 8
const int F = 7; // F= Arduino chân 7
const int A = 2; // A = Arduino chân 2
const int B = 3; // B = Arduino chân 3
const int E = 6; // E = Arduino chân 6
const int D = 5; // D = Arduino chân 5
const int C = 4; // C = Arduino chân 4
const int dp = 9; // dp = Arduino chân 9
const int second = 1000; // thiết lập với mili giây, 1000 milliseconds = 1 second
const int digit = 10; // Số ký tự hiển thị 10 digits (0 - 9)
const int segment = 7; // Số thanh hiển thị trong LED (7) 
// Định nghĩa những thanh( led đơn) sáng 
byte digseg[digit][segment] = { 
{ 1,1,1,1,1,1,0 }, // = 0
{ 0,1,1,0,0,0,0 }, // = 1
{ 1,1,0,1,1,0,1 }, // = 2
{ 1,1,1,1,0,0,1 }, // = 3
{ 0,1,1,0,0,1,1 }, // = 4
{ 1,0,1,1,0,1,1 }, // = 5
{ 1,0,1,1,1,1,1 }, // = 6
{ 1,1,1,0,0,0,0 }, // = 7
{ 1,1,1,1,1,1,1 }, // = 8
{ 1,1,1,1,0,1,1 } // = 9
};
void setup() { 
// Định nghĩa chân xuất tín hiệu OUTPUT
pinMode(A, OUTPUT); 
pinMode(B, OUTPUT);
pinMode(C, OUTPUT);
pinMode(D, OUTPUT);
pinMode(E, OUTPUT);
pinMode(F, OUTPUT);
pinMode(G, OUTPUT);
pinMode(dp, OUTPUT);
// Tắt dấu chấm
digitalWrite(dp, LOW); 
}
// Loop through all 7 LED segments starting with pin 2 
void writeDigit(byte digit) 
{
byte pin = 2; 
byte seg;
for (seg = 0; seg < 7; seg++) 
{
digitalWrite(pin, digseg[digit][seg]);
pin++;
}
}
void loop() 
{
byte digit;
for (digit=0; digit < 10; digit++) 
{
writeDigit(digit); 
delay(second); 
}
delay(4*second);
}

