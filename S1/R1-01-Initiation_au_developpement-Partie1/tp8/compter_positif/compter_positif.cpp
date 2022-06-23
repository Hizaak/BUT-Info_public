/*
 Programme : nombre de valeurs positives d'un tableau
 But : compte le nombre de valeurs positives d'un tableau
 Date de dernière modification : 21/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void nombrePositifsTab(int tableau[], unsigned int NB_CASES, unsigned int &nbPositifs);
//But : compte le nombre de valeurs positives nbPositifs dans un tableau tableau de taile NB_CASES

int main(void)
{
    const unsigned int NB_CASES = 5;
    int tableau[NB_CASES] = {1, 2, 3, 4, 5};
    unsigned int nbPositifs = 0;
    nombrePositifsTab(tableau, NB_CASES, nbPositifs); //appel de la procédure
    cout<<nbPositifs;
}

void nombrePositifsTab(int tableau[], unsigned int NB_CASES, unsigned int &nbPositifs)
{
    unsigned int i;
    for(i=0;i<NB_CASES;i++){
        if(tableau[i]>=0){
            nbPositifs++;
        }
    }
}