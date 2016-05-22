#include <iostream>
#include "matcreuse.h"
#include <string>
#include <algorithm>
#include <random>

using namespace std;

string Commandes[12] = {"addm","addv","suppv","+","-","*","^",">>","trans","aff","genm"};
vector<matcreuse*> Mat; // Tableau de matrices
matcreuse* tempMat;

int randomVal(int minimum, int maximum)
{
    return(minimum + (rand()%(maximum-minimum+1)));
}

matcreuse* generateMat(int nbElements, int l,int c,int minimum,int maximum)
{
    vector<int> Lignes;
    vector<int> Colonnes;
    vector<int> Valeurs;

    if(nbElements > l*c)
    {
        cout << "Impossible de créer une matrice de " << nbElements << " elements avec les dimensions : " << l << "/" << c << endl;
        return NULL;
    }

    for(int i=0;i<nbElements;i++) // PB : Pas complètement aléatoire par rapport à leur position
    {
        Lignes.push_back(i/l%l);
        Colonnes.push_back(i%c);
        Valeurs.push_back(randomVal(minimum,maximum));
    }

    matcreuse *Mtmp = new matcreuse(Valeurs,Lignes,Colonnes);
    return Mtmp;
}

int find(string s)
{
    for(int i=0;i<10;i++)
    {
        if(Commandes[i] == s) return i;
    }
    return -1;
}

