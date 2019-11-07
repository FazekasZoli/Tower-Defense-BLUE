#pragma once
#include <vector>
#include <memory>

#include "Entity.h"

class Critter : public Entity
{
public:
	//default konstruktor
	Critter(int life = 5, int speed = 10) : life(life), speed(speed), Entity() {};
  
	//konstruktor
	Critter(int newLife, int newSpeed, Position& pos, int cost) : Entity(pos, cost), life(newLife), speed(newSpeed) {};

	//GETTEREK (azért inline mert az osztály leírásában szerepeltetem a tagfüggvények teljes definícióját (rövidek))
	inline int getLife() const { return life; };
	inline int getSpeed() const { return speed; };

	//SETTEREK
	//........
	inline void setLife(int newLife) { life = newLife; };
	inline void setSpeed(int newSpeed) { speed = newSpeed; };

	//move algoritmus(ha tesztelni akarod akkor a teszt fv-el teheted meg)
	void move(std::vector<std::pair<Position, Position>> p);
	void test_move();

	std::shared_ptr<Entity> clone() override
	{
		return std::make_shared<Critter>(*this);
	}

private:
	//élet
	int life;

	//milyen gyorsan tud mozogni
	int speed;
};
