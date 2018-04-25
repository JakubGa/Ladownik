#include "Planet.h"



CPlanet::CPlanet(float grav)
{
	Gravity = grav;
}


CPlanet::~CPlanet()
{
}

float CPlanet::ShowGrav()
{
	return Gravity;
}
