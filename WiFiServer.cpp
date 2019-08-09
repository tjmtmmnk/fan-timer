#include "WiFiServer.h"
#include "config.h"

ESP32WiFiServer::ESP32WiFiServer(int _port) : port(_port) {
  server = new WiFiServer(port);
}

void ESP32WiFiServer::connect() {
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server->begin();
}