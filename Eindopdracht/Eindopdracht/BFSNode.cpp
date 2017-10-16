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

void BFSNode::AddNode(Room* nodeRoom)
{
	if (room->HasNeighbour(nodeRoom))
	{
		BFSNode* node = new BFSNode(nodeRoom);
		nodes.push_back(node);
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i]->AddNode(nodeRoom);
	}
}

int BFSNode::GetDepth()
{
	vector<int> heights;
	for (int i = 0; i < nodes.size(); i++)
	{
		heights.push_back(nodes[i]->GetDepth());
	}
	int height = 0;
	for (int i = 0; i < heights.size(); i++)
		if (heights[i] > height)
			height = heights[i];
	return height + 1;
}
