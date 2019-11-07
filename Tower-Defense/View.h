#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
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

enum GameEnd
{
	WIN,
	LOST
};

class View
{
private:
	
	int menuState = 0;
	short mainPpos = -1;
	std::vector<std::string> probaPalyaNevek = { "Proba elso palya","Proba masodik palya","Proba harmadik palya", "", "." }; //�ltal�nosabb p�lyakezel�s, k�spobb lehet map vagy b�rmi 
	void mainMenu();

	sf::RenderWindow window;
	int screenX = 1000;
	int screenY = 800;
	sf::Event event;
	sf::Texture grassTexture;
	sf::Texture routeTexture;
	sf::Texture entityTexture;



public:
	//View() :window(sf::VideoMode(1000, 800), "Proba") {};
	void displayIntro();
	void displayMenu();
	//A mentett palyak �s a bet�ltendo p�ly�k hasonl�an t�rolhat�ak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo �rt�kekkel)
	//�gy az enummal adhatjuk meg �ppen mit �rjon ki a select level, ut�na ugyan�gy ind�tja el a p�ly�t
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya);
	void displayGameOver(GameEnd status);

	void graphic();
	void setUpDisplay();
	void displayRoute();
};

class Button
{
public:
	Button(const sf::Texture& normal, const sf::Texture&  clicked, std::string, sf::Vector2f location);
	~Button();

private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSpr;
	sf::String String;
	bool current;
};



