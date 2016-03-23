#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>
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
	int indice(int,int);
	bool Get(int,int,int&);
	void ReadFile(string);
	void WriteFile(string);
	void Afficher();
};

inline vector<string> Split(string s,char c)
{
    vector<string> internal;
    stringstream ss(s);
    string tok;
    while(getline(ss,tok,c))
    {
        internal.push_back(tok);
    }
    return internal;
}
