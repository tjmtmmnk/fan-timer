#include <ESP32Servo.h>

Servo servo;

const int servo_pin = 33;

const int push_button_pos = 50;
const int start_pos = 0;

void setup() {
  Serial.begin(115200);
  servo.setPeriodHertz(50);
  servo.attach(servo_pin);
}

void loop() {
  servo1.write(start_pos);
  delay(5000);
  servo1.write(push_button_pos);
  delay(1000);
}
