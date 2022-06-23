/*
 Programme : Calculer le prix réduit
 But : Doit calculer le prix réduit à partir de la réduction entrée et du prix
 Date de dernière modification : 20/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void calculerPrixReduit(float prixInitial, float pourcentageReduc, float &prixReduit);
//But : calcule le prixReduit après l'application d'un pourcentageReduc sur un prixInitial

int main(void)
{
    //Déclaration des variables
    float prixInitial;
    float pourcentageReduc;
    float prixReduit;
    //Saisie
    cout << "Saisissez le prix initial : ";
    cin >> prixInitial;
    cout << "Saisissez le pourcentage reduction : ";
    cin >> pourcentageReduc;
    calculerPrixReduit(prixInitial, pourcentageReduc, prixReduit); //Appel de la procédure calculerPrixReduit
    cout << prixReduit;
}

void calculerPrixReduit(float prixInitial, float pourcentageReduc, float &prixReduit)
{
    prixReduit = prixInitial * (1 - (pourcentageReduc / 100));
}