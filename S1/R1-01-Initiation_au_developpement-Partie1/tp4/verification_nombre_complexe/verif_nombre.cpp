#include <iostream>
using namespace std;

int main (void)
{
    //Initialisation
    double note;
    //Programme principal
    cout<<"Saisir une valeur entre 0 et 20 : ";
    do {
        cin>>note;
        if(! (0 <= note && note <= 20)){
            cout<<"La valeur doit etre comprise entre 0 et 20. Recommencez : ";
        }
    } while (! (0 <= note && note <= 20));
    cout<<"Merci !";
}