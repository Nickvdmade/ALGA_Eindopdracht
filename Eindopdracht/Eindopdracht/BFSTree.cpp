#include "BFSTree.h"

BFSTree::BFSTree()
{
	root = nullptr;
}

BFSTree::~BFSTree()
{
	delete root;
}

void BFSTree::AddNode(Room* room)
{
	if (root != nullptr)
		root->Addnode(room);
	else
	{
		BFSNode* node = new BFSNode(room);
		root = node;
	}
}

int BFSTree::GetDepth()
{
	return root->GetDepth() - 1;
}
