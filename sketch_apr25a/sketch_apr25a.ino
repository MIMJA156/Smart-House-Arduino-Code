// Created By Miles & Connor

#include "WebServer.h"
#include "Interval.h"
#include <WiFi.h>
#include "Pin.h"

char *SSID = "RPL";
char *PASSWORD = "123456789";

WebServer server(80);

Pin pin23(23, LOW);


void setup() {
  Serial.begin(115200);

  server.get("/", [](WiFiClient client) {
    client.println(getHtml());
  });

  server.get("/api/toggle", [](WiFiClient client) {
    pin23.toggle();
  });

  server.begin(SSID);
}

void loop() {
  server.listen();
}

String getHtml(){
return "<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\" /><meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\" /><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\" /><title>Document</title></head><body><button id=\"toggle\">Toggle Pin</button></body><script>const toggle = document.getElementById(\"toggle\");toggle.addEventListener(\"click\", () => {fetch(\"/api/toggle\");});</script></html>";
}
