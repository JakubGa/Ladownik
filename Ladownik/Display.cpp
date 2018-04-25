#include "Display.h"
#include <stdio.h>
#include <string>
#include <cstring>
#include <sstream>




CDisplay::CDisplay()
{

		//Create window
		//Initialize SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			TTF_Init();
			//Create window
			gWindow = SDL_CreateWindow("L¹downik", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			}
			else
			{
				//Get window surface
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			gFont = TTF_OpenFont("arial.ttf", 18);
		}


			SDL_Surface* gPlanetSurface = NULL;
			SDL_Surface* gShip = NULL;
			//Load splash image
			try
			{
				gPlanetSurface = SDL_LoadBMP("mars-surface.bmp");
				gShip = SDL_LoadBMP("mars_express.bmp");
				if (gPlanetSurface == NULL || gShip == NULL) throw 1;
			}
			catch(int err)
			{
				printf("Unable to load image %s! SDL Error: %s\n", "mars-surface.bmp", SDL_GetError());
			}

			PlanetTexture = SDL_CreateTextureFromSurface(gRenderer, gPlanetSurface);
			ShipTexture = SDL_CreateTextureFromSurface(gRenderer, gShip);
			SDL_FreeSurface(gPlanetSurface);
			SDL_FreeSurface(gShip);
			gPlanetSurface = NULL;
			gShip = NULL;


}


CDisplay::~CDisplay()
{
	//Deallocate surface
	SDL_FreeSurface(gScreenSurface);
	gScreenSurface = NULL;
	SDL_DestroyTexture(PlanetTexture);
	PlanetTexture = NULL;
	SDL_DestroyTexture(ShipTexture);
	ShipTexture = NULL;
	SDL_DestroyRenderer(gRenderer);
	gRenderer = NULL;
	TTF_CloseFont(gFont);
	gFont = NULL;

	//Destroy window
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	SDL_Quit();
}

void CDisplay::rysuj(CShip* Statek)
{
	std::stringstream lancuch;
	lancuch.precision(5);
	lancuch << "Prêdkosc: " << Statek->ShowSpeed() <<std::endl<<"Paliwo: "<< Statek->ShowFuel()<<std::endl <<"Wysokosc: " << Statek->ShowHeight()<<std::endl<<"Ciag: "<<Statek->ShowPower();
	std::string tekst = lancuch.str();
	SDL_Surface* TextSurface = TTF_RenderText_Blended(gFont, tekst.c_str(), gColor);
	SDL_Texture* textTexture;
	textTexture = SDL_CreateTextureFromSurface(gRenderer, TextSurface);
	SDL_Rect renderQuad = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	SDL_RenderCopy(gRenderer, PlanetTexture, NULL, &renderQuad);
	SDL_Rect renderShip = { 480, 600-(Statek->ShowHeight() * 6), 91, 72 };
	SDL_RenderCopy(gRenderer, ShipTexture, NULL, &renderShip);
	SDL_Rect renderText = { 0,0, TextSurface->w, TextSurface->h };
	SDL_RenderCopy(gRenderer, textTexture, NULL, &renderText);
	SDL_FreeSurface(TextSurface);
	TextSurface = NULL;
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
	SDL_RenderPresent(gRenderer);
}

void CDisplay::WyswietlWynik(int i)
{
	std::string wynik;
	switch (i)
	{
	case 1:
		wynik = "Gratulacje! Wyladowales";
		break;
	case 2:
		wynik = "Brak paliwa...";
		break;
	case 3:
		wynik = "Za szybko, rozbiles sie...";
		break;
	default:
		wynik = "Game Over";
		break;
	}
	gFont = TTF_OpenFont("arial.ttf", 32);
	SDL_Surface* TextSurface = TTF_RenderText_Solid(gFont, wynik.c_str(), gColor);
	SDL_Texture* textTexture;
	textTexture = SDL_CreateTextureFromSurface(gRenderer, TextSurface);
	SDL_Rect renderText = { 100,100, TextSurface->w, TextSurface->h };
	SDL_RenderCopy(gRenderer, textTexture, NULL, &renderText);
	TextSurface = NULL;
	SDL_DestroyTexture(textTexture);
	textTexture = NULL;
	SDL_RenderPresent(gRenderer);
}