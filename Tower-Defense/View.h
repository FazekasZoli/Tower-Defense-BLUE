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

#include "Critter.h"
#include "Tower.h"
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
	void setStateVar(bool);
	//void setText(std::string);
	bool getVar();
	void initialize(sf::Texture* normal, sf::Texture* clicked, sf::Vector2f location, ButtonType ownType);
	sf::Sprite* getSprite();
	sf::Sprite* getSpriteNorm();
	//sf::String * getText();
	ButtonType getType();

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
	void draw(sf::RenderWindow * window);
	Button* getUpgradeButton() { return &upgradeButton; };
	Button* getSellButton() { return &sellButton; };
	static TowerButtons* SelectedTower;
	bool checkClickTower(sf::Vector2f mousePos);


private:
	
	Button upgradeButton;
	Button sellButton;

};




class View : public ViewEvents
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
	sf::Texture newEntityFront;
	sf::Texture newEntityBack;
	sf::Texture newEntityLeft;
	sf::Texture newEntityRight;
	sf::Texture upgradeButtonTex;
	sf::Texture sellButtonTex;
	sf::Sprite spriteBG;

	
	std::list<std::shared_ptr<Critter>>* crittersPtr;
	std::vector<std::shared_ptr<Tower>>* towersPtr;
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Sprite> RoadSprites;
	std::vector<sf::Sprite> towerSprites;
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
	sf::CircleShape radius;
	int baseRadius = 100;

	int* playerLife;
	int* playerMoneyV;
	sf::Text playerLifeText;
	sf::Text playerLifeRizsa;
	sf::Text playerMoneyText;
	sf::Text playerMoneyRizsa;
	sf::Font font;


public:
	//View() :window(sf::VideoMode(1000, 800), "Proba") {};
	void displayIntro();
	void displayMenu(int numberOfRoads);
	//A mentett palyak �s a bet�ltendo p�ly�k hasonl�an t�rolhat�ak(pl a new game tartalmazza ugyanazokat mint a mentett csak adott kezdo �rt�kekkel)
	//�gy az enummal adhatjuk meg �ppen mit �rjon ki a select level, ut�na ugyan�gy ind�tja el a p�ly�t
	void displayLevelSelect(LevelSelectMode mode, std::vector<std::string> &betoltendoPalya, int numberOfMaps);
	void displayGameOver(GameEnd status);
	//void graphic();
	void updateGraphic();
	void setUpDisplay(std::list<std::shared_ptr<Critter>>& critterList, std::vector<std::shared_ptr<Tower>>& towerList, std::vector<std::pair<Position, Position>> &road, int* playerLifee, int * playerMoney);
	void addSprites(std::list<std::shared_ptr<Critter>>& critterList, const sf::Texture &texture);
	void addRouteSprites(std::vector<std::pair<Position, Position>> &road, const sf::Texture &texture);
	void updateSprites();
	void addNewTower();

	void closeWindow();
	void addNewSprites(std::list<std::shared_ptr<Critter>>& critterList);
	void TowerButtonsLogic();
	
};







