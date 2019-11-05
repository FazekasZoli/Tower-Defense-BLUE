#include "Game.h"

void Game::gameLogic()
{
	_view->displayIntro();
	_view->displayMenu();
	_view->displayGameOver();

	// crittereket fel kell iratni az observerre a játék inicializálásakor
}

void Game::updatePlayerLife()
{
	_player->setLife(_player->getLife() - 1);
}
