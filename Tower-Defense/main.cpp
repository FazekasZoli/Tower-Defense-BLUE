#include <iostream>
#include "Observer.h"
#include "Player.h"

int main(int argc, char *argv[]) 
{
	Player* player = new Player(10, 2000);

	std::cout << "Jatekos elete: " << player->getLife() << std::endl;
	std::cout << "Jatekos penze: " << player->getMoney() << std::endl;

	player->addMoney(500);
	player->removeMoney(50);

	std::cout << "Jatekos elete: " << player->getLife() << std::endl;
	std::cout << "Jatekos penze: " << player->getMoney() << std::endl;



	return 0;
}