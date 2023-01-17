#include "Led.h"
#include "gpiofuncties.h"


Led::~Led()
{
}

void Led::veranderLichtsterkte(double lichtsterkte)
{
    this->lichtsterkte = lichtsterkte;
}

string Led::deEigenaar()
{
    return eigenaar;
}