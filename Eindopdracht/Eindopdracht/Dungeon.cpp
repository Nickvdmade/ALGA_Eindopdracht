#include "Dungeon.h"

Dungeon::Dungeon(int x, int y)
{
	xSize = x + x - 1;
	ySize = y + y - 1;
	rooms = new Piece**[x + x - 1];
	for (int i = 0; i < xSize; i++)
		rooms[i] = new Piece*[y + y - 1];
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
			else if (x % 2 == 0)
				rooms[x][y] = new Corridor('H');
			else if (y % 2 == 0)
				rooms[x][y] = new Corridor('V');
			else
				rooms[x][y] = new Piece();
		}
	}
}

void Dungeon::Print()
{
	for (int x = 0; x < xSize; x++)
	{
		for (int y = 0; y < ySize; y++)
		{
			rooms[x][y]->Print();
		}
		cout << endl;
	}
}
