#include <iostream>
using namespace std;

int main (void)
{
    // Declaation des variables
    double initial, reduction, final;
    // L utilisateur rentre les valeurs associees
    cout <<"Quel est le prix initial du produit ? (en euros) ";
    cin >> initial;
    cout <<"Quel est la reduction appliquee ? (en pourcentages) ";
    cin >> reduction;
    // On applique la formule
    final = initial * ((100-reduction)/100);
    // Affichage du prix final
    cout <<"Le prix final du produit est : "<<final<<" euros.";
}