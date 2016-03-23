#include "MatCreuse.h"

using namespace std;

MatCreuse::MatCreuse()
{
	Valeurs.clear();
    Lignes.clear();
    Colonnes.clear();
}

MatCreuse::MatCreuse(vector<int> V,vector<int> L,vector<int> C)
{
	for(int i=0;i<V.size();i++)
	{
		Valeurs.insert(Valeurs.end(),V.at(i));
        Lignes.insert(Lignes.end(),L.at(i));
        Colonnes.insert(Colonnes.end(),C.at(i));
	}
}

void MatCreuse::Add(int l,int c,int v)
{
    Valeurs.push_back(v);
    Lignes.push_back(l);
    Colonnes.push_back(c);
}

int MatCreuse::Get(int l,int c)
{
    int line = find(Lignes.begin(),Lignes.end(),l) - Lignes.begin();
    while(Colonnes.at(line) != c)
    {
        line = find(Lignes.begin(),Lignes.end(),l) - Lignes.begin();
    }
    return Valeurs.at(line);
}

/*void MatCreuse::ReadFile(string url)
{
	ifstream fic(url.c_str());
	if(fic)						// Si le fichier existe
	{
		string s;
	    int i=0;
	    int j=0;
	    while(fic>>s)			// Tant qu'il y a des lignes dans le fichier
		{
            Valeurs.insert(Valeur.end(),atoi(s.c_str()));
            Lignes.insert(Lignes.end(),i);
            Colonnes.insert(Colonnes.end(),j);
			if(j==2)
			{
				j=0;
				i++;	
			}
			else
			{
				j++;
			}
		}
		fic.close();
		ofstream fic2(url.c_str());	//Ecrire dans le fichier
		if(fic2)					//fic2 valide
		{
			int t;
		    for(int l=0;l<i;l++)	// Pour chaque élément visité (while au dessus)
			{
				t=Mat[l][0];
				Mat[l][0]=Mat[l][1];	//Inverse Mat[l][0] et Mat[l][1]
				Mat[l][1]=t;			//
				fic2<<Mat[l][0];
				fic2<<" ";
				fic2<<Mat[l][1];
				fic2<<" ";
				fic2<<Mat[l][2];
				fic2<<endl;	
			}
		fic2.close();
		}
	}
}*/





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
