#include "Game.h"

void Game::gameLogic()
{
	//_view->displayIntro();
	//_view->displayMenu();

	std::shared_ptr<Critter> c = _cm->createCritter(NORMAL);

	// crittereket fel kell iratni az observerre a játék inicializálásakor
	c->addObserver(this);

	// tmp road
	std::vector<std::pair<Position, Position>> p;

	Position start1(0, 0); //honnan
	Position dir1(1, 0); //irány
	Position end1(50, 0); //hova
	Position dir2(0, 1);
	Position end2(50, 50);
	Position dir3(-1, 0);
	Position end3(0, 50);
	p.emplace_back(start1, dir1);
	p.emplace_back(end1, dir2); 
	p.emplace_back(end2, dir3);
	p.emplace_back(end3, start1);
	
	// move teszt
	for (size_t i = 0; i < 50; i++)
	{
		c->move(p);
		std::cout << "x: " << c->getPos().x << " y: " << c->getPos().y << std::endl;
	}
}

void Game::updatePlayerLife()
{
	_player->setLife(_player->getLife() - 1);

	if (_player->getLife() == 0)
	{
		_view->displayGameOver(LOST);
	}
}

