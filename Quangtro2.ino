//Chương trình đọc quang trở 2
int quangtro = A5; //Thiết đặt chân analog đọc quang trở
int bientro = A4; // Thiết đặt chân analog đọc biến trở
int led = 2;// Thiết đặt chân digital là đèn led
void setup() {
  // Khởi tạo cộng Serial 9600
  Serial.begin(9600);
  //pinMode
  pinMode(led,OUTPUT);
}
void loop() {
  int giatriQuangtro = analogRead(quangtro);// đọc giá trị quang trở
  int giatriBientro = analogRead(bientro);// đọc giá trị biến trở
  // Nếu giá trị quang trở <= giá trị biến trở thì bật đèn
  if (giatriQuangtro <= giatriBientro) {
      digitalWrite(led,HIGH);
  } 
  else {
    digitalWrite(led,LOW);
  }
  // Xuất giá trị ra Serial Monitor
  Serial.print("Quang tro ");
  Serial.print(giatriQuangtro);
  Serial.print(", bien tro ");
  Serial.print(giatriBientro);
  Serial.print(" => ");
  // Dòng nay tương đương đoạn code sau
  /*
  if (giatriQuangtro <= giatriBientro) {
      Serial.println("Sang");
  } 
  else {
  Serial.println("Tat");
  }
  */
  Serial.println((giatriQuangtro <= giatriBientro) ? "Sang" : "Tat");
}
