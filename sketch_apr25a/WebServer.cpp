// Created By Miles & Connor

#include "esp32-hal.h"
#include "WebServer.h"
#include <utility>
#include <WiFi.h>
#include <map>

WebServer::WebServer(uint16_t port)
{
  server = new WiFiServer(port);
};

void WebServer::begin(char *ssid, char *password)
{
  if (password == ""){
    password = NULL; 
  }
  
  WiFi.softAP(ssid, password);
  ip = WiFi.softAPIP();

  server->begin();
};

IPAddress WebServer::getIp()
{
  return ip;
};

void WebServer::listen()
{
  WiFiClient client = server->available();

  if (!client)
    return;
  String currentLine = "";
  String header = "";

  while (client.connected())
  {
    if (client.available())
    {
      char c = client.read();
      header += c;
      if (c == '\n')
      {
        if (currentLine.length() == 0)
        {
          client.println("HTTP/1.1 200 OK");
          client.println("Content-type:text/html");
          client.println("Connection: close");
          client.println();

          String location = getUrl(header);

          if (callbackMap[location])
          {
            callbackMap[location](client);
          }

          break;
        }
        else
        {
          currentLine = "";
        }
      }
      else if (c != '\r')
      {
        currentLine += c;
      }
    }
  }
}

void WebServer::get(String location, void (*callback)(WiFiClient))
{
  callbackMap.emplace(location, callback);
}

String WebServer::getUrl(String header)
{
  int first = header.indexOf(" ");
  String start = header.substring(first + 1);
  String url = start.substring(0, start.indexOf(" "));
  return url;
}
