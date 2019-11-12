#pragma once
#include <vector>
#include <fstream>
#include <iostream>

#include "Entity.h"

class Grid
{
private:
	//std::vector<std::pair<Position, Position>> generateRoad(Position start, Position end);

public:
	Grid(int gridSizeX = 10, int gridSizeY = 10)
		: gridSizeX(gridSizeX), gridSizeY(gridSizeY)
	{}
	
	void setRoad(std::vector<std::pair<Position, Position>> road) { _road = road; }
	std::vector<std::pair<Position, Position>>& getRoad() { return _road; };

	void saveGrid(std::vector<std::pair<Position, Position>> road_);
	std::vector<std::pair<Position, Position>> loadGrid();

private:
	int gridSizeX;
	int gridSizeY;

	// first pair is location, second direction after position
	std::vector<std::pair<Position,Position>> _road;
	
	std::vector<std::vector<std::pair<Position, Position>>> _roadsForGame;
};

