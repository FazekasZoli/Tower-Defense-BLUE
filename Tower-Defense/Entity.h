#pragma once

#include <memory>
#include <cmath>

struct Position
{
	int x = 0;
	int y = 0;	

	Position() {}

	Position(int x, int y) : x(x), y(y)	{}

	Position(const Position& p) : x(p.x), y(p.y) {}

	//overloading
	bool operator==(const Position& p)
	{
		if (x == p.x && y == p.y)
		{
			return true;
		}
		return false;	
	}

	bool operator!=(const Position& p)
	{
		if (x != p.x && y != p.y)
		{
			return true;
		}
		return false;		
	}

	Position operator*=(int speed)
	{
		Position result(this->x, this->y);

		result.x *= speed;
		result.y *= speed;

		return result;	
	}

	Position operator+=(Position p)
	{
		x += p.x;
		y += p.y;

		return *this;	
	}


};

class Entity
{
protected:
	Position _pos;
	Position irany;
	int _cost;

public:
	Entity() : _pos({ 0, 0 }), _cost()
	{
	}

	Entity(int x, int y, int cost = 0)
		: _pos({ x, y }), _cost(cost)
	{}

	Entity(const Position& p, int cost = 0) : _pos(p), _cost(cost) {}

	int getCost() const { return _cost; };
	Position getPos() const { return _pos; };
	Position getDir() const { return irany; };

	void setPos(int x, int y, int dirX, int dirY) { _pos.x = x; _pos.y = y; irany.x = dirX; irany.y = dirY; }
	void setPosTw(Position pos) { _pos.x = pos.x; _pos.y = pos.y;}

	double distance(Position p)
	{
		double result = sqrt(pow((_pos.x + p.x), 2) + pow((_pos.y + p.y), 2));

		return result;
	}
	//virtual std::shared_ptr<Entity> clone() = 0;
};