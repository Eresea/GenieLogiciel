/**
 * \file matcreuse.h
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

class matcreuse{
private:
	vector<int> Valeurs;
	vector<int> Lignes;
	vector<int> Colonnes;
public :
	int nbLignes;
	int nbColonnes;
	matcreuse();
	matcreuse(vector<int>,vector<int>,vector<int>);
	void Add(int,int,int);
	void Del(int,int);
	int indice(int,int) const;
	bool Get(int,int,int&);
	void ReadFile(string);
	void WriteFile(string);
	void Afficher();
	void transposee();

	matcreuse& operator*=(const int b)
	{
	    for(int i=0;i<Valeurs.size();i++)
        {
            Valeurs[i] = Valeurs[i] * b;
        }
	}

	friend matcreuse operator*(matcreuse a, const int b)
    {
        a*=b;
        return a;
    }

	matcreuse& operator*=(const matcreuse& b)
	{
		if(nbLignes != b.nbColonnes)
		{
			cout << "Erreur dans la multiplication de matrices." << endl;
			return *this;
		}
		int temp,temp1,temp2;
		vector<int> Results;
        for(int i=0;i<Valeurs.size();i++) // Pour tous les éléments existants
        {
            int firstX = Lignes[i];
            int firstY = Colonnes[i];
            temp = 0;
            int nbSameLine = count(Lignes.begin(),Lignes.end(),Lignes.at(i)); //Nombre d'autres éléments sur la même ligne
            vector<int>::iterator it = find(Lignes.begin(),Lignes.end(),Lignes.at(i)); // Premier élément de la même ligne
            for(int j=0;j<nbSameLine;j++)// Pour tous les éléments de la même ligne
            {
                int y1 = Colonnes[it - Lignes.begin()];
                int x2 = y1;
                int y2 = Colonnes[i];
                Get(Lignes[i],y1,temp1);
                if(b.indice(x2,y2)+1)
                {
                    temp2 = b.Valeurs.at(b.indice(x2,y2));
                    temp += temp1 * temp2;
                }
                it = find(it+1,Lignes.end(),Lignes.at(i)); // Prochain élément de la même ligne
            }
            it = Lignes.begin();
            if(temp != 0) Results.insert(Results.begin()+i,temp);
            else Del(Lignes[i],Colonnes[i]);
        }
        Valeurs = Results;
        return *this;
	}

friend matcreuse operator*(matcreuse a, const matcreuse& b)
{
	a*=b;
	return a;
}

matcreuse& operator+=(const matcreuse& b)
{
    if(nbLignes == b.nbLignes && nbColonnes == b.nbColonnes)
    {
        for(int i=0;i<Valeurs.size();i++)
        {
            int x = Lignes[i];
            int y = Colonnes[i];
            if(b.indice(x,y)+1)
            {
                Valeurs[i]+= b.Valeurs.at(b.indice(x,y));
                if(Valeurs[i] == 0) Del(x,y);
            }
        }
    }
    else cout << "Les dimensions des matrices d'additions sont différentes !" << endl;
}

friend matcreuse operator+(matcreuse a, const matcreuse& b)
{
    a+=b;
    return a;
}

matcreuse& operator-=(const matcreuse& b)
{
    (*this)+=(b*-1);
    return *this;
}

friend matcreuse operator-(matcreuse a, const matcreuse& b)
{
    a-=b;
    return a;
}

matcreuse& operator^=(const int b)
{
    matcreuse *m = new matcreuse(Valeurs,Lignes,Colonnes);
    for(int i=1;i<b;i++)
    {
        (*this)*= *m;
    }
    return *this;
}

friend matcreuse operator^(matcreuse a, const int b)
{
    a^=b;
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
