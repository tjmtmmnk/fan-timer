#include "/Users/hp29/Library/Arduino15/packages/esp32/hardware/esp32/1.0.2/libraries/WiFi/src/WiFi.h"

class ESP32WiFiServer {
  private:
   WiFiServer *server;
   int port;

   public:
    ESP32WiFiServer(int);
    void connect();
};