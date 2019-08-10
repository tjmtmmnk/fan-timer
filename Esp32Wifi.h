#ifndef ESP32WIFI
#define ESP32WIFI

#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#include "config.h"
#include "Arduino.h"
#include "servo.h"
#include "ESPAsyncWebServer.h"

class Esp32Wifi {
 private:
  int port;
  WiFiClient *client;
  AsyncWebServer *server;
  PushServo *servo;

 public:
  Esp32Wifi(int);
  void receive_UTC_time();
  void connect();
  void routing();
};

#endif