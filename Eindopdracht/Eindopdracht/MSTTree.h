#pragma once

#include "MSTNode.h"
#include "MSTCorridor.h"

class MSTTree
{
private:
	MSTNode* root;

public:
	MSTTree();
	~MSTTree();
	void AddNode(Room*);
	bool HasNode(Room*) const;
	bool HasConnection(Room*, Room*) const;
};
