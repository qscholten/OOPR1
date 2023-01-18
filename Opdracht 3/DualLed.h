#include <string>
#include "Led.h"

using namespace std;
#pragma once

#define OUTPUT 1

class DualLed: public Led
{
  public:
    DualLed(RockPi *pi, const Weerstand *weerstand1, const Weerstand *weerstand2, int pinNummer1, int pinNummer2, string kleur1, string kleur2, string eigenaar, double lichtsterkte);
    DualLed(DualLed&);
    ~DualLed();
    bool zetAan(string);
    void zetUit();
    string connectie() const;
    int ledStatus();
  private:
    string kleur1;
    string kleur2;
    int status;
    int pinNummer1;
    int pinNummer2;
    int aangesloten;
    RockPi *pi;
    const Weerstand *weerstand1;
    const Weerstand *weerstand2;
};