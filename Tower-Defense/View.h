#pragma once
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>


enum LevelSelectMode
{
	NewGame,
	LoadGame
};

class View
{
private:
	int menuState = 0;
	short mainPpos = -1;
	std::vector<std::string> probaPalyaNevek = { "Proba elso palya","Proba masodik palya","Proba harmadik palya", "", "." }; //általánosabb pályakezelés, késpobb lehet map vagy bármi 
	void mainMenu();

public:
	void displayIntro();
	void displayMenu();
	//A mentett palyak és a betöltendo pélyék hasonlóan tárolhatóak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo értékekkel)
	//így az enummal adhatjuk meg éppen mit írjon ki a select level, utána ugyanúgy indítja el a pályát
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya);
};