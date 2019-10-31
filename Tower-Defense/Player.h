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

	//GETTEREK: lek�rdez�st biztos�tja(ezzel jelen�tj�k majd meg a HUD-on az �letet �s a p�nzt, constans �rt�kek)
	int getLife() const;
	int getMoney() const;

	//SETTEREK: arra kell, hogy tudjuk m�dos�tani a Life �s a Money �rt�k�n.

	void setLife(int _life);
	void setMoney(int _money);

	// "hozz�ad / elvesz met�rusok" ha kell
	int addMoney(int _money);
	int removeMoney(int _money);

	//v�s�rl�s met�dusa
	//void pay(int _money);



};