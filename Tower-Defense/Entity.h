#pragma once

class Entity
{
	private:

		double x, y;
		int _cost;

	public:

		Entity(double x, double y, int _cost)
			: x(x), y(y), _cost(_cost)
		{}

		double getX();
		double getY();
		int getCost();


};