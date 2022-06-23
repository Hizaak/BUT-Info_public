/*
 Programme : Morpion
 But : Permet de dérouler une partie de morpion
 Date de dernière modification : 09/01/2022
 Auteurs : Nicolas DARGAZANLI et Alexandre MAURICE, TD I TP 2
 Remarques : Code conforme aux algorithmes des sous-programmes
 Nous assurons être les uniques auteurs de ces programmes.
*/

#include "morpion.h"
#include <iostream>
using namespace std;

// ----------------------------- INITIALISATION ----------------------------

void initialiserMorpion(char morpion[TAILLE_MAX][TAILLE_MAX])
{
    for (unsigned int i = 0; i < TAILLE_MAX; i++) // Pour toutes les lignes du morpion de taille TAILLE_MAX
    {
        for (unsigned int j = 0; j < TAILLE_MAX; j++) // Pour toutes les cases de la ligne i
        {
            morpion[i][j] = ' '; // Case vide marquée par un espace
        }
    }
}

void personnaliserJoueur(Joueur &joueur1, Joueur &joueur2)
{
    // Personnalisation du joueur1
    cout << "Joueur 1, saississez votre nom : ";
    cin >> joueur1.nom; // Saisie du nom
    cout << joueur1.nom << ", entrez votre symbole : ";
    cin >> joueur1.symbole; // Saisie du symbole
    cout << endl;

    // Personnalisation du joueur2
    cout << "Joueur 2, saississez votre nom : ";
    cin >> joueur2.nom; // Saisie du nom
    // Vérification du nom du joueur2
    while (joueur1.nom == joueur2.nom) // Tant que le joueur2 en rentre pas un autre nom que celui du joueur1 il sera redemandé
    {
        cout << "Ce nom est deja utilise, veuillez en choisir un autre... : ";
        cin >> joueur1.nom;
    }
    cout << joueur2.nom << ", entrez votre symbole : ";
    cin >> joueur2.symbole; // Saisie du symbole
    // Vérification du symbole du joueur2
    while (joueur1.symbole == joueur2.symbole) // Tant que le joueur2 en rentre pas un autre symbole que celui du joueur1 il sera redemandé
    {
        cout << endl
             << "Ce symbole n'est pas utilisable veuillez en choisir un autre... : ";
        cin >> joueur2.symbole;
    }
}

// ----------------------------- PRIMITIVES E/S ----------------------------

void afficherRegles()
{
    cout << "------------------------ MORPION ------------------------" << endl;
    cout << "Jeu avec 2 joueurs et une grille de taille modulable. Chaque joueur joue a tour de role." << endl;
    cout << "Le but du jeu est d aligner, avant son adversaire, X symboles identiques, horizontalement, verticalement ou en diagonale." << endl;
    cout << "Le nombre de symboles X a aligner correspond a la dimension specifiee avant la partie." << endl
         << endl;
    cout << "La partie se termine :" << endl;
    cout << "   - quand l un des joueurs a aligne ses X symboles, auquel cas il gagne." << endl;
    cout << "   - quand la grille est complete, et il y a egalite (pas de gagnant)." << endl;
    cout << "   - quand l un des joueurs abandonne, auquel cas c'est l autre joueur qui gagne." << endl;
    cout << "Chaque joueur a donc son propre symbole." << endl
         << endl;
    cout << "Dans cette version du Morpion, une phase prealable de personnalisation permet a chaque joueur de saisir son prenom et le symbole choisi pour jouer." << endl;
    cout << "Quand un joueur doit jouer il peut :" << endl;
    cout << "   - saisir la position de la case ou placer son symbole, sous la forme LigneColonne (exemple : 12 pour Ligne 1, Colonne 2)" << endl;
    cout << "   - saisir A (ou a) pour abandonner le jeu" << endl
         << endl;
    cout << "Appuyez sur Entree pour continuer...";
    cin.ignore(); // Permet d'entrer une saisie sans traitement afin de laisser à l'utilisateur le temps de lire les règles
}

void demanderDimension(unsigned short int &dimension)
{
    cout << "Saisissez la dimension du morpion : ";
    cin >> dimension;                                          // Première saisie de dimension
    while ((dimension < TAILLE_MIN || dimension > TAILLE_MAX)) //Tant que la dimension n'est comprise entre TAILLE_MIN et TAILLE_MAX inclus
    {
        cout << "La dimension doit etre comprise entre 3 et 9 :";
        cin >> dimension;
    }
}

