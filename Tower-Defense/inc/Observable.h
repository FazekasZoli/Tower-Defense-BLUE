#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <list>
#include <memory>

#include "Observer.h"
#include "..\Critter.h"
#include "..\View.h"

class Observable 
{
	private:
	    std::list<CritterObserver*> _critterFinishObservers;  ///< The registered observers.		

    public:

		/// Adds an observer.
		/// \param obs	Observer to add.
	    void addObserver(CritterObserver *obs) 
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
	    void removeObserver(CritterObserver *obs) 
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
	    void notifyCritterFinishedRoad(std::shared_ptr<Critter> finishedCritter) 
		{
		    for (auto obs : _critterFinishObservers) 
			{
				obs->critterFinishedRoad(finishedCritter);
		    }
	    }
};

class ViewEvent
{
	ViewObserver* _obs;

	void notifyButtonClicked(ButtonType clickType) 
	{
		switch (clickType)
		{
		case Pause:
			break;
		case Resume:
			break;
		case TowerPlace:
			_obs->placeTower();
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
};

#endif /* OBSERVABLE_H_ */
