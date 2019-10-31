#pragma once
#include "View.h"

class Player;
class Grid;

class Game
{
private:
	Player* _player;
	View* _view;
	Grid* _grid;

public:
	Game(Player* player, View* view, Grid* grid) : _player(player), _view(view), _grid(grid) {}

	void gameLogic();

};
