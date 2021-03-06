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

bool Room::HasNeighbour(Room* room) const
{
	if (room == north || room == east || room == south || room == west)
		return true;
	return false;
}

void Room::DeleteNeighbour(Room* room)
{
	if (north == room && north != nullptr)
	{
		north->south = nullptr;
		north = nullptr;
	}
	if (east == room && east != nullptr)
	{
		east->west = nullptr;
		east = nullptr;
	}
	if (south == room && south != nullptr)
	{
		south->north = nullptr;
		south = nullptr;
	}
	if (west == room && west != nullptr)
	{
		west->east = nullptr;
		west = nullptr;
	}
}

char Room::GetType() const
{
	return type;
}

void Room::SetType(char roomType)
{
	type = roomType;
}

int Room::GetWeight() const
{
	return weight;
}

void Room::SetWeight(int roomWeight)
{
	weight = roomWeight;
}

void Room::SetVisited(bool visit)
{
	visited = visit;
}

bool Room::IsVisited() const
{
	return visited;
}

void Room::SetShortPath(bool shortestPath)
{
	shortPath = shortestPath;
}

void Room::Print() const
{
	HANDLE hConsole;
	int colour = bWhite;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (visited)
		colour = bYellow;
	if (shortPath)
		colour = bRed;
	
	SetConsoleTextAttribute(hConsole, colour);
	if (type == 'S' || type == 'E')
		cout << type;
	else
		cout << weight;
	colour = bWhite;
	SetConsoleTextAttribute(hConsole, colour);
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
