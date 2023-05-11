// Created By Miles & Connor

#ifndef WebServer_h
#define WebServer_h

#include <functional>
#include <WiFi.h>
#include <map>

class WebServer
{
private:
  WiFiServer *server;
  IPAddress ip;
  std::map<String, std::function<void(WiFiClient)>> callbackMap;

public:
  WebServer(uint16_t port);
  IPAddress getIp();
  String getUrl(String header);
  void begin(char *ssid, char *password = NULL);
  void listen();
  void get(String location, void (*callback)(WiFiClient));
};
#endif
