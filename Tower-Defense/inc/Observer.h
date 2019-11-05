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
	virtual void updatePlayerLife() = 0;
};

#endif /* OBSERVER_H_ */
