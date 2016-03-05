#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>

using namespace std;

class MatCreuse{
private:
	vector< vector<int> > Mat;
	int Width;
	int Height;

public :
	MatCreuse();
	MatCreuse(vector< vector<int> >, int, int);
	void ReadFile(string)


/*  plein de pb, a revoir

	MatCreuse operator+(MatCreuse const& a); 
	MatCreuse operator-(MatCreuse const& a);

*/
};
