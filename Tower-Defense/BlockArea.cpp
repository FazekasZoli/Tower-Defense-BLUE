#include "BlockArea.h"

BlockArea::BlockArea(std::pair<Position, Position> &leftRoadPos, std::pair<Position, Position> &rightRoadPos)
{
	// getting directions
	if (0 < leftRoadPos.second.x || leftRoadPos.second.y < 0) // if right or down
	{
		topLeftCorner.x = leftRoadPos.first.x - TILE;
		topLeftCorner.y = leftRoadPos.first.y + TILE;

		bottomRightCorner.x = rightRoadPos.first.x + TILE;
		bottomRightCorner.y = rightRoadPos.first.y - TILE;
	}
	else if (0 < leftRoadPos.second.y || leftRoadPos.second.x < 0) // if left or top
	{
		topLeftCorner.x = rightRoadPos.first.x - TILE;
		topLeftCorner.y = rightRoadPos.first.y + TILE;

		bottomRightCorner.x = leftRoadPos.first.x + TILE;
		bottomRightCorner.y = leftRoadPos.first.y - TILE;
	}		
}

BlockArea::BlockArea(Position& towerPos)
{
	topLeftCorner.x = towerPos.x - TILE;
	topLeftCorner.y = towerPos.y + TILE;

	bottomRightCorner.x = towerPos.x + TILE;
	bottomRightCorner.y = towerPos.y - TILE;
}

bool BlockArea::contains(Position &p) const
{
	return (topLeftCorner.x < p.x && p.x < bottomRightCorner.x) && (bottomRightCorner.y < p.y && p.y < topLeftCorner.y);
}
