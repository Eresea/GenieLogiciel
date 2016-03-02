#include "MatCreuse.h"

using namespace std;

MatCreuse::MatCreuse()
{
	Width = 10;
	Height = 10;


	Mat.resize(Height);

	for(int i=0; i<Height;i++)
	Mat[i].resize(Width);
}

MatCreuse::MatCreuse(vector< vector<int> > V, int w, int h)
{
	Width = w;
	Height = h;

	Mat.resize(Height);	

	for(int i=0; i<Height;i++)
	Mat[i].resize(Width);
}





/*
MatCreuse operator+(MatCreuse const& a)
{
	int w,h;
	

	if(a.Height<=Height) h=a.Height;
	else h=Height;

	if(a.Width<=Width) w=a.Width;
	else w=Width;	

	MatCreuse tmp;
	tmp.Width=w;
	tmp.Height=h;
	tmp.Mat.resize(h);

	for(int i=0; i<h;i++)
	tmp.Mat[i].resize(w);

	for(int i=0;i<a.Height;i++)
	{
		for(int j=0;j<a.leight;i++)
		{
			tmp.Mat[i][j]= a.Mat[i][j]+Mat[i][j];
		}
	}

	return tmp;
}

MatCreuse operator-(MatCreuse const& a)
{
	int w,h;
	

	if(a.Height<=Height) h=a.Height;
	else h=Height;

	if(a.Width<=Width) w=a.Width;
	else w=Width;	

	MatCreuse tmp;
	tmp.Width=w;
	tmp.Height=h;
	tmp.Mat.resize(h);

	for(int i=0; i<h;i++)
	tmp.Mat[i].resize(w);

	for(int i=0;i<a.Height;i++)
	{
		for(int j=0;j<a.leight;i++)
		{
			tmp.Mat[i][j]= a.Mat[i][j]+Mat[i][j];
		}
	}

	return tmp;
}*/
