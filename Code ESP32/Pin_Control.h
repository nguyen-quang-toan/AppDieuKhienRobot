// Sử dụng #ifndef và #define để tránh việc bị  include 2 lần
#ifndef Pin_Control_H
#define Pin_Control_H
// Gọi hàm cần dùng
#include <ESP32_Servo.h>
#include "BluetoothSerial.h"


// Khai báo chân động cơ
const int Motor1Pin1    = 12;
const int Motor1Pin2    = 23;
const int Motor2Pin1    = 33;
const int Motor2Pin2    = 32;
const int Motor3Pin1    = 4 ;
const int Motor3Pin2    = 16;
// Khai báo biến
static int val                 = 0;
static unsigned char pwmValue  = 0;
double MaxpwmValue             = 0;
String device_name             = "Robot";
BluetoothSerial SerialBT;
Servo servo1;
Servo servo2;



// Sau khi thực hiện xong sẽ kết thúc
#endif