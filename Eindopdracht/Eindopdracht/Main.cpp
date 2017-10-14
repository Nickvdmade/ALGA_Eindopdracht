#include <sstream>
#include "Dungeon.h"
#include "BFS.h"

Dungeon* InitDungeon()
{
	string input = "";
	int x = 0, y = 0;
	cout << "Please enter width of dungeon:" << endl;
	cout << "-> ";
	getline(cin, input);
	stringstream(input) >> x;
	cout << endl;

	cout << "Please enter height of dungeon:" << endl;
	cout << "-> ";
	getline(cin, input);
	stringstream(input) >> y;

	Dungeon* dungeon = new Dungeon(y, x);
	return dungeon;
}

void SwapStart(Dungeon* dungeon) {
	string input = "";
	int x = 0, y = 0;
	
	while (x < 1 || x > dungeon->getWidth()) 
	{
		cout << "Please enter first digit:" << endl;
		cout << "-> ";
		getline(cin, input);
		stringstream(input) >> x;
		cout << endl;
	}
	while (y < 1 || y > dungeon->getHeight())
	{
		cout << "Please enter second digit:" << endl;
		cout << "-> ";
		getline(cin, input);
		stringstream(input) >> y;
	}
	dungeon->SwapStart(y, x);
}

void SwapEnd(Dungeon* dungeon) {
	string input = "";
	int x = 0, y = 0;

	while (x < 1 || x > dungeon->getWidth())
	{
		cout << "Please enter first digit:" << endl;
		cout << "-> ";
		getline(cin, input);
		stringstream(input) >> x;
		cout << endl;
	}
	while (y < 1 || y > dungeon->getHeight())
	{
		cout << "Please enter second digit:" << endl;
		cout << "-> ";
		getline(cin, input);
		stringstream(input) >> y;
	}
	dungeon->SwapEnd(y, x);
}

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
	//init
	cout << "Welcome to the Dungeon game." << endl;
	Dungeon* dungeon;

	string input = "";
	cout << "Would you like to determine the size of the dungeon? <yes/no>" << endl;
	cout << "-> ";
	getline(cin, input);
	if (input == "yes" || input == "y")
		dungeon = InitDungeon();
	else
		dungeon = new Dungeon(8, 8);

	dungeon->FillDungeon();
	cout << "press enter to continue";
	getchar();
	
	//swap start
	system("cls");
	cout << "Dungeon:" << endl;
	dungeon->Print();

	cout << "Would you like to swap the start of the dungeon? <yes / no>" << endl;
	cout << "-> ";
	getline(cin, input);
	if (input == "yes" || input == "y")
		SwapStart(dungeon);
	system("cls");
	cout << "Dungeon:" << endl;
	dungeon->Print();

	//swap end
	cout << "Would you like to swap the end of the dungeon? <yes / no>" << endl;
	cout << "-> ";
	getline(cin, input);
	if (input == "yes" || input == "y")
		SwapEnd(dungeon);
	system("cls");
	cout << "Dungeon:" << endl;
	dungeon->Print();
	cout << "press enter to continue";
	
	//start
	string choice = "";
	while (choice != "quit" && choice != "q")
	{
		ShowUI(dungeon);
		getline(cin, choice);
		if (choice == "talisman" || choice == "t")
		{
			cout << "talisman used" << endl;
			BFS* bfs = new BFS();
			bfs->BreathFirstSearch(0,0, dungeon);
			cout << "Exit is " << bfs->GetDepth() << " rooms away." << endl;
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