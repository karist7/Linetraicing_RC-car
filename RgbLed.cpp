#include "RgbLed.h"

RgbLed::RgbLed(int redState,int greenState, int blueState){
  this->redState = redState;
  this->greenState = greenState;
  this->blueState = blueState;
  pinMode(this->redState,OUTPUT);
  pinMode(this->greenState,OUTPUT);
  pinMode(this->blueState,OUTPUT);
}
void RgbLed::ledState(int state){
  if(state==1){
    digitalWrite(this->redState,LOW);
    digitalWrite(this->greenState,HIGH);
    digitalWrite(this->blueState,LOW);
  }
  else if (state == 2){
    digitalWrite(this->redState,LOW);
    digitalWrite(this->greenState,LOW);
    digitalWrite(this->blueState,HIGH);
  }
   else if (state == 3){
    digitalWrite(this->redState,HIGH);
    digitalWrite(this->greenState,HIGH);
    digitalWrite(this->blueState,LOW);
  }
   else if (state == 4){
    digitalWrite(this->redState,LOW);
    digitalWrite(this->greenState,HIGH);
    digitalWrite(this->blueState,HIGH);
  }
   else {
    digitalWrite(this->redState,HIGH);
    digitalWrite(this->greenState,LOW);
    digitalWrite(this->blueState,LOW);
  }
}