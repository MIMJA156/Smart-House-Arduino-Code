#include "interval.h"
#include "webServer.h"
#include <WiFi.h>

const char *SSID = "Conner-and-Miles";
const char *PASSWORD = "123456789";

WebServer server(80);

void setup()
{
  Serial.begin(115200);

  server.get("/api/pin-26-on", []()
             { Serial.println("get - 26 -> on"); });

  server.get("/api/pin-26-off", []()
             { Serial.println("get - 26 -> off"); });

  server.begin(SSID, PASSWORD);
}

void loop()
{
  server.update();
}

String getHtml()
{
  return "<!DOCTYPE html><html><head><title>Arduino Control</title></head><body><style>html,body {height:100%;overflow-y:auto;}.main {width:100%;height:100%;padding:none;background:rgb(188, 210, 183);display:grid;grid-template-rows:auto(8,1fr);grid-template-columns: auto(1,1fr);}.head {grid-row:1/1;grid-column:1/1;border:2px solid rgb(86,190,149);margin:2px;text-align:center;font-size:400%;font-weight:bold;}.body {grid-row:2/8;grid-column:1/1;border:2px solid rgb(86,190,149);margin:2px;}.button-container {width:180px;height:180px;border:2px solid rgb(86, 190, 149);margin:10px;float:left;text-align:center;}.main-button {background:rgb(143,143,143);width:60%;height:30%;margin:12px;}.button-title {font-size:200%;}</style><div class=\"main\"><div class=\"head\">Arduino Controller</div><div class=\"body\"><div class=\"button-container\"><button class=\"main-button\" onclick=\"fetch('/api/26-toggle')\">toggle</button><p class=\"button-title\">pin 26</p></div><div class=\"button-container\"><button class=\"main-button\" onclick=\"fetch('/api/27-toggle')\">toggle</button><p class=\"button-title\">pin 27</p></div><div class=\"button-container\"><button class=\"main-button\" onclick=\"fetch('/api/fire-alarm')\">FIRE ALARM</button><p class=\"button-title\"></p></div></div></div></body></html>";
}