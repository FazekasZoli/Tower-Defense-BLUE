#include "Player.h"


//Getterek implement�l�sa
int Player::getLife() const
{
	return life;
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

int Player::addMoney(int _money)
{
	money += _money;
	return money;
}

int Player::removeMoney(int _money)
{
	money -= _money;
	return money;
}
