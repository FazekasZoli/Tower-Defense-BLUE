#pragma once

class Player
{
private:

	int life;
	int money;


public:

	//Player konstruktora
	Player(int _life, int _money) : life(_life), money(_money) {};

	//destruktor ha kell
	~Player();

	//GETTEREK: lekérdezést biztosítja(ezzel jelenítjük majd meg a HUD-on az életet és a pénzt, constans értékek)
	int getLife() const;
	int getMoney() const;

	//SETTEREK: arra kell, hogy tudjuk módosítani a Life és a Money értékén.

	void setLife(int _life);
	void setMoney(int _money);

	// "hozzáad / elvesz metórusok" ha kell
	int addMoney(int _money);
	int removeMoney(int _money);

	//vásárlás metódusa
	//void pay(int _money);



};
