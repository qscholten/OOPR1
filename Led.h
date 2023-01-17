#include <string>
#include "Weerstand.h"
#incldue "RockPi.h"

using namespace std;
#pragma once

#define OUTPUT 1

class Led
{
  public:
    Led(int);
    ~Led();
    virtual bool zetAan(string);
    virtual void zetUit();
    virtual int connectie();
    virtual int ledStatus();
    void veranderLichtsterkte(double);
    double hoeveelheidLicht();
    string deEigenaar();
  private:
    string eigenaar;
    double lichtsterkte;
};