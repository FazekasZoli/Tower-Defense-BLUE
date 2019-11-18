#include "TowerManager.h"
#include <iostream>

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
void TowerManager::createTowerForGame(int type, Position pos)
{
	//std::cout << "TowerPlaced: " << pos.x << "," << pos.x << "\n";
	_towerForGame.emplace_back(_createTower(static_cast<TowerType>(type)));
	_towerForGame.back()->setPosTw(pos);
} 
void TowerManager::upgradeTower(Tower* tower)
{
	tower->upgrade();

}

int TowerManager::sellTower(std::vector<std::shared_ptr<Tower>> towers)
{
	for (auto tower : towers)
	{
		return towers[0]->getSellCost();
	}
	return 0;
}

std::vector<std::shared_ptr<Tower>>& TowerManager::getTowerList()
{
	return _towerForGame;
}

void TowerManager::deleteTowers()
{
	_towerForGame.clear();
}
