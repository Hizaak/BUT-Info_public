#ifndef CHAINES_H
#define CHAINES_H

#include <iostream> // Pour exploiter le type string
using namespace std;


void rechercherRemplacer (char carARemplacer, char carRemplacement, string& chaine, unsigned int& nbRempla);
/* Remplace dans chaine les occurrences de carARemplacer par carRemplacement.
   nbRempla indique le nombre de remplacements effectués */

unsigned int rechercherRemplacer (char carARemplacer, char carRemplacement, string& chaine);
/* Remplace dans chaine les occurrences de carARemplacer par carRemplacement
   puis retourne le nombre de remplacements réalisés. */

unsigned int nbMots (string phrase);
// retourne le nombre de mots composant phrase

string cesar (string phrase, int cle);
/*
 - Chiffre la chaine phrase avec la clé cle selon le chiffrement de César si cle est positif.
 - Déchiffre la chaine phrase avec la clé cle selon le chiffrement de César si cle est negatif.
Prend en compte les majuscules et plusieurs types de séparateurs (virgule, apostrophe, ...)*/

#endif
