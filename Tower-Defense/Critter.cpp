#pragma once
#include <iostream>
#include <memory>

#include "Critter.h"
#include <Windows.h>

void Critter::move(std::vector<std::pair<Position, Position>> road_)
{
	//std::cout << "asd\n" << road_[0].first.x << " " << road_[0].first.y << "\n";
	for (int i = 0; i < road_.size(); i++)
	{
		
		if (pos == road_[i].first)
		{
			dir = road_[i].second;
			/*if (irany.x == 1 && irany.y == 0)
			{
				std::cout << "Jobbra halad" << std::endl;
			}
			else if (irany.x == 0 && irany.y == 1)
			{
				std::cout << "Lefele halad" << std::endl;
			}
			else if (irany.x == -1 && irany.y == 0)
			{
				std::cout << "Balra halad" << std::endl;
			}
			else if (irany.x == 0 && irany.y == 0)
			{
				std::cout << "Egyhelyben all" << std::endl;
			}*/
		}
		
	}
	pos += dir *= speed;
}

void Critter::test_move()
{
	//move teszt, bárki belebarmolhat
	std::vector<std::pair<Position, Position>> p;

	Position start1(0, 0); //honnan
	Position dir1(1, 0); //irány
	Position end1(50, 0); //hova

	Position dir2(0, 1);
	Position end2(50, 50);

	Position dir3(-1, 0);
	Position end3(0, 50);

	//Critter* monster = new Critter();
	p.emplace_back(start1, dir1);
	p.emplace_back(end1, dir2);
	p.emplace_back(end2, dir3);
	p.emplace_back(end3, start1);
	
	for (int i = 0; i < 50; i++)
	{
		this->move(p);
		std::cout << "x: " << getPos().x << " y: " << getPos().y << std::endl;
	}
}

int Critter::damage(int dmg)
{
	this->life -= dmg;
	if (this->life <= 0)
	{ 
		std::cout << "critter died\n";
		this->isAlive = false;
		return cost;
	}
	return 0;
}

std::shared_ptr<Critter> Critter::clone()
{
	return std::make_shared<Critter>(*this);
}
