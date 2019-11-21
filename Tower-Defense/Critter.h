#pragma once
#include <vector>
#include <memory>

#include "Entity.h"

class Critter : public Entity
{
public:	
	Critter() : Entity(10), life(10), speed(10), isAlive(true), isFinished(false) { maxLife = life; };
	
	std::shared_ptr<Critter> clone();

	int getLife() const { return life; };
	int getMaxLife() const { return maxLife; };
	int getSpeed() const { return speed; };
	bool getIsAlive() const { return isAlive; };
	//int getIsFinished() const;

	void setLife(int newLife) { life = newLife; };
	void setMaxLife(int newLife) { maxLife = newLife; };
	void setSpeed(int newSpeed) { speed = newSpeed; };
	void setIsAlive(bool newState) { isAlive = newState; };

	void move(std::vector<std::pair<Position, Position>> road_);
	void test_move();

	int damage(int dmg);

private:
	int life;
	int maxLife;
	int speed;
	bool isAlive;
	bool isFinished;
};
