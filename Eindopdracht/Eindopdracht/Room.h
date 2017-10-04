#pragma once
#include "Piece.h"

using namespace std;

class Room : public Piece
{
private:
	int weight;
	char type;
	bool visited;
	bool shortPath;

public:
	Room(char);
	void Print();
};