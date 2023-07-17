
#include <ESP32_Servo.h>
#include "BluetoothSerial.h"
// OTA Bluetooth
// Khai báo chân động cơ
const int Motor1Pin1 = 13;
const int Motor1Pin2 = 12;
const int Motor2Pin1 = 14;
const int Motor2Pin2 = 27;
const int Motor3Pin1 = 34;
const int Motor3Pin2 = 35;
const int Motor4Pin1 = 22;
const int Motor4Pin2 = 23;
//const int enA = 13;
//const int enB = 27;
int pwmValue = 0;
String device_name = "32";
BluetoothSerial SerialBT;
Servo myservo;
int pos = 0;
int servoPin = 18;
void setup() {
  // Khởi tạo các chân kết nối với động cơ là OUTPUT
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
  //pinMode(enA, OUTPUT);
  //pinMode(enB, OUTPUT);
  // Khởi tạo cổng kết nối
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
  myservo.attach(servoPin); 
  myservo.write(pos);
}

void loop() {
  // Kiểm tra có thiết bị nào kết nối với Bluetooth hay không
  if (SerialBT.hasClient()) {
    // Kiểm tra ký tự điều khiển
    if (Serial.available()) {
      char receivedChar = SerialBT.read();
      if (receivedChar == 'A') {
          pwmValue = 0;
          Serial.println(pwmValue);
      } else if (receivedChar == 'S') {
          pwmValue = 28;
          Serial.println(pwmValue);
      } else if (receivedChar == 'D') {
          pwmValue = 56;
          Serial.println(pwmValue);
      } else if (receivedChar == 'F') {
          pwmValue = 84;
          Serial.println(pwmValue);
      } else if (receivedChar == 'G') {
          pwmValue = 112;
          Serial.println(pwmValue);
      } else if (receivedChar == 'H') {
          pwmValue = 140;
          Serial.println(pwmValue);
      } else if (receivedChar == 'J') {
          pwmValue = 168;
          Serial.println(pwmValue);
      } else if (receivedChar == 'K') {
          pwmValue = 196;
      } else if (receivedChar == 'L') {
          pwmValue = 224;
          Serial.println(pwmValue);
      } else if (receivedChar == 'M') {
          pwmValue = 255;
          Serial.println(pwmValue);
      } else if (receivedChar == 'Q') {
          // Xử lý cho trường hợp nhận được ký tự 'F'
          Serial.println('Q');
          up();
      } else if (receivedChar == 'W') {
          // Xử lý cho trường hợp nhận được ký tự 'B'
          Serial.println('W');
          back();
      } else if (receivedChar == 'E') {
          // Xử lý cho trường hợp nhận được ký tự 'S'
          Serial.println('E');
          dung();
      } else if (receivedChar == 'R') {
          // Xử lý cho trường hợp nhận được ký tự 'L'
          Serial.println('R');
          turnleft();
      } else if (receivedChar == 'T') {
          // Xử lý cho trường hợp nhận được ký tự 'R'
          Serial.println('T');
          turnright();
      } else if (receivedChar == 'Z') {
          // Kẹp cấu kiện
          pos = 180;
          Serial.println('Z');
      } else if (receivedChar == 'X') {
          // Nhả cấu kiện
          Serial.println('0');
          Serial.println('X');
      } else if (receivedChar == 'C') {
          // Nâng cấu kiện
          Serial.println('C');
      } else if (receivedChar == 'V') {
          // Hạ cấu kiện
          Serial.println('V');
      }  else if (receivedChar == '0') {
        // Dùng động cơ nâng / hạ
          stopservo();
          Serial.println('B');
      }
    }
    // Kiểm tra giá trị của Bluetooth
    if (SerialBT.available()) {
      char receivedChar = SerialBT.read();
      // Kiểm tra ký tự điều khiển
      if (receivedChar == 'A') {
        pwmValue = 0;
        Serial.println(pwmValue);
      } else if (receivedChar == 'S') {
          pwmValue = 28;
          Serial.println(pwmValue);
      } else if (receivedChar == 'D') {
          pwmValue = 56;
          Serial.println(pwmValue);
      } else if (receivedChar == 'F') {
          pwmValue = 84;
          Serial.println(pwmValue);
      } else if (receivedChar == 'G') {
          pwmValue = 112;
          Serial.println(pwmValue);
      } else if (receivedChar == 'H') {
          pwmValue = 140;
          Serial.println(pwmValue);
      } else if (receivedChar == 'J') {
          pwmValue = 168;
          Serial.println(pwmValue);
      } else if (receivedChar == 'K') {
          pwmValue = 196;
          Serial.println(pwmValue);
      } else if (receivedChar == 'L') {
          pwmValue = 224;
          Serial.println(pwmValue);
      } else if (receivedChar == 'M') {
          pwmValue = 255;
          Serial.println(pwmValue);
      } else if (receivedChar == 'Q') {
          // Xử lý cho trường hợp nhận được ký tự 'F'
          Serial.println('Q');
          up();
      } else if (receivedChar == 'W') {
          // Xử lý cho trường hợp nhận được ký tự 'B'
          Serial.println('W');
          back();
      } else if (receivedChar == 'E') {
          // Xử lý cho trường hợp nhận được ký tự 'S'
          Serial.println('E');
          dung();
      } else if (receivedChar == 'R') {
          // Xử lý cho trường hợp nhận được ký tự 'L'
          Serial.println('R');
          turnleft();
      } else if (receivedChar == 'T') {
          // Xử lý cho trường hợp nhận được ký tự 'R'
          Serial.println('T');
          turnright();
      } else if (receivedChar == 'Z') {
        // Kẹp cấu kiện
        Serial.println('Z');
        //kepcaukien();
        pos = 180;
        } else if (receivedChar == 'X') {
        // Nhả cấu kiện
        Serial.println('X');
        pos = 0;
        Serial.println('X');
        Serial.println('0');
      } else if (receivedChar == 'C') {
        // Nâng cấu kiện
        Serial.println('C');
      } else if (receivedChar == 'V') {
        // Hạ cấu kiện
        Serial.println('V');
      } else if(receivedChar = '0') {
        // Dừng động cơ nâng / hạ
        stopservo();
        Serial.println('B'); 
      }
    } 
  }
}

