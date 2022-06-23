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
    char c;
    chaine="starfoulah";
    int i=int(chaine.size()-1);
    while(i>=0){
        c=chaine[i];
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y'){
            cout<<i;
            break;
        }
        i--;
    }
    return 0;
}