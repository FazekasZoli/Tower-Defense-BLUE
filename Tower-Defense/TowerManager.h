#pragma once
#include <memory>
#include <iostream>
#include "Tower.h"
#include <unordered_map>
#include "Entity.h"

enum TowerType
{
	BASIC,
	POISON,
	FREEZE

};


class TowerManager : public Entity
{
private:

	std::unordered_map < TowerType, std::shared_ptr<Tower>> _towerTemplates;
	std::shared_ptr<Tower> createTower(TowerType type);

	std::list<std::shared_ptr<Tower>> _towersForGame;

public:

	TowerManager();

	void towerUpgrade();
	int sellTower();

	double placeTower(Position position);

};