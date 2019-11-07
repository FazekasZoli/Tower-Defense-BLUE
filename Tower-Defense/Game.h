#pragma once
#include <memory>

#include "Player.h"
#include "View.h"
#include "Grid.h"
#include "CritterManager.h"
#include "Observer.h"

class Game : public CritterObserver
{	  
private:
	// Inherited via CritterObserver
	virtual void updatePlayerLife() override;

	void setupGame();
	void setupRound();
	void currentRound();

public:
	Game(int level = 0) : 
		_player(std::make_unique<Player>()), _view(std::make_unique<View>()), _grid(std::make_shared<Grid>()), _cm(std::make_shared<CritterManager>()), _level(level) 
	{}

	void playGame();

private:
	std::unique_ptr<Player> _player;
	std::unique_ptr<View> _view;
	std::shared_ptr<Grid> _grid;
	std::shared_ptr<CritterManager> _cm;

	int _level;
};