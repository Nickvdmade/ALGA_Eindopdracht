#include "Room.h"

Room::Room(char roomType)
{
	type = roomType;
	weight = rand() % 10;
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

char Room::GetType()
{
	return type;
}

void Room::SetType(char roomType)
{
	type = roomType;
}

int Room::GetWeight()
{
	return weight;
}

void Room::SetWeight(int roomWeight)
{
	weight = roomWeight;
}

void Room::Print() const
{
	if (type == 'S' || type == 'E')
		cout << type;
	else
		cout << weight;
}

void Room::PrintRight() const
{
		if (east != nullptr)
		cout << '-';
	else
		cout << '~';
}

void Room::PrintDown() const
{
	if (south != nullptr)
		cout << '|';
	else
		cout << ':';
	cout << ' ';
}
