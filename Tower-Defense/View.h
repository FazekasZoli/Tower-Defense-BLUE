#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <vector>
#include <string>
#include <list>
//#pragma comment(lib, "openal32.lib")
//#pragma comment(lib, "sndfile.lib") 
//#pragma comment(lib, "sfml-system.lib") 
#include "Critter.h"
#include "Tower.h"
#include "inc/Observable.h"
#include "Grid.h"

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
	void setStateVar(bool);
	//void setText(std::string);
	bool getVar();
	void initialize(sf::Texture* normal, sf::Texture* clicked, sf::Vector2f location, ButtonType ownType);
	sf::Sprite* getSprite();
	sf::Sprite* getSpriteNorm();
	//sf::String * getText();
	ButtonType getType();
	sf::Vector2f pos;

private:
	sf::Sprite normal;
	sf::Sprite clicked;
	sf::Sprite* currentSpr;
	//sf::String String;
	bool current;
	//sf::Text string;
	ButtonType ownType;
};

class TowerButtons:public Button
{
public:
	TowerButtons();
	~TowerButtons();
	//sf::Sprite backgroundGrass;
	//void setBG(sf::Texture bg);
	void draw(sf::RenderWindow & window);
	void drawLevel(sf::RenderWindow & window);
	Button* getUpgradeButton() { return &upgradeButton; };
	Button* getSellButton() { return &sellButton; };
	static TowerButtons* SelectedTower;
	bool checkClickTower(sf::Vector2f mousePos);
	void setLevelPtr(int* levelptr);
	void levelTextini(sf::Font *font);
	int* levelPtr;
	int* radPtr;
	sf::Text level;
	sf::CircleShape range;
	sf::CircleShape* getRangeCircPtr() { return &range; };

	

private:
	
	Button upgradeButton;
	Button sellButton;

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
	sf::Texture grassTexture2;
	sf::Texture routeTexture;
	sf::Texture entityTexture;
	sf::Texture newEntityFront;
	sf::Texture newEntityBack;
	sf::Texture newEntityLeft;
	sf::Texture newEntityRight;
	sf::Texture grave;
	sf::Texture upgradeButtonTex;
	sf::Texture sellButtonTex;
	sf::Sprite spriteBG;

	std::shared_ptr<Grid> gridPtr;

	std::list<std::shared_ptr<Critter>>* crittersPtr;
	std::vector<std::shared_ptr<Tower>>* towersPtr;
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Sprite> RoadSprites;
	//std::vector<sf::Sprite> towerSprites;
	std::vector<TowerButtons> towerButtons;

	std::vector<Button> Buttons;
	Button buttonTowerProba;
	Button *selectedButton;
	sf::Texture button1;
	sf::Texture button2;
	sf::Texture towerTex;
	sf::Sprite placingTower;
	sf::Texture TowerShady;
	sf::Sprite TowerShadySprite;
	sf::Texture TowerShadyRed;
	sf::Sprite TowerShadySpriteRed;
	sf::CircleShape radius;
	int baseRadius = 100;

	int* playerLife;
	int* playerMoneyV;
	
	sf::Text playerLifeText;
	sf::Text playerLifeRizsa;
	sf::Text playerMoneyText;
	sf::Text playerMoneyRizsa;
	sf::Text notEoughMoney;
	int notEoughMoneyCounter;
	bool notEoughMoneyBool;

	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Font font;

public:
	//View() :window(sf::VideoMode(1000, 800), "Proba") {};
	void displayIntro();
	void displayMenu(size_t numberOfRoads);
	//A mentett palyak és a betöltendo pályák hasonlóan tárolhatóak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo értékekkel)
	//így az enummal adhatjuk meg éppen mit írjon ki a select level, utána ugyanúgy indítja el a pályát
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya, int numberOfMaps);
	void displayGameOver(GameEnd status);
	//void graphic();
	void updateGraphic();
	void setUpDisplay(std::list<std::shared_ptr<Critter>>& critterList, std::vector<std::shared_ptr<Tower>>& towerList, std::vector<std::pair<Position, Position>> &road, int* playerLifee, int * playerMoney, std::shared_ptr<Grid> gridPtr);
	void addSprites(std::list<std::shared_ptr<Critter>>& critterList, const sf::Texture &texture);
	void addRouteSprites(std::vector<std::pair<Position, Position>> &road, const sf::Texture &texture);
	void updateSprites();
	void addNewTower();
	void addNotEnoughMoneyError();
	void playNotEnoughMoneySound();
	void removeTower(Position &towerPos);

	void closeWindow();
	void addNewSprites(std::list<std::shared_ptr<Critter>>& critterList);
	void TowerButtonsLogic();
	
};







