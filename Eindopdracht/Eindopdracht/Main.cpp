#include "Dungeon.h"

void main()
{
	Dungeon *dungeon = new Dungeon(4,4);
	dungeon->FillDungeon();
	
	dungeon->Print();
	
	getchar();
	delete dungeon;

	_CrtDumpMemoryLeaks();
}