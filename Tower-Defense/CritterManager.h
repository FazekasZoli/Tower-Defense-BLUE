#pragma once
#include <memory>
#include <unordered_map>
#include <list>
#include <iostream>

#include "Critter.h"
#include "Observable.h"

enum CritterType { NORMAL };

class CritterManager : public Observable
{
private:	
	std::shared_ptr<Critter> createCritter(CritterType critterType); // majd private legyen
	void createCrittersForGame();
	
public:	
	CritterManager();	

	void moveActualRoundCritters(int actualRound, const std::vector<std::pair<Position, Position>>& road);

private:
	// critter sablonok
	std::unordered_map<CritterType, std::shared_ptr<Critter>> _critterTemplates;
		
	std::vector<std::list<std::shared_ptr<Critter>>> _crittersForGame;	

};
