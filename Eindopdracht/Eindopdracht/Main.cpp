#include "Dungeon.h"

void checkForLeaks()
{
#ifdef _DEBUG

	int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);

	flag |= _CRTDBG_LEAK_CHECK_DF;

	_CrtSetDbgFlag(flag);

#endif
}

void main()
{
	checkForLeaks();

	Dungeon *dungeon = new Dungeon(4,4);
	dungeon->FillDungeon();
	
	dungeon->Print();
	
	getchar();
	delete dungeon;
}