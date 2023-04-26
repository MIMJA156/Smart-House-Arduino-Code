#include "esp32-hal.h"
#include "Interval.h"

Interval::Interval(int wantedSampleRate) {
  sampleRate = wantedSampleRate;
  lastCycle = millis();
  isRunning = true;
}

void Interval::run(){
  throw std::invalid_argument("Please Overide this functions");
}

void Interval::update() {
  if(millis() - lastCycle > sampleRate){
    run();
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