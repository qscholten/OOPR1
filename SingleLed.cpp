#include "SingleLed.h"

SingleLed::SingleLed(RockPi *pi, int pinNummer, Weerstand *weerstand, string kleur, string eigenaar, double lichtsterkte)
{
  this->pi = pi;
  this->pinNummer = pinNummer;
  this->weerstand = weerstand;
  this->kleur = kleur;
  this->eigenaar = eigenaar;
  this->lichtsterkte = lichtsterkte;
  this->status = 0;
  this->aangesloten = 0;
}
