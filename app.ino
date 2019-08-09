#include "Esp32Wifi.h"
#include "servo.h"

PushServo *servo;
Esp32Wifi *wifi;

void setup() {
  Serial.begin(115200);
  servo = new PushServo(33, 0, 50);
  wifi = new Esp32Wifi(80);
  wifi->connect();
}
void loop() {
  wifi->receive_UTC_time();
  servo->push_button();
}
