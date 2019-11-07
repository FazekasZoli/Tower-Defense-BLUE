#pragma once

#include <memory>

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

	//virtual std::shared_ptr<Entity> clone() = 0;
};