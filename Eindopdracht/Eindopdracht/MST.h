#pragma once

#include "MSTTree.h"
#include "Dungeon.h"
#include "MSTCorridor.h"

class MST
{
private:
	MSTTree* prim;
	vector<MSTCorridor*> queue;
	vector<MSTCorridor*> collapse;

public:
	MST();
	~MST();
	void GenerateMinimumSpanningTree(Dungeon*);
	int HandGrenade(Dungeon*);
	void AddToQueue(Room*);
};
