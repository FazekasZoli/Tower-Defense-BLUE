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

	std::shared_ptr<Critter> createCritter(CritterType critters)
	{
		return _critters[critters]->clone();
	}

	// critterek listája levelenként
	std::vector<std::list<std::shared_ptr<Critter>>> _crittersForGame;

	// feltöltöm az egyes levelekhez tartozó critter listát critterekkel

	void createCrittersForGame()
	{
		
			for (int i = 1; i <= 5; i++)
			{
				_crittersForGame[0].push_back(createCritter(NORMAL));
			}
			for (int i = 1; i <= 10; i++)
			{
				_crittersForGame[1].push_back(createCritter(NORMAL));
			}
			for (int i = 1; i <= 15; i++)
			{
				_crittersForGame[2].push_back(createCritter(NORMAL));
			}
	}

};
