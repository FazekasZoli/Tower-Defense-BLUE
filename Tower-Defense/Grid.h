#pragma once
#include <vector>
#include <fstream>
#pragma once
#include <iostream>
#include "Entity.h"

class Grid
{
public:
	Grid() {}

	std::vector<std::pair<Position, Position>> & getRoad(int selectedRoad)  { return allRoads[selectedRoad]; };
	int allRoadsSize() { return allRoads.size(); };
	void saveGrid();
	std::vector<std::pair<Position, Position>> loadRoad(int ActualMap);
	
	void loadRoads() 
	{
		for (size_t i = 1; i <= 2; i++)
		{
			allRoads.push_back(loadRoad(i));
		}
	}

private:
	std::vector<std::vector<std::pair<Position, Position>>> allRoads;

};

