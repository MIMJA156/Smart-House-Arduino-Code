#ifndef WebServer_h
#define WebServer_h
#include <WiFi.h>
#include <map>
#include <unordered_map>

class WebServer
{
private:
  WiFiServer *server;
  IPAddress ip;
  std::unordered_map<char *, void (*&)()> callBackMap;

public:
  WebServer(uint16_t port);
  IPAddress getIp();
  String getUrl(String header);
  void begin(const char *ssid, const char *password);
  void update();
  void get(char *location, void (*callback)());
};
#endif