#ifndef MORPION_H
#define MORPION_H
#include <iostream>
using namespace std;

//Déclarations des types

const unsigned int TAILLE_MAX = 9; // Taille maximale que le tableau peu atteindre (TAILLE_MAX> dimension du jeu)

//Déclaration du type Joueur
struct Joueur
{
    string nom;   // nom du joueur
    char symbole; //symbole du joueur
};

//Initialisation

void initialiserMorpion(char morpion[][TAILLE_MAX]);
//BUT initialise un jeu du morpion dans un tableau à deux dimension de taille TAILLE_MAX

//Primitives E/S

void affichage(char morpion[][TAILLE_MAX], unsigned int DIMENSION);
//BUT affiche un tableau de jeu du morpion de dimension DIMENSION

//Jeu

Joueur prochainJoueur(Joueur joueur1, Joueur joueur2, unsigned int nbcoup);
//BUT retourne le prochain joueur à jouer

int charToInt(char car);
//BUT retourne l'entier de type string en type entier

bool caseValide(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, string coordonnees);
//BUT retourne vrais si les coordonnées saisie par le joueur sont correctes.

void placerSymbole(char morpion[][TAILLE_MAX], Joueur joueurActuel, unsigned int i, unsigned int j);
// Place le symbole du joueur Actuel dans le morpion aux coordonnées i j

//Verification de victoire

bool victoireLigne(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, unsigned short int i, const Joueur JoueurActuel);
//BUT retourne un booléen vrais si la ligne i du morpion d'une taille DIMENSION est composé du symbole du joueur actuel

bool victoireColone(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, unsigned short int j, const Joueur JoueurActuel);
//BUT retourne un booléen vrais si la colonne j du morpion d'une taille DIMENSION est composé du symbole du joueur actuel

bool victoireDiagonnaleSecondaire(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, const Joueur JoueurActuel);
//BUT retourne un booléen vrais si la diagonnale secondaire du morpion de taille DIMENSION est composé du symbole du joueur actuel

bool victoireDiagonnalePrincipale(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, const Joueur JoueurActuel);
//BUT retourne un booléen vrais si la diagonnale principale du morpion de taille DIMENSION est composé du symbole du joueur actuel

bool verifierVictoire(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, Joueur joueurActuel, unsigned int i, unsigned int j);
//BUT retourne vrai si le coup du joueur actuel le fait gagné

#endif // MORPION_H