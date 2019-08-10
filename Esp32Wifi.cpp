#include "Esp32Wifi.h"

Esp32Wifi::Esp32Wifi(int _port) : port(_port) {
  server = new WiFiServer(port);
};

void Esp32Wifi::connect() {
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
void Esp32Wifi::receive_UTC_time() {
  WiFiClient _client = server->available();
  if (_client) {
    client = &_client;
    String current_line = "";
    while (client->connected()) {
      if (client->available()) {
        char c = client->read();
        Serial.write(c);
        if (c == '\n') {
          if (current_line.length() == 0) {
            client->println("HTTP/1.1 200 OK");
            client->println("Content-type:text/html");
            client->println();
            client->print(
                "Click <a href=\"/H\">here</a> to turn the LED on pin 5 "
                "on.<br>");
            client->print(
                "Click <a href=\"/L\">here</a> to turn the LED on pin 5 "
                "off.<br>");

            // The HTTP response ends with another blank line:
            client->println();
            break;
          } else {
            current_line = "";
          }
        } else if (c != '\r') {
          current_line += c;
        }

        if (current_line.endsWith("GET /H")) {
          Serial.println("high!!!!");
          digitalWrite(2, HIGH);
        }
        if (current_line.endsWith("GET /L")) {
          digitalWrite(2, LOW);
        }
      }
    }
    client->stop();
    Serial.println("Client Disconnected.");
  }
}