#pragma once

class Player
{
private:

	int life;
	int money;


public:

	//Player konstruktora
	Player(int _life = 5, int _money = 100) : life(_life), money(_money) {};

	//destruktor ha kell
	~Player() {}

	//GETTEREK: lekérdezést biztosítja(ezzel jelenítjük majd meg a HUD-on az életet és a pénzt, constans értékek)
	int getLife() const;
	int getMoney() const;
	int *getLifePtr();
	int *getMoneyPtr();

	//SETTEREK: arra kell, hogy tudjuk módosítani a Life és a Money értékén.

	void setLife(int _life);
	void setMoney(int _money);

	// "hozzáad / elvesz metórusok" ha kell
	int sellTower(int _money);
	int buyTower(int _money);

	//vásárlás metódusa
	//void pay(int _money);



};
