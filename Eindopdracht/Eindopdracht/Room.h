#pragma once
#include <iostream>

using namespace std;

class Room
{
private:
	int weight;
	char type;
	bool north, east, west, south;
	bool visited;
	bool shortPath;

public:
	Room();
	void FillRoom(char);
	void Print();
};