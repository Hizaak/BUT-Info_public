/**  MODULE Fractions
     permettant la manipulation de nombres RATIONNELS
     Implémentation proche d'un Type Abstrait de Données (TAD) 
     ----------------------------------------------------------------------
But :
    En tant que TAD, il met à disposition :
    - Un type Fraction, composé :
        ...d'un numérateur, entier portant le signe de la fraction
        ...d'un dénominaeur > 0

    - Une constante FRACTIONNULLE = 0/1
    - Des primitives (= sous-programmes) permettant de :
        ...faire des calculs entre fractions : addition, soustraction, multiplication, division
        ...comparer des fractions : égal, supérieur, inférieur
        ...afficher à l'écran une fraction ou saisir une fraction au clavier

    Afin de se rapprocher de l'usage mathématique, toutes les primitives de calcul mathématique :
    - attendent en paramètre donnée des fractions irréductibles
    - produisent des fractions irréductibles.
    L'utilisation du type Fraction impose par ailleurs que le numérateur soit porteur du signe de la fraction et que le dénominateur est > 0.
---------

 Date de dernière modification : xxxx
 Auteur : xxx
 Remarques : Code conforme aux spécification précisées dans le sujet R1.01-partie2 - td n°2
*/

#ifndef FRACTIONS_H
#define FRACTIONS_H

//Types
struct Fraction
{
     int num;           //Numérateur, porteur du signe de la fraction
     unsigned int den;  //Dénominateur, doit être >0
};

//Constantes
const Fraction FRACTION_NULLE={0,1};

//Pas de constructeur dans cette version

//Observateurs

//Accesseurs

//Opérateurs binaires

//Opérateurs de comparaison

//Autre primitive

//Primitives d'Entrée / Sortie
void afficher(Fraction frac);
// affiche à l'écran le contenu du paramètre fraction frac sous sa forme irréductible
// pré-condition : le paramètre frac est une fraction irréductible

Fraction saisir();
// Retourne une fraction irréductible à partir de 2 valeurs entières saisies au clavier
// post-condition : la fraction retournée est une fraction irréductible normalisée

#endif //FRACTION_H