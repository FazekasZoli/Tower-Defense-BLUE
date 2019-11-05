#pragma once
#include <vector>

#include "Entity.h"

class Grid
{
private:
	std::vector<std::pair<Position, Position>> generateRoad(Position start, Position end);

public:
	Grid(int gridSizeX = 10, int gridSizeY = 10)
		: gridSizeX(gridSizeX), gridSizeY(gridSizeY)
	{}

	std::vector<std::pair<Position, Position>> const& getRoad() const { return road; };

	void saveGrid();
	void loadGrid();

private:
	int gridSizeX;
	int gridSizeY;

	// first pair is location, second direction after position
	std::vector<std::pair<Position,Position>> road;
};
