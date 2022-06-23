/**  MODULE bibTableaux 
     regroupe des sous-programmes applicables à des tableaux
     -------------------------------------------------------
But :
    Mettre à dispositon d'un programmeur des sous-programmes applicables aux tableaux.
    Conformes aux exercices des TD n°1 et et 3 de R1.01
    
    Il peut s'agit de tableaux d'entiers ou d'enregistrements de type Personne.
    Les tableaux manipulés doivent être triés par ordre décroissant de valeur.
    Dans le cas des tableaux d'enregistrements de type Personne, ils seront triés par ordre 
    décroissant de nom.
---------

 Date de dernière modification : 26/11/2021
 Auteur : Alexandre MAURICE
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef BIBTABLEAU_H
#define BIBTABLEAU_H

//Observateurs
bool estTrieCroissant(const int tab[],
                      unsigned short int lgTab);

bool estTrieDecroissant(const int tab[],
                        unsigned short int lgTab);

//Recherches
void recherchePremiereOccDichoEntier(int valeur,
                                    const int tab[],
                                    unsigned short int lgTab);

// Primitives d'Entrée-Sortie
void afficherTableauEntiers(const int tab[],
                            unsigned short int lgTab);

// But : affiche à l'écran le contenu d'aun tableau tab contenant lgTab > 0 éléments
//       si lgTab = 0, affiche un message indiquant que le tableau n'a pas de valeur significative (tableau 'vide')

#endif //FRACTION_H