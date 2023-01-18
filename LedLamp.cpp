#include "LedLamp.h"

bool LedLamp::turnOn(string kleur) {
    bool aan = false;
    for (int i = 0; i < leds.size(); i++) {
        aan |= leds[i]->zetAan(kleur);
    }
    return aan;
}

void LedLamp::turnOff() {
    for (int i = 0; i < leds.size(); i++) {
        leds[i]->zetUit();
    }
}

string LedLamp::connection() const {
    string output = "";
    for (int i = 0; i < leds.size(); i++)
    {
        output += " " + leds[i]->connectie();
    }
    return output;
}

void LedLamp::addLed(Led* led) {
    leds.push_back(led);
}

bool LedLamp::ledStatus() {
    bool status;
    for (int i = 0; i < leds.size(); i++)
    {
        status |= leds[i]->ledStatus();
    }
    return status;
}