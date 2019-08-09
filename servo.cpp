#include "servo.h"

PushServo::PushServo(int _servo_pin, int _start_pos, int _push_button_pos)
    : servo_pin(_servo_pin),
      start_pos(_start_pos),
      push_button_pos(_push_button_pos) {
  servo = new Servo();
  servo->setPeriodHertz(50);
  servo->attach(servo_pin);
}

void PushServo::push_button() {
  servo->write(start_pos);
  delay(1000);
  servo->write(push_button_pos);
  delay(1000);
  servo->write(start_pos);
  delay(1000);
}