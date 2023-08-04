// Thư viên bluetooth và động cơ Servo
#include <ESP32_Servo.h>
#include "BluetoothSerial.h"
#include "Function_Control.h"
#include "Pin_Control.h"

void setup() 
{
  // Khởi tạo các chân kết nối với động cơ là OUTPUT
  pinMode(Motor1Pin1, OUTPUT);
  pinMode(Motor1Pin2, OUTPUT);
  pinMode(Motor2Pin1, OUTPUT);
  pinMode(Motor2Pin2, OUTPUT);
  pinMode(Motor3Pin2, OUTPUT);
  pinMode(Motor3Pin2, OUTPUT);
  // Khởi tạo cổng kết nối
  Serial.begin(921600); 
  SerialBT.begin(device_name); 
  servo1.attach(16);
  servo2.attach(4);
}
void loop() 
{
  // Kiểm tra có thiết bị nào kết nối với Bluetooth hay không
  if (SerialBT.hasClient()) 
  {
    // Kiểm tra ký tự điều khiển
    if (Serial.available()) 
    {
    char receivedChar = Serial.read();
      switch (receivedChar) 
        {
        case 'A':
            MaxpwmValue = pwmValue_0();
            Serial.println(MaxpwmValue);
            break;
        case 'S':
            MaxpwmValue = pwmValue_28();
            Serial.println(MaxpwmValue);
            break;
        case 'D':
            MaxpwmValue = pwmValue_56();
            Serial.println(MaxpwmValue);
            break;
        case 'F':
            MaxpwmValue = pwmValue_84();
            Serial.println(MaxpwmValue);
            break;
        case 'G':
            MaxpwmValue = pwmValue_112();
            Serial.println(MaxpwmValue);
            break;
        case 'H':
            MaxpwmValue = pwmValue_140();
            Serial.println(MaxpwmValue);
            break;
        case 'J':
            MaxpwmValue = pwmValue_168();
            Serial.println(MaxpwmValue);
            break;
        case 'K':
            MaxpwmValue = pwmValue_196();
            Serial.println(MaxpwmValue);
            break;
        case 'L':
            MaxpwmValue = pwmValue_224();
            Serial.println(MaxpwmValue);
            break;
        case 'M':
            MaxpwmValue = pwmValue_255();
            Serial.println(MaxpwmValue);
            break;
        //***************************************************//
        case 'Q':
          // Xử lý cho trường hợp nhận được ký tự 'Q'
          while (pwmValue<MaxpwmValue)
          {
            delay(50);
            pwmValue+=1;
            up();
            Serial.println(pwmValue);
          }
          break;
        case 'W':
          while (pwmValue<MaxpwmValue)
          {
            delay(50);
            pwmValue+=1;
            back();
            Serial.println(pwmValue);
          }
          break;
        case 'E':
          // Xử lý cho trường hợp nhận được ký tự 'E'
          Serial.println("Dung");
          dung();
          pwmValue=(dung());
          break;
        case 'R':
          // Xử lý cho trường hợp nhận được ký tự 'R'
          Serial.println("Quay trai");
          turnleft();
          break;
        case 'T':
          // Xử lý cho trường hợp nhận được ký tự 'T'
          Serial.println("Quay phai");
          turnright();
          break;
        //****************************************************//
        case 'C':
          // Nâng cấu kiện
          Serial.println("nang cang");
          nang_cang();
          break;
        case 'V':
          // Hạ cấu kiện
          Serial.println("ha cang");
          ha_cang();
          break;  
        case 'U':
        // Dùng động cơ nâng / hạ
          dung_nang_ha();
          Serial.println("dung dong co nang, ha cang");
          break;  
        case 'I':
          keo_cang_len();
          Serial.println("keo cang len");
          break;  
        case 'O':
          tha_cang_xuong();
          Serial.println("tha cang xuong");
          break;  
        case 'P':
          dung_keo_tha_cang();
          Serial.println("dung dong co keo / tha cang");
      }
    }
    // Kiểm tra giá trị của Bluetooth

  if (SerialBT.available()) 
    {
    char receivedChar = SerialBT.read();
      
    switch (receivedChar) 
    {   // Điều chỉnh xung pwm và gán giá trị cho maxpwmvlue
        case 'A':
            MaxpwmValue = pwmValue_0();
            Serial.println(MaxpwmValue);
            break;
        case 'S':
            MaxpwmValue = pwmValue_28();
            Serial.println(MaxpwmValue);
            break;
        case 'D':
            MaxpwmValue = pwmValue_56();
            Serial.println(MaxpwmValue);
            break;
        case 'F':
            MaxpwmValue = pwmValue_84();
            Serial.println(MaxpwmValue);
            break;
        case 'G':
            MaxpwmValue = pwmValue_112();
            Serial.println(MaxpwmValue);
            break;
        case 'H':
            MaxpwmValue = pwmValue_140();
            Serial.println(MaxpwmValue);
            break;
        case 'J':
            MaxpwmValue = pwmValue_168();
            Serial.println(MaxpwmValue);
            break;
        case 'K':
            MaxpwmValue = pwmValue_196();
            Serial.println(MaxpwmValue);
            break;
        case 'L':
            MaxpwmValue = pwmValue_224();
            Serial.println(MaxpwmValue);
            break;
        case 'M':
            MaxpwmValue = pwmValue_255();
            Serial.println(MaxpwmValue);
            break;
// *********************************************************************************************//
       //********************************** Điều khiển robot ******************************//
        case 'Q':
        // Robot tiến và tăng tốc độ lên từ từ cho đến khi đủ xung yêu cầu
          if (pwmValue<MaxpwmValue)
          { 
            if (val>=20)
            {
              val=20;
            }
            else
            {
              val+=1;
            }
            pwmValue=map(val,0,20,0,MaxpwmValue);
          }
          Serial.println(pwmValue);
          up();
          break;
          
        case 'W':
        // Robot lùi và tăng tốc độ lên từ từ cho đến khi đủ xung yêu cầu
           if (pwmValue<MaxpwmValue)
          { 
            if (val>=20)
            {
              val=20;
            }
            else
            {
              val+=1;
            }
            pwmValue=map(val,0,20,0,MaxpwmValue);
          }
          Serial.println(pwmValue);
          back();
          break;
        case 'E':
          // Xử lý cho trường hợp nhận được ký tự 'E'
          Serial.println("Dung");
          dung();
          break;
        case 'R':
          // Xử lý cho trường hợp nhận được ký tự 'R'
          Serial.println("Quay trai");
          turnleft();
          break;
        case 'T':
          // Xử lý cho trường hợp nhận được ký tự 'T'
          Serial.println("Quay phai");
          turnright();
          break;
        case 'C':
          // Nâng cấu kiện
          Serial.println("nang cang");
          nang_cang();
          break;
        case 'V':
          // Hạ cấu kiện
          Serial.println("ha cang");
          ha_cang();
          break;  
        case 'U':
        // Dùng động cơ nâng / hạ
          dung_nang_ha();
          Serial.println("dung dong co nang, ha cang");
          break;  
        case 'I':
        // Kéo càng lên
          keo_cang_len();
          Serial.println("keo cang len");
          break;  
        case 'O':
        // Thả càng xuống
          tha_cang_xuong();
          Serial.println("tha cang xuong");
          break;  
        case 'P':
        // Dừng động cơ kéo / thả càng
          dung_keo_tha_cang();
          Serial.println("dung dong co keo / tha cang"); 
      }
    }
  }
  else 
  {
      dung();
      pwmValue=dung();
      dung_nang_ha();
      dung_keo_tha_cang();
      //Serial.println("Vui long ket noi Bluetooth va thu lai !");
  }
}
