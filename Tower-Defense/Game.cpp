#include "Game.h"

void Game::gameLogic()
{
	//_view->displayIntro();
	//_view->displayMenu();

	std::shared_ptr<Critter> c = _cm->createCritter(NORMAL);

	// crittereket fel kell iratni az observerre a játék inicializálásakor
	c->addObserver(this);

	// temp road
	/*std::vector<std::pair<Position, Position>> troad;
	troad.push_back({ {0, 0} , {1, 0} });
	troad.push_back({ {5, 0} , {0, 1} });
	troad.push_back({ {5, 5} , {1, 0} });
	troad.push_back({ {10, 5} , {0, 0} });*/

	std::vector<std::pair<Position, Position>> p;

	Position start1(0, 0); //honnan
	Position dir1(1, 0); //irány
	Position end1(50, 0); //hova

	Position dir2(0, 1);
	Position end2(50, 50);

	Position dir3(-1, 0);
	Position end3(0, 50);

	Critter* monster = new Critter();

	p.emplace_back(start1, dir1);
	p.emplace_back(end1, dir2);
	p.emplace_back(end2, dir3);

	p.emplace_back(end3, start1);

	for (size_t i = 0; i < 100; i++)
	{
		c->move(p);
		std::cout << "x: " << monster->getPos().x << " y: " << monster->getPos().y << std::endl;
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

