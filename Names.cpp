#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include "Strings.cpp"
#define NAMEFILE "./names.txt"
#define TRIM (after(lines[i],':'))

//Define global variables
vector<string> femaleNames;
vector<string> maleNames;
vector<string> lastNames;

//!Return number between floor and ceiling
unsigned int ranNum(int floor, int ceiling){
  return (floor + (rand()%cieling)) - 1;
}

void loadNames(){
  string buffer;
  vector<string> lines;
  ifstream in(NAMEFILE);

  for(;getLine(in, buffer);)
    lines.push_back(buffer);
  
  for(int i = 0; i < in.capacity; i++){
    if(lines[i].find("female")!=-1)
      femaleNames.push_back(TRIM);
    else if(lines[i].find("male")!=-1)
      maleNames.push_back(TRIM);
    else if(lines[i].find("last:")!=-1)
      lastNames.push_back(TRIM);
  }
}

string name(unsigned int t){
  switch t{
    case 0:
      return maleNames[(ranNum(1,maleNames.capacity))];
    case 1:
      return femaleNames[(ranNum(1,femaleNames.capacity))];
    case 2:
      return lastNames[(ranNum(1,lastNames.capacity))];
    default:
      break;
    }
  return "";
}
