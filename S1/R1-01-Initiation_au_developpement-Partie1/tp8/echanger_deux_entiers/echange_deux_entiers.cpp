/*
 Programme : echange deux entiers d'un tableau
 But : echange deux entiers d'un tableau
 Date de dernière modification : 20/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/
#include <iostream>
using namespace std;

//Déclaration des sous-programmes
void echangerNombres(int& nb1, int& nb2);
//But : échange deux nombres en position nb1 et nb2 d'un tableau

int main(void)
{
    //Déclaration des variables
    int valeur1=3;
    int valeur2=1;
    cout << valeur1<<" "<<valeur2<<endl;
    echangerNombres(valeur1,valeur2); //Appel de la procédure calculer echangerNombres
    cout << valeur1<<" "<<valeur2;
}

void echangerNombres(int& nb1, int& nb2)
{
    int nb3 = nb1;
    nb1 = nb2;
    nb2 = nb3;
}