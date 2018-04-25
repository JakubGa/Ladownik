#include "Ship.h"



CShip::CShip()
{
	ciag = 0;
	wysokosc = 100;
	predkosc = 8;
	paliwo = 15000;
}


CShip::~CShip()
{
}

void CShip::UpdatePower(int wartosc)
{
	if (wartosc == 1 && ciag < 5)
	{
		ciag++;
	}
	else if (wartosc == -1 && ciag > 0)
	{
		ciag--;
	}
}

float CShip::ShowHeight()
{
	return wysokosc;
}

int CShip::ShowPower()
{
	return ciag;
}

void CShip::UpdateSpeed(float delta)
{
	predkosc += delta/10;
}
void CShip::UpdateHeight(int time, float Grav)
{
	wysokosc -= time*predkosc/10;
	wysokosc -= (Grav - ciag)*time*time/20;
	paliwo -= (float)ciag/10;
}

float CShip::ShowSpeed()
{
	return predkosc;
}

float CShip::ShowFuel()
{
	return paliwo;
}