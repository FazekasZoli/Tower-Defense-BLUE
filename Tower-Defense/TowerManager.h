#pragma once
#include "Tower.h"
//#include "Observable.h"
#include <memory>
#include <unordered_map>
#include <list>
#include <vector>
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
	void upgradeTower(std::vector<std::shared_ptr<Tower>> towers);
	int sellTower(std::vector<std::shared_ptr<Tower>> towers);
	std::vector<std::shared_ptr<Tower>>& getTowerList();
	void deleteTowers();

};