void handleCommandes(string s)
{
    matcreuse *Mtmp;
    int op = -1;
    string l,c,v,minimum,maximum;
    for(int i=3;i<8;i++)
    {
        if(s.find(Commandes[i]) != string::npos)//Si s contient une opération
        {
            op = i;
            break;
        }
    }
    if(op == -1)
    {

        string operation = s.substr(0,s.find(" "));
        int posC,posV;
        for(int i=0;i<11;i++)
        {
            if(Commandes[i] == operation)
            {
                op = i;
                break;
            }
        }
        switch(op)
        {
        case 0:
            Mtmp = new matcreuse();
            Mtmp->ReadFile(s.substr(5));
            Mat.push_back(Mtmp);
            cout << "Mat" << Mat.size()-1 << " cree avec le contenu de " << s.substr(5) << endl;
            break;
        case 1:
            l = s.substr(s.substr(8).find(" ")+9,(s.find(",") - (s.substr(8).find(" ")+9)));
            posC = (s.substr(8).find(" ")+9) + (s.find(",") - (s.substr(8).find(" ")+9))+1;
            c = s.substr(posC,(s.substr(posC).find(",")));
            posV = posC +(s.substr(posC).find(","))+1;
            v = s.substr(posV);
            Mat[atoi(s.substr(8,s.substr(8).find(" ")).c_str())]->Add(atoi(l.c_str()),atoi(c.c_str()),atoi(v.c_str()));
            cout << "Ajoute la valeur " << v << " en " << l << "," << c << " a Mat" << atoi(s.substr(8,s.substr(8).find(" ")).c_str()) << endl;
            break;
        case 2:
            l = s.substr(s.substr(9).find(" ")+10,(s.find(",") - (s.substr(9).find(" ")+10)));
            posC = (s.substr(9).find(" ")+10) + (s.find(",") - (s.substr(9).find(" ")+10))+1;
            c = s.substr(posC);
            Mat[atoi(s.substr(9,s.substr(9).find(" ")).c_str())]->Del(atoi(l.c_str()),atoi(c.c_str()));
            cout << "La valeur en " << l << "," << c << " de Mat" << atoi(s.substr(9,s.substr(9).find(" ")).c_str()) << " a ete supprimee" << endl;
            break;
        case 8:
            Mat[atoi(s.substr(9,s.substr(9).find(" ")).c_str())]->transposee();
            cout << "Mat" << s.substr(9,s.substr(9).find(" ")) << " a ete transposee" << endl;
            break;
        case 9:
            if(s.find("tempMat") != string::npos)
            {
                tempMat->Afficher();
            }
            else
            {
                if(Mat.size() > atoi(s.substr(7,s.substr(7).find(" ")).c_str())) Mat[atoi(s.substr(7,s.substr(7).find(" ")).c_str())]->Afficher();
                else cout << "Mat" << s.substr(7,s.substr(7).find(" ")) << " n'est pas initialise !" << endl;
            }
            break;
        case 10: // Aleatoire
            v = s.substr(s.substr(5).find(" ")+6,(s.find(",") - (s.substr(5).find(" ")+6)));
            posC = (s.substr(5).find(" ")+6) + (s.find(",") - (s.substr(5).find(" ")+6))+1;
            l = s.substr(posC,(s.substr(posC).find(",")));
            posC = posC +(s.substr(posC).find(","))+1;
            c = s.substr(posC,(s.substr(posC).find(",")));
            posC = posC +(s.substr(posC).find(","))+1;
            minimum = s.substr(posC,(s.substr(posC).find(",")));
            posC = posC +(s.substr(posC).find(","))+1;
            maximum = s.substr(posC);

            Mat.push_back(generateMat(atoi(v.c_str()),atoi(l.c_str()),atoi(c.c_str()),atoi(minimum.c_str()),atoi(maximum.c_str())));
            if(Mat[Mat.size()-1]) cout << "Mat" << Mat.size()-1 << " cree avec un contenu aleatoire" << endl;
            else Mat.pop_back();
            break;
        default:
            cout << "Commande non reconnue !" << endl;
            break;
        }
    }
    else // C'est une opération
    {
        int posOp;
        switch(op)
        {
        case 3: //+
            posOp = s.find("+");
            if(Mat.size() > max(atoi(s.substr(3,posOp-3).c_str()),atoi(s.substr(posOp+4).c_str())))
            {
                *Mat[atoi(s.substr(3,posOp-3).c_str())] += *Mat[atoi(s.substr(posOp+4).c_str())];
            }
            else cout << "Mat" << max(atoi(s.substr(3,posOp-3).c_str()),atoi(s.substr(posOp+4).c_str())) << " n'est pas initialise !" << endl;
            break;
        case 4: //-
            posOp = s.find("-");
            if(Mat.size() > max(atoi(s.substr(3,posOp-3).c_str()),atoi(s.substr(posOp+4).c_str())))
            {
                *Mat[atoi(s.substr(3,posOp-3).c_str())] -= *Mat[atoi(s.substr(posOp+4).c_str())];
            }
            else cout << "Mat" << max(atoi(s.substr(3,posOp-3).c_str()),atoi(s.substr(posOp+4).c_str())) << " n'est pas initialise !" << endl;
            break;
        case 5: //*
            posOp = s.find("*");
            if(s.substr(posOp).find("Mat") != string::npos)
            {
                if(Mat.size() > max(atoi(s.substr(3,posOp-3).c_str()),atoi(s.substr(posOp+4).c_str())))
                {
                    *Mat[atoi(s.substr(3,posOp-3).c_str())] *= *Mat[atoi(s.substr(posOp+4).c_str())];
                }
                else cout << "Mat" << max(atoi(s.substr(3,posOp-3).c_str()),atoi(s.substr(posOp+4).c_str())) << " n'est pas initialise !" << endl;
            }
            else
            {
                if(Mat.size() > atoi(s.substr(3,posOp-3).c_str()))
                {
                    *Mat[atoi(s.substr(3,posOp-3).c_str())] *= atoi(s.substr(posOp+1).c_str());
                }
                else cout << "Mat" << s.substr(3,posOp-3) << " n'est pas initialise !" << endl;
            }
            break;
        case 6: //^
            posOp = s.find("^");
            if(Mat.size() > atoi(s.substr(3,posOp-3).c_str()))
            {
                *Mat[atoi(s.substr(3,posOp-3).c_str())] ^= atoi(s.substr(posOp+1).c_str());
            }
            else cout << "Mat" << atoi(s.substr(3,posOp-3).c_str()) << " n'est pas initialise !" << endl;
            break;
        case 7:
            posOp = s.find(">>");
            if(s.substr(s.size()-4,50) == ".txt") // Export
            {
                if(s.substr(0,posOp-1) == "tempMat")
                {
                    tempMat->WriteFile(s.substr(posOp+2));
                }
                else Mat[atoi(s.substr(posOp+5).c_str())]->WriteFile(s.substr(posOp+2));
            }
            else
            {
                if(s.substr(0,posOp) == "tempMat")
                {
                    if(s.substr(posOp+1).find("Mat")+posOp+1 == s.length()-3)
                    {
                        Mat.push_back(tempMat);
                        cout << "Mat" << Mat.size()-1 << " a ete cree a partir de tempMat" << endl;
                    }
                    else Mat[atoi(s.substr(posOp+5).c_str())] = tempMat;
                }
                else if(s.substr(0,posOp).find(".txt") != string::npos)
                {
                    if(s.substr(posOp+1).find("tempMat") != string::npos)
                    {
                        tempMat = new matcreuse();
                        tempMat->ReadFile(s.substr(0,posOp));
                        cout << "tempMat a ete rempli a partir de " << s.substr(0,posOp) << endl;
                    }
                    else if(s.substr(posOp+1).find("Mat")+posOp+1 == s.length()-3)
                    {
                        Mtmp = new matcreuse();
                        Mtmp->ReadFile(s.substr(0,posOp));
                        Mat.push_back(Mtmp);
                        cout << "Mat" << Mat.size()-1 << " a ete cree a partir de " << s.substr(0,posOp) << endl;
                    }
                    else
                    {
                        Mat[atoi(s.substr(posOp+5).c_str())]->ReadFile(s.substr(0,posOp-1));
                    }
                }
                else
                {
                    if(s.substr(posOp+1).find("tempMat") != string::npos)
                    {
                        tempMat = Mat[atoi(s.substr(0,posOp).c_str())];
                    }
                    else if(s.substr(posOp+1).find("Mat")+posOp+1 == s.length()-3)
                    {
                        Mat.push_back(Mat[atoi(s.substr(posOp+5).c_str())]);
                        cout << "Mat" << Mat.size()-1 << " a ete cree a partir de Mat" << s.substr(posOp+5) << endl;
                    }
                    else Mat[atoi(s.substr(0,posOp).c_str())] = Mat[atoi(s.substr(posOp+5).c_str())];
                }


                // FINIR LA FONCTION + DEBUG
            }
            break;
        }
    }
}

int main(int argc , char** argv)
{
string Cmd = "";
cout << "> ";
getline(cin,Cmd);

while(Cmd != "quit")
{
    handleCommandes(Cmd);

    cout << "> ";
    getline(cin,Cmd);
}


return 0;

}
