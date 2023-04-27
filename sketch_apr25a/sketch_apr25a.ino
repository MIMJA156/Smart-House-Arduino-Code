#include "interval.h"
#include "webServer.h"
#include <WiFi.h>

const char* SSID = "connor-and-miles";
const char* PASSWORD = "123456789";

WebServer server(80);

void setup() {
  Serial.begin(115200);

  server.begin(SSID, PASSWORD);
}

void loop() {
  server.update([](String header){
    server.get("/", header, [](){

    });

    server.get("/api/", header, [](){
      Serial.println("api");
    });
  });
}

string html(){
  
}