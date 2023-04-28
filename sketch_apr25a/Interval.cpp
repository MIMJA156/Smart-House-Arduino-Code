#include "Interval.h"
#include <Arduino.h>

Interval::Interval(int wantedSampleRate, void (*passedCallback)()) {
  sampleRate = wantedSampleRate;
  lastCycle = millis();
  isRunning = true;
  callback = passedCallback;
}

void Interval::update() {
  if (millis() - lastCycle > sampleRate) {
    callback();
    frameCount++;
    lastCycle = millis();
  }
}

void Interval::setIsRunning(bool newRunning) {
  isRunning = newRunning;
}

int Interval::getFrameCount() {
  return frameCount;
}