#include <string>
#include "Led.h"

using namespace std;
#pragma once

#define OUTPUT 1

class SingleLed: public Led
{
  public:
    SingleLed(RockPi *pi, int pinNummer, const Weerstand *weerstand, string kleur, string eigenaar, double lichtsterkte);
    bool zetAan(string);
    void zetUit();
    int connectie();
    int ledStatus();
  private:
    string kleur;
    int status;
    int pinNummer;
    int aangesloten;
    RockPi *pi;
    const Weerstand *weerstand;
};