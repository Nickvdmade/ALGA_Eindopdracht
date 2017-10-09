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

void Room::PrintRight()
{
	if (type == 'S' || type == 'E')
		cout << type;
	else
		cout << weight;
	if (east != null)
		if (eastCorridor)
			cout << '-';
		else
			cout << '~';
	else
		cout << ' ';
}

void Room::PrintDown()
{
	if (south != null)
		if (southCorridor)
			cout << '|';
		else
			cout << ':';
	else
		cout << ' ';
	cout << ' ';
}
