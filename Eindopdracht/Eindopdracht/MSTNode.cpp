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
	for each (MSTNode* node in nodes)
	{
		if (!HasNode(nodeRoom))
			node->AddNode(nodeRoom);
	}
}

bool MSTNode::HasNode(Room* findRoom) const
{
	if (room == findRoom)
		return true;
	bool hasNode = false;
	for each(MSTNode* node in nodes)
	{
		hasNode = node->HasNode(findRoom);
		if (hasNode)
			return true;
	}
	return hasNode;
}

Room* MSTNode::GetRoom() const
{
	return room;
}

bool MSTNode::HasConnection(Room* startRoom, Room* endRoom) const
{
	if (room == startRoom)
	{
		for each (MSTNode* node in nodes)
			if (node->GetRoom() == endRoom)
				return true;
	}
	else
		for each(MSTNode* node in nodes)
		{
			if (node->GetRoom() == startRoom)
			{
				if (room == endRoom)
					return true;
			}
			bool found = node->HasConnection(startRoom, endRoom);
			if (found)
				return found;
		}
	return false;
}
