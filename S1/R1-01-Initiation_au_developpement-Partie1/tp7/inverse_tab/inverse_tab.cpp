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
    int tab[NB_CASES]={1,2,3,4,5,6,7,8,9,10};
    int i=0;
    int temp;
    while(i<=NB_CASES/2){
        temp=tab[i];
        tab[i]=tab[NB_CASES-i];
        tab[NB_CASES-i]=temp;
        i++;
    }
    for(i=0;i<=NB_CASES;i++){
        cout<<tab[i]<<endl;
    }
    return 0;
}
