#ifndef Pin_h
#define Pin_h

class Pin{
  private:
  int state;
  int pin;

  public:
  Pin(int, int);
  int getState();
  void setState(int);
  void toggle();
};

#endif