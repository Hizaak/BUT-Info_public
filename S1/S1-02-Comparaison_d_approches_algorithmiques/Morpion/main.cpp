
#include "game-tools.h"
#include "morpion.h"
#include <iostream>
using namespace std;

int main(void)
{
    //Varriable et autres types
    Joueur joueur1;
    Joueur joueur2;
    Joueur joueurActuel;
    Joueur JoueurGagant;
    char morpion[TAILLE_MAX][TAILLE_MAX];
    unsigned int nbcoup = 0;
    unsigned int i; //Indice de lignes du morpion
    unsigned int j; //Indice de colonne du morpion
    bool victoire = false;
    string coordonnees;

    //Afficher les règles
    //afficherRegles();

    //Phase Personnalisation
    cout << "----------Phase de Personnalisation----------" << endl;
    short unsigned int dimension = 0;
    while ((dimension < 3 || dimension > 9))
    {
        cout << "Saisissez la dimension du morpion : ";
        cin >> dimension;
    }

    //Joueur 1
    cout << "Joueur 1 : Saississez votre nom : ";
    cin >> joueur1.nom;
    cout << "Joueur 1 : Saississez votre symbole de jeu : ";
    cin >> joueur1.symbole;
    cout << endl;

    //Joueur 1
    cout << "Joueur 2, saississez votre nom : ";
    cin >> joueur2.nom;
    //On verifie le nom  du joueur 2
    while (joueur1.nom == joueur2.nom)
    {

        cout << "Ce nom est deja utilise... Veuillez en choisir un autre... : ";
        cin >> joueur1.nom;
    }

    //Joueur 2
    cout << "Joueur 2, saississez votre symbole de jeu : ";
    cin >> joueur2.symbole;
    while (joueur1.symbole == joueur2.symbole)
    {

        cout << endl
             << "Ce symbole n'est pas utilisable veuillez en choisir un autre... : ";
        cin >> joueur2.symbole;
    }

    initialiserMorpion(morpion);
    effacer();
    //Debut de la partie
    while (!victoire && nbcoup < dimension * dimension)
    {
        effacer();
        nbcoup += 1;
        joueurActuel = prochainJoueur(joueur1, joueur2, nbcoup);
        //Le joueur actuel joue un coup
        affichage(morpion, dimension);
        cout << joueurActuel.nom << ", entrez les coordonnees de la case que vous voulez jouer ou 'a' pour abandonner : ";
        cin >> coordonnees;
        if (coordonnees == "a")
        {
            JoueurGagant = prochainJoueur(joueur1, joueur2, nbcoup + 1);
            victoire = true;
            break;
        };
        while (!caseValide(morpion, dimension, coordonnees))
        {
            cout << joueurActuel.nom << ", vous etes debile : ";
            cin >> coordonnees;
        }
        i = charToInt(coordonnees[0]) - 1; //Indice de la ligne du morpion que le joueur veux jouer
        j = charToInt(coordonnees[1]) - 1; //Indice de la colonne du morpion que le joueur veux jouer
        placerSymbole(morpion, joueurActuel, i, j);
        //test(morpion,dimension, joueurActuel, i, j);
        if (verifierVictoire(morpion, dimension, joueurActuel, i, j))
        {
            JoueurGagant = joueurActuel;
            victoire = true;
        }

        affichage(morpion, dimension);
    }
    if (victoire)
    {
        cout << endl
             << JoueurGagant.nom << " a gagne wow";
    }
    else
    {
        cout << "Personne a gagne.. Vous etes debiles";
    }

    return 0;
}
