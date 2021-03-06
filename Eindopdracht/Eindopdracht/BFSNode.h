#pragma once
#include <vector>
#include "Room.h"

using namespace std;

class BFSNode
{
private:
	Room* room;
	vector<BFSNode*> nodes;

public:
	BFSNode(Room*);
	~BFSNode();
	void AddNode(Room*);
	int GetDepth();
};
