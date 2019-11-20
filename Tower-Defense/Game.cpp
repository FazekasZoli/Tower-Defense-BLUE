#include "Game.h"

void Game::playGame()
{
	setupGame();
	//_view->displayIntro();
	
	_view->displayMenu(_grid->allRoadsSize());
	while (!_endGame)
	{	

		setupRound();

		while (0 < _player->getLife())
		{
			_cm->resetTimer();
			while (0 < _player->getLife() && !_cm->allCritterIsDead(_currentRound))
			{
				if (_endGame)
				{
					break;
				}
				currentRound();
			}
			if (_endGame)
			{
				break;
			}

			++_currentRound;
			std::cout << _currentRound << "\n";
			if ((_player->getLife() > 0) && _currentRound == 3)
			{
				//system("pause");
				
				_currentRound = 0;
				_view->closeWindow();
				_tm->deleteTowers();
				_view->displayGameOver(WIN);
				break;

			}
			_view->addNewSprites(_cm->getCrittersForRound(_currentRound));
		}
		if (_endGame)
		{
			break;
		}
		_view->displayMenu(_grid->allRoadsSize());
	}	
}

void Game::critterFinishedRoad()
{
	_player->setLife(_player->getLife() - 1);	

	if (_player->getLife() == 0)
	{
		_currentRound = 0;
		_view->closeWindow();
		_tm->deleteTowers();
		_view->displayGameOver(LOST);
	}
}

void Game::critterDied()
{
}


void Game::setupGame()
{	
	_cm->addCritterFinishObserver(this);
	_view->addViewObserver(this);
	_grid->loadRoads();
}

void Game::setupRound()
{
	_cm->resetCritters(0);
	_cm->resetCritters(1);
	_cm->resetCritters(2);
	_currentRound = 0;
	_grid->createBlockedAreaFromRoad(_currentRound);
	_player->setLife(100);
	_player->setMoney(100);
	//_cm->resetCritters(_currentRound);
	_view->setUpDisplay(_cm->getCrittersForRound(_currentRound), _tm->getTowerList(), _grid->getRoad(_selectedRoad), _player->getLifePtr(), _player->getMoneyPtr(),  _grid);
}

void Game::currentRound()
{	
	if (!_isPaused)
		
		_cm->moveActualRoundCritters(_currentRound, _grid->getRoad(_selectedRoad));
		_tm->attackWithTowers(_cm->getCrittersForRound(_currentRound));
	
	_view->updateGraphic();	
}

void Game::towerPlaced(int type, Position towerPos)
{
	if (25 <= _player->getMoney()) {
		_tm->createTowerForGame(type, towerPos);
		_view->addNewTower();
		_grid->addBlockedTowerArea(towerPos);
		_player->buyTower(25);

	}
	else
	{
		_view->playNotEnoughMoneySound();
		_view->addNotEnoughMoneyError();
		std::cout << "Nincs elegendo penzed a torony megvasarlasahoz.\n";
	}
}

void Game::buyTower(Tower* tower)
{
	if (tower->getBuyCost() < _player->getMoney())
	{
		_player->buyTower(tower->getBuyCost());
		towerPlaced(tower->getType(),tower->getPosition());
		//grid tiltolista implementalas
		
	}
	else
	{
		std::cout << "Nincs elegendo penzed a torony megvasarlasahoz.\n";
	}
}

void Game::sellTower(Position &towerPos)
{
	for (auto &it:_tm->getTowerList())
	{
		if (it->getPos()== towerPos) {
			std::cout << "\nSOLD\n";
			_player->sellTower(it->getSellCost());
			_tm->sellTower(towerPos);
			_view->removeTower(towerPos);
			_grid->removeBlockedTowerArea(towerPos);
			return;
			//
			//REMOVE FROM BLOCKED AREA!!!!
			//
		}
	}
	//_player->sellTower(tower->getSellCost());
	//torony torles majd ez alá..

}

void Game::upgradeTower(Position &towerPos)
{
	if (10 <= _player->getMoney()) {
		_tm->upgradeTower(towerPos);
		_player->buyTower(10);
	}
	
}

void Game::levelSelected(int selectedRoad)
{
	_selectedRoad = selectedRoad;
}

void Game::endGameRequest()
{
	_endGame = true;
}
