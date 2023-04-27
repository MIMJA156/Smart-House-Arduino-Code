#include "esp32-hal.h"
#include "WebServer.h"
#include <WiFi.h>

WebServer::WebServer(uint16_t port){
  server = new WiFiServer(port);
};

void WebServer::begin(const char *ssid, const char *password){
  WiFi.softAP(ssid, password);
  ip = WiFi.softAPIP();

  server->begin();
};

IPAddress WebServer::getIp(){
  return ip;
};

void WebServer::update(void (*handler)(String header)){
  WiFiClient client = server->available();

  if(!client) return;
  String currentLine = "";
  String header = "";
  
  while(client.connected()){
    if(client.available()){
      char c = client.read();
      header += c;
      if(c == '\n'){
        if(currentLine.length() == 0){
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            handler(header);
          break;
        } else {
          currentLine = "";
        }
      } else if (c != '\r'){
        currentLine += c;
      }
    }
  }
}

void WebServer::get(String url, client, String header, String (*callback)(WiFiClient client)){
  String headerUrl = getUrl(header);
  if(headerUrl == url){
    String res = callback();
    client.println(res);
  }
}

String WebServer::getUrl(String header){
  int first = header.indexOf(" ");
  String start = header.substring(first + 1);
  String url = start.substring(0, start.indexOf(" "));
  return url;
}