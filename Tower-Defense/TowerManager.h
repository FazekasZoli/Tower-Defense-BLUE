#pragma once
#include "Tower.h"
//#include "Observable.h"
#include <memory>
#include <unordered_map>
#include <list>
#include <vector>

class TowerManager //: public Observable
{
private:

	std::unordered_map<TowerType, std::shared_ptr<Tower>> _towerTemplates;
	std::vector<std::shared_ptr<Tower>> _towerForGame;
	std::shared_ptr<Tower> _createTower(TowerType type);

public:
		
	TowerManager();

	void createTowerForGame();
	void upgradeTower(std::vector<std::shared_ptr<Tower>> towers);
	int sellTower(std::vector<std::shared_ptr<Tower>> towers);

};