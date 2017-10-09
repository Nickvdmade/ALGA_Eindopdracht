#pragma once

#include <iostream>

using namespace std;

class Room
{
private:
	int weight;
	char type;
	bool visited;
	bool shortPath;
	Room* north;
	Room* east;
	Room* south;
	Room* west;

public:
	Room(char);
	void AddNeighbours(Room* neighbours[4]);
	void Print();
	void PrintRight();
	void PrintDown();
};