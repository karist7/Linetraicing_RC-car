#ifndef Motor_H
#define Motor_H
#include <Arduino.h>

class Motor{
  private:
    int A_IA;
    int A_IB;
    int B_IA;
    int B_IB;
  public:
    Motor(int A_IA, int A_IB, int B_IA, int B_IB);
    void front();
    void back();
    void right();
    void left();
    void stop();
};

#endif