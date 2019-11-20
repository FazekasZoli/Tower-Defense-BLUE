#pragma once
#include <memory>

#include "Player.h"
#include "View.h"
#include "Grid.h"
#include "CritterManager.h"
#include "Observer.h"
#include "TowerManager.h"

class Game : public CritterManagerObserver, public ViewObserver
{	  
private:
	void setupGame();
	void setupRound();
	void currentRound();

public:
	Game(int defaultRoad = 0, int currentRound = 0, bool isPaused = false, bool endGame = false) : 
		_player(std::make_unique<Player>()), _view(std::make_unique<View>()), _grid(std::make_shared<Grid>()), _cm(std::make_shared<CritterManager>()), _tm(std::make_shared<TowerManager>()),
		_selectedRoad(defaultRoad), _currentRound(currentRound), _isPaused(isPaused), _endGame(endGame)
	{		
	}

	void playGame();

	// Events
	// Inherited via CritterObserver
	virtual void critterFinishedRoad() override;	
	// Inherited via ViewObserver
	virtual void levelSelected(int selectedLevel) override;
	virtual void endGameRequest() override;
	virtual void buyTower(Position &towerPos) override;	
	virtual void sellTower(Position &towerPos) override;
	virtual void upgradeTower(Position &towerPos) override;	

private:
	std::unique_ptr<Player> _player;
	std::unique_ptr<View> _view;
	std::shared_ptr<Grid> _grid;
	std::shared_ptr<CritterManager> _cm;
	std::shared_ptr<TowerManager> _tm;
		
	int _currentRound;	
	int _selectedRoad;
	bool _isPaused;
	bool _endGame;

	
};