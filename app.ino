#include "Esp32Wifi.h"

Esp32Wifi *wifi;

void setup() {
  Serial.begin(115200);
  wifi = new Esp32Wifi(80);
  wifi->connect();
}
void loop() { wifi->receive_UTC_time(); }
