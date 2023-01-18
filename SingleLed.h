#include <string>
#include "Led.h"

using namespace std;
#pragma once

#define OUTPUT 1

class SingleLed: public Led
{
  public:
    SingleLed(RockPi,int, Weerstand,string, string,double);
    SingleLed(SingleLed&);
    ~SingleLed();
    bool zetAan(string);
    void zetUit();
    int connectie();
    int ledStatus();
  private:
    string kleur;
    int status;
    int pinNummer;
    int aangesloten;
    Rockpi *pi;
    Weerstand *weerstand;
    Led *led;
};