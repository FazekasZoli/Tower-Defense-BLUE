#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>
#include <list>

#include "critter.h"
#include "inc/Observable.h"

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


class Button {
public:
	Button() {};
	bool checkClick(sf::Vector2f mousePos);
	void setState(bool);
	void setText(std::string);
	bool getVar();
	void initialize(sf::Texture* normal, sf::Texture* clicked, std::string, sf::Vector2f location, ButtonType ownType);
	sf::Sprite* getSprite();
	sf::String * getText();
	ButtonType getType();

private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSpr;
	sf::String String;
	bool current;
	sf::Text string;
	ButtonType ownType;
};




class View : public ViewEvents
{
private:
	
	int menuState = 0;
	short mainPpos = -1;
	std::vector<std::string> probaPalyaNevek = { "Proba elso palya","Proba masodik palya","Proba harmadik palya", "", "." }; //általánosabb pályakezelés, késpobb lehet map vagy bármi 
	void mainMenu();

	sf::RenderWindow window;
	int screenX = 1000;
	int screenY = 800;
	sf::Event event;
	sf::Texture grassTexture;
	sf::Texture routeTexture;
	sf::Texture entityTexture;
	sf::Sprite spriteBG;
	sf::Sprite placingTower;
	std::list<std::shared_ptr<Critter>>* crittersPtr;
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Sprite> RoadSprites;
	std::vector<Button> Buttons;
	Button buttonTowerProba;
	Button *selectedButton;
	sf::Texture button1;
	sf::Texture button2;
	sf::Texture Tower;
	sf::Texture TowerShady;
	sf::Sprite TowerShadySprite;

	int* playerLife;
	sf::Text playerLifeText;
	sf::Text playerLifeRizsa;
	sf::Font font;

public:
	//View() :window(sf::VideoMode(1000, 800), "Proba") {};
	void displayIntro();
	void displayMenu();
	//A mentett palyak és a betöltendo pályák hasonlóan tárolhatóak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo értékekkel)
	//így az enummal adhatjuk meg éppen mit írjon ki a select level, utána ugyanúgy indítja el a pályát
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya);
	void displayGameOver(GameEnd status);
	//void graphic();
	void updateGraphic();
	void setUpDisplay(std::list<std::shared_ptr<Critter>>& critterList, std::vector<std::pair<Position, Position>> &road, int* playerLifee);
	void addSprites(std::list<std::shared_ptr<Critter>>& critterList, const sf::Texture &texture);
	void addRouteSprites(std::vector<std::pair<Position, Position>> &road, const sf::Texture &texture);
	void updateSprites();
	

	
};







