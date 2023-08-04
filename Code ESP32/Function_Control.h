// Gọi cần dùng
#include "Pin_Control.h"
// Hàm tiến robot
void up() 
{
  //fast(pwmValue,MaxpwmValue,val);
  analogWrite(Motor1Pin1, pwmValue);
  analogWrite(Motor1Pin2, LOW);
  analogWrite(Motor2Pin1, LOW);
  analogWrite(Motor2Pin2, pwmValue);
  //return fast(pwmValue,MaxpwmValue,val);
  return;
}
// Hàm lùi robot
void back()   
{
  //fast(pwmValue,MaxpwmValue,val);
  analogWrite(Motor1Pin1, LOW);
  analogWrite(Motor1Pin2, pwmValue);
  analogWrite(Motor2Pin1, pwmValue);
  analogWrite(Motor2Pin2, LOW);
  //return fast(pwmValue,MaxpwmValue,val);
  return;
}
// Dừng robot
unsigned char  dung() 
{
  analogWrite(Motor1Pin1, LOW);
  analogWrite(Motor1Pin2, LOW);
  analogWrite(Motor2Pin1, LOW);
  analogWrite(Motor2Pin2, LOW);
  return pwmValue=0,val=0;
}
// Hàm cho robot quay trái
void turnleft() 
{
  analogWrite(Motor1Pin1, LOW);
  analogWrite(Motor1Pin2, pwmValue);
  analogWrite(Motor2Pin1, LOW);
  analogWrite(Motor2Pin2, pwmValue); 
}
// Hàm cho robto quay phải
void turnright() 
{
  analogWrite(Motor1Pin1, pwmValue); 
  analogWrite(Motor1Pin2, LOW); 
  analogWrite(Motor2Pin1, pwmValue); 
  analogWrite(Motor2Pin2, LOW); 
}

// Nâng trục càng
void nang_cang() 
{
  servo1.write(0);
}
// Hạ trục càng
void ha_cang() 
{
  servo1.write(180);
}  
// Dừng nâng / hạ càng
void dung_nang_ha() 
{
  servo1.write(90);
}
// kéo càng
void keo_cang_len() {
  servo2.write(0);
}
// thả càng
void tha_cang_xuong() {
  servo2.write(90);
}
// dừng kéo / thả càng
void dung_keo_tha_cang() {
  servo1.write(0);
}
//*******************************************************//
// Điều chỉnh xung pwm và trả về giá trị cho MaxpwmValue
unsigned char pwmValue_0() {
  return  MaxpwmValue = 0;
}
unsigned char pwmValue_28() {
  return  MaxpwmValue = 28;
}
unsigned char pwmValue_56() {
  return  MaxpwmValue = 56;
}
unsigned char pwmValue_84() {
  return  MaxpwmValue = 84;
}
unsigned char pwmValue_112() {
  return  MaxpwmValue = 112;
}
unsigned char pwmValue_140() {
  return  MaxpwmValue = 140;
}
unsigned char pwmValue_168() {
  return  MaxpwmValue = 168;
}
unsigned char pwmValue_196() {
  return  MaxpwmValue = 196;
}
unsigned char pwmValue_224() {
  return  MaxpwmValue = 224;
}
unsigned char pwmValue_255() {
  return  MaxpwmValue = 255;
}
//*******************************************************//
void gia_toc_up(unsigned char MaxpwmValue)
{ 
  if (pwmValue>=MaxpwmValue)
  { pwmValue=MaxpwmValue;
    up();
    Serial.println(pwmValue);
    return;
  }
  else
  {
    for(pwmValue;pwmValue<=MaxpwmValue;pwmValue+=1)
    {
      Serial.println(pwmValue);
      //delay(100);
      up();
      if (pwmValue==MaxpwmValue)
      {
        break;
      }
    }
  }
  return;
}


