#include "LedLamp.h"

bool LedLamp::zetAan(string kleur) {
    bool aan = false;
    for (int i = 0; i < leds.size(); i++) {
        aan |= leds.at(i)->zetAan(kleur);
    }
    return aan;
}

void LedLamp::zetUit() {
    for (int i = 0; i < leds.size(); i++) {
        leds.at(i)->zetUit();
    }
}

string LedLamp::connectie() const {
    string output = "";
    for (int i = 0; i < leds.size(); i++)
    {
        output += " " + leds[i]->connectie();
    }
    return output;
}

void LedLamp::voegLedToe(Led* led) {
    leds.push_back(led);
}

bool LedLamp::ledStatus() {
    bool status;
    for (int i = 0; i < leds.size(); i++)
    {
        status |= leds.at(i)->ledStatus();
    }
    return status;
}