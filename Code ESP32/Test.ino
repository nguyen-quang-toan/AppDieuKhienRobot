#include "BluetoothSerial.h"
// OTA Bluetooth
// Khai báo chân động cơ
const int Motor1Pin1 = 12;
const int Motor1Pin2 = 14;
const int Motor2Pin1 = 33;
const int Motor2Pin2 = 32;
const int enA = 13;
const int enB = 27;


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
    if (Serial.available() == 2) {
      int lowerByte = Serial.read();
      int hightByte = Serial.read();
      int value = (hightByte * 265) + lowerByte;
      byte pwmValue = map(value, 1000, 1255, 0, 255);
      analogWrite(enA, pwmValue);
      analogWrite(enB, pwmValue);
    }
    // Kiểm tra giá trị
    if (Serial.available()) {
      char receivedChar = SerialBT.read();
      if (receivedChar == 'F') {
        // Xử lý cho trường hợp nhận được ký tự 'F'
        Serial.println("F");
        up();
      } else if (receivedChar == 'B') {
        // Xử lý cho trường hợp nhận được ký tự 'B'
        Serial.println("B");
        back();
      } else if (receivedChar == 'S') {
        // Xử lý cho trường hợp nhận được ký tự 'S'
        Serial.println("S");
        dung();
      } else if (receivedChar == 'L') {
        // Xử lý cho trường hợp nhận được ký tự 'L'
        Serial.println("L");
        turnleft();
      } else if (receivedChar == 'R') {
        // Xử lý cho trường hợp nhận được ký  tự 'R'
        Serial.println("R");
      }
      SerialBT.write(receivedChar);
    }
    // Kiểm tra giá trị để điều chỉnh xung PWM
    if (SerialBT.available() == 2) {
      int lowerByte = Serial.read();
      int hightByte = Serial.read();
      int value = (hightByte * 265) + lowerByte;
      byte pwmValue = map(value, 1000, 1255, 0, 255);
      analogWrite(enA, pwmValue);
      analogWrite(enB, pwmValue);
    }
    // Kiểm tra giá trị của Bluetooth
    if (SerialBT.available()) {
      char receivedChar = SerialBT.read();
      if (receivedChar == 'F') {
       // Xử lý cho trường hợp nhận được ký tự 'F'
        Serial.println("F");
        up();
      } else if (receivedChar == 'B') {
        // Xử lý cho trường hợp nhận được ký tự 'B'
        Serial.println("B");
        back();
      } else if (receivedChar == 'S') {
        // Xử lý cho trường hợp nhận được ký tự 'S'
        Serial.println("S");
        dung();
      } else if (receivedChar == 'L') {
        // Xử lý cho trường hợp nhận được ký tự 'L'
        Serial.println("L");
        turnleft();
      } else if (receivedChar == 'R') {
        // Xử lý cho trường hợp nhận được ký tự 'R'
        Serial.println("R");
        turnright();
      }
      Serial.write(receivedChar);
    } 
    // Nếu không có thiết bị nào kết nối bluetooth thì in ra chữ DISCONNECTED đồng thời gọi hàm dừng
  } else {
    dung();
    Serial.println("DISCONNECTED");
    }
}

// Hàm tiến
void up() {
  digitalWrite(Motor1Pin1, 0);
  digitalWrite(Motor1Pin2, 1);
  digitalWrite(Motor2Pin1, 0);
  digitalWrite(Motor2Pin2, 1);
}
// Hàm lùi
void back() {
  digitalWrite(Motor1Pin1, 1); 
  digitalWrite(Motor1Pin2, 0);
  digitalWrite(Motor2Pin1, 1);
  digitalWrite(Motor2Pin2, 0);
}
// Hàm quay phải
void turnright() {
  digitalWrite(Motor1Pin1, 0);
  digitalWrite(Motor1Pin2, 1);
  digitalWrite(Motor2Pin1, 1);
  digitalWrite(Motor2Pin2, 0);

}
// Hàm quay trái
void turnleft() {
  digitalWrite(Motor1Pin1, 1);
  digitalWrite(Motor1Pin2, 0);
  digitalWrite(Motor2Pin1, 0);
  digitalWrite(Motor2Pin2, 1);
}
// Hàm dừng
void dung() {
  digitalWrite(Motor1Pin1, 0);
  digitalWrite(Motor1Pin2, 0);
  digitalWrite(Motor2Pin1, 0);
  digitalWrite(Motor2Pin2, 0);
}
