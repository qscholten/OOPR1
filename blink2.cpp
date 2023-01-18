#include "Led.h"
#include <iostream>
#include "Weerstand.h"
#include "RockPi.h"
#include "LedLamp.h"
#include "SingleLed.h"
#include "DualLed.h"
#include <unistd.h>


int	main() {
RockPi miniC(20208294); //vul hier je eigen studienummer in.
LedLamp lampje;
const Weerstand r1(330);
const Weerstand r2(330);
const Weerstand r3(330);
const Weerstand r4(330);

string ledKleur1="groen";
string ledKleur2="rood";
string eigenaar= "Qing Scholten";

lampje.voegLedToe(new SingleLed(&miniC,&r1,134, ledKleur1, eigenaar,0.9));
lampje.voegLedToe(new DualLed(&miniC,&r2,&r3,132,135, ledKleur1, ledKleur2,eigenaar,1.2));
lampje.voegLedToe(new SingleLed(&miniC,&r1,112, ledKleur1, eigenaar,0.9));
lampje.zetAan("Rood");
sleep(3);
lampje.zetAan("Groen");
sleep(3);
lampje.zetUit();
sleep(1);
cout<<"connectie(s) van ll:"<< lampje.connectie()<<endl;

return 0;
}