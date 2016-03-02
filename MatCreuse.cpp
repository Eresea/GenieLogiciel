#include "MatCreuse.h"

using namespace std;

MatCreuse::MatCreuse()
{
	Width = 10;
	Height = 10;
	for(int i=0; i<Height;i++)
	Mat[i].resize(Width);
}

MatCreuse::MatCreuse(vector< vector<int> > V, int w, int h)
{
	Width = w;
	Height = h;
	for(int i=0; i<Height;i++)
	Mat[i].resize(Width);
}
