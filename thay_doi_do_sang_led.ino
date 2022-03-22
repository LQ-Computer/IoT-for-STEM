int led = 6;           // cổng digital mà LED được nối vào
int giatribandau = 0;    // mặc định độ sáng của đèn là 
int tanggiatri = 5;    // mỗi lần thay đổi độ sáng thì thay đổi với giá trị là bao nhiêu


void setup()  {
  // pinMode đèn led là OUTPUT
  pinMode(led, OUTPUT);
}

void loop()  {
  //xuất giá trị độ sáng đèn LED
  analogWrite(led, giatribandau);    

  // thay đổi giá trị là đèn LED
  giatribandau = giatribandau + tanggiatri;

  // Đoạn code này có nghĩa nếu độ sáng == 0 hoặc bằng == 255 thì sẽ đổi chiều của biến thay đổi độ sáng. Ví dụ, nếu đèn từ sáng yếu --> sáng mạnh thì fadeAmount dương. Còn nếu đèn sáng mạnh --> sáng yếu thì fadeAmmount lúc này sẽ có giá trị âm
  if (giatribandau == 0 || giatribandau == 255) {
    tanggiatri = -tanggiatri ;
  }    
  //đợi 30 mili giây để thấy sự thay đổi của đèn
  delay(50);                            
}

