#pragma once

#include "Dungeon.h"
#include <deque>

class Dijkstra
{
private:
	int** weights;
	string** directions;
	deque<Room*> queue;
	int ySize;
	int xSize;

	void AddToQueue(Room*);
	void CheckPosition(Room*, int*) const;
	string GetShortestPath(Dungeon*) const;
	void ResetDijkstra() const;

public:
	Dijkstra(int, int);
	~Dijkstra();
	string ShortestPath(Dungeon*, int, int);
};
