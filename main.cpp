#include "iostream"
#include <ctime>
#include <cstdlib>
#include "game.h"

using namespace std;

int info(void)
{
	cout << "Actual Entity is Copyright 2011-2013 Exocom\n";
}

int help(void)
{
	cout << "Please consult the readme.txt that should have came with AE\n";
}

int main()
{
	srand(time(NULL));
	cout << "Welcome to Actual Entity!\n";
	string menuChoice = "";
	bool playing = true;
	while (playing == true)
	{
		cout << ">Game\n>Info\n>Help\n>Quit\n";
		getline(cin, menuChoice);
		if (menuChoice == "info")
		{
			info();
		}
		if (menuChoice == "help")
		{
			help();
		}
		if (menuChoice == "game")
		{
			playing = game();
		}
		if (menuChoice == "quit")
		{
			playing = false;
		}
	}
	return 0;
}
