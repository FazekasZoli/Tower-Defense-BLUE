#pragma once
#include <vector>
#include <list>
#include <fstream>
#include <iostream>

#include "Entity.h"
#include "BlockArea.h"

class Grid
{
private:
	std::vector<std::vector<std::pair<Position, Position>>> allRoads;

	std::list<std::shared_ptr<BlockArea>> blockedAreas;

public:
	// store road
	std::vector<std::pair<Position, Position>> & getRoad(int selectedRoad)  { return allRoads[selectedRoad]; };
	int allRoadsSize() { return allRoads.size(); };
	
	// load road
	void saveRoad();
	void loadRoads();
	std::vector<std::pair<Position, Position>> loadRoad(const int actualMap);

	// blocked area related methods
	bool isAreaBlocked(const Position &pos);
	void addBlockedTowerArea(Position &towerPos);
	void createBlockedAreaFromRoad(const int level);
};
