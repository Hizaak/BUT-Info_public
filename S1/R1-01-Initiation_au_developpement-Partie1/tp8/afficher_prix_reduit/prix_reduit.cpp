/*
 Programme : Afficher le prix réduit
 But : Doit afficher le prix réduit à partir de la réduction entrée et du prix
 Date de dernière modification : 20/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void afficherPrixReduit(float prixInitial, float pourcentageReduc);
//But : affiche le prixReduit après l'application d'un pourcentageReduc sur un prixInitial

int main (void)
{
    //Déclaration des variables
    float prixInitial;
    float pourcentageReduc;
    //Saisie
    cout<<"Saisissez le prix initial : ";
    cin>>prixInitial;
    cout<<"Saisissez le pourcentage reduction : ";
    cin>>pourcentageReduc;
    afficherPrixReduit(prixInitial,pourcentageReduc); //Appel de la procédure afficherPrixReduit
    return 0;
}

void afficherPrixReduit(float prixInitial, float pourcentageReduc){
    cout<<"Le prix final est de "<<prixInitial*(1-(pourcentageReduc/100));
}