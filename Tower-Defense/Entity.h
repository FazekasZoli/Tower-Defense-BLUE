#pragma once

//#include <memory>
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
	Position pos;
	Position dir;
	int cost;

public:
	Entity() : pos({ 0, 0 }), cost()
	{}

	Entity(int x, int y, int cost = 0)
		: pos({ x, y }), cost(cost)
	{}

	Entity(int cost =  0)
		: cost(cost)
	{}

	Entity(const Position& p, int cost) : pos(p), cost(cost) {}

	int getCost() const { return cost; };
	Position getPos() { return pos; };
	Position getDir() const { return dir; };

	void setPos(int x, int y, int dirX, int dirY) { pos.x = x; pos.y = y; dir.x = dirX; dir.y = dirY; }
	void setPosTw(Position newPos) { this->pos.x = newPos.x; this->pos.y = newPos.y;}

	double distance(Position &p)
	{
		double result = sqrt(pow((pos.x - p.x), 2) + pow((pos.y - p.y), 2));

		return result;
	}
	//virtual std::shared_ptr<Entity> clone() = 0;
};