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
	bool HasNode(Room*) const;
	bool HasConnection(Room*, Room*) const;
	Room* GetRoom() const;
};
