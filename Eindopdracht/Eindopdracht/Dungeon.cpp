#include "Dungeon.h"

Dungeon::Dungeon(int x, int y)
{
	rooms = new Room*[x];
	for (int i = 0; i < x; i++)
		rooms[i] = new Room[y];
	xSize = x;
	ySize = y;
}

void Dungeon::FillDungeon()
{
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			if (x == 0 && y ==0)
				rooms[x][y].FillRoom('S');
			else if (x == xSize - 1 && y == ySize - 1)
				rooms[x][y].FillRoom('E');
			else
				rooms[x][y].FillRoom('D');
		}
	}
}

void Dungeon::Print()
{
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			rooms[x][y].Print();
		}
		cout << endl;
	}
}
