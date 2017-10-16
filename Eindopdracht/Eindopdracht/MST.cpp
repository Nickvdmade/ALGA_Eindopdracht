#include "MST.h"

MST::MST()
{
	prim = new MSTTree();
}

MST::~MST()
{
	delete prim;
}

void MST::GenerateMinimumSpanningTree(Dungeon* dungeon)
{
	queue.clear();
	Room* startRoom = dungeon->FindStart();
	prim->AddNode(startRoom);
	AddToQueue(startRoom);
	while(!queue.empty())
	{
		vector<MSTCorridor*>::iterator deleteCorridor = queue.begin();
		for (vector<MSTCorridor*>::iterator it = queue.begin(); it != queue.end(); it++)
		{
			MSTCorridor* current = *deleteCorridor;
			MSTCorridor* iterator = *it;
			if (current->GetWeight() > iterator->GetWeight())
				deleteCorridor = it;
		}
		MSTCorridor* nextCorridor = *deleteCorridor;
		prim->AddNode(nextCorridor->GetEndRoom());
		queue.erase(deleteCorridor);
		AddToQueue(nextCorridor->GetEndRoom());
		delete nextCorridor;
	}
}

int MST::HandGrenade(Dungeon* dungeon)
{
	collapse.clear();
	for (int y = 0; y < dungeon->getHeight(); y++)
	{
		for (int x = 0; x < dungeon->getWidth(); x++)
		{
			Room* room = dungeon->FindPosition(y, x);
			if (room->north != nullptr)
			{
				if (!prim->HasConnection(room, room->north))
				{
					MSTCorridor* north = new MSTCorridor(room, room->north);
					collapse.push_back(north);
				}
			}
			if (room->east != nullptr)
			{
				if (!prim->HasConnection(room, room->east))
				{
					MSTCorridor* east = new MSTCorridor(room, room->east);
					collapse.push_back(east);
				}
			}
			if (room->south != nullptr)
			{
				if (!prim->HasConnection(room, room->south))
				{
					MSTCorridor* south = new MSTCorridor(room, room->south);
					collapse.push_back(south);
				}
			}
			if (room->west != nullptr)
			{
				if (!prim->HasConnection(room, room->west))
				{
					MSTCorridor* west = new MSTCorridor(room, room->west);
					collapse.push_back(west);
				}
			}
		}
	}
	int collapseAmount = rand() % 6 + 10;
	if (collapseAmount > collapse.size())
		collapseAmount = collapse.size();
	for (int i = 0; i < collapseAmount; i++)
		collapse[i]->Collapse();
	return collapseAmount;
}

void MST::AddToQueue(Room* room)
{
	if (room->north != nullptr && !prim->HasNode(room->north))
	{
		MSTCorridor* north = new MSTCorridor(room, room->north);
		queue.push_back(north);
	}
	if (room->east != nullptr && !prim->HasNode(room->east))
	{
		MSTCorridor* east = new MSTCorridor(room, room->east);
		queue.push_back(east);
	}
	if (room->south != nullptr && !prim->HasNode(room->south))
	{
		MSTCorridor* south = new MSTCorridor(room, room->south);
		queue.push_back(south);
	}
	if (room->west != nullptr && !prim->HasNode(room->west))
	{
		MSTCorridor* west = new MSTCorridor(room, room->west);
		queue.push_back(west);
	}
}
