#ifndef IRsensor_H
#define IRsensor_H
#include <Arduino.h>
class IRsensor{
private:
  int IRsensor_Pin;
public:
  IRsensor(int Rsensor_Pin); // (IRsensor 사용할 핀)
  int IRsensor_analog();    // 거리에 따라 0(멀다)~4(가깝다) 정수값 반환
  int IRsensor_digital();    // 감지 시 1  , 미감지 시 0  정수값 반환
};

#endif