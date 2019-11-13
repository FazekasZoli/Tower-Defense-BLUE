#pragma once
#include <vector>
#include <memory>

#include "Entity.h"

enum TowerType
{
	BASE,
	FREEZING,
	POISONING
};

class Tower : public Entity
{
public:
	//konstruktor
	Tower(TowerType _type, Position& position);


	//GETTEREK (az�rt inline mert az oszt�ly le�r�s�ban szerepeltetem a tagf�ggv�nyek teljes defin�ci�j�t (r�videk))
	inline TowerType getType() const { return type; };
	inline int getBuyCost() const { return buyCost; };
	inline int getSellCost() const { return sellCost; };
	inline bool getAttackPower() const { return attackPower; };
	inline bool getAttackRange() const { return attackRange; };

	//SETTEREK
	//........
	inline void setType(TowerType _type) { type = _type; };
	inline void setBuyCost(int _buyCost) { buyCost = _buyCost; };
	inline void setSellCost(int _sellCost) { sellCost = _sellCost; };
	inline void setAttackPower(int _attackPower) { attackPower = _attackPower; };
	inline void setAttackRange(int _attackRange) { attackRange = _attackRange; };

	//metodusok
	void upgrade(std::shared_ptr<Tower> tower);
	
	std::shared_ptr<Tower> clone(); 

private:
	//tipus
	TowerType type;

	// az az osszeg, amennyi�rt a tower lehelyezheto
	int buyCost;

	//az az osszeg, amennyiert a tower visszavalthato
	int sellCost;

	// a tower hatoereje
	int attackPower;

	//tamadas hatosugara
	int attackRange;
};

