#pragma once
#include <memory>
#include <unordered_map>
#include <list>
#include <iostream>
#include <chrono>
#include <algorithm>

#include "Critter.h"
#include "inc\Observable.h"

enum CritterType { NORMAL };

class CritterManager : public CritterEvents
{
private:	
	std::shared_ptr<Critter> createCritter(CritterType critterType); // majd private legyen
	void createCrittersForGame();
	
public:	
	CritterManager();	

	std::list<std::shared_ptr<Critter>>& getCrittersForRound(int actualRound);

	void moveActualRoundCritters(int actualRound, const std::vector<std::pair<Position, Position>>& road);

private:
	std::chrono::high_resolution_clock::time_point _startTime;
	bool _startTimeIsValid = false;

	// critter sablonok
	std::unordered_map<CritterType, std::shared_ptr<Critter>> _critterTemplates;
		
	std::vector<std::list<std::shared_ptr<Critter>>> _crittersForGame;	

};
