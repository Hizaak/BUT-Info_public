 /*
 Programme : test du module Fractions
 But :  Tester la conformité de chaque fonctionnalité du module Fractions
        par rapport aux jeux d'essais prévus
 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#include "fractions.h"
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void testAfficher();

int main()
{
    testAfficher();
    return 0;
}

//Définition des sous-programmes
void testAfficher()
{
    afficher({1,3});
    cout<<endl;
    afficher({-1,3});
    cout<<endl;
    afficher({0,1});
    cout<<endl;
    afficher(FRACTION_NULLE);
    cout<<endl;
    afficher({1,1});
    cout<<endl;
}