void afficherMorpion(char morpion[][TAILLE_MAX], const unsigned int DIMENSION)
{
    for (unsigned int i = 0; i < DIMENSION; i++) // Pour toutes les lignes du morpion de taille DIMENSION
    {
        for (unsigned int j = 0; j < DIMENSION; j++) // Pour toutes les cases de la ligne i
        {
            cout << "+---"; // Formation des lignes du quadrillage
        }
        cout << "+" << endl; // Fermeture de la ligne du quadrillage (à droite)
        cout << "| ";        // Délimitation verticale de la grille (à gauche)

        for (unsigned int j = 0; j < DIMENSION; j++) // Pour toutes les cases de la ligne i
        {
            cout << morpion[i][j]; // On affiche le symbole de la case [vide (= espace) ou symbole des joueurs]
            cout << " | ";         // Délimitation des cases et délimitation de la grille droite
        }
        cout << endl;
    }
    for (unsigned int j = 0; j < DIMENSION; j++)
    {
        cout << "+---"; // Formation de la dernière ligne pour refermer le quadrillage
    }
    cout << "+" << endl; // Fermeture de cette même dernière ligne
}

void annoncerResultat(bool victoire, Joueur joueurGagnant, const unsigned int nbCoup)
{
    cout << endl << "Tour numero : " << nbCoup << endl;
    if (victoire) // Si la victoire est déclarée, on annonce que le joueurGagnant a gagné
    {
        cout << endl << joueurGagnant.nom << " a gagne, bravo !";
    }
    // Sinon on annonce l'égalité
    else
    {
        cout << "Il y a egalite, dommage... :(";
    }
}

// ---------------------------------- JEU ----------------------------------

Joueur prochainJoueur(Joueur joueur1, Joueur joueur2, unsigned int nbCoup)
{
    if (nbCoup % 2 == 0) // Si le nombre de coup est pair dans ce cas le joueur1 doit jouer
    {
        return joueur2;
    }
    else
    {
        return joueur1; //Si le nombre de coup est impair dans ce cas le joueur2 doit jouer
    }
}

void jouerCoup(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, Joueur joueur1, Joueur joueur2, Joueur &joueurGagnant, unsigned int &nbCoup, bool &victoire)
{
    Joueur joueurActuel; // Joueur jouant le coup
    string coordonnees;  // Chaîne de caractère des coordonnées données par les joueurs
    unsigned int i;      // Indice de ligne du morpion (saisi par le joueur dans la chaîne de caractères coordonnees)
    unsigned int j;      // Indice de colonne du morpion (saisi par le joueur dans la chaîne de caractères coordonnees)

    // Préparation
    // On determine quel joueur doit jouer en fonction du nombre de coup
    nbCoup += 1; // On ajoute un coup au nombre de coups joués
    joueurActuel = prochainJoueur(joueur1, joueur2, nbCoup);
    // On affiche le morpion pour montrer les cases accessibles au joueur
    afficherMorpion(morpion, DIMENSION);
    cout << endl << "Tour numero : " << nbCoup << endl;

    cout << joueurActuel.nom << ", entrez les coordonnees de la case que vous voulez jouer ou 'a' pour abandonner : ";
    cin >> coordonnees;
    if (coordonnees == "a" || coordonnees == "A")
    {
        joueurGagnant = prochainJoueur(joueur1, joueur2, nbCoup + 1);
        victoire = true;
    }
    if (!victoire)
    {
        // Vérification des coordonnées
        while (!caseValide(morpion, DIMENSION, coordonnees))
        {
            cout << joueurActuel.nom << ", veuillez saisir une coordonnee valide : ";
            cin >> coordonnees;
        }

        // Modification du morpion
        // Conversion des coordonnées
        i = charToInt(coordonnees[0]) - 1; // Conversion pour obtenir l'indice de la ligne du morpion que le joueur veux jouer
        j = charToInt(coordonnees[1]) - 1; // Conversion pour obtenir l'indice de la colonne du morpion que le joueur veux jouer
        placerSymbole(morpion, joueurActuel, i, j);
        if (verifierVictoire(morpion, DIMENSION, joueurActuel, i, j))
        {
            joueurGagnant = joueurActuel; // Si la victoire est déclarée, on détermine enfin le joueurGagnant
            victoire = true;              // On met à jour le booléen victoire
        }
    }
}

void placerSymbole(char morpion[][TAILLE_MAX], Joueur joueurActuel, unsigned int i, unsigned int j)
{
    morpion[i][j] = joueurActuel.symbole; //Place le symbole du joueur dans le morpion dans la case (i,j)
}

// ------------------------------ OBSERVATEURS -----------------------------

bool victoireLigne(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, unsigned int i, const Joueur joueurActuel)
{
    bool victoire = true;                              // On considère la victoire avant la vérification
    for (unsigned short int j = 0; j < DIMENSION; j++) // Parcours du tableau du morpion à la ligne i
    {
        if (morpion[i][j] != joueurActuel.symbole)
        {
            victoire = false; // Si on détecte un autre élément que le symbole du joueur alors il n'y a pas de victoire
        }
    }
    return victoire; // Retour du booléen victoire
}

