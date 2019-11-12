#include "Game.h"

void Game::gameLogic()
{
	//_view->displayIntro();
	//_view->displayMenu();
	
	std::shared_ptr<Critter> c = _cm->createCritter(NORMAL);
	c->setSpeed(10);
	std::list<std::shared_ptr<Critter>> critterList;
	critterList.push_back(c);
	// crittereket fel kell iratni az observerre a játék inicializálásakor
	c->addObserver(this);

	// tmp road
	//std::vector<std::pair<Position, Position>> p;

	//Position start1(0, 0); //honnan
	//Position dir1(1, 0); //irány

	//Position end1(400, 0); //hova
	//Position dir2(0, 1);

	//Position end2(400,200);
	//Position dir3(-1, 0);

	//Position end3(100,200);
	//Position dir4(0, 1);

	//Position end4(100,500);
	//Position dir5(1, 0);

	//Position end5(800, 500);
	//Position dir6(0, 1);

	//Position end6(800, 800);

	//p.emplace_back(start1, dir1);
	//p.emplace_back(end1, dir2); 
	//p.emplace_back(end2, dir3);
	//p.emplace_back(end3, dir4);
	//p.emplace_back(end4, dir5);
	//p.emplace_back(end5, dir6);
	//p.emplace_back(end6, start1);
	_grid->loadGrid();

	_view->setUpDisplay(critterList, _grid->getRoad());
	// move teszt
	for (size_t i = 0; i < 500; i++)
	{
		c->move(_grid->getRoad());
		_view->updateGraphic(critterList);
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

