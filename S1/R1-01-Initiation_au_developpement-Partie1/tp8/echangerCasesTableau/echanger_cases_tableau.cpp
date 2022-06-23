/*
 Programme : inverse deux cases d'un tableau
 But : inverse deux cases d'un tableau
 Date de dernière modification : 20/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void echangerCasesTableau(int tableau[], unsigned int case1, unsigned int case2);
//But : echange deux cases dans un tableau
int main(void)
{
    const unsigned int NB_CASES=5;
    int tableau[NB_CASES]={1,2,3,4,5};
    cout<<tableau[1]<<" "<<tableau[4]<<endl; //Affiche les éléments qui vont être inversés
    echangerCasesTableau(tableau,1,4); //appel de la procédure echangerCasesTableau
    cout<<tableau[1]<<" "<<tableau[4]; //Affiche les éléments qui ont été inversés
}

void echangerCasesTableau(int tableau[], unsigned int case1, unsigned int case2)
{
    int temp = tableau[case1];
    tableau[case1]=tableau[case2];
    tableau[case2]=temp;
}