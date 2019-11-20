#include "Game.h"	

int main(int argc, char* argv[])
 {
	ShowWindow(GetConsoleWindow(), SW_SHOWMAXIMIZED);

	Game game;
	  
	game.playGame();
	
	return 0;
}