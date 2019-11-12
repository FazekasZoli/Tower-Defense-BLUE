#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer {
    public:
	    virtual ~Observer() {}
	    //virtual void update() = 0;
};

class CritterObserver : public Observer
{
public:
	virtual void critterFinishedRoad(std::shared_ptr<Critter> finishedCritter) = 0;
};

class ViewObserver : public Observer
{
public:
	virtual void placeTower() = 0;
	virtual void levelSelected (int selectedLevel) = 0;
};

#endif /* OBSERVER_H_ */
