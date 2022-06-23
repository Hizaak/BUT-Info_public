/*
 Programme : Afficher le prix réduit
 But : Doit afficher le prix réduit à partir de la réduction entrée et du prix
 Date de dernière modification : 26/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/

#include <iostream>
using namespace std;

//Déclaration des sous-programmes
double moyenneTab(const double tableau[], const unsigned int NB_CASES);
//But : effectue la moyenne d'un tableau

int main(void)
{
    const unsigned int NB_CASES = 4;
    double tableau[NB_CASES] = {10,15,15,20};
    double moyenne=moyenneTab(tableau,NB_CASES);
    cout<<moyenne;
}

//Définition des sous-programmes
double moyenneTab(const double tableau[], const unsigned int NB_CASES)
{
    double somme=0;
    unsigned int i;
    for(i=0;i<=NB_CASES-1;i++)
    {
        somme+=tableau[i];
    }
    return somme/i;
}