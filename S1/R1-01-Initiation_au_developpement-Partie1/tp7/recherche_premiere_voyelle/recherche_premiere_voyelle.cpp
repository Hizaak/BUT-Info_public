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
    string chaine;
    int i=0;
    char c;
    chaine="bqqqqqq";
    while(i<=int(chaine.size())){
        c=chaine[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y'){
            cout<<i;
            break;
        }
        i++;
    }
}