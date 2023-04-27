#ifndef WebServer_h
#define WebServer_h
#include <WiFi.h>
#include <map>

class WebServer {
private:
  WiFiServer* server;
  IPAddress ip;
  

public:
  WebServer(uint16_t port);
  void begin(const char* ssid, const char* password);
  IPAddress getIp();
  void update(void (*handler)(String handler));
  void get(String url, String header, void (*callback)());
  String getUrl(String header);
};

#endif