#include <iostream>

#include "Observer.h"
#include "Player.h"
#include "View.h"
#include "Game.h"
#include "Critter.h"

int main(int argc, char *argv[]) 
{
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);
  	View* view = new View();
	Player* player = new Player();
	Game* game = new Game(player, view);

	game->gameLogic();

	delete view;
	delete player;
	delete game;


	return 0;
}