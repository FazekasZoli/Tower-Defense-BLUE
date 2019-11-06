#pragma once

#include "Critter.h"
#include <memory>
#include <unordered_map>
#include <list>
#include <iostream>

class CritterManager
{
private:

	int critAlive;
	int critSummon;
	int critTotal;

	Critter* critter;

	std::unordered_map<CritterType, std::shared_ptr<Critter>> _critters;

public:

	CritterManager(){}
	CritterManager(Critter* critter)
		: critter(critter)
	{};

	virtual ~CritterManager();

	int getCritAlive() { return critAlive; }
	int getCritSummon() { return critSummon; }
	int getCritTotal() { return critTotal; }

	CritterManager()
	{

		std::shared_ptr<Critter>critter_ptr(new Critter);
		_critters.insert = critter_ptr;
	}

	std::shared_ptr<Entity> createCritter(CritterType critters)
	{
		return _critters[critters]->clone();
	}


};

enum CritterType
{
	NORMAL
};
