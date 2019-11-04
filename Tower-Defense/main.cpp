#include <iostream>

#include "Game.h"	

int main(int argc, char* argv[])
{
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	Game game;

	game.gameLogic();

	return 0;
}