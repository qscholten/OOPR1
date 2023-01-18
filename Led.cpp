#include "Led.h"

void Led::veranderLichtsterkte(double lichtsterkte) {
    this->lichtsterkte = lichtsterkte;
}

double Led::hoeveelheidLicht() {
    return this->lichtsterkte;
}

string Led::deEigenaar() {
    return this->eigenaar;
}

Led::Led(string eigenaar, int lichtsterkte) {
    this->lichtsterkte = lichtsterkte;
    this->eigenaar = eigenaar;
}

bool Led::zetAan(string) {
    return true;
}

void Led::zetUit() {
}

int Led::connectie() {
    return 0;
}

int Led::ledStatus(){
    return 0;
}