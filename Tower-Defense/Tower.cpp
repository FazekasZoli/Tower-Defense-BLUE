#include "Tower.h"
#include <iostream>
#include <memory>


Tower::Tower(TowerType _type, Position& position) : Entity(position), type(_type)
{
	switch (_type)
	{
	case BASE:
		buyCost = 50;
		sellCost = buyCost * 0.6;
		attackPower = 1;
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
