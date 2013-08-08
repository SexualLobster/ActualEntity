#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iomanip>

#define MNAMES	5
#define FNAMES	5
#define LNAMES	5

using namespace std;

int ranNum(int min, int max)
{
	return (rand() % (max - min + 1)) + min;
}

string maleName()
{
	ifstream infile("maleNames.txt");
	if (!infile)
	{
		cout << "Could not open file: maleNames.txt" << endl;
		return "Fatal Error";
	}
	vector<string> lines;
	string line;
	unsigned int lineNo = 1;
	lineNo = ranNum(1, MNAMES);
	while (lineNo != 0)
	{
		getline(infile, line);
		lines.push_back(line);
		lineNo--;
	}
	if (line == "")
	{
		cout << "Error: Could not get male first name." << endl;
	}
	infile.close();
	return line;
}
string femaleName()
{
	ifstream infile("femaleNames.txt");
	if (!infile)
	{
		cout << "Could not open file: femaleNames.txt" << endl;
		return "Fatal Error";
	}
	vector<string> lines;
	string line;
	unsigned int lineNo = 1;
	lineNo = ranNum(1, FNAMES);
	while (lineNo != 0)
	{
		getline(infile, line);
		lines.push_back(line);
		lineNo--;
	}
	if (line == "")
	{
		cout << "Error: Could not get female first name." << endl;
	}
	infile.close();
	return line;
}
string lastName()
{
	ifstream infile("lastNames.txt");
	if (!infile)
	{
		cout << "Could not open file: lastNames.txt" << endl;
		return "Fatal Error";
	}
	vector<string> lines;
	string line;
	unsigned int lineNo = 1;
	lineNo = ranNum(1, LNAMES);
	while (lineNo != 0)
	{
		getline(infile, line);
		lines.push_back(line);
		lineNo--;
	}
	if (line == "")
	{
		cout << "Error: Could not get last name." << endl;
	}
	infile.close();
	return line;
}
