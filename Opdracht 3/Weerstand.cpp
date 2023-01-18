#include "Weerstand.h"

Weerstand::Weerstand(int waarde)
{
    this->waarde = waarde;
}

Weerstand::~Weerstand()
{
}

int Weerstand::weerstandsWaarde()
{
    return waarde;
}