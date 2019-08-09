#ifndef SERVO
#define SERVO
#include <ESP32PWM.h>
#include <ESP32Servo.h>
#include <ESP32Tone.h>
#include <analogWrite.h>
#include "Arduino.h"

class PushServo {
 private:
  int servo_pin;
  int start_pos;
  int push_button_pos;
  Servo *servo;

 public:
  PushServo(int, int, int);
  void push_button();
};

#endif