#include <string>
#include <vector>

using namespace std;

class MatCreuse{
private:
	vector< vector<int> > Mat;
	int Width;
	int Height;

public :
	MatCreuse();
	MatCreuse(vector< vector<int> >, int, int);


/*  plein de pb, a revoir

	MatCreuse operator+(MatCreuse const& a); 
	MatCreuse operator-(MatCreuse const& a);

*/
};
