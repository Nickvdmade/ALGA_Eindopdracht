#include "BFSNode.h"

BFSNode::BFSNode(Room* nodeRoom)
{
	room = nodeRoom;
}

BFSNode::~BFSNode()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
}

bool BFSNode::Addnode(Room* nodeRoom)
{
	if (room->HasNeighbour(nodeRoom))
	{
		BFSNode* node = new BFSNode(nodeRoom);
		nodes.push_back(node);
		return true;
	}
	bool done = false;
	for (int i = 0; i < nodes.size(); i++)
	{
		done = nodes[i]->Addnode(nodeRoom);
	}
	return done;
}
