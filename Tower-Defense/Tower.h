#pragma once
#include <vector>
#include <memory>
#include <chrono>
#include <ctime>
#include <list>

#include "Entity.h"
#include "Critter.h"

enum TowerType { BASE, FREEZING, POISONING };

class Tower : public Entity
{
public:
	Tower(Position& pos)
		: Entity(pos, 25), type(BASE), level(1), attackPower(10), attackRange(100), coolDown(2000), lastAttackTime(std::chrono::system_clock::now())
	{}	

	std::shared_ptr<Tower> clone(); 
	inline double* getAttackRangePtr() { return &attackRange; };
	inline int* getLevelPtr() { return &level; };

	TowerType getType() const { return type; };		
	double getSellCost() const { return cost * 0.6; };
	double getAttackPower() const { return attackPower; };
	double getAttackRange() const { return attackRange; };

	void upgrade();
	int attack(std::list<std::shared_ptr<Critter>>& critters);	

private:
	TowerType type;
	int level;	
	double attackPower;
	double attackRange;
	double coolDown;

	std::chrono::time_point<std::chrono::system_clock> lastAttackTime;	
};

