#include <iostream>
#include "matcreuse.h"
#include <string>

using namespace std;

int main(int argc , char** argv)
{
vector<int> N;
int tmp(0);
MatCreuse M(N,N,N);
MatCreuse M2(N,N,N);
M.ReadFile("Test.txt");
M2.ReadFile("Test2.txt");
//M.Afficher();
M.WriteFile("Test.txt");
M2.WriteFile("Test2.txt");

M2*=M;
M2.Afficher();

//if(M.Get(0,0,tmp)) cout << tmp << endl;


return 0;

}
