#pragma once
#include "Room.h"

class Dungeon
{
private:
	Room **rooms;
	int xSize, ySize;

public:
	Dungeon(int, int);
	void FillDungeon();
	void Print();
};