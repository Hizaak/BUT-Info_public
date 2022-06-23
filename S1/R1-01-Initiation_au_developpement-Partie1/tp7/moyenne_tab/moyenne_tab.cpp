/*
 Programme :
 But :
 Date de dernière modification :
 Auteur :
 Remarques :
*/
#include <iostream>
using namespace std;

int main (void)
{
    const int NB_CASES=2;
    int tab[NB_CASES]={10,10};
    int somme=0;
    int i;
    double moyenne;
    for(i=0;i<=NB_CASES-1;i++){
        somme+=tab[i];
    }
    moyenne=somme/i;
    cout<<moyenne;
    return 0;
}