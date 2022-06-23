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
    cout<<"Saisissez la chaine de caracteres : ";
    cin>>chaine;
    while(true){
        if(chaine[i]!=chaine[int(chaine.size()-i-1)]){
            cout<<"Ce n'est pas un palindrome";
            break;
        }
        if(i>int(chaine.size())/2){
            cout<<"C'est un palindrome";
            break;
        }
        i++;
    }
    return 0;
}
