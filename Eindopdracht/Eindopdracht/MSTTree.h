#pragma once

#include "MSTNode.h"

class MSTTree
{
private:
	MSTNode* root;

public:
	MSTTree();
	~MSTTree();
	void AddNode(Room*);
};
