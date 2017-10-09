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

void Room::AddNeighbours(Room* neighbours[4])
{
	north = neighbours[0];
	east = neighbours[1];
	south = neighbours[2];
	west = neighbours[3];
}

void Room::Print()
{
	if (type == 'S' || type == 'E')
		cout << type;
	else
		cout << weight;
}

void Room::PrintRight()
{
		if (east != nullptr)
		cout << '-';
	else
		cout << '~';
}

void Room::PrintDown()
{
	if (south != nullptr)
		cout << '|';
	else
		cout << ':';
	cout << ' ';
}
