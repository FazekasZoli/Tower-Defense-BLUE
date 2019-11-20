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

int* Player::getMoneyPtr()
{
	return &money;
}

double Player::getMoney() const
{
	return money;
}

//Setterek implent�l�sa

void Player::setLife(int _life)
{
	life = _life;
}

void Player::setMoney(double _money)
{
	money = _money;
}

double Player::sellTower(double _money)
{
	money += _money;
	return money;
}

double Player::buyTower(double _money)
{
	money -= _money;
	return money;
}