bool victoireColonne(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, unsigned int j, const Joueur joueurActuel)
{
    bool victoire = true;                              // On considère la victoire avant la vérification
    for (unsigned short int i = 0; i < DIMENSION; i++) // Parcours du tableau du morpion à la colonne j
    {
        if (morpion[i][j] != joueurActuel.symbole)
        {
            victoire = false; // Si on détecte un autre élément que le symbole du joueur alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen victoire
}

bool victoireDiagonalePrincipale(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, const Joueur joueurActuel)
{
    bool victoire = true;                        // On considère la victoire avant la vérification
    for (unsigned int i = 0; i < DIMENSION; i++) // Parcours des cases morpion dans la diagonale principale (haut gauche -> bas droite)
    {
        /*Les cases sur cette diagonnales sont celle vérifiant l'équation : i = j
        où :
        i représente le numéro de la ligne,
        j représente le numéro de la colonne,
        tels que 0 <= (i,j) <= DIMENSION-1 */

        if (morpion[i][i] != joueurActuel.symbole) // Pour simplifier le code, morpion[i][i] est plus clair
        {
            victoire = false; // Si on détecte un autre élément que le symbole du joueur alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen de victoire
}

bool victoireDiagonaleSecondaire(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, const Joueur joueurActuel)
{
    bool victoire = true;                        // On considère la victoire avant la vérification
    for (unsigned int i = 0; i < DIMENSION; i++) // Parcours des cases du morpion dans la diagonale secondaire (haut droite -> bas gauche)
    {
        /*Les cases sur cette diagonnales sont celle vérifiant l'équation : DIMENSION-1-(i+j)=0
        où :
        i représente le numéro de la ligne,
        j représente le numéro de la colonne,
        tels que 0 <= (i,j) <= DIMENSION-1 */

        if (morpion[DIMENSION - 1 - i][i] != joueurActuel.symbole)
        {
            victoire = false; // Si on détecte un autre élément que le symbole du joueur alors il n'y a pas de victoire
        }
    }
    return victoire; //Retour du booléen victoire
}

bool verifierVictoire(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, Joueur joueurActuel, unsigned int i, unsigned int j)
{
    bool trouve = false;              // On considère au début qu'il n'y a pas de victoire
    if (i == j || i + j == DIMENSION) // Si les coordonnées se trouvent sur une diagonale on peut vérifier les diagonnales
    {
        if (victoireDiagonalePrincipale(morpion, DIMENSION, joueurActuel) ||
            victoireDiagonaleSecondaire(morpion, DIMENSION, joueurActuel))
        {
            // Si une victoire est trouvée dans les diagonnales, on met trouve à vrai
            trouve = true;
        }
    }
    //On vérifie la ligne et la colonne de la case
    //Si une victoire est trouvé dans la colonne ou la lignes de la case
    if ((victoireLigne(morpion, DIMENSION, i, joueurActuel) ||
         victoireColonne(morpion, DIMENSION, j, joueurActuel)) &&
        !trouve)
    {
        // Si une victoire est trouvée dans les lignes et les colonnes, on met trouve à vrai
        trouve = true;
    }
    return trouve;
}

bool caseValide(char morpion[][TAILLE_MAX], const unsigned int DIMENSION, string coordonnees)
{
    unsigned int i = charToInt(coordonnees[0]); // Indice de lignes du morpion
    unsigned int j = charToInt(coordonnees[1]); // Indice de colonne du morpion

    /* Les coordonnées saisies par le joueur comprises entre 1 et DIMENSION sont automatiquement adaptées pour correspondre à la manipulation des tableaux en C++
       Le minimum est donc morpion[0][0] et le maximum est morpion[DIMENSION][DIMENSION] */
    // Si i et j sont dans l'intervalle [1,DIMENSION] et que cette case est vide
    if (i >= 1 &&
        i <= DIMENSION &&
        j >= 1 &&
        j <= DIMENSION &&
        morpion[i - 1][j - 1] == ' ')
    {
        return true; //Si tout les conditions sont vérifiés la case est valide
    }
    else
    {
        return false; // Si au moins une des conditions est fausse la case n'est pas valide
    }
}

// --------------------------------- OUTILS --------------------------------

int charToInt(char car)
{
    // Nous récupérons l'entier de type char et le convertissons en int grâce à la table ASCII
    // L'ordre des caractères 0,1,...,9 est le même en ASCII, il faut donc retirer 0 pour avoir le caractère
    return int(car) - int('0');
}