#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

class MatCreuse{
private:
	vector<int> Valeurs;
	vector<int> Lignes;
	vector<int> Colonnes;
public :
	MatCreuse();
	MatCreuse(vector<int>,vector<int>,vector<int>);
	void Add(int,int,int);
	int Get(int,int);
	//void ReadFile(string);
};
