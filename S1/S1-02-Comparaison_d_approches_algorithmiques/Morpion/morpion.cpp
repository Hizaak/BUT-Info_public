#include "morpion.h"

#include <iostream>
using namespace std;





//BUT initialise un jeu du morpion dans un tableau à deux dimension de taille TAILLE_MAX
void initialiserMorpion(char morpion[TAILLE_MAX][TAILLE_MAX])
{
    for (unsigned int i = 0; i < TAILLE_MAX; i++) //Pour toutes les lignes du morpion de taille DIMENSION
    {
        for (unsigned int j = 0; j < TAILLE_MAX; j++) // Pour toutes les cases de la ligne i
        {
            morpion[i][j] = ' '; //Case vide marqué par un espace vide
        }
    }
}

void affichage(char morpion[][TAILLE_MAX], const unsigned int DIMENSION)
{
    for (size_t i = 0; i < DIMENSION; i++)
    {
        for (size_t j = 0; j < DIMENSION; j++)
        {
            cout << "+---";
        }
        cout << "+" << endl; //Affichage d'une ligne

        cout << "| ";

        for (size_t j = 0; j < DIMENSION; j++)
        {
            cout << morpion[i][j];
            cout << " | ";
        }

        cout << endl;
    }

    for (size_t j = 0; j < DIMENSION; j++)
    {
        cout << "+---";
    }
    cout << "+" << endl; //Affichage d'une ligne
}

//BUT retourne un booléen vrais si la ligne i du morpion d'une taille DIMENSION est composé du symbole du joueur actuel
bool victoireLigne(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, unsigned int i, const Joueur JoueurActuel)
{

    bool victoire = true;                              //On assume une victoire avant la verification
    for (unsigned short int j = 0; j < DIMENSION; j++) //Parcours du tableau du morpion à la ligne i
    {
        if (morpion[i][j] != JoueurActuel.symbole)
        {                     //Si on constate autre chose que le symbole du joueur
            victoire = false; // alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen de victoire
}

//BUT retourne un booléen vrais si la colonne j du morpion d'une taille DIMENSION est composé du symbole du joueur actuel
bool victoireColone(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, unsigned int j, const Joueur JoueurActuel)
{

    bool victoire = true;                              //On assume une victoire avant la verification
    for (unsigned short int i = 0; i < DIMENSION; i++) //Parcours du tableau du morpion à la ligne j
    {
        if (morpion[i][j] != JoueurActuel.symbole)
        {                     //Si on constate autre chose que le symbole du joueur
            victoire = false; // alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen de victoire
}

//BUT retosurne un booléen vrais si la diagonnale secondaire du morpion de taille DIMENSION est composé du symbole du joueur actuel
bool victoireDiagonnaleSecondaire(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, const Joueur JoueurActuel)
{

    bool victoire = true;                        //On assume une victoire avant la verification
    for (unsigned int i = 0; i < DIMENSION; i++) //Parcours des cases morpion dans la diagonale secondaire (haut droite -> bas gauche)
    {
        /*Les cases sur cette diagonnales sont celle vérifiant l'équation n-1-(i+j)=0
        où n représente l'ordre de la matrice,
        i représente le numéro de la ligne,
        j représente le numéro de la colonne,
        tels que 0<=(i,j)<=DIMENSION-1*/

        if (morpion[DIMENSION - 1 - i][i] != JoueurActuel.symbole)
        {                     //Si on constate autre chose que le symbole du joueur
            victoire = false; // alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen de victoire
}

Joueur prochainJoueur(Joueur joueur1, Joueur joueur2, unsigned int nbcoup)
{
    if (nbcoup % 2 == 0)
    {
        return joueur2;
    }
    else
    {
        return joueur1;
    }
}

//BUT retourne un booléen vrais si la diagonnale principale du morpion de taille DIMENSION est composé du symbole du joueur actuel
bool victoireDiagonnalePrincipale(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, const Joueur JoueurActuel)
{

    bool victoire = true;                        //On assume une victoire avant la verification
    for (unsigned int i = 0; i < DIMENSION; i++) //Parcours des cases morpion dans la diagonale principale (haut gauche -> bas droite)
    {
        //Les cases sur cette diagonnale sont celle avec le même numero de ligne et colonne
        if (morpion[i][i] != JoueurActuel.symbole)
        {                     //Si on constate autre chose que le symbole du joueur
            victoire = false; // alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen de victoire
}

int charToInt(char car)
{
    return int(car) - int('0');
}

void placerSymbole(char morpion[][TAILLE_MAX], Joueur joueurActuel, unsigned int i, unsigned int j)
{
    morpion[i][j] = joueurActuel.symbole;
}

bool verifierVictoire(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, Joueur joueurActuel, unsigned int i, unsigned int j)
{
    bool trouve = false;
    if (i == j || i + j == DIMENSION)
    {
        if (
            victoireDiagonnalePrincipale(morpion, DIMENSION, joueurActuel) ||
            victoireDiagonnaleSecondaire(morpion, DIMENSION, joueurActuel))
        {
            trouve = true;
        }
    }

    if (victoireLigne(morpion, DIMENSION, i, joueurActuel) ||
        victoireColone(morpion, DIMENSION, j, joueurActuel))
    {
        trouve = true;
    }
    return trouve;
}



bool caseValide(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, string coordonnees)
{
    unsigned int i = charToInt(coordonnees[0]); //Indice de lignes du morpion
    unsigned int j = charToInt(coordonnees[1]); //Indice de colonne du morpion
    if (i >= 1 &&
        i <= DIMENSION &&
        j >= 1 &&
        j <= DIMENSION &&
        morpion[i - 1][j - 1] == ' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}