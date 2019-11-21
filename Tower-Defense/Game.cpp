#include "Game.h"

void Game::playGame()
{
	setupGame();
	_view->displayIntro();
	
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

void Game::setupGame()
{	
	_cm->addCritterFinishObserver(this);
	_view->addViewObserver(this);
	_grid->loadRoads();
}

void Game::setupRound()
{
	Position startPos = (_grid->getRoad(_selectedRoad))[0].first;
	_currentRound = 0;
	_cm->resetCritters(startPos);
	_grid->createBlockedAreaFromRoad(_selectedRoad);
	_player->setLife(100);
	_player->setMoney(100);
	_view->setUpDisplay(_cm->getCrittersForRound(_currentRound), _tm->getTowerList(), _grid->getRoad(_selectedRoad), _player->getLifePtr(), _player->getMoneyPtr(),  _grid);
}

void Game::currentRound()
{	
	int moneyGotThisTurn = 0;
	if (!_isPaused)
	{
		_cm->moveActualRoundCritters(_currentRound, _grid->getRoad(_selectedRoad));
		moneyGotThisTurn=_tm->attackWithTowers(_cm->getCrittersForRound(_currentRound));
		_player->addMoney(moneyGotThisTurn);
	}
	_view->updateGraphic();	
}

void Game::buyTower(Position &towerPos)
{
	if (25 <= _player->getMoney()) {
		_tm->createTowerForGame(towerPos);
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

void Game::sellTower(Position &towerPos)
{
	for (auto &tower : _tm->getTowerList())
	{
		if (tower->getPos() == towerPos) 
		{
			std::cout << "\nSOLD\n";
			_player->sellTower(tower->getSellCost());
			_tm->sellTower(towerPos);
			_view->removeTower(towerPos);
			_grid->removeBlockedTowerArea(towerPos);
			return;			
		}
	}
	//_player->sellTower(tower->getSellCost());
	//torony torles majd ez alá..
}

void Game::upgradeTower(Position &towerPos)
{
	int cost = 15;
	if (cost <= _player->getMoney()) {
		_tm->upgradeTower(towerPos);
		_player->buyTower(cost);
	}
	else
	{
		_view->playNotEnoughMoneySound();
		_view->addNotEnoughMoneyError();
		std::cout << "Nincs elegendo penzed a torony megvasarlasahoz.\n";
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
