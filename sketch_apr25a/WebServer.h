#include <functional>
#ifndef WebServer_h
#define WebServer_h
#include <WiFi.h>
#include <map>
#include <unordered_map>
#include <map>

class WebServer {
private:
  WiFiServer *server;
  IPAddress ip;
  std::map<String, std::function<void(WiFiClient)>> callbackMap;

public:
  WebServer(uint16_t port);
  IPAddress getIp();
  String getUrl(String header);
  void begin(const char *ssid, const char *password);
  void update();
  void get(String location, void (*callback)(WiFiClient));
};
#endif