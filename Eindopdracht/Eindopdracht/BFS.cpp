#include "BFS.h"

BFS::~BFS()
{
	delete visited;
}

void BFS::BreathFirstSearch(int y, int x, Dungeon* dungeon)
{
	dungeon->ClearVisited();
	dungeon->ClearShortestPath();
	ClearQueue();
	if (visited != nullptr)
		delete visited;
	Room* startPosition = dungeon->FindPosition(y - 1, x - 1);
	if (!startPosition->IsVisited())
	{
		roomQueue.push_back(startPosition);
		visited = new BFSTree();
		startPosition->SetVisited(true);
		Room* end = dungeon->FindEnd();
		while (roomQueue.back() != end)
		{
			Room* room = *roomQueue.begin();
			roomQueue.pop_front();
			visited->AddNode(room);
			room->SetVisited(true);

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
		end->SetVisited(true);
	}
}

int BFS::GetDepth() const
{
	return visited->GetDepth();
}

void BFS::ClearQueue()
{
	roomQueue.clear();
}
