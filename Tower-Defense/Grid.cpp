#pragma once
#include <functional>
#include <string>

#include "Grid.h"

void Grid::saveRoad()
{
	std::vector<std::pair<Position, Position>> road;
		   
	std::ofstream outputFile;

	outputFile.open("TowerDefLoad.txt");
	if (!outputFile.is_open()) //hiba kezelés
	{
		std::cout << "Error";
		return;
	}

	for (int i = 0; i < road.size(); i++) // vegigmegyek a roadon és beleiratom a koordinatakat
	{
		outputFile << road[i].first.x << " " << road[i].first.y << " ";
		outputFile << road[i].second.x << " " << road[i].second.y << " ";
	}
	outputFile.close();

}

std::vector<std::pair<Position, Position>> Grid::loadRoad(const int actualMap)
{
	int level = actualMap;

	std::string levelMap = std::to_string(level);

	std::ifstream reader;
	std::string palyaNeve;
	palyaNeve += "TowerdefLoad" + levelMap + ".txt";

	Position pos1;
	Position pos2;
	std::vector<std::pair<Position, Position>> load;

	reader.open(palyaNeve);
	if (!reader.is_open()) // hibakezeles
	{
		std::cout << "Error open ";
	}

	while (reader >> pos1.x && reader >> pos1.y && reader >> pos2.x && reader >> pos2.y) // addig megyek amig a vegere nem erek és a fájlban lévő x és y parokat betöltöm a load vectorba
	{
		load.emplace_back(std::make_pair(pos1, pos2));
	}
	reader.close();

	return load;
}

void Grid::loadRoads()
{
	for (size_t i = 1; i <= 2; i++)
	{
		allRoads.push_back(loadRoad(i));
	}
}

void Grid::createBlockedAreaFromRoad(const int level)
{
	blockedAreas.clear();

	for (size_t i = 0; i < allRoads[level].size() - 1; i++)
	{
		blockedAreas.emplace_back(std::make_shared<BlockArea>(allRoads[level][i], allRoads[level][i + 1]));
	}
}

void Grid::addBlockedTowerArea(Position& towerPos)
{
	blockedAreas.emplace_back(std::make_shared<BlockArea>(towerPos));
}

void Grid::removeBlockedTowerArea(Position& towerPos)
{
	blockedAreas.remove_if([towerPos](BlockArea& area) { return area.getIdPos() == towerPos; });
}

bool Grid::isAreaBlocked(const Position &pos)
{
	// create corners from center position
	Position topLeft(pos.x - BlockArea::TILE, pos.y + BlockArea::TILE);
	Position topRight(pos.x + BlockArea::TILE, pos.y + BlockArea::TILE);
	Position bottomLeft(pos.x - BlockArea::TILE, pos.y - BlockArea::TILE);
	Position bottomRight(pos.x + BlockArea::TILE, pos.y - BlockArea::TILE);

	// check if corners are fall into one of the blocked areas
	for (const std::shared_ptr<BlockArea> area : blockedAreas)
	{
		if (area->contains(topLeft) ||
			area->contains(topRight) ||
			area->contains(bottomLeft) ||
			area->contains(bottomRight))
			return true;
	}
	return false;
}

