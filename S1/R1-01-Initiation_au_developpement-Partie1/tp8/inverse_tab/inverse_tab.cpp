/*
 Programme : inverse un tableau
 But : inverser un tableau
 Date de dernière modification : 20/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void inverseTab(int tableau[], unsigned int const NB_CASES);
//But : calcule le prixReduit après l'application d'un pourcentageReduc sur un prixInitial

int main(void)
{
    unsigned int i;
    unsigned int const NB_CASES = 10;
    int tableau[NB_CASES] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (i = 0; i < NB_CASES; i++)
    {
        cout<<tableau[i]<<" ";
    }
    cout<<endl;
    inverseTab(tableau, NB_CASES);
    for (i = 0; i < NB_CASES; i++)
    {
        cout<<tableau[i]<<" ";
    }
}

void inverseTab(int tableau[], unsigned int const NB_CASES)
{
    int i;
    for (i = 0; i < int(NB_CASES / 2); i++)
    {
        int temp;
        temp = tableau[i];
        tableau[i] = tableau[NB_CASES - i - 1];
        tableau[NB_CASES - i - 1] = temp;
    }
}
