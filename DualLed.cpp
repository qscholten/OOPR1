#include "DualLed.h"

DualLed::DualLed(RockPi *pi, const Weerstand *weerstand1, const Weerstand *weerstand2, int pinNummer1, int pinNummer2, string kleur1, string kleur2, string eigenaar, double lichtsterkte): Led(eigenaar, lichtsterkte)
{
  this->pi = pi;
  this->pinNummer1 = pinNummer1;
  this->pinNummer2 = pinNummer2;
  this->weerstand1 = weerstand1;
  this->weerstand2 = weerstand2;
  this->kleur1 = kleur1;
  this->kleur2 = kleur2;
  this->status = 0;
  this->aangesloten = 2;
  pi->koppelAansluiting(pinNummer1);
  pi->zetPinMode(pinNummer1,1);
  pi->koppelAansluiting(pinNummer2);
  pi->zetPinMode(pinNummer2,1);
}

DualLed::DualLed(DualLed &DL): Led(DL){
  const Weerstand r1(*DL.weerstand1);
  this->weerstand1 = &r1;
  const Weerstand r2(*DL.weerstand2);
  this->weerstand2 = &r2;
  this->kleur1 = DL.kleur1;
  this->kleur2 = DL.kleur2;
  this->status = DL.status;
  this->aangesloten = DL.aangesloten;
  this->pinNummer1 = DL.pinNummer1;
  this->pinNummer2 = DL.pinNummer2;
  this->pi = DL.pi;
}

DualLed::~DualLed() {
    
}

bool DualLed::zetAan(string kleur) {
  if (this->kleur1.compare(kleur) == 0) {
        pi->pinWaarde(pinNummer1,1);
        this->status = 1;
        return true;
  }
  else if (this->kleur2.compare(kleur) == 0) {
        pi->pinWaarde(pinNummer2,1);
        this->status = 1;
        return true;
  }
  return false;
}

void DualLed::zetUit() {
  pi->pinWaarde(pinNummer1,0);
  pi->pinWaarde(pinNummer2,0);
  this->status = 0;
}

string DualLed::connectie() const
{
    string a = to_string(this->pinNummer1);
    string b = to_string(this->pinNummer2);
    return a + " " + b;
}

int DualLed::ledStatus() {
  return this->status;
}