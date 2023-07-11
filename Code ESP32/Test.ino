#include "BluetoothSerial.h"
// OTA Bluetooth
// Khai báo chân động cơ
const int Motor1Pin1 = 12;
const int Motor1Pin2 = 14;
const int Motor2Pin1 = 33;
const int Motor2Pin2 = 32;
const int enA = 13;
const int enB = 27;
int pwmValue = 0;
String device_name = "ESP32 Robot";

BluetoothSerial SerialBT;

void setup() {
  // Khởi tạo các chân kết nối với động cơ là OUTPUT
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  // Khởi tạo cổng kết nối
  Serial.begin(115200);
  SerialBT.begin(device_name); //Bluetooth device name
}

void loop() {
  // Kiểm tra có thiết bị nào kết nối với Bluetooth hay không
  if (SerialBT.hasClient()) {
    // Kiểm tra giá trị để điều chỉnh xung PWM
    /*if (Serial.available() == 2) {
      int lowerByte = Serial.read();
      int hightByte = Serial.read();
      int value = (hightByte * 265) + lowerByte
      byte c = map(value, 1000, 1255, 0, 255);
      Serial.println(pwmValue);
      analogWrite(enA, pwmValue);
      analogWrite(enB, pwmValue);
    } */
    // Kiểm tra ký tự điều khiển
    if (Serial.available()) {
      char receivedChar = SerialBT.read();
      if (receivedChar == '1') {
        pwmValue = 0;
        Serial.println(pwmValue);
      } else if (receivedChar == '2') {
          pwmValue = 28;
          Serial.println(pwmValue);
      } else if (receivedChar == '3') {
          pwmValue = 56;
          Serial.println(pwmValue);
      } else if (receivedChar == '4') {
          pwmValue = 112;
          Serial.println(pwmValue);
      } else if (receivedChar == '5') {
          pwmValue = 140;
          Serial.println(pwmValue);
      } else if (receivedChar == '6') {
          pwmValue = 168;
          Serial.println(pwmValue);
      } else if (receivedChar == '7') {
        pwmValue = 192;
        Serial.println(pwmValue);
      } else if (receivedChar == '8') {
        pwmValue = 224;
        Serial.println(pwmValue);
      } else if (receivedChar == '9') {
        pwmValue = 255;
        Serial.println(pwmValue);
      } else if (receivedChar == 'F') {
        // Xử lý cho trường hợp nhận được ký tự 'F'
        up();
      } else if (receivedChar == 'B') {
        // Xử lý cho trường hợp nhận được ký tự 'B'
        back();
      } else if (receivedChar == 'S') {
        // Xử lý cho trường hợp nhận được ký tự 'S'
        dung();
      } else if (receivedChar == 'L') {
        // Xử lý cho trường hợp nhận được ký tự 'L'
        turnleft();
      } else if (receivedChar == 'R') {
        // Xử lý cho trường hợp nhận được ký tự 'R'
        turnright();
      }
    }
    // Kiểm tra giá trị để điều chỉnh xung PWM
    /*if (SerialBT.available() == 2) {
      int lowerByte = Serial.read();
      int hightByte = Serial.read();
      int value = (hightByte * 265) + lowerByte;
      byte pwmValue = map(value, 1000, 1255, 0, 255);
      Serial.println(pwmValue);
      analogWrite(enA, pwmValue);
      analogWrite(enB, pwmValue);
    } */
    // Kiểm tra giá trị của Bluetooth
    if (SerialBT.available()) {
      char receivedChar = SerialBT.read();
      // Kiểm tra ký tự điều khiển
      if (receivedChar == '1') {
        pwmValue = 0;
        Serial.println(pwmValue);
      } else if (receivedChar == '2') {
          pwmValue = 28;
          Serial.println(pwmValue);
      } else if (receivedChar == '3') {
          pwmValue = 56;
          Serial.println(pwmValue);
      } else if (receivedChar == '4') {
          pwmValue = 112;
          Serial.println(pwmValue);
      } else if (receivedChar == '5') {
          pwmValue = 140;
          Serial.println(pwmValue);
      } else if (receivedChar == '6') {
          pwmValue = 168;
          Serial.println(pwmValue);
      } else if (receivedChar == '7') {
        pwmValue = 192;
        Serial.println(pwmValue);
      } else if (receivedChar == '8') {
        pwmValue = 224;
        Serial.println(pwmValue);
      } else if (receivedChar == '9') {
        pwmValue = 255;
        Serial.println(pwmValue);
      } else if (receivedChar == 'F') {
        // Xử lý cho trường hợp nhận được ký tự 'F'
        up();
      } else if (receivedChar == 'B') {
        // Xử lý cho trường hợp nhận được ký tự 'B'
        back();
      } else if (receivedChar == 'S') {
        // Xử lý cho trường hợp nhận được ký tự 'S'
        dung();
      } else if (receivedChar == 'L') {
        // Xử lý cho trường hợp nhận được ký tự 'L'
        turnleft();
      } else if (receivedChar == 'R') {
        // Xử lý cho trường hợp nhận được ký tự 'R'
        turnright();
      }
    }
  }
}

void up() {
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
  analogWrite(enA, pwmValue);
  analogWrite(enB, pwmValue);
}

void back() {
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
  analogWrite(enA, pwmValue);
  analogWrite(enB, pwmValue);
}

void dung() {
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}

void turnleft() {
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH); 
}

void turnright() {
  digitalWrite(Motor1Pin1, LOW); 
  digitalWrite(Motor1Pin2, HIGH); 
  digitalWrite(Motor2Pin1, HIGH); 
  digitalWrite(Motor2Pin2, LOW); 
}
