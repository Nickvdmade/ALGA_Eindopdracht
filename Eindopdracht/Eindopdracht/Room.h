#pragma once

#include <iostream>
#include <Windows.h>
#include <string>

#include "ColourCodes.h"

using namespace std;

class Room
{
private:
	int weight;
	char type;
	bool visited;
	bool shortPath;
	
public:
	Room* north;
	Room* east;
	Room* south;
	Room* west;

	Room(char);
	void AddNeighbours(Room*[4]);
	bool HasNeighbour(Room*) const;
	void DeleteNeighbour(Room*);
	char GetType() const;
	void SetType(char);
	int GetWeight() const;
	void SetWeight(int);
	void SetVisited(bool);
	bool IsVisited() const;
	void SetShortPath(bool);
	void Print() const;
	void PrintRight() const;
	void PrintDown() const;
};