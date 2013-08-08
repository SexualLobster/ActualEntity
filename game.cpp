#include <iostream>
#include "Names.cpp"

using namespace std;

int game(int argc, char** argv){
  int gender = ranNum(1, 2); //Zero for male, One for female
  string fName = "";
  fName = name(gender) + " " +  name(2);
  cout << fName << endl;
  cout << "Gender: " << (gender?"Female":"Male") << endl;
}
