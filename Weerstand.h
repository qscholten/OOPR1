#include "RockPi.h"

#include <string>

using namespace std;
#pragma once

#define OUTPUT 1

class Weerstand
{
  public:
    Weerstand(int);
    ~Weerstand();
    int weerstandsWaarde();
  private:
    int waarde;
};