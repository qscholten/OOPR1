#include <iostream>
#include <unistd.h>

using namespace std;

#include "Led.h"
#include "SingleLed.h"
#include "RockPi.h"
#include "gpiofuncties.h"
#include "Weerstand.h"
#include "DualLed.h"

#define TIMELEDON 1000000
#define TIMELEDOFF 500000

void printConnecties(const Led& l) {
   cout<<"Led verbonden op  de volgende poort(en): "<<l.connectie()<<endl;
}

int main (void)
{
  cout<<"hoi opgave2"<<endl;
 	
//RockPi miniC(123456); //vul hier je eigen studienummer in.
//RaspberryPi miniC(123456); //vul hier je eigen studienummer in.
/*/
RockPi miniC(20208294); //vul hier je eigen studienummer in.
const Weerstand r1(330);
string ledKleur="groen";
string eigenaar= "Qing Scholten";
SingleLed sl1(&miniC,134,&r1,ledKleur, eigenaar,0.9); //bij raspberry pi nr 18
SingleLed ledje2(sl1);
string testKleur="groen";
sl1.zetAan(testKleur);
sleep(1);
ledje2.zetUit();
//pinMode(134,1);
//digitalWrite (134,1);
return 0 ;*/

/*
RockPi miniC(20208294); //vul hier je eigen studienummer in.
const Weerstand r1(330);
const Weerstand r2(330);
const Weerstand r3(330);
string ledKleur1="groen";
string ledKleur2="rood";
string eigenaar= "Qing Scholten";
SingleLed* sl1=new SingleLed(&miniC,&r1,134, ledKleur1, eigenaar,0.9);//nr 18
DualLed* dl1=new DualLed(&miniC,&r2,&r3,132,135, ledKleur1, ledKleur2,eigenaar,1.2);// 23,24

Led* l1=sl1;
Led* l2=dl1;

l1->zetAan("groen");
sleep(1);
l2->zetAan("groen");
sleep(1);
l2->zetAan("rood");
sleep(1);

Led* uit=sl1;
uit->zetUit();
sleep(1);
uit=dl1;
uit -> zetUit();

delete sl1;
delete dl1;
return 0;*/
cout << "!!!Hello World van de tijd!!!" << endl;
RockPi miniC(123456); //vul hier je eigen studienummer in.
const Weerstand r1(330);
const Weerstand r2(330);
const Weerstand r3(330);
string ledKleur1="Groen";
string ledKleur2="Rood";
string eigenaar= "Pietje Puk";
SingleLed sl1(&miniC,&r1,134, ledKleur1, eigenaar,0.9);//nr 18
DualLed dl1(&miniC,&r2,&r3,132,135, ledKleur1, ledKleur2,eigenaar,1.2);
printConnecties(sl1);
printConnecties(dl1);
for(int i=0;i<5;++i) {
sl1.zetAan("Groen");
sleep(1);
sl1.zetUit();
sleep(2);
}
dl1.zetAan("Groen");
sleep(2);
dl1.zetAan("Rood");
sleep(2);
dl1.zetUit();

return 0;
}
