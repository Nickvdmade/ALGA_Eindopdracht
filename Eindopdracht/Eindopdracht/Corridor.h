#pragma once
#include "Piece.h"

class Corridor : public Piece
{
private:
	bool horizontal = false;
	bool vertical = false;
	bool collapsed = false;

public:
	Corridor(char);
	void Print();
};