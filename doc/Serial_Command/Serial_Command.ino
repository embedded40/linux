//https://mechasolution.vn/Blog/processing-bai-3-serial-command-va-dieu-khien-3-led-bang-giao-dien

//#include <SoftwareSerial.h>           //chi dung cho esp8266 , esp32 khong xai                 
#include <SerialCommand.h>              //Thư viện Serial Command

int LedA=2;                             //Led 1  | ESP32 LED pin 2
int LedB=16;                            //Led 2  EPP8266 pin 15
int LedC=10;                            //Led 3
SerialCommand SCmd;                     //Khai báo lớp SCmd (Serial Command)

void setup()
{  
  pinMode(LedA,OUTPUT);                 //Định nghĩa chân LedA,LedB,LedC là OUTPUT
  pinMode(LedB,OUTPUT);
  pinMode(LedC,OUTPUT);
  digitalWrite(LedA,LOW);               //Tắt cả 3 LED
  digitalWrite(LedB,LOW);
  digitalWrite(LedC,LOW);
  Serial.begin(9600);                   //Set BaudRate 9600 (phải cùng BaudRate với Processing)
  SCmd.addCommand("LED",LED);           //Chờ lệnh từ HOST có Command Name là LED
}

void loop()
{  
  SCmd.readSerial();                    //Chờ Serial
}


void LED() //Gồm 2 tham số (led_char,val);
{  
  int led_char,val;                     //Biến chọn led và trạng thái. led_char tương dương 3 led theo thứ tự 1 2 3. Val (value) là giá trị 1 - bật và 0 - tắt
  char *arg;                            //Tham số
  
  arg = SCmd.next();                    //Đọc tham số thứ 1
  led_char = atoi(arg); 

  arg = SCmd.next();                    //Đọc tham số thứ 2
  val = atoi(arg); 
  
//  Serial.println(led_char);             //In ra serial
//  Serial.println(val);
  
  //Điều khiển led
  if (led_char==1) {digitalWrite(LedA,val);Serial.println(millis());}
  if (led_char==2) {digitalWrite(LedB,val);}
  if (led_char==3) {digitalWrite(LedC,val);}
}
