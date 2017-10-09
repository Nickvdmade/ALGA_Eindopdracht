#include "Dungeon.h"

Dungeon::Dungeon(int x, int y)
{
	xSize = x;
	ySize = y;
	rooms = new Room**[x];
	for (int i = 0; i < xSize; i++)
		rooms[i] = new Room*[y];
}

void Dungeon::FillDungeon()
{
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			if (x % 2 == 0 && y % 2 == 0)
			{
				if (x == 0 && y == 0)
					rooms[x][y] = new Room('S');
				else
				{
					if (x == xSize - 1 && y == ySize - 1)
						rooms[x][y] = new Room('E');
					else
						rooms[x][y] = new Room('D');
				}
			}
		}
	}
}

void Dungeon::Print()
{
	for (int x = 0; x < xSize * 2; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			if (x % 2 == 0)
				rooms[x / 2][y]->PrintRight();
			else
				rooms[x][y / 2]->PrintDown();
		}
		cout << endl;
	}
}
