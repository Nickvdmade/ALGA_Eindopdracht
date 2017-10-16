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
	void FillDungeon() const;
	void AddNeighbours() const;
	void SwapStart(int, int);
	Room* FindStart();
	void SwapEnd(int, int);
	Room* FindEnd();
	Room* FindPosition(int, int) const;
	void Print() const;
	int getWidth();
	int getHeight();
	void ClearVisited();
};