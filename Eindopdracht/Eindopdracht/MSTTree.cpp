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
	{
		if (!root->HasNode(room))
			root->AddNode(room);
	}
	else
	{
		MSTNode* node = new MSTNode(room);
		root = node;
	}
}

bool MSTTree::HasNode(Room* room) const
{
	return root->HasNode(room);
}

bool MSTTree::HasConnection(Room* startRoom, Room* endRoom) const
{
	return root->HasConnection(startRoom, endRoom);
}
