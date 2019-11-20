#pragma once
#include <utility>

#include "Entity.h"

class BlockArea
{
private:
	Position idPos;

	Position topLeftCorner;
	Position bottomRightCorner;

public:
	static const int TILE = 25;
	
	BlockArea(std::pair<Position, Position>& leftRoadPos, std::pair<Position, Position>& rightRoadPos);
	BlockArea(Position& towerPos);
	
	Position& getIdPos();

	bool contains(Position& p) const;
};

