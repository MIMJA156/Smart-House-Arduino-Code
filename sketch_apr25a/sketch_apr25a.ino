#include "interval.h"
#include <WiFi.h>

const char* SSID = "connor and miles are the best coders in the world!";
const char* PASSWORD = "123";

const int output26 = 26;
const int output27 = 27;

bool pin26State = false;
bool pin27State = true;
bool highLowTone = false;  //false low true high

void run() {
  pin26State = !pin26State;
  pin27State = !pin27State;

  digitalWrite(output26, pin26State ? HIGH : LOW);
  digitalWrite(output27, pin27State ? HIGH : LOW);
}

void beepSpeaker() {
  highLowTone = !highLowTone;
  int frequency = highLowTone ? 2400 : 500;
  tone(25, frequency, 0.9);
}

Interval fire(700, run);
Interval beep(300, beepSpeaker);


void setup() {
  Serial.begin(115200);

  pinMode(output26, OUTPUT);
  pinMode(output27, OUTPUT);

  digitalWrite(output26, pin26State);
  digitalWrite(output27, pin27State);

  WiFi.softAP(SSID, PASSWORD);
}

void loop() {
  fire.update();
  beep.update();
}
