#pragma once

#include "Room.h"

class Dungeon
{
private:
	Room ***rooms;
	int ySize, xSize;

public:
	Dungeon(int, int);
	~Dungeon();
	void FillDungeon();
	void AddNeighbours();
	void Print();
};