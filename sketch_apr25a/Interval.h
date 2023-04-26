#ifndef Interval_h
#define Interval_h
#include <Arduino.h>

class Interval {
private:
  int sampleRate;
  int lastCycle;
  int frameCount;
  bool isRunning;

public:
  Interval(int wantedSampleRate);
  void update();
  void run();
  void setIsRunning(bool newRunning);
  int getFrameCount();
};

#endif