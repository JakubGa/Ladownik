#include "Game.h"


CGame::CGame()
{
	Okno = new CDisplay;
	Voyager = new CShip;
	Mars = new CPlanet(3.71);
}


CGame::~CGame()
{
	delete(Okno);
	delete(Voyager);
	delete(Mars);
}

void CGame::Loop()
{
	bool quit = false;
	time_t StartTime = time(NULL);
	while (!quit && Voyager->ShowHeight() > 0 && Voyager->ShowFuel()>0)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			//User presses a key
			else if (e.type == SDL_KEYDOWN)
			{
				//Select surfaces based on key press
				switch (e.key.keysym.sym)
				{
				case SDLK_UP:
					Voyager->UpdatePower(1);
					break;

				case SDLK_DOWN:
					Voyager->UpdatePower(-1);
					break;

				default:
					Voyager->UpdatePower(0);
					break;
				}
			}
		}
		UpdateState(&StartTime);
		Okno->rysuj(Voyager);
	}
}

void CGame::UpdateState(time_t *czas)
{
	time_t CurrTime = time(NULL);
	Voyager->UpdateHeight((int)(CurrTime - *czas), Mars->ShowGrav());
	Voyager->UpdateSpeed((float)(CurrTime - *czas)*(Mars->ShowGrav()-Voyager->ShowPower()));
	*czas = CurrTime;
}

void CGame::Wynik()
{
	if (Voyager->ShowHeight() < 0 && Voyager->ShowFuel() > 0 && Voyager->ShowSpeed() < 15.1)
	{
		Okno->WyswietlWynik(1);
	}
	else if (Voyager->ShowFuel() < 0)
	{
		Okno->WyswietlWynik(2);
	}
	else if (Voyager->ShowSpeed() > 15)
	{
		Okno->WyswietlWynik(3);
	}
	while (SDL_PollEvent(&e) == 0)
	{
	}
}
