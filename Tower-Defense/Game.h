#pragma once

#include "Player.h"
#include "View.h"

class Game
{
private:
	Player* _player;
	View* _view;
	//Grid* _grid;

public:
	Game(Player* player, View* view) : _player(player), _view(view) {}

	void gameLogic();

};
