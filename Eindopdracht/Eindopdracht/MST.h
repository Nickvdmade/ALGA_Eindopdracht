#pragma once

#include "MSTTree.h"
#include "Dungeon.h"
#include "MSTCorridor.h"

class MST
{
private:
	MSTTree* prim;
	vector<MSTCorridor*> queue;

public:
	MST();
	~MST();
	void GenerateMinimumSpanningTree(Dungeon*);
};
