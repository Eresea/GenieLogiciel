/**
 * \file MatCreuse.h
 * \brief Bibliothèque de matrices creuses
 * \author Groupe G1
 * \version 0.1
 * \date 27 april 2016
 *
 * Bibliothèque de création de matrices creuses.
 *
 */

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
	int nbLignes;
	int nbColonnes;
	MatCreuse();
	MatCreuse(vector<int>,vector<int>,vector<int>);
	void Add(int,int,int);
	int indice(int,int) const;
	bool Get(int,int,int&);
	void ReadFile(string);
	void WriteFile(string);
	void Afficher();

	MatCreuse& operator*=(const MatCreuse& b)
	{
		if(nbLignes != b.nbColonnes)
		{
			cout << "Erreur dans la multiplication de matrices. Euh.. Non" << endl;
			return *this;
		}
		for(int i=0;i<nbColonnes/*+1*/;i++) // Pour chaque ligne/colonne
		{
			int x,y;
			int val =0;
			for(int j=0;j<nbLignes/*+1*/;j++)
			{
				if(Get(j,i,x))
				{
					if(b.indice(i,j)+1)
					{
						y = b.Valeurs.at(b.indice(i,j));
						val += x*y;
					}
				}
			}			
			Valeurs[i] = val;
		}
		return *this;
	}

friend MatCreuse operator*(MatCreuse a, const MatCreuse& b)
{
	a*=b;
	return a;
}

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
