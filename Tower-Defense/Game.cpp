#include "Game.h"

void Game::playGame()
{
	setupGame();
	_view->displayIntro();
	_view->displayMenu();

	setupRound();	
	
	_view->setUpDisplay(_cm->getCrittersForRound(_currentRound), _grid->getRoad());

	for (size_t i = 0; i < 200; i++)
	{
		_cm->moveActualRoundCritters(_currentRound, _grid->getRoad());
		_view->updateGraphic(_cm->getCrittersForRound(_currentRound));
	}
}

void Game::critterFinishedRoad()
{
	_player->setLife(_player->getLife() - 1);

	if (_player->getLife() == 0)
	{
		_view->displayGameOver(LOST);
	}
}

void Game::placeTower()
{
}

void Game::levelSelected(int selectedLevel)
{
	_selectedLevel = selectedLevel;
}

void Game::setupGame()
{
	// Load map
	// tmp road
	//std::vector<std::pair<Position, Position>> tmp;
	
	for (size_t i = 1; i <= 2; i++)
	{
		_grid->loadGrid(i);
		_grid->allRoads.push_back(_grid->getRoad());
	}
	
}

void Game::setupRound()
{

	_currentRound = 0;


}

void Game::currentRound()
{
}

