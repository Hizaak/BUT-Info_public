/**
 * @file Individu.h
 * @author Alexandre Maurice (contact@alexandremaurice.fr)
 * @brief Spécifie une classe Individu en relation réciproque avec sa Voiture
 * @details Paragraphe 1, Paragraphe 1, Paragraphe 1, Paragraphe 1, Paragraphe 1, Paragraphe 1, Paragraphe 1, Paragraphe 1, Paragraphe 1.
 * 
 * Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2, Paragraphe 2.
 * 
 * Paragraphe 3, Paragraphe 3, Paragraphe 3, Paragraphe 3, Paragraphe 3, Paragraphe 3.
 * 
 * @version 0.1
 * @date 12-08-2022
 * 
 * @warning A un Individu correspond au plus une Voiture
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef INDIVIDU_H
#define INDIVIDU_H

using namespace std;

#include "Voiture.h" // Utilisée ci-dessous
#include <iostream>

class Voiture; /* Annonce une définition ultérieure de Voiture
                   permet de faire référence aux membres de Voiture dans la classe Individu */

/**
 * @brief Représente un individu via son nom, son prénom et sa voiture
 * @deprecated Utilisez à la place la classe Personne qui est plus récente
 * 
 */
class Individu
{
    // ATTRIBUTS
  public:
    /**
     * @brief Le nom de l'individu
     */
    string nom;
    /**
     * @brief Le prénom de l'individu
     */
    string prenom;
    /**
     * @brief Lien avec la voiture de l'individu
     */
    Voiture *maVoiture;

    // MÉTHODES
  public:
    /**
     * @brief Construit un nouvel objet individu
     */
    Individu(string = "", string = "");
    /**
     * @brief Détruit un objet Individu à partir de son nom et de son prénom
     */
    ~Individu();

    /**
     * @brief Retourne l'identité de l'Individu
     * 
     * @return une chaine de caractère sous la forme "nom prénom"
     * @bug Problème de formatage des espaces entre le nom et le prénom
     * @todo Ajouter un paramètre pour préciser si on veut un affichage du type "nom prénom" ou "prénom nom"
     */
    string toString();
    string toStringAndLink(); // Affiche l'identité de l'Individu et de sa Voiture s'il en a une

    // Méthodes spécifiques
    void majMaVoiture(Voiture* voiture);
    /**
     * @brief Définit la voiture de l'Individu
     * 
     * @param voiture pointeur vers l'objet Voiture piloté par l'Individu
     */
    void setMaVoiture(Voiture* voiture);
    void supprimerLien();
};

#endif // INDIVIDU_H