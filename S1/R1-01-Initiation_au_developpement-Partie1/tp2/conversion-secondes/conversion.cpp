#include <iostream>
using namespace std;

int main (void)
{
    // Declaration de variables
    int heures, minutes, secondes;
    // L utilisateur rentre les valeurs associees
    cout<<"Saisissez le nombre d heures : ";
    cin >> heures;
    cout<<"Saisissez le nombre de minutes : ";
    cin >> minutes;
    // Calcul
    secondes = heures * 3600 + minutes * 60;
    // Affichage
    cout <<"Cela fait tres exactement "<<secondes<<" secondes chef.";
}