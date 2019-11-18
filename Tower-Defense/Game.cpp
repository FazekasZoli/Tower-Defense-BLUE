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
	// add Game to CritterManager observer
	_cm->addCritterObserver(this);
	// add Game to View observer
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
	_player->setLife(3);
	//_cm->resetCritters(_currentRound);
	_view->setUpDisplay(_cm->getCrittersForRound(_currentRound), _tm->getTowerList() , _grid->getRoad(_selectedRoad), _player->getLifePtr());
}

void Game::currentRound()
{	
	if (!_isPaused)
		
		_cm->moveActualRoundCritters(_currentRound, _grid->getRoad(_selectedRoad));
	
	_view->updateGraphic();	
}

void Game::towerPlaced(int type, Position towerPos)
{
	_tm->createTowerForGame(type, towerPos);
	_view->addNewTower();
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

void Game::sellTower(Tower* tower)
{
	_player->sellTower(tower->getSellCost());
	//torony torles majd ez alá..

}

void Game::upgradeTower(Tower* tower)
{
	_tm->upgradeTower(tower);
}

void Game::levelSelected(int selectedRoad)
{
	_selectedRoad = selectedRoad;
}

void Game::endGameRequest()
{
	_endGame = true;
}
