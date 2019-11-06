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
	std::vector<std::string> probaPalyaNevek = { "Proba elso palya","Proba masodik palya","Proba harmadik palya", "", "." }; //általánosabb pályakezelés, késpobb lehet map vagy bármi 
	void mainMenu();

	sf::RenderWindow window;
	sf::Event event;


public:
	//View() :window(sf::VideoMode(1000, 800), "Proba") {};
	void displayIntro();
	void displayMenu();
	//A mentett palyak és a betöltendo pályák hasonlóan tárolhatóak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo értékekkel)
	//így az enummal adhatjuk meg éppen mit írjon ki a select level, utána ugyanúgy indítja el a pályát
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya);
	void displayGameOver(GameEnd status);

	void graphic();
	void setUpDisplay();
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

Button::Button(const sf::Texture& normal, const sf::Texture&  clicked, std::string, sf::Vector2f location)
{
	this->normal.setTexture(normal);
	this->clicked.setTexture(clicked);
	this->current = &(this->normal);
	current = false;
}

Button::~Button()
{
}