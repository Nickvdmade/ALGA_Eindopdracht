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
	Room* startRoom = dungeon->FindStart();
	prim->AddNode(startRoom);
	if (startRoom->north != nullptr)
	{
		MSTCorridor* north = new MSTCorridor(startRoom, startRoom->north);
		queue.push_back(north);
	}
	if (startRoom->east != nullptr)
	{
		MSTCorridor* east = new MSTCorridor(startRoom, startRoom->east);
		queue.push_back(east);
	}
	if (startRoom->south != nullptr)
	{
		MSTCorridor* south = new MSTCorridor(startRoom, startRoom->south);
		queue.push_back(south);
	}
	if (startRoom->west != nullptr)
	{
		MSTCorridor* west = new MSTCorridor(startRoom, startRoom->west);
		queue.push_back(west);
	}
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
	}
}
