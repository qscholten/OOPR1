#ifndef LOGLED_H
#define LOGLED_H

#include "Tijdsduur.h"
#include "Stopwatch.h"
#include "RockPi.h"
#include <string>

using namespace std;
#pragma once

class Logled
{
public:
    Logled(RockPi *, int, string, string, int);
    Logled(RockPi *, int, int);
    ~Logled();
    void zetAan();
    void zetUit();
    bool ledStatus();
    unsigned int TijdOver();
    string deEigenaar();
private:
    bool status;
    int pinNr;
    string eigenaar;
    Tijdsduur branduren;
    Stopwatch tijdmeting;
    RockPi *Pi;
};
#endif