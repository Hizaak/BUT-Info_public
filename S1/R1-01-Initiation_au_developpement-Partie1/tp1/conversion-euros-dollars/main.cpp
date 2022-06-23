/*
 Programme : ConversionEurosVersDollars
 But :  Convertit en dollars une somme en euros entrée au clavier
 Date de dernière modification : 25 août 2015
 Auteur : P. Etcheverry
 Remarques : Code conforme aux spécification internes données en cours
*/

#include <iostream>
using namespace std;

int main (void)
{
    // VARIABLES
    double sommeEuros; // La somme en euros qui doit être convertie en dollars.
    double sommeDollars; // La somme en dollars résultant de la conversion.
    const double TAUX_EUROS_VERS_DOLLARS = 1.3383; // Le taux de conversion utilisé pour convertir des euros en dollars.

    // TRAITEMENTS
    // clavier >> saisirSommeEuros >> sommeEuros
     cout << "Entrez la somme en euros a convertir en dollars :  ";
     cin >> sommeEuros;

    // sommeEuros, TAUX_EUROS_VERS_DOLLARS >> calculerSommeDollars >> sommeDollars
    sommeDollars = sommeEuros * TAUX_EUROS_VERS_DOLLARS;

    // sommeDollars >> afficherSommeDollars >> écran
    cout << "La somme convertie est egale a " << sommeDollars << " $" << endl;

    return 0;
}