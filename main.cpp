#include <iostream>
#include "MatCreuse.h"
#include <string>

using namespace std;

int main(int argc , char** argv)
{
vector<int> N;
int tmp(0);
MatCreuse M(N,N,N);
M.ReadFile("Test.txt");
M.Afficher();
M.WriteFile("Test.txt");

if(M.Get(0,0,tmp)) cout << tmp << endl;


return 0;

}
