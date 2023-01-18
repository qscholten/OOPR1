#include <string>
#include "Weerstand.h"
#include "RockPi.h"

using namespace std;
#pragma once

#define OUTPUT 1

class Led
{
  protected:
  string eigenaar;
  public:
    Led(string, double);
    virtual bool zetAan(string);
    virtual void zetUit();
    virtual int connectie();
    virtual int ledStatus();
    void veranderLichtsterkte(double);
    double hoeveelheidLicht();
    string deEigenaar();
  private:
    double lichtsterkte;
};