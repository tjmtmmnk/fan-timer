#include "Esp32Wifi.h"
#include "servo.h"

PushServo *servo;
Esp32Wifi *wifi;

const int led_pin = 2;
const int servo_pin = 33;

void setup() {
  pinMode(led_pin, OUTPUT);
  Serial.begin(115200);
  servo = new PushServo(servo_pin, 0, 50);
  wifi = new Esp32Wifi(80);
  wifi->connect();
}
void loop() {
  wifi->receive_UTC_time();
  servo->push_button();
}
