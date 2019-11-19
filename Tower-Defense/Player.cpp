#include "Player.h"


//Getterek implement�l�sa
int Player::getLife() const
{
	return life;
}

int* Player::getLifePtr()
{
	return &life;
}

int * Player::getMoneyPtr()
{
	return &money;
}

int Player::getMoney() const
{
	return money;
}

//Setterek implent�l�sa

void Player::setLife(int _life)
{
	life = _life;
}

void Player::setMoney(int _money)
{
	money = _money;
}

int Player::sellTower(int _money)
{
	money += _money;
	return money;
}

int Player::buyTower(int _money)
{
	money -= _money;
	return money;
}
