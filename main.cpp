#include <iostream>
#include "matcreuse.h"
#include <string>

using namespace std;

string Commandes[10] = {"Afficher","+","-","*","^","","","","",""};
matcreuse** Mat; // Tableau de matrices

int find(string s)
{
    for(int i=0;i<10;i++)
    {
        if(Commandes[i] == s) return i;
    }
    return -1;
}

int main(int argc , char** argv)
{
    string Cmd = "";
vector<int> N;
int tmp(0);
matcreuse M(N,N,N);
matcreuse M2(N,N,N);
M.ReadFile("Test.txt");
M2.ReadFile("Test2.txt");
M.WriteFile("Test.txt");
M2.WriteFile("Test2.txt");

M.Afficher();
cout << endl;
(M+M2).Afficher();
cout << endl;
(M*M2).Afficher();
cout << endl;
(M^2).Afficher();

while(Cmd != "quit")
{
    switch(find(Cmd))
    {
    case 0:
        M.Afficher();
        break;
    case 1:
        M+=M2;
        break;
    case 2:
        M-=M2;
        break;
    case 3:
        M*=M2;
        break;
    case -1:
        cout << "Commande non reconnue !" << endl;
        break;
    }

    cout << "> ";
    cin >> Cmd;
}


return 0;

}
