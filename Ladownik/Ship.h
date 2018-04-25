#pragma once
class CShip
{
public:
	CShip();
	~CShip();
	void UpdatePower(int wartosc);
	float ShowHeight();
	int ShowPower();
	void UpdateSpeed(float delta);
	void UpdateHeight(int time, float grav);
	float ShowSpeed();
	float ShowFuel();


private:
	float wysokosc, paliwo, predkosc;
	int ciag;
};

