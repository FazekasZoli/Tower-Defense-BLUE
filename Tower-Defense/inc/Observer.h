#pragma once

class Observer {
    public:
	    virtual ~Observer() {}	    
};

class CritterObserver : public Observer
{
public:
	virtual void critterFinishedRoad() = 0;
};

class ViewObserver : public Observer
{
public:
	virtual void placeTower() = 0;
	virtual void levelSelected (int selectedLevel) = 0;
};
