#include <string>
#include "Weerstand.h"
#include "RockPi.h"
#include "ConnectionPlatform.h"

using namespace std;
#pragma once

#define OUTPUT 1

class Arduino: public ConnectionPlatform
{
  public:
    void pinWaarde(int,int) = 0;
    void zetPinMode(int,int) = 0;
    bool koppelAansluiting(int) = 0;
  private:
    string fabrikant;
};