#pragma once

//class Tower;

class Observer {
    public:
	    virtual ~Observer() {}	    
};

class CritterManagerObserver : public Observer
{
public:
	virtual void critterFinishedRoad() = 0;	
};

class ViewObserver : public Observer
{
public:
	virtual void levelSelected (int selectedLevel) = 0;
	virtual void endGameRequest() = 0;

	virtual void buyTower(Position& towerPos) = 0;
	virtual void sellTower(Position& towerPos) = 0;
	virtual void upgradeTower(Position& towerPos) = 0;
};
