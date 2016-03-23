#include <iostream>
#include "MatCreuse.h"
#include <string>

using namespace std;

int main(int argc , char** argv)
{
vector<int> N;
MatCreuse M(N,N,N);
M.Add(0,0,5);
M.Add(0,1,12);
cout << "0,0 : " << M.Get(0,0) << endl;
cout << "0,1 : " << M.Get(0,1) << endl;

return 0;

}
