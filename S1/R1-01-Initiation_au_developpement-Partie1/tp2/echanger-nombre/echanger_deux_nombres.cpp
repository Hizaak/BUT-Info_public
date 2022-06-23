#include <iostream>
using namespace std;

int main (void)
{
    // Declaration des variables
    int nb1, nb2, temp;
    cout <<"Entrez la valeur du premier nombre : ";
    cin >> nb1;
    cout <<"Entrez la valeur du second nombre : ";
    cin >> nb2;

    // Echange du pemier et du second nombre
    temp = nb1;
    nb1 = nb2;
    nb2 = temp;

    // Affichage des nombres après l'échange
    cout <<"Le pemier nombre est : "<<nb1<<endl;
    cout <<"Le second nombre est : "<<nb2;
}