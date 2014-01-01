#include <iostream>
#include "func.cpp"

#define SCHOOL_AGE 6
#define SCHOOL_GRAD_AGE 18
#define MAX_CMD 3

using namespace std;

int game(int argc, char** argv)
{
	class Person
	{
	public:

		string fName;
		//string mName; //No middle name yet; I'll do it in the future; Middle names are useless
		string lName;

		int gender; //0 Male, 1 female.
		unsigned int age;
		int deathAge;
		bool alive;
		int hereditaryLifespan;
		int intel;
		int grade;
		int schoolState; // 0 = no school, 1 = in school, 2 = highschool grad, 3 = in college, 4 = college grad

		//int familyMoney = 0;



		void printStats()
		{
			cout << "First name:\t" << fName << "." << endl;
			cout << "Last name:\t" << lName << "." << endl;
			cout << "Gender:\t\t" << gender << ". ~ 0 = male, 1 = female." << endl;
			cout << "Age:\t\t" << age << "." << endl;
			cout << "Death age:\t" << deathAge << "." << endl;
			cout << "Intel:\t\t" << intel << "." << endl;
		}
	};

	Person cPlayer;
	Person cMother;
	Person cFather;

	cMother.hereditaryLifespan = ranNum(-20, 20);
	cFather.hereditaryLifespan = ranNum(-20, 20);
	cPlayer.hereditaryLifespan = (cFather.hereditaryLifespan + cMother.hereditaryLifespan) / 2;

	cMother.age = ranNum(18, 45); // Old floor/ceiling is 40/61
	cFather.age = ranNum((cMother.age / 2 + 7), 55);
	cFather.lName = name(2);
	cMother.lName = cFather.lName; //TODO: Skanks!
	cPlayer.gender = ranNum(0, 1); //Zero for male, One for female
	cPlayer.lName = cFather.lName;
	cPlayer.fName = name(cPlayer.gender);

	cFather.intel = ranNum(20, 80);
	cMother.intel = ranNum(20, 80);
	cPlayer.intel = (cFather.intel + cMother.intel) / 2;
	
	cMother.deathAge = (50 + cMother.hereditaryLifespan);
	cFather.deathAge = (45 + cFather.hereditaryLifespan);
	
	//Too lazy to implement otherwise.
	//cPlayer.gender--;
	cPlayer.deathAge = (75 + (5 * cPlayer.gender)) - cPlayer.hereditaryLifespan; 
	//cPlayer.gender++; //^If you are a female, you get 5 more years on average
	cPlayer.age = 0;

	int cmdCount = 0;
	string cmd = "";
	cout << "You are " << cPlayer.fName << " " << cPlayer.lName << "." << endl;
	while (cPlayer.alive == true)
	{
		if (cPlayer.age == SCHOOL_GRAD_AGE)
		{
			if (cPlayer.grade > 59)
			{
				cout << "Holy Jesus! You graduated!" << endl;
				cPlayer.schoolState++;
			}
			if (cPlayer.grade < 60)
			{
				cout << "Whoa dude, repeating a year!" << endl;
			}
		}


		getline(cin, cmd);
		if (cmd == "age a year")
		{
			cPlayer.age++;
			if (cMother.alive == true)
			{
				cMother.age++;
			}
			if (cFather.alive == true)
			{
				cFather.age++;
			}
			cout << "You are now " << cPlayer.age << " years old." << endl;

			if (cPlayer.age == SCHOOL_AGE)
			{
				cPlayer.schoolState = 1;
				cPlayer.grade = cPlayer.intel;
			}
			if (cPlayer.schoolState == 1)
			{
				cPlayer.intel = cPlayer.intel + (cPlayer.grade / 20);
				if (cPlayer.grade <= 60)
				{
					cout << "You are currently failing school." << endl;
				}
			}

			if (cMother.age == cMother.deathAge)
			{
				cout << "Your mother died at age " << cMother.age << ". That sucks." << endl;
			}
			if (cFather.age == cFather.deathAge)
			{
				cout << "Your father died at age " << cFather.age << ". That sucks." << endl;
			}
			if (cPlayer.age == cPlayer.deathAge)
			{
				cPlayer.alive = false;
			}
			cmdCount = 0;
		}
		if (cmd == "study")
		{
			if (cPlayer.grade >= 100 && cPlayer.intel >= 100)
			{
				cout << "Studying can no longer help you." << endl;
			}
			if (cPlayer.grade < 100 && cPlayer.intel < 100)
			{
				if (cPlayer.schoolState == 1 || cPlayer.schoolState == 3)
				{
					cPlayer.intel = cPlayer.intel + ranNum(0, 5);
					cout << "Turbo nerd." << endl;
					cmdCount++;
				}
			}
		}
		if (cmd == "show deathage")
		{
			cout << cPlayer.deathAge << endl;
		}
		if (cmd == "kill mom")
		{
			cMother.age = cMother.deathAge - 1;
			cout << "Whoa, dick!" << endl;
		}
		if (cmd == "show stats")
		{
			cPlayer.printStats();
		}
		if (cmd == "show mom stats")
		{
			cMother.printStats();
		}
		if (cmd == "show dad stats")
		{
			cFather.printStats();
		}
		if (cmdCount == MAX_CMD)
		{
			cout << "You've done the max!" << endl;
		}
	}
	cout << "You dead." << endl;

}
