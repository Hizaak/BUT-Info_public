/*
Programme : Jeu du pendu
But : trouver le mot caché avec 7 tentatives incorrectes tolérées
Date de dernière modification : 15 octobre 2021
Auteur : Nicolas DARGAZANLI & Alexandre MAURICE
Remarques : Conforme aux spécifications initiales. Les deux extensions ont été traitées.
*/

#include <iostream>
#include "game-tools.h"
using namespace std;

int main(void)
{
    //Déclaration de variables
    int idxTheme;                   // Indice du thème que l'utilisateur à choisi
    const int nbMotTheme = 12;      // Nombre de mot dans chaque thème
    char lettre;                    // Lettre proposée par le joueur
    string mot = "";                // Mot à deviner
    short unsigned int i;           // Indice de boucle
    int tentativesRestante = 7;     // Nombre de tentative incorrectes restantes
    string lettresIncorrectes = ""; // Toutes les lettres incorrectes deja proposées par le joueur
    bool trouve;                    // true si la lettre saisie est dans le mot
    bool dejaVuCorrecte;            // true si la lettre saisie a déjà été rencontrée et était correcte
    bool dejaVuIncorrecte;          // true si la lettre saisie a déjà été rencontree et était incorrecte

    //Création des thèmes (tableaux de mots) pouvant être proposés
    string informatique[nbMotTheme] = {"ordinateur", "programme", "logiciel", "algorithme", "compilation", "processeur", "moniteur", "peripherique", "binaire", "memoire", "imprimante", "disques"};
    string mathematiques[nbMotTheme] = {"addition", "operation", "arithmetique", "exponentielle", "proportionnalite", "fraction", "arrangement", "divisibilite", "logarithme", "multiplicite", "equation", "scalaire"};
    string cinema[nbMotTheme] = {"godzilla", "shining", "avengers", "realisateur", "spiderman", "producteur", "jumanji", "ironman", "camera", "annabelle", "titanic", "panoramique"};

    //Premier affichage du nom du jeu
    cout << "**Jeu du pendu**" << endl
         << endl;

    //Sélection du mot à deviner en fonction du theme et vérification
    do
    {
        cout << "[1] Informatique" << endl
             << "[2] Mathematiques" << endl
             << "[3] Cinema" << endl
             << endl
             << "Choisissez un theme : ";
        cin >> idxTheme;  //On demande a l'utilisateur de saisir un thème à jouer
        switch (idxTheme) //Switch de definition du theme à jouer
        {
        case 1:
            mot = informatique[random(0, nbMotTheme - 1)]; //Selectionne aléatoirement un mot dans le tableau du theme Informatique
            break;
        case 2:
            mot = mathematiques[random(0, nbMotTheme - 1)]; //Selectionne aléatoirement un mot dans le tableau du theme Mathematiques
            break;
        case 3:
            mot = cinema[random(0, nbMotTheme - 1)]; //Selectionne aléatoirement un mot dans le tableau du theme Cinema
            break;

        default:
            cout << "Theme non reconnu... Recommencez." << endl; //Dans le cas où l'indice du thème n'est pas reconnu on affiche un message d'erreur
            break;
        }
    } while (mot == ""); //Si le mot est vide, cela veut dire que aucun thème n'a été sélectionné.

    //Génère le mot affiché à l'écran en fonction du nombre de lettre du mot à deviner.
    //Le mot affiché est alors pour l'instant une suite de tirets.
    string motcache = ""; // Mot caché qui se revèlera au fur et à mesure de la partie
    for (i = 0; i <= mot.size() - 1; i++)
    {
        motcache += '-'; //On ajoute un '-' jusqu'a ce que la taille des deux mots soit égale
    }

    //###################
    // Debut de la partie
    //###################
    while (tentativesRestante > 0 && motcache != mot) // Tant qu'il reste des tentatives au joueur et qu'il n'a pas trouvé le mot, le jeu continue
    {
        //Affichage
        effacer(); //Efface le terminal
        cout << "**Jeu du pendu**" << endl
             << endl; //Réaffiche le nom du jeu
        cout << "Le mot a trouver : " << motcache << endl
             << endl; //Affichage du mot à deviner sous forme de tirets

        if (tentativesRestante > 4)
        { //Si le nombre de tentatives est supérieur à 4, il sera affiché en vert
            afficherTexteEnCouleur("Nombre de coups restant : ", vert);
            afficherNombreEnCouleur(tentativesRestante, vert, true);
        }
        if (tentativesRestante <= 4 && tentativesRestante >= 2)
        { //Si le nombre de tentatives est compris entre 4 et 2 inclus, il sera affiché en violet
            afficherTexteEnCouleur("Nombre de coups restant : ", violet);
            afficherNombreEnCouleur(tentativesRestante, violet, true);
        }
        if (tentativesRestante == 1)
        { //Quand il ne reste plus que une seule tentative, on l'affiche en rouge
            afficherTexteEnCouleur("Nombre de coups restant : ", rouge);
            afficherNombreEnCouleur(tentativesRestante, rouge, true);
        }

        //Reinitialisation des booleens et des indices avant la prochaine recherche
        dejaVuIncorrecte = false;
        dejaVuCorrecte = false;
        trouve = false;
        i = 0;

        //Saisie de la lettre à jouer
        cout << "Entrez une lettre : ";
        cin >> lettre;
        cout << endl;

        //On verifie si la lettre a deja été rencontrée et si elle est incorrecte
        while (i < lettresIncorrectes.size()) //Tant que i est inférieur à la longueur du mot composé de toutes les lettres incorrectes :
        {
            if (lettresIncorrectes[i] == lettre)
            {                            //Si la lettre rencontrée est la même que la lettre déjà stockée
                dejaVuIncorrecte = true; //alors le booléen dejaVuIncorrecte devient true
                break;                   //Il ne sert donc à rien de continuer la recherche
            }
            i++; //Incrémentation de i
        }
        //On verifie si la lettre a deja été rencontrée et si elle est correcte
        //On utilise le mot caché comme moyen pour connaître les lettres correctes déjà saisies.
        if (!dejaVuIncorrecte)
        {                               //Si la lettre est incorrecte pas besoin de la rechercher dans les lettres correctes
            i = 0;                      //Reinitialisation de i
            while (i < motcache.size()) //Tant que i est inférieur à la longueur du mot caché.
            {
                if (motcache[i] == lettre)
                {                          //Si la lettre rencontrée est la même que la lettre déjà stockée
                    dejaVuCorrecte = true; //alors le booléen dejaVuCorrecte devient true
                    break;                 //Il ne sert donc à rien de continuer la recherche
                }
                i++; //Incrémentation de i
            }
        }
        if (!dejaVuIncorrecte && !dejaVuCorrecte)
        {                                         //Dans le cas où la lettre saisie n'a jamais été rencontrée
            for (i = 0; i <= mot.size() - 1; i++) //On recherche cette lettre dans le mot à deviner
            {
                if (mot[i] == lettre)
                {                         //Si la lettre rencontrée est la même que la lettre dans le mot à deviner
                    motcache[i] = lettre; //On remplace les tirets par la lettre trouvée
                    trouve = true;
                }
            }
            if (trouve)
            { //Si la lettre a été trouvée dans le mot
                cout << "La lettre " << lettre << " EST presente dans le mot :-) " << endl;
            }
            else
            { //Dans le cas contraire
                cout << "La lettre n'est PAS presente dans le mot :-( " << endl;
                lettresIncorrectes += lettre; //On ajoute la lettre Incorrecte dans la chaines des lettres incorrectes
                tentativesRestante--;         //On retire une tentatives au joueur
            }
        }
        else
        { //Dans le cas où la lettre saisie a déjà été rencontrée
            if (dejaVuIncorrecte)
            { //Si elle est Incorrecte on indique au joueur son erreur
                cout << "Vous avez deja essaye cette lettre et elle n'est toujours pas dans le mot..." << endl;
                tentativesRestante--;
            } //On lui retire au passage une tentative.
            if (dejaVuCorrecte)
            { //Si la lettre est Correcte on indique au joueur son étourderie mais sans lui retirer de tentatives
                cout << "Vous avez deja trouve cette lettre...Essayez en d'autres :)" << endl;
            }
        }

        pause(2); // Pause de 2 secondes pour laisser le temps au joueur de voir le résultat de la recherche
    }
    //Fin du jeu, Affichage du résultat
    effacer(); // On efface le terminal
    cout << "**Jeu du pendu**" << endl
         << endl; //Réaffiche le nom du jeu une dernière fois
    if (motcache == mot)
    { //Le joueur a gagné
        afficherTexteEnCouleur("B R A V O\nVous avez gagne\nVous avez trouve le mot cache ! :)", vert, true);
    }
    else
    { //Le joueur a perdu
        afficherTexteEnCouleur("P E R D U\nOh Non...\nOn dirait que vous avez manque de tentatives. :(", rouge, true);
    }
    //Affichage du mot à deviner
    cout << "Le mot etait : ";
    afficherTexteEnCouleur(mot, bleu, true);
    return 0;
}