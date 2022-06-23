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
bool estNote(double valeur);
//But : retourne Vrai si la valeur saisie est comprise entre 0 et 20, Faux sinon

int main(void)
{
    double valeur;
    cout << "Saisissez une valeur : ";
    cin >> valeur;
    if (estNote(valeur))
    {
        cout << "Cette note est valide";
    }
    else
    {
        cout << "Cette valeur n'est pas une note valide";
    }
}

//Définition des sous-programmes
bool estNote(double nombre)
{
    return (0 <= nombre && nombre <= 20 ? true : false);
}