#ifndef ESP32WIFI
#define ESP32WIFI

#include <WiFi.h>
#include "config.h"
#include "Arduino.h"
#include "servo.h"

class Esp32Wifi {
 private:
  int port;
  WiFiServer *server;
  WiFiClient *client;
  PushServo *servo;

 public:
  Esp32Wifi(int);
  void receive_UTC_time();
  void connect();
};

#endif