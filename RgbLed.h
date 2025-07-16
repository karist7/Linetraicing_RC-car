#ifndef RGBLED_H
#define RGBLED_H
#include <Arduino.h>
class RgbLed{
  private:
    int redState;
    int greenState;
    int blueState;
  public:
    RgbLed(int redState, int greenState, int blueState);
    void ledState(int state);
};

#endif