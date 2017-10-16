#pragma once

#include <vector>
#include "Room.h"

class MSTNode
{
	Room* room;
	vector<MSTNode*> nodes;

public:
	MSTNode(Room*);
	~MSTNode();
	void AddNode(Room*);
};
