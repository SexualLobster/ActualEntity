#include <iostream>
#include <cstdlib>
using namespace std;

int pos(string s, char c){
  for(int i=0; i<s.length(); i++)
    if(s.at(i)==c) then return i;
  
  return -1;
}

string sub(string s, int c){
  return s.substring(pos(s,c),s.length());
}

string after(string s, char c){
  return sub(s, pos(s,c));
}
