#include "UltraSound.h"
#include "Motor.h"
UltraSound::UltraSound(int trig_pin, int echo_pin){
  this->trig_pin = trig_pin;
  this->echo_pin = echo_pin;
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

}

long UltraSound::checkDistance(){
  digitalWrite(this->trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(this->trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(this->trig_pin,LOW);

  long duration = pulseIn(this->echo_pin,HIGH,30000); //pulse값 조정
  if(duration == 0){
  //Serial.println("초음파 센서 오류: 신호 수신 실패");
    return -1;
  }

  long distance  = duration /58.2;
  //Serial.println(distance);
  return distance;
}