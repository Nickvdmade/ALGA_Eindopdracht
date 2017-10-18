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

	void AddToQueue(Room*);
public:
	MST();
	~MST();
	void GenerateMinimumSpanningTree(Dungeon*);
	int HandGrenade(Dungeon*);
	
};
