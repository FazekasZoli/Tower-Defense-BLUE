#pragma once
#include <memory>
#include <unordered_map>
#include <list>
#include <iostream>

#include "Critter.h"

enum CritterType
{
	NORMAL
};

class CritterManager
{
private:

	int critAlive;
	int critSummon;
	int critTotal;

	Critter* critter;

	std::unordered_map<CritterType, std::shared_ptr<Critter>> _critters;

public:
	
	CritterManager(Critter* critter)
		: critter(critter)
	{};	

	int getCritAlive() { return critAlive; }
	int getCritSummon() { return critSummon; }
	int getCritTotal() { return critTotal; }

	CritterManager()
	{
		std::shared_ptr<Critter>critter_ptr(new Critter);
		_critters.insert(std::make_pair(NORMAL, critter_ptr));
		
	}

	std::shared_ptr<Entity> createCritter(CritterType critters)
	{
		return _critters[critters]->clone();
	}
};
