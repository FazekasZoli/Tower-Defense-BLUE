#include "Game.h"

void Game::gameLogic()
{
	_view->displayIntro();
	_view->displayMenu();
	_view->displayGameOver();
}
