#pragma once
#include "Grid.h"
#include <functional>
#include <string>

void Grid::saveGrid()
{
	std::cout << " ASD" << std::endl;
	std::vector<std::pair<Position,  Position>> road;
	Position p1(0, 1);
	Position p2(2, 3);
	road.emplace_back(std::make_pair( p1 ,p2));
	
	
	std::ofstream outputFile;
	std::cout << " Megnyitom a fajlt" << std::endl;
	outputFile.open("TowerDefLoad.txt");
	if (!outputFile.is_open())
	{
		std::cout << "Error";
		return ;
		
	}

	for (int i = 0; i < road.size(); i++)
	{
		outputFile << road[i].first.x << "," << road[i].first.y << "\n";
		outputFile << road[i].second.x << "," << road[i].second.y << "\n";
	}
	outputFile.close();

}

void Grid::loadGrid()
{
	


	//std::ifstream reader;
	//reader.open("TowerDefLoad.txt");
	//while (!reader.eof())
	//{
	//	std::getline()
	//}

	//reader.close();
	std::ifstream in("TowerDefLoad.txt");
	std::string str;
	while (std::getline(in, str)
	{
	if(str.size () >0)

	
	}

	
}