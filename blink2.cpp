#include <iostream>
#include <unistd.h>

using namespace std;

#include "Led.h"
#include "SingleLed.h"
#include "RockPi.h"
#include "gpiofuncties.h"

#define TIMELEDON 1000000
#define TIMELEDOFF 500000

int main (void)
{
  cout<<"hoi opgave2"<<endl;
 	
//RockPi miniC(123456); //vul hier je eigen studienummer in.
//RaspberryPi miniC(123456); //vul hier je eigen studienummer in.
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
return 0 ;
}
