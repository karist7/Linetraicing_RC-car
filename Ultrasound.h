#ifndef ULTRASOUND_H
#define ULTRASOUND_H
#include <Arduino.h>
class UltraSound{
  private:
    int trig_pin;
    int echo_pin;
  public:
    UltraSound(int trig_pin,int echo_pin);
    long checkDistance(); //거리 측정 후 반환
    //void intterupt();
};


#endif