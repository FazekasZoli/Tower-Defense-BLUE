#include <iostream>
#include "Critter.h"
#include "Game.h"	

int main(int argc, char* argv[])
 {
	//ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	Game game;
	  
	game.playGame();

	//Critter monster;
	//monster.test_move();

	return 0;
}