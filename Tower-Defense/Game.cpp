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
			while (0 < _player->getLife() && !_cm->allCritterIsDead(_currentRound) && !_endGame)
			{				
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
	_currentRound = 0;
	
	//_cm->resetCritters(_currentRound);
	_cm->resetCritters(0);
	_cm->resetCritters(1);
	_cm->resetCritters(2);
	
	_player->setLife(100);
	
	_view->setUpDisplay(_cm->getCrittersForRound(_currentRound), _tm->getTowerList() , _grid->getRoad(_selectedRoad), _player->getLifePtr());
}

void Game::currentRound()
{	
	if (!_isPaused)		
		_cm->moveActualRoundCritters(_currentRound, _grid->getRoad(_selectedRoad));
	
	_view->updateGraphic();	
}

void Game::placeTower(int type, Position towerPos)
{
	_tm->createTowerForGame(type, towerPos);
	_view->addNewTower();
}

void Game::levelSelected(int selectedRoad)
{
	_selectedRoad = selectedRoad;
}

void Game::endGameRequest()
{
	_endGame = true;
}
