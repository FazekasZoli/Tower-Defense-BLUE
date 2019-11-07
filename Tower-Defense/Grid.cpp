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
{//létrehoztam 6 position-t 3 pályához aminek 2 koordinataja van egyenlőre

	

	std::ifstream reader;
	reader.open("TowerDefLoad.txt");
	if (!reader.is_open()) // hibakezeles
	{
		std::cout << "Error open ";
		return;
	}
	//tmp az ideiglenes
	int tmpX1;
	int tmpY1;
	int tmpX2;
	int tmpY2;
	int tmpX3;
	int tmpY3;
	int tmpX4;
	int tmpY4;
	int tmpX5;
	int tmpY5;
	int tmpX6;
	int tmpY6;
	
	Position p1;
	Position p2;
	Position p3;
	Position p4;
	Position p5;
	Position p6;
	
	
	while (!reader.eof()) // addig megyek amig a vegere nem erek
	{//reader feltolti a tmp-ket majd alatta kapja meg az ertekeket
		reader >> tmpX1;
		reader >> tmpY1;
		reader >> tmpX2;
		reader >> tmpY2;
		reader >> tmpX3;
		reader >> tmpY3;
		reader >> tmpX4;
		reader >> tmpY4;
		reader >> tmpX5;
		reader >> tmpY5;
		reader >> tmpX6;
		reader >> tmpY6;
		p1.x = tmpX1;
		p1.y = tmpY1;
		p2.x = tmpX2;
		p2.y = tmpY2;
		p3.x = tmpX3;
		p3.y = tmpY3;
		p4.x = tmpX4;
		p4.y = tmpY4;
		p5.x = tmpX5;
		p5.y = tmpY5;
		break;
	}//kiüritem a roadot és feltöltöm
	road.clear();
	road.emplace_back(p1, p2);
	road.emplace_back(p3, p4);
	road.emplace_back(p5, p6);

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