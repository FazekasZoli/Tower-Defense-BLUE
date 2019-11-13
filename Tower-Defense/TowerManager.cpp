#include "TowerManager.h"
#include "Tower.h"

std::shared_ptr<Tower> TowerManager::createTower(TowerType type)
{
	return _towerTemplates[type]->clone();
}

TowerManager::TowerManager()
{
	std::shared_ptr<Tower> _tower_ptr = std::make_shared<Tower>(new Tower);
	_towerTemplates.insert(std::make_pair(BASIC, _tower_ptr));
}
