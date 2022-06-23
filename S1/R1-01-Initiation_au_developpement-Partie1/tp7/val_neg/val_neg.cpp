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
    const int NB_CASES=10;
    int tab[NB_CASES]={2,3,-1,-6,8,9,-10,-3,3,7};
    int nbValNeg=0;
    int i;
    for(i=0;i<=NB_CASES-1;i++){
        if(tab[i]<0){
            nbValNeg+=1;
        }
    }
    cout<<nbValNeg;
    return 0;
}