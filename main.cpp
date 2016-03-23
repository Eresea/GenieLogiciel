#include <iostream>
#include "MatCreuse.h"
#include <string>

using namespace std;

int main(int argc , char** argv)
{
vector<int> N;
int tmp(0);
MatCreuse M(N,N,N);
M.Add(0,0,5);
M.Add(0,1,12);
M.Get(0,0,tmp);
cout << "0,0 : " << tmp << endl;
M.Get(0,1,tmp);
cout << "0,1 : " << tmp << endl;

return 0;

}
