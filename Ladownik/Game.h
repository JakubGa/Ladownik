#pragma once
#include <time.h>
#include "Display.h"
#include "Ship.h"
#include "Planet.h"
class CGame
{
public:
	CGame();
	~CGame();
	void Loop();
	void Wynik();

private:
	CDisplay *Okno;
	CShip *Voyager;
	CPlanet *Mars;
	SDL_Event e;
	void UpdateState(time_t *czas);
};

