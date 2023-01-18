#include "Logled.h"
#include <iostream>
#include <unistd.h>
#include "RockPi.h"

using namespace std;

Logled::Logled(RockPi *pi, int pin, string kleur, string naam, int duratie) : status(false), eigenaar(naam), Pi(pi), branduren(duratie), pinNr(pin)
{
    pi->koppelAansluiting(pin);
    pi->zetPinMode(pin,1);
}

Logled::Logled(RockPi *pi, int pin, int duratie) : status(false), eigenaar("Anoniem"), Pi(pi), branduren(duratie), pinNr(pin)
{
    pi->koppelAansluiting(pin);
    pi->zetPinMode(pin,1);
}

Logled::~Logled()
{
}

void Logled::zetAan()
{
    tijdmeting.reset();
    if (TijdOver() > 0)
    {

        tijdmeting.begin();
        status = true;
        Pi->pinWaarde(pinNr, status);
    }
}

void Logled::zetUit()
{
    tijdmeting.stop();
    branduren.eraf(tijdmeting.deTijd());
    status = false;
    Pi->pinWaarde(pinNr, status);
}

bool Logled::ledStatus()
{
    return status;
}

unsigned int Logled::TijdOver()
{
    return branduren.deTimerTijd();
}

string Logled::deEigenaar()
{
    return eigenaar;
}

bool Logled::getstatus()
{
    return status;
}