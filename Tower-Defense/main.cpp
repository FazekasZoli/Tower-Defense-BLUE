#include <iostream>
#include "Critter.h"
#include "Game.h"	

int main(int argc, char* argv[])
{
	//ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	//Game game;

	//game.gameLogic();

	Critter monster;
	monster.test_move();

	Player player;

	player.setLife(1);

	game.updatePlayerLife();

	return 0;
}