#include "BFS.h"

BFS::~BFS()
{
	delete visited;
}

void BFS::BreathFirstSearch(int y, int x, Dungeon* dungeon)
{
	Room* startPosition = dungeon->FindPosition(y, x);
	if (!startPosition->IsVisited())
	{
		roomQueue.push_back(startPosition);
		visited = new BFSTree();
		startPosition->Visited();
		Room* end = dungeon->FindEnd();
		while (roomQueue.back() != end)
		{
			Room* room = *roomQueue.begin();
			roomQueue.pop_front();
			visited->AddNode(room);
			room->Visited();

			if (room->north != nullptr && !room->north->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->north) == roomQueue.end())
			{
				if (room->north == end)
					break;
				roomQueue.push_back(room->north);
			}
			if (room->east != nullptr && !room->east->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->east) == roomQueue.end())
			{
				if (room->east == end)
					break;
				roomQueue.push_back(room->east);
			}
			if (room->south != nullptr && !room->south->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->south) == roomQueue.end())
			{
				if (room->south == end)
					break;
				roomQueue.push_back(room->south);
			}
			if (room->west != nullptr && !room->west->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->west) == roomQueue.end())
			{
				if (room->west == end)
					break;
				roomQueue.push_back(room->west);
			}
		}
		visited->AddNode(end);
		end->Visited();
	}
}

int BFS::GetDepth()
{
	return visited->GetDepth();
}
