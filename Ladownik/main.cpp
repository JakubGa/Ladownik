#include <iostream>
#include "Game.h"


int main(int argc, char* args[])
{
	CGame *Ladowanie = new CGame;
	Ladowanie->Loop();
	Ladowanie->Wynik();
	delete(Ladowanie);


	return 0;
}