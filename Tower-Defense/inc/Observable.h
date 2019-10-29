#ifndef OBSERVABLE_H_
#define OBSERVABLE_H_

#include <list>

#include "Observer.h"

class Observable {

    private:
	    std::list<Observer*> observers;  ///< The registered observers.

    public:

		/// Adds an observer.
		/// \param obs	Observer to add.
	    void addObserver(Observer *obs) {
		    //check if already in
		    for (const auto p : observers) {
			    if (p == obs) {
				    return;
			    }
		    }
		    observers.push_back(obs);
	    }

		/// Removes an observers.
		/// \param obs	Observer to remove.
	    void removeObserver(Observer *obs) {
		    for (auto it = std::begin(observers); it != std::end(observers); ++it) {
			    if (*it == obs) {
				    observers.erase(it);
				    break;
			    }
		    }
	    }

		/// Notifies all the observers, i.e., calls  observers update function.
	    void notify() const {
		    for (auto obs : observers) {
			    obs->update();
		    }
	    }

};

#endif /* OBSERVABLE_H_ */
