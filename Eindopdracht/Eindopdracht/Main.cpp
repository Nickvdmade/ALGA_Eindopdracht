#include <sstream>
#include "Dungeon.h"
#include "BFS.h"
#include "MST.h"
#include "Dijkstra.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
Dungeon* dungeon;
BFS* bfs;
MST* mst;
Dijkstra* dijkstra;

void SetColour(int colour)
{
	SetConsoleTextAttribute(hConsole, colour);
}

Dungeon* InitDungeon()
{
	string input = "";
	int x = 0, y = 0;

	while (x < 2 || x > 10)
	{
		cout << "Please enter width of dungeon:";
		SetColour(bRed);
		cout << " <min = 2, max = 10>" << endl;
		SetColour(bWhite);
		cout << "-> ";
		getline(cin, input);
		stringstream(input) >> x;
	}

	while (y < 2 || y > 10)
	{
		cout << "Please enter height of dungeon:";
		SetColour(bRed);
		cout << " <min = 2, max = 10>" << endl;
		SetColour(bWhite);
		cout << "-> ";
		getline(cin, input);
		stringstream(input) >> y;
	}

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

void ShowUI(Dungeon* dungeon, string message)
{
	system("cls");
	SetColour(bWhite);
	cout << "Legend:" << endl;
	SetColour(bYellow);
	cout << "- Blue room: Visited room" << endl;
	SetColour(bRed);
	cout << "- Red room: Room is part of shortest path" << endl;
	SetColour(bWhite);
	cout << "- White room: Normal room" << endl;
	cout << endl;
	dungeon->Print();
	SetColour(bGreen);
	cout << message << endl << endl;
	SetColour(bWhite);
	cout << "You have the following choices:" << endl;
	cout << "- talisman" << endl;
	cout << "- handgrenade" << endl;
	cout << "- compass" << endl;
	cout << "- new dungeon" << endl;
	cout << "- quit" << endl;
	cout << endl;
	cout << "-> ";
}

void InitGame()
{
	system("cls");
	//init
	SetColour(bWhite);
	cout << "Welcome to the Dungeon game." << endl << endl;

	string input = "";
	cout << "Would you like to determine the size of the dungeon? <yes/no>" << endl;
	cout << "Standard size is 8 by 8" << endl << endl;
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

	cout << "Would you like to swap the start of the dungeon? <yes / no>" << endl << endl;
	cout << "-> ";
	getline(cin, input);
	if (input == "yes" || input == "y")
		SwapStart(dungeon);
	system("cls");
	cout << "Dungeon:" << endl;
	dungeon->Print();

	//swap end
	cout << "Would you like to swap the end of the dungeon? <yes / no>" << endl << endl;
	cout << "-> ";
	getline(cin, input);
	if (input == "yes" || input == "y")
		SwapEnd(dungeon);
	system("cls");
	cout << "Dungeon:" << endl;
	dungeon->Print();
	cout << "press enter to continue";
	bfs = new BFS();
	mst = new MST();
	dijkstra = new Dijkstra(dungeon->getHeight(), dungeon->getWidth());
}

void main()
{
	//start game
	string choice = "";
	string message = "";
	InitGame();

	while (choice != "quit" && choice != "q")
	{
		ShowUI(dungeon, message);
		getline(cin, choice);
		if (choice == "talisman" || choice == "t")
		{
			string input = "";
			int x = 0, y = 0;
			while (x < 1 || x > dungeon->getWidth())
			{
				cout << "Please enter first digit: (between 1 and " << dungeon->getWidth() << ")" << endl;
				cout << "-> ";
				getline(cin, input);
				stringstream(input) >> x;
			}
			while (y < 1 || y > dungeon->getHeight())
			{
				cout << "Please enter second digit: (between 1 and " << dungeon->getHeight() << ")" << endl;
				cout << "-> ";
				getline(cin, input);
				stringstream(input) >> y;
			}
			bfs->BreathFirstSearch(y, x, dungeon);
			message = "Talisman used, exit is " + to_string(bfs->GetDepth()) + " rooms away.";
			
		}
		else if (choice == "handgrenade" || choice == "h")
		{
			mst->GenerateMinimumSpanningTree(dungeon);
			int collapseAmount = mst->HandGrenade(dungeon);
			if (collapseAmount != 0)
				message = "Handgrenade used, " + to_string(collapseAmount) + " corridors have collapsed.";
			else
				message = "Handgrenade can't be used, crucial corridors would collapse.";
		}
		else if (choice == "compass" || choice == "c")
		{
			string input = "";
			int x = 0, y = 0;
			while (x < 1 || x > dungeon->getWidth())
			{
				cout << "Please enter first digit: (between 1 and " << dungeon->getWidth() << ")" << endl;
				cout << "-> ";
				getline(cin, input);
				stringstream(input) >> x;
			}
			while (y < 1 || y > dungeon->getHeight())
			{
				cout << "Please enter second digit: (between 1 and " << dungeon->getHeight() << ")" << endl;
				cout << "-> ";
				getline(cin, input);
				stringstream(input) >> y;
			}
			message = "Compass used, directions are:\n" + dijkstra->ShortestPath(dungeon, y, x) + ".";
		}
		else if(choice == "new dungeon" || choice == "n")
		{
			delete bfs;
			delete mst;
			delete dijkstra;
			delete dungeon;
			InitGame();
		}
		else if(choice != "quit" && choice != "q")
		{
			message = "Invalid input";
		}
	}

	delete bfs;
	delete mst;
	delete dijkstra;
	delete dungeon;
}