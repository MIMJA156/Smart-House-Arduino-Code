#include <utility>
#include "esp32-hal.h"
#include "WebServer.h"
#include <WiFi.h>
#include <unordered_map>

WebServer::WebServer(uint16_t port) {
  server = new WiFiServer(port);
};

void WebServer::begin(const char *ssid, const char *password) {
  WiFi.softAP(ssid, password);
  ip = WiFi.softAPIP();

  server->begin();
};

IPAddress WebServer::getIp() {
  return ip;
};

void WebServer::update() {
  WiFiClient client = server->available();

  if (!client) return;
  String currentLine = "";
  String header = "";

  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      header += c;
      if (c == '\n') {
        if (currentLine.length() == 0) {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println("Connection: close");
          client.println();

          // return logic
          char* urlAsChar;
          strcpy(urlAsChar, getUrl(header).c_str());
          callBackMap.find(urlAsChar)->second()
          break;
        } else {
          currentLine = "";
        }
      } else if (c != '\r') {
        currentLine += c;
      }
    }
  }
}

void WebServer::get(char* location, void (*callback)()){
  callBackMap.insert(std::pair<char*,void (*&)()>(location, callback));
}

String WebServer::getUrl(String header) {
  int first = header.indexOf(" ");
  String start = header.substring(first + 1);
  String url = start.substring(0, start.indexOf(" "));
  return url;
}