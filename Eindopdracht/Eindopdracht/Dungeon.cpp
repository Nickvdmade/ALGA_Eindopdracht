#include "Dungeon.h"

Dungeon::Dungeon(int y, int x)
{
	ySize = y;
	xSize = x;
	rooms = new Room**[y];
	for (int i = 0; i < ySize; i++)
		rooms[i] = new Room*[x];
}

Dungeon::~Dungeon()
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
			delete rooms[x][y];
	for (int y = 0; y < ySize; y++)
		delete rooms[y];
	delete rooms;
}

void Dungeon::FillDungeon() const
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
			if (y == 0 && x == 0)
				rooms[y][x] = new Room('S');
			else
			{
				if (y == ySize - 1 && x == xSize - 1)
					rooms[y][x] = new Room('E');
				else
					rooms[y][x] = new Room('D');
			}
	AddNeighbours();
}

void Dungeon::AddNeighbours() const
{
	Room* neighbours[4];
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
		{
			if (y == 0)
			{
				neighbours[0] = nullptr;
				neighbours[2] = rooms[y + 1][x];
			}
			else
			{
				if (y == ySize - 1)
				{
					neighbours[2] = nullptr;
					neighbours[0] = rooms[y - 1][x];
				}
				else
				{
					neighbours[0] = rooms[y - 1][x];
					neighbours[2] = rooms[y + 1][x];
				}
			}
			if (x == 0)
			{
				neighbours[3] = nullptr;
				neighbours[1] = rooms[y][x + 1];
			}
			else
			{
				if (x == xSize - 1)
				{
					neighbours[1] = nullptr;
					neighbours[3] = rooms[y][x - 1];
				}
				else
				{
					neighbours[3] = rooms[y][x - 1];
					neighbours[1] = rooms[y][x + 1];
				}
			}
			rooms[y][x]->AddNeighbours(neighbours);
		}
}

void Dungeon::SwapStart(int y, int x)
{
	int weight = rooms[y][x]->GetWeight();
	int type = rooms[y][x]->GetType();
	Room* start = FindStart();
	rooms[y][x]->SetWeight(0);
	rooms[y][x]->SetType('S');
	start->SetWeight(weight);
	start->SetType(type);
}

Room* Dungeon::FindStart()
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
			if (rooms[y][x]->GetType() == 'S')
				return rooms[y][x];
}

void Dungeon::SwapEnd(int y, int x)
{
	int weight = rooms[y][x]->GetWeight();
	int type = rooms[y][x]->GetType();
	Room* end = FindEnd();
	rooms[y][x]->SetWeight(0);
	rooms[y][x]->SetType('E');
	end->SetWeight(weight);
	end->SetType(type);
}

Room* Dungeon::FindEnd()
{
	for (int y = 0; y < ySize; y++)
		for (int x = 0; x < xSize; x++)
			if (rooms[y][x]->GetType() == 'E')
				return rooms[y][x];
}

void Dungeon::Print() const
{
	for (int y = 0; y < ySize * 2; y++)
	{
		for (int x = 0; x < xSize; x++)
		{
			if (y % 2 == 0)
			{
				rooms[y / 2][x]->Print();
				if (x != xSize - 1)
					rooms[y / 2][x]->PrintRight();
			}
			else
				if (y != ySize * 2 - 1)
					rooms[y / 2][x]->PrintDown();
		}
		cout << endl;
	}
}
