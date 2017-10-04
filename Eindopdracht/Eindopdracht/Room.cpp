#include "Room.h"

Room::Room(char roomType)
{
	type = roomType;
	weight = rand() % 9 + 1;
	if (roomType == 'S' || roomType == 'E')
	{
		weight = 0;
	}
}

void Room::Print()
{
	if (type == 'S' || type == 'E')
		cout << type;
	else
		cout << weight;
}
