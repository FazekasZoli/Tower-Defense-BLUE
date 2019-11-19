#pragma once

#include "Observer.h"



class CritterEvents 
{
	private:
	    std::list<CritterObserver*> _critterFinishObservers;  ///< The registered observers.		

    public:

		/// Adds an observer.
		/// \param obs	Observer to add.
	    void addCritterObserver(CritterObserver *obs) 
		{
		    //check if already in
		    for (const auto p : _critterFinishObservers) 
			{
			    if (p == obs) 
					return;
		    }
		    _critterFinishObservers.push_back(obs);
	    }

		/// Removes an observers.
		/// \param obs	Observer to remove.
	    void removeCritterObserver(CritterObserver *obs) 
		{
		    for (auto it = std::begin(_critterFinishObservers); it != std::end(_critterFinishObservers); ++it) 
			{
			    if (*it == obs) 
				{
				    _critterFinishObservers.erase(it);
				    break;
			    }
		    }
	    }

		/// Notifies all the observers, i.e., calls  observers update function.
	    void notifyCritterFinishedRoad() 
		{
		    for (auto obs : _critterFinishObservers) 
			{
				obs->critterFinishedRoad();
		    }
	    }
};

enum ButtonType { Pause, Resume, TowerPlace, TowerUpgrade, TowerSell, NextRoundStart, OwnTower };

class ViewEvents
{
private:
	ViewObserver* _obs;

	

public:
	void addViewObserver(ViewObserver* obs) { _obs = obs; }

	void notifyButtonClicked(ButtonType clickType, int type, Position towerPos) 
	{
		switch (clickType)
		{
		case Pause:
			break;
		case Resume:
			break;
		case TowerPlace:
			_obs->placeTower(type, towerPos);
			break;
		case TowerUpgrade:
			break;
		case TowerSell:
			break;
		case NextRoundStart:
			break;
		default:
			break;
		}
	}

	void notifySelectedLevel(int selectedLevel)
	{
		_obs->levelSelected(selectedLevel);
	}

	void notifyEndGameRequest()
	{
		_obs->endGameRequest();
	}
};
