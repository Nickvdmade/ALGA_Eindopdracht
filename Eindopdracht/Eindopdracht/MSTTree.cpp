#include "MSTTree.h"

MSTTree::MSTTree()
{
	root = nullptr;
}

MSTTree::~MSTTree()
{
	delete root;
}

void MSTTree::AddNode(Room* room)
{
	if (root != nullptr)
		root->AddNode(room);
	else
	{
		MSTNode* node = new MSTNode(room);
		root = node;
	}
}
