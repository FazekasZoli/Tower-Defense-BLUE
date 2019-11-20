#include <iostream>
#include <memory>

#include "Tower.h"

std::shared_ptr<Tower> Tower::clone()
{
	return std::make_shared<Tower>(*this);
}

void Tower::attack(std::list<std::shared_ptr<Critter>>& critters)
{
	auto diff = std::chrono::system_clock::now() - lastAttackTime;
	if (std::chrono::duration <double, std::milli>(diff).count() > coolDown)
	{
		double min = attackRange;
		for (auto& critter : critters)
		{			
			if (critter->distance(this->pos) < min && critter->getIsAlive())
			{
				std::cout << "attack\n";
				min = critter->distance(this->pos);
				critter->damage(attackPower);
				lastAttackTime = std::chrono::system_clock::now();
				break;
			}
		}		
	}
}

void Tower::upgrade()
{
	++level;
	attackPower *= 1.25;
	attackRange *= 1.25;
	coolDown *= 0.75;
}
