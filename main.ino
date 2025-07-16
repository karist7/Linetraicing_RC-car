#include <SoftwareSerial.h>
#include "IRsensor.h"
#include "Motor.h"
#include "Ultrasound.h"
#include "RgbLed.h"
#define blueTX 10
#define blueRX 9
char ble = 0;
char ser = 0;
SoftwareSerial HC06(blueTX, blueRX);
bool autoFlag = false;
IRsensor IR1(A0);  // IR센서 핀 수정
int IR = A0;
IRsensor IR2(A1);        // IR센서 핀 수정
Motor M1(5, 6, 12, 13);  // pin ; A_IA, A_IB, B_IA, B_IB  (A:앞  B; 뒤)
UltraSound Ultra(2, 3);
RgbLed rgb(A1, A2, A3);
void setup() {
  Serial.begin(9600);
  HC06.begin(9600);
}

void HC06proc() {
  if (Serial.available() > 0) {

    ser = Serial.read();
    HC06.write(ser);
  }
  if (HC06.available() > 0) {
    ble = HC06.read();

    Serial.write(ble);
    if (ble == 'f') {
      M1.front();
      rgb.ledState(1);
      Serial.println("F");
    } else if (ble == 'r') {
      M1.right();
      rgb.ledState(3);
      Serial.println("R");
    } else if (ble == 'l') {
      M1.left();
      rgb.ledState(4);
      Serial.println("L");
    } else if (ble == 's') {
      M1.stop();
      rgb.ledState(5);
      Serial.println("s");
    } else if (ble == 'a') {
      autoFlag = !autoFlag;
    }
  }
}

void loop() {
  HC06proc();
  if (!autoFlag) {
    long dis = Ultra.checkDistance();
    if (dis >= 15) {
      int Value_IR1 = IR1.IRsensor_analog();
      int Value_IR2 = IR2.IRsensor_analog();
      if (Value_IR1 == 0 && Value_IR2 == 0) {
        M1.stop();
        rgb.ledState(5);
      } else if (Value_IR1 == 0 && Value_IR2 == 1) {
        M1.right();
        rgb.ledState(3);
      } else if (Value_IR1 == 1 & Value_IR2 == 0) {
        M1.left();
        rgb.ledState(4);
      } else if (Value_IR1 == 1 & Value_IR2 == 1) {
        M1.front();
        rgb.ledState(1);
      }
    } else {

      M1.stop();
      rgb.ledState(5);
      delay(2000);
    }
  } else {
    Serial.println("aUTO");
  }
  delay(10);
}
