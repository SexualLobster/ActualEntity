#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Strings.cpp"
#define NAMEFILE "./names.txt"
#define TRIM (after(buffer,':'))

//Define global variables
vector<string> femaleNames;
vector<string> maleNames;
vector<string> lastNames;

//!Return number between floor and ceiling
unsigned int ranNum(int floor, int ceiling){
  return (floor + (rand()%ceiling)) - 1;
}

void loadNames(){
  string buffer;
  ifstream in(NAMEFILE);

  
  
  for(int i = 0; getline(in,buffer); i++){
    if(buffer.find("female")!=-1)
      femaleNames.push_back(TRIM);
    else if(buffer.find("male")!=-1)
      maleNames.push_back(TRIM);
    else if(buffer.find("last:")!=-1)
      lastNames.push_back(TRIM);
    else break;
  }
}

string name(unsigned int t){
  loadNames();
  switch(t){
    case 0:
      return maleNames[(ranNum(1,maleNames.capacity()))];
    case 1:
      return femaleNames[(ranNum(1,femaleNames.capacity()))];
    case 2:
      return lastNames[(ranNum(1,lastNames.capacity()))];
    default:
      break;
    }
  return "";
}
