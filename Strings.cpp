#include <iostream>
#include <cstdlib>
using namespace std;

int pos(string s, char c){
  for(int i=0; i<s.length(); i++)
    if(s.at(i)==c){
      return i;
    }
  
  return -1;
}

string sub(string s, int c){
  return s.substr(c+1,s.length());
}

string after(string s, char c){
  return sub(s, pos(s,c));
}
