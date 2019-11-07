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

	// feltöltöm az egyes pályákhoz tartozó critter listát
	void createCrittersForGame()
	{
		// pálya 0 critterei
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

public:	

	CritterManager()
	{
		// add normal critter sablon
		std::shared_ptr<Critter>critter_ptr(new Critter);
		_critterTemplates.insert(std::make_pair(NORMAL, critter_ptr));		

		createCrittersForGame();
	}

	std::shared_ptr<Critter> createCritter(CritterType critters)
	{
		return _critterTemplates[critters]->clone();
	}

	void removeCritter(std::shared_ptr<Critter> critter)
	{

	}

	std::list<std::shared_ptr<Critter>> getCrittersForLevel(int level) const
	{
		if (level < _crittersForGame.size())
		{
			return _crittersForGame[level];
		}
		throw "error: level not exist";
	}

private:
	// critter sablonok
	std::unordered_map<CritterType, std::shared_ptr<Critter>> _critterTemplates;

	// critterek listája pályánként
	std::vector<std::list<std::shared_ptr<Critter>>> _crittersForGame;	
};
