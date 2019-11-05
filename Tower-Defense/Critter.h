#pragma once
#include "Entity.h"

class Critter : public Entity
{

public:

	//default konstruktor
	Critter() : Entity() {};

	//konstruktor

	Critter(int newLife, int newSpeed, Position& pos, int cost) : Entity(pos, cost), life(newLife), speed(newSpeed) {};

	//GETTEREK (az�rt inline mert az oszt�ly le�r�s�ban szerepeltetem a tagf�ggv�nyek teljes defin�ci�j�t (r�videk))
	inline int getLife() const { return life; };
	inline int getSpeed() const { return speed; };

	//SETTEREK
	//........
	inline void setLife(int newLife) { life = newLife; };
	inline void setSpeed(int newSpeed) { speed = newSpeed; };

private:

	//�let
	int life;

	//milyen gyorsan tud mozogni
	int speed;


};
