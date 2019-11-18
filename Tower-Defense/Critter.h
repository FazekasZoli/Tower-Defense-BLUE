#pragma once
#include <vector>
#include <memory>

#include "Entity.h"

class Critter : public Entity
{
public:
	//default konstruktor
	Critter(int life = 10, int speed = 10, bool isAlive = true) : Entity(), life(life), speed(speed), isAlive(isAlive) {};
  
	//konstruktor
	Critter(int newLife, int newSpeed, Position& pos, int cost, bool isAlive = true) : Entity(pos, cost), life(newLife), speed(newSpeed) , isAlive(isAlive) {};

	//GETTEREK (azért inline mert az osztály leírásában szerepeltetem a tagfüggvények teljes definícióját (rövidek))
	inline int getLife() const { return life; };
	inline int getSpeed() const { return speed; };
	inline bool getIsAlive() const { return isAlive; };

	//SETTEREK
	//........
	inline void setLife(int newLife) { life = newLife; };
	inline void setSpeed(int newSpeed) { speed = newSpeed; };
	inline void setIsAlive(bool newState) { isAlive = newState; };

	//move algoritmus(ha tesztelni akarod akkor a teszt fv-el teheted meg)
	void move(std::vector<std::pair<Position, Position>> road_);
	void test_move();

	void damage(int dmg);

	std::shared_ptr<Critter> clone(); //override

private:
	//élet
	int life;

	//milyen gyorsan tud mozogni
	int speed;
	
	//a critter statusza
	bool isAlive;
};
