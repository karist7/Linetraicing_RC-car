#include "Motor.h"

Motor::Motor(int A_IA, int A_IB, int B_IA, int B_IB){
  this->A_IA = A_IA;
  this->A_IB = A_IB;
  this->B_IA = B_IA;
  this->B_IB = B_IB;
  pinMode(this->A_IA,OUTPUT);
  pinMode(this->A_IB,OUTPUT);
  pinMode(this->B_IA,OUTPUT);
  pinMode(this->B_IA,OUTPUT);

}

void Motor::front(){
    analogWrite(this->A_IA, 0);   //128
    analogWrite(this->A_IB, 0);
    analogWrite(this->B_IA, 0);     //128
    analogWrite(this->B_IB, 0);
//Serial.println("f");
}

void Motor::back(){
    analogWrite(this->A_IA, 0);
    analogWrite(this->A_IB, 0); //128
    analogWrite(this->B_IA, 0);
    analogWrite(this->B_IB, 0); //128
    //Serial.println("b");
}

void Motor::right(){
    analogWrite(this->A_IA, 0); //128
    analogWrite(this->A_IB, 0);
    analogWrite(this->B_IA, 0);
    analogWrite(this->B_IB, 0); //64
    //Serial.println("r");
}

void Motor::left(){
    analogWrite(this->A_IA, 0);//64
    analogWrite(this->A_IB, 0);
    analogWrite(this->B_IA, 0);//128
    analogWrite(this->B_IB, 0);
    //Serial.println("l");
}
void Motor::stop(){
    analogWrite(this->A_IA, 0);
    analogWrite(this->A_IB, 0);
    analogWrite(this->B_IA, 0);
    analogWrite(this->B_IB, 0);
    //Serial.println("s");
}