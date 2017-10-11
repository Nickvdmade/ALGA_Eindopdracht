#pragma once

#include "BFSNode.h"

class BFSTree
{
private:
	BFSNode* root;

public:
	BFSTree();
	~BFSTree();
	void AddNode(Room*);
};