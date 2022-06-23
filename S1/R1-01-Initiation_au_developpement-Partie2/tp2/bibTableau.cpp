/**  CORPS MODULE Fractions  
     ------------------------ */

/**  inclusions
     ------------------------ */
#include "bibTableau.h"
#include <iostream>
using namespace std;

/* Types - Variables - Constantes propres au corps
 */

/* Déclaration des sous-programmes utilisés dans ce corps
 */

/* Corps des sous-programmes déclarés dans l'Interface bibTableau.h
 */

/* Corps des sous-programmes déclarés dans ce corps
 */

void afficher (const int tab[],
               unsigned short int lgTab)
{
    if (lgTab > 0)
    {
        cout << "{";
        for (unsigned short int i = 0; i<lgTab-1; i++)
        {
            cout << tab[i] << ", " ;

        };
        cout << tab[lgTab-1] << "} "<< endl;
    }
    else
    {
        cout << "tableau vide " << endl;
    }
}

void recherchePremiereOccDichoEntier(const int tab[], unsigned int lgTab, int val, unsigned int& pos, bool& trouve)
{
    
    //Déclaration et calcul de borneInf et de borneSup
    //Initialiser la recherche
    unsigned int borneSup=lgTab-1;
    unsigned int borneInf=0;
    unsigned int milieu;
    trouve=false;
    //Effectuer la recherche
    while(true)
    {
        if (borneInf>borneSup)
        {
            break;
        }
        //Calcul du milieu des bornes
        milieu=int(borneSup+borneInf/2)+1;

        if (tab[milieu]==val)
        {
            trouve=true;
            pos=milieu;
        }
        
    }
}
