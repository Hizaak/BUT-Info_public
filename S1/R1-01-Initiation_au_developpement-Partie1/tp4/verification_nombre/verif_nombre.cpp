#include <iostream>
using namespace std;

int main (void)
{
    //Initialisation
    double note;
    //Programme principal
    do {
        cout<<"Saisir une valeur entre 0 et 20 : ";
        cin>>note;
    } while (! (0 <= note && note <= 20));

    cout<<"Merci !";
}