void up() {
  analogWrite(Motor1Pin1, pwmValue);
  analogWrite(Motor1Pin2, LOW);
  analogWrite(Motor2Pin1, LOW);
  analogWrite(Motor2Pin2, pwmValue);
  //analogWrite(enA, pwmValue);
  //analogWrite(enB, pwmValue);
}

void back() {
  analogWrite(Motor1Pin1, LOW);
  analogWrite(Motor1Pin2, pwmValue);
  analogWrite(Motor2Pin1, pwmValue);
  analogWrite(Motor2Pin2, LOW);
  //analogWrite(enA, pwmValue);
  //analogWrite(enB, pwmValue);
}

void dung() {
  analogWrite(Motor1Pin1, LOW);
  analogWrite(Motor1Pin2, LOW);
  analogWrite(Motor2Pin1, LOW);
  analogWrite(Motor2Pin2, LOW);
}

void turnleft() {
  analogWrite(Motor1Pin1, LOW);
  analogWrite(Motor1Pin2, pwmValue);
  analogWrite(Motor2Pin1, LOW);
  analogWrite(Motor2Pin2, pwmValue); 
}

void turnright() {
  analogWrite(Motor1Pin1, pwmValue); 
  analogWrite(Motor1Pin2, LOW); 
  analogWrite(Motor2Pin1, pwmValue); 
  analogWrite(Motor2Pin2, LOW); 
}
// Quay trái A
void upLeft() {
  analogWrite(Motor1Pin1, 90);
  analogWrite(Motor1Pin2, LOW);
  analogWrite(Motor2Pin1, 60);
  analogWrite(Motor2Pin2, LOW);
}
// Quay phải D
void upRight() {
  analogWrite(Motor1Pin1, 60);
  analogWrite(Motor1Pin2, LOW);
  analogWrite(Motor2Pin1, 90);
  analogWrite(Motor2Pin2, LOW);
}
// Nâng cấu kiện
void nangcaukien() {
  analogWrite(Motor4Pin1, 255);
  analogWrite(Motor4Pin2, 0);
}
// Hạ cấu kiện
void hacaukien() {
  analogWrite(Motor4Pin1, 0);
  analogWrite(Motor4Pin2, 255);
}  
// Dừng chạy động cơ nâng / hạ
void stopservo() {
  analogWrite(Motor4Pin1, 0);
  analogWrite(Motor4Pin2, 0);
}
