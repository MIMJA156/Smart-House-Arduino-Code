#include "WebServer.h"
#include "Interval.h"
#include <WiFi.h>
#include "Pin.h"

const char *SSID = "Miles-Quint-Ashton";
const char *PASSWORD = "123456789";

WebServer server(80);

Pin pin15(15, LOW);


void setup() {
  Serial.begin(115200);

  server.get("/", [](WiFiClient client) {
    client.println(getHtml());
  });

  server.get("/api/toggle", [](WiFiClient client) {
    pin15.toggle();
    Serial.println("toggle");
  });

  server.begin(SSID, PASSWORD);
}

void loop() {
  server.listen();
}

String getHtml(){
return "<!DOCTYPE html><html><head><title>The Shack Control</title></head><body><style>html,body {height: 100%;overflow-y: auto;font-family: Arial;}button.main-button {border-radius: 10px;font-size: 30px;background-color: #03CC29;color: white;padding: 10px;margin: 10px;border-color: #02ad22;transition: 0.3s;}div.monitor {border-radius: 10px;font-size: 30px;background-color: #c4c4c4;color: white;padding: 10px;margin: 5px;transition: 0.3s;}button.main-button:hover {background-color: #0CD833;}h1 {text-align: center;font-size: 72px;}div.btn-body {display: flex;justify-content: center;align-items: center;border-radius: 30px;background-color: #f0f0f0;padding: 5px;margin: 10px;}p.monitor-head {font-size: 12px;line-height: 2px;}</style><div class=\"main\"><h1>The High Rolla Controlla</h1><div class=\"btn-body\"><button class=\"main-button\" onclick=\"fetch('/api/toggle')\">Toggle Dah Lights</button></div></div></body></html>";
}