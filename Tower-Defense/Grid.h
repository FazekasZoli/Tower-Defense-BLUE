#pragma once
#include <list>

#include "Entity.h"

class Grid
{
private:
	std::list<Position> generateRoad(Position start, Position end);

public:
	Grid(int gridSizeX = 10, int gridSizeY = 10)
		: gridSizeX(gridSizeX), gridSizeY(gridSizeY)
	{}

	std::list<Position> const& getRoad() const { return road; };

	void saveGrid();
	void loadGrid();

private:
	int gridSizeX;
	int gridSizeY;

	std::list<Position> road;
};
#pragma once
