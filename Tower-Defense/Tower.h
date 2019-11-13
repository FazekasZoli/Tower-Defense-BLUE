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


	//GETTEREK (azért inline mert az osztály leírásában szerepeltetem a tagfüggvények teljes definícióját (rövidek))
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

	// az az osszeg, amennyiért a tower lehelyezheto
	int buyCost;

	//az az osszeg, amennyiert a tower visszavalthato
	int sellCost;

	// a tower hatoereje
	int attackPower;

	//tamadas hatosugara
	int attackRange;
};

