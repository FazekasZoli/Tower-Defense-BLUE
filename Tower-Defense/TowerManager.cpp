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
void TowerManager::createTowerForGame()
{
	_towerForGame.emplace_back(_createTower(BASE));
}

void TowerManager::upgradeTower(std::vector<std::shared_ptr<Tower>> towers)
{
	for (auto tower : towers)
	{
		tower->upgrade(towers[0]);
	}

}

int TowerManager::sellTower(std::vector<std::shared_ptr<Tower>> towers)
{
	for (auto tower : towers)
	{
		return towers[0]->getSellCost();
	}
}