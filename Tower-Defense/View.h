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
	std::vector<std::string> probaPalyaNevek = { "Proba elso palya","Proba masodik palya","Proba harmadik palya", "", "." }; //�ltal�nosabb p�lyakezel�s, k�spobb lehet map vagy b�rmi 
	void mainMenu();

public:
	void displayIntro();
	void displayMenu();
	//A mentett palyak �s a bet�ltendo p�ly�k hasonl�an t�rolhat�ak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo �rt�kekkel)
	//�gy az enummal adhatjuk meg �ppen mit �rjon ki a select level, ut�na ugyan�gy ind�tja el a p�ly�t
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya);
};