#pragma once
#include "Entity.h"

class Critter : public Entity
{

public:

	//default konstruktor
	Critter() : life(1), positionX(0), positionY(0), reward(150), speed(1) {};

	//konstruktor
	
	Critter(int newLife, int newPositionX, int newPositionY, int newReward, int newSpeed) : life(newLife), positionX(newPositionX), positionY(newPositionY), reward(newReward), speed(newSpeed) {};

	//destruktor
	~Critter();

	//GETTEREK (az�rt inline mert az oszt�ly le�r�s�ban szerepeltetem a tagf�ggv�nyek teljes defin�ci�j�t (r�videk))
	inline int getLife() const { return life; };
	inline int getPositionX() const { return positionX; };
	inline int getPositionY() const { return positionY; };
	inline int getReward() const { return reward; };
	inline int getSpeed() const { return speed; };

	//SETTEREK
	//........
	inline void setLife(int newLife) { life = newLife; };
	inline void setReward(int newReward) { reward = newReward; };
	inline void setSpeed(int newSpeed) { speed = newSpeed; };

private:

	//�let
	int life;

	//--Poz�ci�--
	int positionX;
	int positionY;

	//jutalom, ha meghal
	int reward;

	//milyen gyorsan tud mozogni
	int speed;


};
