#include <iostream>
#include <memory>

#include "Tower.h"

Tower::Tower(TowerType _type, Position& position) : Entity(position), type(_type), lastAttackTime(std::chrono::system_clock::now())
{
	switch (_type)
	{
	case BASE:
		buyCost = 50;
		sellCost = buyCost * 0.6;
		attackPower = 11;
		attackRange = 50;
		break;
	case POISONING:
		buyCost = 75;
		sellCost = buyCost * 0.6;
		attackPower = 1;
		attackRange = 50;
		break;
	case FREEZING:
		buyCost = 100;
		sellCost = buyCost * 0.6;
		attackPower = 1;
		attackRange = 50;
		break;
	default:
		break;
	}
}

void Tower::attack(std::list<std::shared_ptr<Critter>>& critters)
{
	auto diff = std::chrono::system_clock::now() - lastAttackTime;
	if (std::chrono::duration <double, std::milli>(diff).count() > 2000)
	{
		double min = attackRange;
		for (auto& critter : critters)
		{
			if (critter->distance(_pos) < min)
			{
				min = critter->distance(_pos);
				critter->damage(attackPower);
			}
		}
		lastAttackTime = std::chrono::system_clock::now();
	}
}



void Tower::upgrade(std::shared_ptr<Tower> tower)
{
	tower->attackPower *= 2;
	tower->sellCost *= 1.2;
	tower->attackRange *= 1.2;
	/*if (tower->type == BASE)
	{
		setType(POISONING);
	}
	else if (tower->type == POISONING)
	{
		setType(FREEZING);
	}*/
}

std::shared_ptr<Tower> Tower::clone()
{
	return std::make_shared<Tower>(*this);
}
