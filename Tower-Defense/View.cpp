#include "View.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>

void introTower()
{
	std::cout << "               " <<" _    _    _" << std::endl;
	Sleep(100);
	std::cout << "               " << "| |__| |__| |" << std::endl;
	Sleep(100);
	std::cout << "               " << "|           |" << std::endl;
	Sleep(100);
	std::cout << "               " << "|__       __|" << std::endl;
	Sleep(100);
	std::cout << "               " << "   |     |    " << std::endl;
	Sleep(100);
	std::cout << "               " << "   |     |    " << std::endl;
	Sleep(100);
	std::cout << "               " << " __|     |__ " << std::endl;
	Sleep(100);
	std::cout << "               " << "|___________| " << std::endl;
}

void welcome()
{
	std::string welcome = "Welcome our TOWER DEFENSE game";
	std::cout << "      ";
	for (int i = 0; i < welcome.size(); ++i)
	{
		std::cout << welcome[i];  
		Sleep(50);
	}
}

void View::displayIntro()
{
	introTower();
	
	Sleep(1000);
		
	std::cout << "\n" << std::endl;

	welcome();

	Sleep(1000);

	std::cout << "\n" << std::endl;
		
	introTower();
}
