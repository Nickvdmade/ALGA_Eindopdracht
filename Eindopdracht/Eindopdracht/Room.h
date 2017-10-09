#pragma once

#include <iostream>
#include <stdio>
#include <stdlib>

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
	bool northCorridor;
	bool eastCorridor;
	bool southCorridor;
	bool westCorridor;

public:
	Room(char);
	void PrintRight();
	void PrintDown();
};