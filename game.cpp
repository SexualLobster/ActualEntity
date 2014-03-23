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

		int boardingState; // 0 = living with parents, 1 independent (includes homeless), 2 shared (room mates, spouse)

		bool employed;
		string jobTitle;
		unsigned int salary;

		int houseMoney;
		int personelMoney;
		int bills;


		//void getJob()

		void printStats() //Prints information; For selected character; Used for debugging
		{
			cout << "First name:\t" << fName << "." << endl;
			cout << "Last name:\t" << lName << "." << endl;
			cout << "Gender:\t\t" << gender << ". ~ 0 = male, 1 = female." << endl;
			cout << "Age:\t\t" << age << "." << endl;
			cout << "Death age:\t" << deathAge << "." << endl;
			cout << "Intel:\t\t" << intel << "." << endl;
			if (employed == 0)
			{
				cout << "Unemployed." << endl;
			}
			else
			{
				cout << jobTitle << " at" << salary << "." << endl;
			}
		}
	};

	//Declares essential people.
	Person cPlayer;
	Person cMother;
	Person cFather;

	//Makes sure essential people are alive.
	cPlayer.alive = true;
	cMother.alive = true;
	cFather.alive = true;

	//Generated Mom/Dad lifespan, along with player character.
	cMother.hereditaryLifespan = ranNum(-20, 20);
	cFather.hereditaryLifespan = ranNum(-20, 20);
	cPlayer.hereditaryLifespan = (cFather.hereditaryLifespan + cMother.hereditaryLifespan) / 2;

	//Sets mother/father age.
	cMother.age = ranNum(18, 45); // Old floor/ceiling is 40/61
	cFather.age = ranNum((cMother.age / 2 + 7), 55);
	
	//Gender
	cMother.gender = 1;
	cFather.gender = 0;
	cPlayer.gender = ranNum(0, 1); //Zero for male, One for female

	//Names
	cFather.fName = name(0);
	cMother.fName = name(1);
	cFather.lName = name(2);
	cMother.lName = cFather.lName; //TODO: Skanks!
	cPlayer.lName = cFather.lName;
	cPlayer.fName = name(cPlayer.gender);

	//Intelligence, which is totally hereditary.
	cFather.intel = ranNum(40, 90);
	cMother.intel = ranNum(40, 90);
	if (ranNum(0, 5) == 3) //Gotta have some gains. 1/5th chance of dad having +10 extra intelligence.
		{
			cFather.intel = cFather.intel + 10;
			if (ranNum(0,10) == 6) //1/10th chance of mom having +10 intelligence
			{
				cMother.intel = cMother.intel + 10;
				if (ranNum(0, 20) == 13) //1/20th chance of both parents being super smart. Ceiling: 125.
				{
					cMother.intel = cMother.intel + 15;
					cFather.intel = cFather.intel +15;
				}
			}
		}
	cPlayer.intel = (cFather.intel + cMother.intel) / 2; //TODO #8, mental retardation.

	//Fun small stuff

	//Death age.
	cMother.deathAge = (80 + cMother.hereditaryLifespan);
	cFather.deathAge = (75 + cFather.hereditaryLifespan);	
	//Too lazy to implement otherwise.
	//cPlayer.gender--;
	cPlayer.deathAge = (75 + (5 * cPlayer.gender)) - cPlayer.hereditaryLifespan; 
	//cPlayer.gender++; //^If you are a female, you get 5 more years on average
	
	cPlayer.age = 0;
	int cmdCount = 0;
	string cmd = "";
	cout << "You are " << cPlayer.fName << " " << cPlayer.lName << "." << endl;
	while (cPlayer.alive == true) //Main game loop.
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
		if (cmd == "age a year" || cmd == "age")
		{
			//cMother.alive = true;
			//cFather.alive = true;
			cPlayer.age++;
			if (cMother.alive == true)
			{
				cMother.age++;
				cout << "Your mother, " << cMother.fName << ", is now " << cMother.age << "." << endl;
			}
			if (cFather.alive == true)
			{
				cFather.age++;
				cout << "Your father, " << cFather.fName << ", is now " << cFather.age << "." << endl;
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

			if (cMother.age == cMother.deathAge && cMother.alive == true)
			{
				cout << "Your mother died at age " << cMother.age << ". That sucks." << endl;
				cMother.alive = false;
			}
			if (cFather.age == cFather.deathAge && cFather.alive == true)
			{
				cout << "Your father died at age " << cFather.age << ". That sucks." << endl;
				cFather.alive = false;
			}
			if (cPlayer.age == cPlayer.deathAge)
			{
				cPlayer.alive = false;
			}
			cmdCount = 0;
			if (cPlayer.boardingState == 0)
			{
				cPlayer.houseMoney = cPlayer.houseMoney - cPlayer.bills;
			}
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
		if (cmd == "getajob")
		{
			getJob(cPlayer.jobTitle, cPlayer.salary);
		}
		if (cmdCount == MAX_CMD)
		{
			cout << "You've done the max!" << endl;
		}
	}
	cout << "You dead." << endl;

}
