#include "servo.h"

PushServo servo(33, 0, 50);

void setup() { Serial.begin(115200); }

void loop() { servo.push_button(); }
