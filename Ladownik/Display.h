#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Ship.h"
class CDisplay
{
public:
	CDisplay();
	~CDisplay();

	void rysuj(CShip* Statek);
	void WyswietlWynik(int i);

private:
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;
	SDL_Window* gWindow = NULL;
	SDL_Renderer* gRenderer = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Texture* PlanetTexture = NULL;
	SDL_Texture* ShipTexture = NULL;
	TTF_Font* gFont = NULL;
	SDL_Color gColor = { 1, 1, 1 };
	SDL_Color gRed = { 1,0,0 };
};

