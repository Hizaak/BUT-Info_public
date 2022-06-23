/*
 Programme : Morpion
 But : Permet de dérouler une partie de morpion
 Date de dernière modification : 09/01/2022
 Auteurs : Nicolas DARGAZANLI et Alexandre MAURICE, TD I TP 2
 Remarques : Déclarations conformes aux programmes
*/

#ifndef MORPION_H
#define MORPION_H
#include <iostream>
using namespace std;

// ------------- DÉCLARATION DES TYPES ET VARIABLES CONSTANTES -------------

// Taille minimale que le tableau peut atteindre (TAILLE_MIN <= dimension du jeu)
const unsigned int TAILLE_MIN = 3;

// Taille maximale que le tableau peut atteindre (TAILLE_MAX => dimension du jeu)
const unsigned int TAILLE_MAX = 9;

// Déclaration du type Joueur
struct Joueur
{
    string nom;   // nom du joueur
    char symbole; //symbole du joueur
};

// ----------------------------- INITIALISATION ----------------------------

void initialiserMorpion(char morpion[][TAILLE_MAX]);
// But : initialise un jeu du morpion dans un tableau à deux dimension de taille TAILLE_MAX

void personnaliserJoueur(Joueur &joueur1, Joueur &joueur2);
/* But : Sous programme qui permet d'attribuer un nom et symbole aux joueurs
    - Le joueur1 est le premier à etre personnalisé
    - Le joueur2 est lui aussi personnalisé
      POST-CONDITION : le joueur2 a un nom et un symbole différent du joueur1
*/

// ----------------------------- PRIMITIVES E/S ----------------------------

void afficherRegles();
/* But : affiche les règles du jeu du morpion
   Pour sortir de l'affichage des règles, il faut appuyer sur "Entrée". */

void demanderDimension(unsigned short int &dimension);
/* But : Demander la dimension de la grille de jeu du morpion 
   POST-CONDITION : la dimension est comprise entre TAILLE_MIN = 3 et TAILLE_MAX = 9 */

void afficherMorpion(char morpion[][TAILLE_MAX], unsigned int DIMENSION);
// But : Affiche une grille du jeu du morpion de la taille choisie

void annoncerResultat(bool victoire, Joueur joueurGagnant, const unsigned int nbCoup);
/* But : Annonce résultat de la patie
    - Si la victoire est déclarée (victoire = vrai), alors le joueurGagnant est félicité
    - Sinon, on déclare une égalité */

// ---------------------------------- JEU ----------------------------------

Joueur prochainJoueur(const Joueur joueur1, const Joueur joueur2, unsigned int nbcoup);
// But : Retourne le prochain Joueur à jouer entre le joueur1 et le joueur2 en fonction du nombre de coups déjà joués

void jouerCoup(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, const Joueur joueur1, const Joueur joueur2, Joueur &joueurGagnant, unsigned int &nbcoup, bool &victoire);
/* But : Joue un coup dans le jeu du morpion dans une grille de taille DIMENSION
        - Le joueur actuel (jouant le coup) est choisi dans le sous programme entre le joueur1 et le joueur2
        - Le joueurGagnant sera mis a jour si un des deux joueurs gagne ainsi que mettre a jour le booleen victoire
        - Le nombre de coups sera mis à jour a chaque appel
    POST-CONDITION : le coup joué est joué à une coordonnée libre
*/

void placerSymbole(char morpion[][TAILLE_MAX], const Joueur joueurActuel, unsigned int i, unsigned int j);
/* But : Place le symbole du joueurActuel dans le morpion aux coordonnées (i,j)
    - i représentant la ligne
    - j représentant le colonne */

// ------------------------------ OBSERVATEURS -----------------------------

bool victoireLigne(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, unsigned short int i, const Joueur JoueurActuel);
// But : retourne vrai si la ligne i du morpion de taille DIMENSION saisie par le joueurActuel est complétée par son symbole

bool victoireColonne(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, unsigned short int j, const Joueur JoueurActuel);
// But : retourne vrai si la colonne j saisie par le joueurActuel est complétée par son symbole

bool victoireDiagonalePrincipale(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, const Joueur JoueurActuel);
// But : retourne vrai si la diagonalePrincipale est complétée par le symbole du joueurGagnant

bool victoireDiagonaleSecondaire(char morpion[][TAILLE_MAX], const unsigned short int DIMENSION, const Joueur JoueurActuel);
// But : retourne vrai si la diagonaleSecondaire est complétée par le symbole du joueurGagnant

bool verifierVictoire(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, Joueur joueurActuel, unsigned int i, unsigned int j);
// But : retourne vrai si les coordonnées (i,j) saisies par le joueurActuel permettent à celui-ci de gagner

bool caseValide(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, string coordonnees);
/* But : retourne vrai si les coordonnées saisie par le joueur peuvent être inserées dans le morpion de taille DIMENSION.
    Vérifie :
        -  Si la case saisie est accessible dans la zone de jeu morpion
        -  Si la case saisie n'a pas déjà été jouée par un des deux joueurs
*/

// --------------------------------- OUTILS --------------------------------

int charToInt(char car);
/* But : retourne l'entier de type char en type int
   PRÉ-CONDITON : le caractère char est compris entre 1 et 9 inclus */

#endif // MORPION_H