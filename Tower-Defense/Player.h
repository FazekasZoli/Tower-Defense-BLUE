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

	//GETTEREK: lek�rdez�st biztos�tja(ezzel jelen�tj�k majd meg a HUD-on az �letet �s a p�nzt, constans �rt�kek)
	int getLife() const;
	double getMoney() const;
	int *getLifePtr();
	int *getMoneyPtr();

	//SETTEREK: arra kell, hogy tudjuk m�dos�tani a Life �s a Money �rt�k�n.

	void setLife(int _life);
	void setMoney(double _money);

	// "hozz�ad / elvesz met�rusok" ha kell
	double sellTower(double _money);
	double buyTower(double _money);
	void addMoney(int moneyGot);

	//v�s�rl�s met�dusa
	//void pay(int _money);



};
