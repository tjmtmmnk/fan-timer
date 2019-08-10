#include "Esp32Wifi.h"

Esp32Wifi::Esp32Wifi(int _port) : port(_port) {
  server = new AsyncWebServer(port);
  servo = new PushServo(33, 0, 50);
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
}

void Esp32Wifi::routing() {
  server->on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    String html = "";

    html +=
        "<form action=\"/on-timer\" method=\"get\">\n"
        "<input type=\"text\" name=\"date\" value=\"aaa\">\n"
        "<input type=\"submit\" name=\"submit\" value=\"submit\">\n"
        "</form>\n";

    request->send(200, "text/html", html);
  });

  server->on("/on-timer", HTTP_GET, [](AsyncWebServerRequest* request) {
    AsyncWebParameter* p = request->getParam(0);
    String ret = "";
    if (p != nullptr) {
      ret = p->value();
    }
    request->send(200, "text/plain", ret);
  });

  server->on("/on-timer", HTTP_POST, [](AsyncWebServerRequest* request) {},
             NULL,
             [](AsyncWebServerRequest* request, uint8_t* data, size_t len,
                size_t index, size_t total) {
               for (size_t i = 0; i < len; i++) {
                 Serial.write(data[i]);
               }

               Serial.println();

               request->send(200);
             });

  server->begin();
}

void Esp32Wifi::receive_UTC_time() {
  // WiFiClient _client = server->available();
  // if (_client) {
  //   client = &_client;
  //   String current_line = "";
  //   while (client->connected()) {
  //     if (client->available()) {
  //       char c = client->read();
  //       Serial.write(c);
  //       if (c == '\n') {
  //         if (current_line.length() == 0) {
  //           String html = "";
  //           html +=
  //               "HTTP/1.1 200 OK\n"
  //               "Content-Type: text/html\n"
  //               "\n";

  //           html +=
  //               "<form action=\"ontime\" method=\"get\">\n"
  //               "<input type=\"text\" name=\"date\" size=\"40\">\n"
  //               "<input type=\"submit\" value=\"submit\">\n"
  //               "</form>\n";

  //           client->print(html);

  //           // The HTTP response ends with another blank line:
  //           client->println();
  //           break;
  //         } else {
  //           current_line = "";
  //         }
  //       } else if (c != '\r') {
  //         current_line += c;
  //       }

  //       if (current_line.endsWith("GET /P")) {
  //         servo->push_button();
  //       }
  //     }
  //   }
  //   client->stop();
  //   Serial.println("Client Disconnected.");
  // }
}