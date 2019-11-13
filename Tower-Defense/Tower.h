#pragma once
#include <memory>

class Tower
{

public:
	std::shared_ptr<Tower> clone();
	
};