#include "SingleLed.h"

SingleLed::SingleLed(RockPi *pi, int pinNummer, const Weerstand *weerstand, string kleur, string eigenaar, double lichtsterkte): Led(eigenaar, lichtsterkte)
{
  this->pi = pi;
  this->pinNummer = pinNummer;
  this->weerstand = weerstand;
  this->kleur = kleur;
  this->status = 0;
  this->aangesloten = 1;
  pi->koppelAansluiting(pinNummer);
  pi->zetPinMode(pinNummer,1);
}

SingleLed::SingleLed(SingleLed SL): Led(SL){
  this->weerstand = SL.weerstand;
  this->kleur = SL.kleur;
  this->status = SL.status;
  this->aangesloten = SL.aangesloten;
  this->pinNummer = SL.pinNummer;
  this->pi = SL.pi;
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