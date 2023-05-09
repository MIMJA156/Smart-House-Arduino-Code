#include "esp32-hal-gpio.h"
#include <Arduino.h>
#include "Pin.h"

Pin::Pin(int givenPin, int beginningState)
{
  pin = givenPin;
  state = beginningState;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, state);
}

int Pin::getState()
{
  return state;
}

void Pin::toggle()
{
  if (state == LOW)
  {
    state = HIGH;
  }
  else
  {
    state = LOW;
  }

  digitalWrite(pin, state);
}

void Pin::on()
{
  state = HIGH;
  digitalWrite(pin, state);
}

void Pin::off()
{
  state = LOW;
  digitalWrite(pin, state);
}