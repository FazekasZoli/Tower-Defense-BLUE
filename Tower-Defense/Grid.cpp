#pragma once
#include "Grid.h"
#include <functional>
#include <string>

void Grid::saveGrid()
{
	std::vector<std::pair<Position, Position>> road;
		   
	std::ofstream outputFile;

	outputFile.open("TowerDefLoad.txt");
	if (!outputFile.is_open()) //hiba kezelés
	{
		std::cout << "Error";
		return;
	}

	for (int i = 0; i < road.size(); i++) // vegigmegyek a roadon és beleiratom a koordinatakat
	{
		outputFile << road[i].first.x << " " << road[i].first.y << " ";
		outputFile << road[i].second.x << " " << road[i].second.y << " ";
	}
	outputFile.close();

}

void Grid::loadGrid()
{//letrehozok egy load vectort amibe betöltöm a faljbol a pozikat
	std::ifstream reader;
	Position pos;
	std::vector<std::pair<Position, Position>> load;
	reader.open("TowerDefLoad.txt");
	if (!reader.is_open()) // hibakezeles
	{
		std::cout << "Error open ";
		return;
	}
			
	while (reader >> pos.x && reader >>pos.y && reader >> pos.x && reader >> pos.y) // addig megyek amig a vegere nem erek és a fájlban lévő x és y parokat betöltöm a load vectorba
	{
		load.emplace_back(std::make_pair(pos,pos));
	}
	//kiüritem a roadot és feltöltöm
	road.clear();
	for (int i = 0; i < load.size(); i++)
	{
		road.emplace_back(load[i]);
	}
		
	//ez alatt ami van az a teszteleshez kellett
	/*for (auto &it : road)
	{
		std::cout << it.first.x << it.first.y << "\n";
		std::cout << it.second.x << it.second.y << "\n";
	}*/
	//std::ofstream outputFile;
	//std::cout << " Kimkentem defload2" << std::endl; // tesztelés
	//outputFile.open("TowerDefLoad2.txt");
	//for (int i = 0; i < road.size(); i++) // vegigmegyek a roadon és beleiratom a koordinatakat
	//{
	//	outputFile << road[i].first.x << " " << road[i].first.y << " ";
	//	outputFile << road[i].second.x << " " << road[i].second.y << " ";
	//}

	reader.close();
}