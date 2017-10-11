#include "Dungeon.h"
#include "BFS.h"

void ShowUI(Dungeon* dungeon)
{
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int colour = bWhite;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "Legend:" << endl;
	colour = bBlue;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- Blue room: Visited room" << endl;
	colour = bRed;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- Red room: Room is part of shortest path" << endl;
	colour = bPurple;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- Purple room: Room is visited and part of shortest path" << endl;
	colour = bWhite;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- White room: Normal room" << endl;
	cout << endl;
	dungeon->Print();
	cout << "You have the following choices:" << endl;
	cout << "- talisman" << endl;
	cout << "- handgrenade" << endl;
	cout << "- compass" << endl;
	cout << "- quit" << endl;
	cout << endl;
	cout << "-> ";
}

void main()
{
	Dungeon* dungeon = new Dungeon(4,7);
	dungeon->FillDungeon();
	
	string choice = "";
	while (choice != "quit" && choice != "q")
	{
		ShowUI(dungeon);
		getline(cin, choice);
		if (choice == "talisman" || choice == "t")
		{
			cout << "talisman used" << endl;
			dungeon->SwapEnd(4, 4);
			BFS* bfs = new BFS();
			bfs->BreathFirstSearch(dungeon);
			delete bfs;
		}
		else if (choice == "handgrenade" || choice == "h")
		{
			cout << "handgrenade used" << endl;
		}
		else if (choice == "compass" || choice == "c")
		{
			cout << "compass used" << endl;
		}
		else if(choice != "quit" && choice != "q")
		{
			cout << "invalid input" << endl;
		}
		cout << "press enter to continue";
		getchar();
		
	}

	delete dungeon;

	_CrtDumpMemoryLeaks();
}