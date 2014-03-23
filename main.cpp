#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game.cpp"
#include <cstring>
using namespace std;

typedef int (*function)(int,char**);

struct cLinePair
{
    function f;
    string name;

    cLinePair(function c, string n)
    {
        f = c;
        name = n;
    }
};

vector<cLinePair> cLinePairs;

int info(int argc, char** argv)
{
    cout << "Copyright 2011-2014 Exocom" << endl;
}

int version(int argc, char** argv)
{
    cout << "Pre Alpha" << endl;
}

int test(int argc, char** argv)
{
    cout << "test" << endl;
}
void initializeCLinePairs()
{
    cLinePairs.push_back(cLinePair(&info, "info"));
    //cLinePairs.push_back(cLinePair(&test, "test"));
    cLinePairs.push_back(cLinePair(&version, "version"));
    cLinePairs.push_back(cLinePair(&game, "game"));
    //cLinePairs.push_back(cLinePair(&game, ""));
}

void handleArgs(int argc, char** argv)
{
    for(int all = 1; all < argc; all++)
    {
        for(int i = 0; i < cLinePairs.capacity()-1; i++)
        {
            if(strcmp(cLinePairs[i].name.c_str(),argv[all])==0)
            {
                cLinePairs[i].f(argc,argv);
            }
        }
    }
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    initializeCLinePairs();
    handleArgs(argc,argv);
    return 0;
}
