#pragma once
#include <memory>
#include <unordered_map>
#include <list>
#include <vector>

#include "Tower.h"
#include "Observer.h"

class TowerManager //: public ViewObserver
{
private:

	std::unordered_map<TowerType, std::shared_ptr<Tower>> _towerTemplates;
	std::vector<std::shared_ptr<Tower>> _towerForGame;
	std::shared_ptr<Tower> _createTower(TowerType type);

public:
		
	TowerManager();

	void createTowerForGame(int type, Position pos);
	void upgradeTower(Position &towerPos);
	void sellTower(Position &towerPos);
	std::vector<std::shared_ptr<Tower>>& getTowerList();
	void deleteTowers();
	void attackWithTowers(std::list<std::shared_ptr<Critter>>& critters);

};