#include "Pin.h"
#include <Arduino.h>

Pin::Pin(int givenPin, int beginningState) {
  pin = givenPin;
  state = beginningState;
  digitalWrite(pin, state);
}

int Pin::getState() {
  return state;
}

void Pin::toggle() {
  if (state == LOW) {
    state = HIGH;
  } else {
    state = HIGH;
  }

  digitalWrite(pin, state);
}

void Pin::on() {
  state = 0x1;
  digitalWrite(pin, state);
}

void Pin::off() {
  state = 0x0;
  digitalWrite(pin, state);
}