#include "Dijkstra.h"

Dijkstra::Dijkstra(int y, int x)
{
	ySize = y;
	xSize = x;
	weights = new int*[y];
	directions = new string*[y];
	for (int i = 0; i < ySize; i++)
	{
		weights[i] = new int[x];
		directions[i] = new string[x];
		for (int j = 0; j < xSize; j++)
		{
			weights[i][j] = -1;
			directions[i][j] = "";
		}
	}
}

Dijkstra::~Dijkstra()
{
	for (int y = 0; y < ySize; y++)
	{
		delete weights[y];
	}
	delete weights;
	delete directions;
}

string Dijkstra::ShortestPath(Dungeon* dungeon, int y, int x)
{
	ResetDijkstra();
	dungeon->ClearShortestPath();
	dungeon->ClearVisited();
	y--;
	x--;
	weights[y][x] = 0;
	directions[y][x] = "start";
	Room* room = dungeon->FindPosition(y, x);
	queue.push_back(room);
	while (!queue.empty())
	{
		room = *queue.begin();
		queue.pop_front();
		CheckPosition(room, dungeon->GetPosition(room));
		AddToQueue(room);
	}
	return GetShortestPath(dungeon);
}

void Dijkstra::AddToQueue(Room* room)
{
	if (room->north != nullptr && !room->north->IsVisited() && find(queue.begin(), queue.end(), room->north) == queue.end())
	{
		queue.push_back(room->north);
	}
	if (room->east != nullptr && !room->east->IsVisited() && find(queue.begin(), queue.end(), room->east) == queue.end())
	{
		queue.push_back(room->east);
	}
	if (room->south != nullptr && !room->south->IsVisited() && find(queue.begin(), queue.end(), room->south) == queue.end())
	{
		queue.push_back(room->south);
	}
	if (room->west != nullptr && !room->west->IsVisited() && find(queue.begin(), queue.end(), room->west) == queue.end())
	{
		queue.push_back(room->west);
	}
}

void Dijkstra::CheckPosition(Room* room, int* position) const
{
	if (room->north != nullptr)
	{
		int weight = weights[position[0]][position[1]] + room->north->GetWeight();
		int northWeight = weights[position[0] - 1][position[1]];
		if (weight < northWeight || northWeight == -1)
		{
			weights[position[0] - 1][position[1]] = weight;
			directions[position[0] - 1][position[1]] = "north";
		}
	}
	if (room->east != nullptr)
	{
		int weight = weights[position[0]][position[1]] + room->east->GetWeight();
		int eastWeight = weights[position[0]][position[1] + 1];
		if (weight < eastWeight || eastWeight == -1)
		{
			weights[position[0]][position[1] + 1] = weight;
			directions[position[0]][position[1] + 1] = "east";
		}
	}
	if (room->south != nullptr)
	{
		int weight = weights[position[0]][position[1]] + room->south->GetWeight();
		int southWeight = weights[position[0] + 1][position[1]];
		if (weight < southWeight || southWeight == -1)
		{
			weights[position[0] + 1][position[1]] = weight;
			directions[position[0] + 1][position[1]] = "south";
		}
	}
	if (room->west != nullptr)
	{
		int weight = weights[position[0]][position[1]] + room->west->GetWeight();
		int westWeight = weights[position[0]][position[1] - 1];
		if (weight < westWeight || westWeight == -1)
		{
			weights[position[0]][position[1] - 1] = weight;
			directions[position[0]][position[1] - 1] = "west";
		}
	}
	room->SetVisited(true);
}

string Dijkstra::GetShortestPath(Dungeon* dungeon) const
{
	Room* end = dungeon->FindEnd();
	int* position = dungeon->GetPosition(end);
	string shortPath = "exit";
	while (directions[position[0]][position[1]] != "start")
	{
		shortPath = directions[position[0]][position[1]] + " - " + shortPath;
		Room* room = dungeon->FindPosition(position[0], position[1]);
		room->SetShortPath(true);
		if (directions[position[0]][position[1]] == "north")
			position[0]++;
		else if (directions[position[0]][position[1]] == "east")
			position[1]--;
		else if (directions[position[0]][position[1]] == "south")
			position[0]--;
		else if (directions[position[0]][position[1]] == "west")
			position[1]++;
	}
	shortPath = directions[position[0]][position[1]] + " - " + shortPath;
	Room* room = dungeon->FindPosition(position[0], position[1]);
	room->SetShortPath(true);
	return shortPath;
}

void Dijkstra::ResetDijkstra() const
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			weights[y][x] = -1;
			directions[y][x] = "";
		}
}
