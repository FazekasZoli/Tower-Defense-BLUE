//#include <iostream>

#include "TowerManager.h"

std::shared_ptr<Tower> TowerManager::_createTower(TowerType type)
{	
	return _towerTemplates[type]->clone();
}

TowerManager::TowerManager()
{
	Position start(10, 10);
	_towerTemplates.insert(std::make_pair(BASE, std::make_shared<Tower>(start)));
}
void TowerManager::createTowerForGame(Position &pos)
{
	_towerForGame.emplace_back(_createTower(BASE));
	_towerForGame.back()->setPosTw(pos);
} 
void TowerManager::upgradeTower(Position & towerPos)
{
	for (auto &tower : _towerForGame)
	{
		if (tower->getPos() == towerPos)
			tower->upgrade();
	}
}

void TowerManager::sellTower(Position &towerPos)
{
	Position tmp;
	for (auto towerIt = _towerForGame.begin(); towerIt != _towerForGame.end(); ++towerIt)
	{
		tmp.x = (*towerIt)->getPos().x;
		tmp.y = (*towerIt)->getPos().y;
		if (tmp == towerPos) {
			_towerForGame.erase(towerIt);
			return;
		}
	}
}

//int TowerManager::sellTower(std::vector<std::shared_ptr<Tower>> towers)
//{
//	for (auto tower : towers)
//	{
//		return towers[0]->getSellCost();
//	}
//	return 0;
//}

std::vector<std::shared_ptr<Tower>>& TowerManager::getTowerList()
{
	return _towerForGame;
}

void TowerManager::deleteTowers()
{
	_towerForGame.clear();
}

void TowerManager::attackWithTowers(std::list<std::shared_ptr<Critter>>& critters)
{
	for (auto &tower : _towerForGame)
	{		
		tower->attack(critters);
	}
}
