#include "iostream"
#include "func.h"

using namespace std;

int game()
{
	int gender = ranNum(0, 1); //Zero for male, One for female
	string fName = "";
	if (gender == 0)
	{
		fName = maleName();
	}
	if (gender == 1)
	{
		fName = femaleName();
	}
	string lName = lastName();
	cout << fName << " " << lName << endl;
	cout << "Gender: 0" << gender << endl;
}
