#include <iostream>
#include "matcreuse.h"
#include <string>

using namespace std;

int main(int argc , char** argv)
{
vector<int> N;
int tmp(0);
matcreuse M(N,N,N);
matcreuse M2(N,N,N);
M.ReadFile("Test.txt");
M2.ReadFile("Test2.txt");
M.WriteFile("Test.txt");
M2.WriteFile("Test2.txt");

M.Afficher();
cout << endl;
(M+M2).Afficher();
cout << endl;
(M*M2).Afficher();


return 0;

}
