#pragma once
#include "Entity.h"

class Critter : public Entity
{

public:

	//default konstruktor
	Critter() : Entity() {};

	//konstruktor

	Critter(int newLife, int newSpeed, Position& pos, int cost) : Entity(pos, cost), life(newLife), speed(newSpeed) {};

	//GETTEREK (azért inline mert az osztály leírásában szerepeltetem a tagfüggvények teljes definícióját (rövidek))
	inline int getLife() const { return life; };
	inline int getSpeed() const { return speed; };

	//SETTEREK
	//........
	inline void setLife(int newLife) { life = newLife; };
	inline void setSpeed(int newSpeed) { speed = newSpeed; };

private:

	//élet
	int life;

	//milyen gyorsan tud mozogni
	int speed;


};
