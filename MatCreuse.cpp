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
	int tmp=indice(l,c);
	if(tmp==-1)
	{
    	Valeurs.push_back(v);
    	Lignes.push_back(l);
    	Colonnes.push_back(c);
	}
	else
	{
		Valeurs[tmp]=v;
	}
}


bool MatCreuse::Get(int l,int c, int &v)
{
	if (indice(l,c) != -1)
	{
		v=Valeurs.at(indice(l,c));
		return true;
	} 
	else { v = 0; return false; }
}



int MatCreuse::indice(int l,int c)
{
    int line = find(Lignes.begin(),Lignes.end(),l) - Lignes.begin();
	if(Colonnes.size() <= c || Lignes.size() <= l) return -1;
    while((Colonnes.at(line) != c))
    {
        line = find(line+1+Lignes.begin(),Lignes.end(),l) - Lignes.begin();
    }

	
	if(line != Lignes.end()-Lignes.begin()) return line;
	else return -1;
    
}

void MatCreuse::ReadFile(string url)
{
	ifstream fic(url.c_str());
	if(fic)						// Si le fichier existe
	{
		string s;
        vector<string> Str;
	    while(fic>>s)			// Tant qu'il y a des lignes dans le fichier
		{
            Str = Split(s,',');
            Valeurs.insert(Valeurs.end(),atoi(Str[2].c_str()));
            Lignes.insert(Lignes.end(),atoi(Str[0].c_str()));
            Colonnes.insert(Colonnes.end(),atoi(Str[1].c_str()));
		}
		fic.close();
    }
}

void MatCreuse::Afficher()
{
	for(int i=0;i<Valeurs.size();i++)
	{
		cout << Lignes[i] << "," << Colonnes[i] << " : " << Valeurs[i] << endl;
	}
}

void MatCreuse::WriteFile(string s)
{
	ofstream File;
	File.open(s.c_str());
	for(int i=0;i<Valeurs.size();i++)
	{
		File << Lignes[i] << "," << Colonnes[i] << "," << Valeurs[i] << '\n';
	}
}

