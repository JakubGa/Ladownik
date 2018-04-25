#pragma once
class CPlanet
{
public:
	CPlanet(float grav);
	~CPlanet();
	float ShowGrav();

private:
	float Gravity;
};

