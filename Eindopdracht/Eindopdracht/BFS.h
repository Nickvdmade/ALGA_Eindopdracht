#pragma once

#include <queue>
#include "Room.h"
#include "Dungeon.h"
#include "BFSTree.h"

using namespace std;

class BFS
{
private:
	deque<Room*> roomQueue;
	BFSTree* visited;

public:
	~BFS();
	void BreathFirstSearch(int, int, Dungeon*);
	int GetDepth();
};
