#include <string>
#include <vector>
#include "Led.h"

using namespace std;
#pragma once

#define OUTPUT 1

class LedLamp
{
  public:
    bool zetAan(string);
    void zetUit();
    string connectie() const;
    void voegLedToe(Led*);
    bool ledStatus();
  private:
    vector <Led*> leds;
};