#pragma once

#include "Critter.h"
#include <memory>
#include <unordered_map>
#include <list>
#include <iostream>

class CritterManager : public Critter
{
private:

	int startX;
	int startY;
	int critAlive;
	int critSummon;
	int critTotal;

	Critter* critter;

public:

	CritterManager(){}
	CritterManager(Critter* critter, int startX, int startY)
		: critter(critter), startX(startX), startY(startY)
	{};

	virtual ~CritterManager();

	int getCritAlive() { return critAlive; }
	int getCritSummon() { return critSummon; }
	int getCritTotal() { return critTotal; }

	//std::unique_ptr<Critter> clone() override
	//{
	//	return std::make_unique<Critter>(*this);
	//}

};

enum CritterType
{
	NORMAL
};

class CritterFactory
{
private:

	std::unordered_map<CritterType, std::unique_ptr<Critter>> _critters;

public:

	CritterFactory()
	{
	
		std::unique_ptr<Critter>critter_ptr(new Critter);
		_critters.insert = critter_ptr;
	}

	std::unique_ptr<Entity> createCritter(CritterType critters)
	{
		return _critters[critters]->clone();
	}
	

};
