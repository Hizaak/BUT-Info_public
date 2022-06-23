#include <iostream>
using namespace std;

int main (void)
{
    // Déclarations des variables
    double val1; // Valeur 1
    double val2; // Valeur 2
    char oper; // Opérateur
    double resultat; // Résultat
    // Entrées de l'utilisateur
    cout<<"Entrez le premier nombre : ";
    cin>>val1; // Affectation
    cout<<"Entrez l'operateur : ";
    cin>>oper; // Affectation
    cout<<"Entrez le second nombre : ";
    cin>>val2; // Affectation
    cout<<endl;
    // Programme de calcul
    switch(oper) 
    {
        case '+' : // Si c'est égal à une addition
            resultat = val1 + val2;
            cout<<val1<<" + "<<val2<<" = "<<resultat;
            break;
        case '-' : // Si c'est égal à une soustraction
            resultat = val1 - val2;
            cout<<val1<<" - "<<val2<<" = "<<resultat;
            break;
        case '*' : // Si c'est égal à une multiplication
            resultat = val1 * val2;
            cout<<val1<<" * "<<val2<<" = "<<resultat;
            break;
        case '/' : // Si c'est égal à une division
            if(val2==0){ // Si on divise par 0 :
                cout<<"Erreur : division par 0"; // Afficher une erreur
                break;
            }
            else
            {
                resultat = val1 / val2; // Sinon, calculer la division
                cout<<val1<<" / "<<val2<<" = "<<resultat; // Affichage
                break;
            }
        default : // Dans le cas où aucun opérateur n'est correct
            cout<<"Operateur invalide.";
        }
    return 0;
}