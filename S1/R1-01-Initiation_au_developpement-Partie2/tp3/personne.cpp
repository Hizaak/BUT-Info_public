#include "personne.h"
using namespace std;

void afficher(const Personne& personne)
{
    cout << "  {" << personne.nom << ", " << personne.prenom << ", { " ;
    cout <<        personne.adresse.numRue << ", " ;
    cout <<        personne.adresse.nomRue << ", ";
    cout <<        personne.adresse.codePostal << ", ";
    cout <<        personne.adresse.nomVille << " }";
    cout << "}"<<endl;
}

void afficher(const Personne tab[],unsigned int nbTab)
{
    for(unsigned int i;i<=nbTab;i++)
    {
        afficher(tab[i]);
    }
}