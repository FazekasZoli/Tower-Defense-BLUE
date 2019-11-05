#pragma once

#include <memory>

struct Position
{
	int x = 0;
	int y = 0;

	Position() {}

	Position(int x, int y) : x(x), y(y)
	{
	}

	Position(const Position& p) : x(p.x), y(p.y) {}
};

class Entity
{
protected:
	Position _pos;
	int _cost;

public:
	Entity() : _pos({ 0, 0 }), _cost(0)
	{
	}

	Entity(int x, int y, int cost = 0)
		: _pos({ x, y }), _cost(cost)
	{}

	Entity(const Position& p, int cost = 0) : _pos(p), _cost(cost) {}

	int getCost() const { return _cost; };
	Position getPos() const { return _pos; };

	virtual std::unique_ptr<Entity> clone() = 0;
};