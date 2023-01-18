#include <string>
#include <vector>
#include "Led.h"

using namespace std;
#pragma once

#define OUTPUT 1

class LedLamp
{
  public:
    bool turnOn(string);
    void turnOff();
    string connection() const;
    void addLed(Led*);
    bool ledStatus();
  private:
    vector <Led*> leds;
};