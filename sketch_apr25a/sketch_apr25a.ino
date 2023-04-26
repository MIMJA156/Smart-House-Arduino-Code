#include "Interval.h"

class FireAllarm : public Interval {
  using Interval::Interval;
  void run(){
    
  }
};

FireAllarm fire(1000);

void setup() {
}

void loop() {
  fire.update();
}
