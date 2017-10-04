#pragma once
#include "Piece.h"
#include "Room.h"
#include "Corridor.h"

class Dungeon
{
private:
	Piece ***rooms;
	int xSize, ySize;

public:
	Dungeon(int, int);
	void FillDungeon();
	void Print();
};