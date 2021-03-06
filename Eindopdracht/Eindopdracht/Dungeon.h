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
	int* GetPosition(Room*);
	void Print() const;
	int getWidth() const;
	int getHeight() const;
	void ClearVisited() const;
	void ClearShortestPath() const;
};