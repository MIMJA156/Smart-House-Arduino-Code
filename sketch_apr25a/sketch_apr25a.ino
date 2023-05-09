#include "WebServer.h"
#include "Interval.h"
#include <WiFi.h>
#include "Pin.h"

const char *SSID = "Connor-Kirk-Alexandra-Smarthouse";
const char *PASSWORD = "123456789";

WebServer server(80);

Pin pin26(26, LOW);
Pin pin27(27, LOW);
Pin pin25(25, LOW);
Pin pin33(33, LOW);

Interval pin33Blink(600, [](){
  pin33.toggle();
});

Interval pin26Blink(800, [](){
  pin26.toggle();
});


void setup() {
  Serial.begin(115200);

  server.get("/", [](WiFiClient client) {
    client.println(getHtml());
  });

  // server.get("/api/26-toggle", [](WiFiClient client) {
  //   pin26.toggle();
  //   Serial.println(2);
  //   client.println(pin26.getState() + "");
  // });

  server.get("/api/27-toggle", [](WiFiClient client) {
    pin27.toggle();
    client.println(pin27.getState() + "");
  });

  server.get("/api/25-toggle", [](WiFiClient client) {
    pin25.toggle();
    client.println(pin25.getState() + "");
  });

  // server.get("/api/33-toggle", [](WiFiClient client) {
  //   pin33.toggle();
  //   client.println(pin33.getState() + "");
  // });

  server.begin(SSID, PASSWORD);
}

void loop() {
  server.listen();
  pin33Blink.update();
  pin26Blink.update();
}

String getHtml(){
return "<!DOCTYPE html><html><head><title>The Shack Control</title></head><body><style>html,body {height: 100%;overflow-y: auto;font-family: Arial;}button.main-button {border-radius: 10px;font-size: 30px;background-color: #03CC29;color: white;padding: 10px;margin: 10px;border-color: #02ad22;transition: 0.3s;}div.monitor {border-radius: 10px;font-size: 30px;background-color: #c4c4c4;color: white;padding: 10px;margin: 5px;transition: 0.3s;}button.main-button:hover {background-color: #0CD833;}h1 {text-align: center;font-size: 72px;}div.btn-body {display: flex;justify-content: center;align-items: center;border-radius: 30px;background-color: #f0f0f0;padding: 5px;margin: 10px;}p.monitor-head {font-size: 12px;line-height: 2px;}</style><div class=\"main\"><h1>The Shack Control</h1><div class=\"btn-body\"><button class=\"main-button\" onclick=\"fetch('/api/25-toggle')\">Thermostat</button><!-- <button class=\"main-button\" onclick=\"fetch('/api/26-toggle')\">Lights 26</button> --><button class=\"main-button\" onclick=\"fetch('/api/27-toggle')\">Ceiling Light</button><!-- <button class=\"main-button\" onclick=\"fetch('/api/33-toggle')\">Lights 33</button> --></div></div></body></html>";
}