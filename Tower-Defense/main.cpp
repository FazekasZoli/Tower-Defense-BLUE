#include <iostream>

#include "Observer.h"
#include "Player.h"
#include "View.h"
#include "Game.h"	

int main(int argc, char *argv[]) 
{
	View* view = new View();
	Player* player = new Player();
	Game* game = new Game(player, view);

	game->gameLogic();

	return 0;
}