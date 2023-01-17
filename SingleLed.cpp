#include "SingleLed.h"

SingleLed::SingleLed(RockPi *pi, int pinNummer, const Weerstand *weerstand, string kleur, string eigenaar, double lichtsterkte)
{
  this->pi = pi;
  this->pinNummer = pinNummer;
  this->weerstand = weerstand;
  this->kleur = kleur;
  this->eigenaar = eigenaar;
  this->veranderLichtsterkte(lichtsterkte);
  this->status = 0;
  this->aangesloten = 0;
  pi->koppelAansluiting(pinNummer);
  pi->zetPinMode(pinNummer,1);
}

bool SingleLed::zetAan(string kleur) {
  if (this->kleur.compare(kleur) != 0) {
        return false;
  }
  pi->pinWaarde(pinNummer,1);
  this->status = 1;
  return true;
}

void SingleLed::zetUit() {
  pi->pinWaarde(pinNummer,0);
  this->status = 0;
}

int SingleLed::connectie() {
  return this->pinNummer;
}

int SingleLed::ledStatus() {
  return this->status;
}