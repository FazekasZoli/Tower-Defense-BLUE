#include "TowerManager.h"

std::shared_ptr<Tower> TowerManager::_createTower(TowerType type)
{
	return _towerTemplates[type]->clone();
}

TowerManager::TowerManager()
{
	Position b(10, 10);
	std::shared_ptr<Tower>tower_ptr(new Tower(BASE, b));
	_towerTemplates.insert(std::make_pair(BASE, tower_ptr));
}
