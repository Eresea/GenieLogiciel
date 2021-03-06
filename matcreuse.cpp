#include "matcreuse.h"

using namespace std;

matcreuse::matcreuse()
{
    Valeurs.clear();
    Lignes.clear();
    Colonnes.clear();
	nbLignes = 0;
	nbColonnes = 0;
}

matcreuse::matcreuse(vector<int> V,vector<int> L,vector<int> C)
{
	nbLignes = 0;
	nbColonnes = 0;
	for(int i=0;i<V.size();i++)
	{
	Valeurs.insert(Valeurs.end(),V.at(i));
        Lignes.insert(Lignes.end(),L.at(i));
        Colonnes.insert(Colonnes.end(),C.at(i));
		if(L.at(i) > nbLignes) nbLignes = L.at(i);
		if(C.at(i) > nbColonnes) nbColonnes = C.at(i);
	}
}

void matcreuse::Add(int l,int c,int v)//Ajoute ou remplace
{
    bool Correct = true;
    for(int i=0;i<Lignes.size();i++) // Emp�che l'ajout de valeurs deja presentes en Ligne/Colonne
            {
                if((Lignes.at(i) == l) && (Colonnes.at(i) == c))
                {
                    Correct = false;
                    Valeurs[i] = v;
                    break;
                }
            }
    if(Correct)
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
        if(l > nbLignes) nbLignes = l;
        if(c > nbColonnes) nbColonnes = c;
    }
}


bool matcreuse::Get(int l,int c, int &v)
{
	if (indice(l,c) != -1)
	{
		v=Valeurs.at(indice(l,c));
		return true;
	}
	else { v = 0; return false; }
}



int matcreuse::indice(int l,int c) const
{
    int line = find(Lignes.begin(),Lignes.end(),l) - Lignes.begin();
    if(line >= Lignes.size()) return -1;
	if(Colonnes.size() <= c || Lignes.size() <= l) return -1;
    while((Colonnes.at(line) != c))
    {
        line = find(line+1+Lignes.begin(),Lignes.end(),l) - Lignes.begin();
        if(line >= Lignes.size()) return -1;
    }


	if(line != Lignes.end()-Lignes.begin()) return line;
	else return -1;

}

void matcreuse::ReadFile(string url)
{
	ifstream fic(url.c_str());
	if(fic)						// Si le fichier existe
	{
		string s;
        vector<string> Str;
        bool Correct = true;
	    while(fic>>s)			// Tant qu'il y a des lignes dans le fichier
		{
		    Str = Split(s,',');
		    for(int i=0;i<Lignes.size();i++) // Emp�che l'ajout de valeurs deja presentes en Ligne/Colonne
            {
                if((Lignes.at(i) == atoi(Str[0].c_str())) && (Colonnes.at(i) == atoi(Str[1].c_str())))
                {
                    Correct = false;
                    //Possibilit� de changer afin de remplacer l'ancienne valeur par celle du nouveau fichier
                    //Valeurs[i] = atoi(Str[2].c_str());
                    break;
                }
            }
            if(Correct)
            {
                Valeurs.push_back(atoi(Str[2].c_str()));
                Lignes.push_back(atoi(Str[0].c_str()));
                Colonnes.push_back(atoi(Str[1].c_str()));
                if(atoi(Str[0].c_str()) > nbLignes) nbLignes = atoi(Str[0].c_str());
                if(atoi(Str[1].c_str()) > nbColonnes) nbColonnes = atoi(Str[1].c_str());
            }
            else cout << "Deja pris" << endl;
            Correct = true;
        }
    }
    fic.close();
}

void matcreuse::Afficher()
{
    if(Valeurs.size() == 0) cout << "Matrice creuse vide !" << endl;
	for(int i=0;i<Valeurs.size();i++)
	{
		cout << Lignes[i] << "," << Colonnes[i] << " : " << Valeurs[i] << endl;
	}
}

void matcreuse::WriteFile(string s)
{
	ofstream File;
	File.open(s.c_str());
	for(int i=0;i<Valeurs.size();i++)
	{
		File << Lignes[i] << "," << Colonnes[i] << "," << Valeurs[i] << '\n';
	}
}

void matcreuse::Del(int x, int y)
{
    int index = indice(x,y);
    if(index == -1) return;
    Valeurs.erase(Valeurs.begin()+index);
    Lignes.erase(Lignes.begin()+index);
    Colonnes.erase(Colonnes.begin()+index);
    int tempnbLignes =0;
    int tempnbColonnes =0;
    for(int i=0;i<Valeurs.size();i++)
    {
        if(Lignes[i] > tempnbLignes) tempnbLignes = Lignes[i];
        if(Colonnes[i] > tempnbColonnes) tempnbColonnes = Colonnes[i];
    }
    nbLignes = tempnbLignes;
    nbColonnes = tempnbColonnes;
}

void matcreuse::transposee()
{
    vector<int> LignesTemp = Lignes;
    for(int i=0;i<Valeurs.size();i++)
    {
        Lignes[i] = Colonnes[i];
        Colonnes[i] = LignesTemp[i];
    }
    int temp = nbLignes;
    nbLignes = nbColonnes;
    nbColonnes = temp;
}

