#include "IRsensor.h"

IRsensor::IRsensor(int IRsensor_Pin) {   
  this->IRsensor_Pin = IRsensor_Pin;
  //pinMode(this->IRsensor_Pin,OUTPUT);
}

int IRsensor::IRsensor_analog() {       
  int value = analogRead(this->IRsensor_Pin);
  //Serial.println(value);
  if (value >= 300 ) return 0;    //
  else return 1;
}

int IRsensor::IRsensor_digital() {
  int value = digitalRead(this->IRsensor_Pin);
  if (value ==0 ) return 0;
  else return 1;

}