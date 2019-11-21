#include <iostream>
#include <memory>

#include "Tower.h"

std::shared_ptr<Tower> Tower::clone()
{
	return std::make_shared<Tower>(*this);
}

int Tower::attack(std::list<std::shared_ptr<Critter>>& critters)
{
	int sum = 0;
	auto diff = std::chrono::system_clock::now() - lastAttackTime;
	if (std::chrono::duration <double, std::milli>(diff).count() > coolDown)
	{
		double min = attackRange;
		for (auto& critter : critters)
		{			
			if (critter->distance(this->pos) < min && critter->getIsAlive())
			{
				std::cout << "attack, damage: " << attackPower << "\n";
				min = critter->distance(this->pos);
				sum+=critter->damage(attackPower);
				lastAttackTime = std::chrono::system_clock::now();
				break;
			}
		}		
	}
	return sum;
}

void Tower::upgrade()
{
	
	attackPower *= 1.25;
	if (level<6)
	{
		attackRange += 0.2*attackRange *(6 - level) / 5;
	}
	coolDown *= 0.9;
	cost += 5;
	++level;
}
