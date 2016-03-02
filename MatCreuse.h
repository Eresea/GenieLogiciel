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

	MatCreuse operator+(MatCreuse const& a);
};
