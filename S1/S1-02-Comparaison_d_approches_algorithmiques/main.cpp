/*
 Programme : Morpion
 But : Permet de dérouler une partie de morpion
 Date de dernière modification : 09/01/2022
 Auteurs : Nicolas DARGAZANLI et Alexandre MAURICE, TD I TP 2
 Remarques : Code conforme à l'algorithme principal
*/

#include "game-tools.h"
#include "morpion.h"
#include <iostream>
using namespace std;

int main(void)
{
    // Déclaration des variables
    Joueur joueur1;                       // Enregistrement du joueur1
    Joueur joueur2;                       // Enregistrement du joueur2
    Joueur joueurGagnant;                 // Enregistrement du joueur qui aura gagné plus tard
    unsigned short int dimension = 0;     // Dimension de la grille du morpion jouable, initialisé à 0 avant demande
    char morpion[TAILLE_MAX][TAILLE_MAX]; // Initialisation de la grille du morpion de taille TAILLE_MAX. Cette taille ne represente pas forcément la taille jouable
    unsigned int nbcoup = 0;              // Nombre de coups joués au fur et à mesure de la partie
    bool victoire = false;                // Booléen de victoire, si il est vrai, cela veut dire qu'un des deux joueurs a gagné

    afficherRegles(); // Affiche les règles du jeu
    effacer();

    // Phase Personnalisation
    cout << "----------Phase de Personnalisation----------" << endl;
    demanderDimension(dimension);          // On demande une taille pour la grille du morpion [VÉRIFIÉ]
    initialiserMorpion(morpion);           // On initialise une grille de jeu
    personnaliserJoueur(joueur1, joueur2); // Personnalisation des joueurs : noms, symboles
    effacer();

    // Phase de jeu
    while (!victoire && nbcoup < dimension * dimension) // Tant qu'une victoire n'est pas déclarée ou que la grille n'est pas remplie totalement
    {
        jouerCoup(morpion, dimension, joueur1, joueur2, joueurGagnant, nbcoup, victoire); // On joue un coup, le bon joueur sera automatiquement choisi
        effacer();                                                                        // On efface l'ecran à chaque coup joué
    }

    // Fin de la partie
    afficherMorpion(morpion, dimension);       // On affiche le morpion après le dernier coup
    annoncerResultat(victoire, joueurGagnant, nbcoup); // Si la victoire est déclarée (victoire = true), on félicite le joueurGagnant
    return 0;
}