#pragma once

#include <queue>
#include <set>
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
	void BreathFirstSearch(Dungeon*);
	//int GetSetDepth();
};
