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
    virtual bool zetAan(string) = 0;
    virtual void zetUit() = 0;
    virtual string connectie() const = 0;
    virtual int ledStatus() = 0;
    void veranderLichtsterkte(double);
    double hoeveelheidLicht();
    string deEigenaar();
  private:
    double lichtsterkte;
};