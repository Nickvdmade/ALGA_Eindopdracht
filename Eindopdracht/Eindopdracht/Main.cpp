#include "Dungeon.h"

void ShowUI(Dungeon* dungeon)
{
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int colour = white;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "Legend:" << endl;
	colour = blue;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- Blue room: Visited room" << endl;
	colour = red;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- Red room: Room is part of shortest path" << endl;
	colour = purple;
	SetConsoleTextAttribute(hConsole, colour);
	cout << "- Purple room: Room is visited and part of shortest path" << endl;
	colour = white;
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
	Dungeon* dungeon = new Dungeon(4,4);
	dungeon->FillDungeon();
	
	string choice = "";
	while (choice != "quit")
	{
		ShowUI(dungeon);
		getline(cin, choice);
		if (choice == "talisman")
		{
			cout << "talisman used" << endl;
		}
		if (choice == "handgrenade")
		{
			cout << "handgrenade used" << endl;
		}
		if (choice == "compass")
		{
			cout << "compass used" << endl;
		}
		if (choice != "quit")
		{
			cout << "press enter to continue";
			getchar();
		}
	}

	delete dungeon;

	_CrtDumpMemoryLeaks();
}