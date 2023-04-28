#include "Pin.h"

void Pin::Pin(int givenPin, int beginningState){
  pin = givenPin;
  state = beginningState;

}

void Pin::setState(int givenState){
  state = givenState;
}

int Pin::getState(){
  return state;
}

void Pin::toggle(){
  if(state == 0){
    state = 1;
  }else{
    state = 0;
  }

  digitalWrite(pin, state);
}