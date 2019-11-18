#pragma once
#include <utility>

#include "Entity.h"

class BlockArea
{
private:
	Position topLeftCorner;
	Position bottomRightCorner;

public:
	static const int TILE = 25;
	
	BlockArea(std::pair<Position, Position>& leftRoadPos, std::pair<Position, Position>& rightRoadPos);
	BlockArea(Position& towerPos);

	bool contains(Position& p) const;
};

