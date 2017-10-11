#include "BFS.h"

BFS::~BFS()
{
	delete visited;
}

void BFS::BreathFirstSearch(Dungeon* dungeon)
{
	roomQueue.push_back(dungeon->FindStart());
	visited = new BFSTree();
	dungeon->FindStart()->Visited();
	Room* end = dungeon->FindEnd();
	while (roomQueue.back() != end)
	{
		Room* room = *roomQueue.begin();
		roomQueue.pop_front();
		visited->AddNode(room);
		room->Visited();

		if (room->north != nullptr && !room->north->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->north) == roomQueue.end())
			roomQueue.push_back(room->north);
		if (room->east != nullptr && !room->east->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->east) == roomQueue.end())
			roomQueue.push_back(room->east);
		if (room->south != nullptr && !room->south->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->south) == roomQueue.end())
			roomQueue.push_back(room->south);
		if (room->west != nullptr && !room->west->IsVisited() && find(roomQueue.begin(), roomQueue.end(), room->west) == roomQueue.end())
			roomQueue.push_back(room->west);
	}
	visited->AddNode(roomQueue.back());
	roomQueue.back()->Visited();
}

/*int BFS::GetSetDepth()
{
	
}*/
