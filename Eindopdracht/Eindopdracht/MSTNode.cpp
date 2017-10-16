#include "MSTNode.h"

MSTNode::MSTNode(Room* nodeRoom)
{
	room = nodeRoom;
}

MSTNode::~MSTNode()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		delete nodes[i];
	}
}

void MSTNode::AddNode(Room* nodeRoom)
{
	if (room->HasNeighbour(nodeRoom))
	{
		MSTNode* node = new MSTNode(nodeRoom);
		nodes.push_back(node);
	}
	bool done = false;
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->AddNode(nodeRoom);
	}
}
