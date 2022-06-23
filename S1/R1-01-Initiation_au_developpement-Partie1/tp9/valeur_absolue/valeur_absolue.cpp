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
double valeurAbsolue(double nombre);
//But : retourne la valeur absolue du nombre

int main(void)
{
    double nombre;
    cout << "Saisissez un nombre : ";
    cin >> nombre;
    cout << "La valeur absolue de " << nombre << " est " << valeurAbsolue(nombre);
}

//Définition des sous-programmes
double valeurAbsolue(double nombre)
{
    /*
    if(nombre<0)
    {
        return -nombre;
    }
    else
    {
        return nombre;
    }
    */
    return (nombre < 0 ? -nombre : nombre);
}