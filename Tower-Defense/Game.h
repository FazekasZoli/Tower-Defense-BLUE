#pragma once
#include <memory>

#include "Player.h"
#include "View.h"
#include "Grid.h"

class Game
{
private:
	std::unique_ptr<Player> _player;
	std::unique_ptr<View> _view;
	std::unique_ptr<Grid> _grid;

public:
	Game() : _player(std::make_unique<Player>()), _view(std::make_unique<View>()), _grid(std::make_unique<Grid>()) {}

	void gameLogic();
};