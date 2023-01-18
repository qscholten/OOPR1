#include <iostream>
#include <iomanip>
#include "Tijdsduur.h"

using namespace std;

Tijdsduur::Tijdsduur(int y) : min(0), sec(y)
{
    normaliseer();
}

Tijdsduur::Tijdsduur(int x, int y) : min(x), sec(y)
{
    normaliseer();
}

void Tijdsduur::eraf(const Tijdsduur &t)
{
    int temp = sec + 60 * min;
    int temp_t = t.sec + 60 * t.min;
    int totaal = temp - temp_t;
    sec = totaal % 60;
    min = totaal / 60;

    normaliseer();
}

void Tijdsduur::erbij(const Tijdsduur &t)
{
    int temp = sec + 60 * min;
    int temp_t = t.sec + 60 * t.min;
    int totaal = temp + temp_t;
    sec = totaal % 60;
    min = totaal / 60;

    normaliseer();
}

void Tijdsduur::maal(int a)
{
    int temp = sec + 60 * min;
    int totaal = temp * a;
    sec = totaal % 60;
    min = totaal / 60;

    normaliseer();
}

void Tijdsduur::print() const
{
    if (min > 0)
        cout << min << " minuten en \t" << sec << " seconden";
    else
        cout << "\t\t\t" << sec << " seconden";
}

int Tijdsduur::deTimerTijd() const
{
    int temp = sec + (min * 60);
    return temp;
}

void Tijdsduur::normaliseer()
{
    int temp = (min * 60) + sec;

    if (temp < 0)
    {
        min = 0;
        sec = 0;
    }
}

Tijdsduur::~Tijdsduur()
{
}

int Tijdsduur::getSeconds() const
{
    return sec;
}

int Tijdsduur::getMinutes() const
{
    return min;
}