#ifndef Interval_h
#define Interval_h
#include <Arduino.h>

class Interval {
private:
  int sampleRate;
  int lastCycle;
  int frameCount;
  bool isRunning;
  void(*callback)();

public:
  Interval(int wantedSampleRate, void(*callback)());
  void update();
  void setIsRunning(bool newRunning);
  int getFrameCount();
};

#endif