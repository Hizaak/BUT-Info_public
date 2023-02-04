/**
 * @file Etudiant.h
 * @brief déclare Etudiant, sous-classe d'Individu. Elle :
- ajoute l'attribut 'formation' et ses accesseurs
- spécialise la méthode usuelle 'toString()',
- et se réfère au constructeur 'Etudiant'
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#ifndef ETUDIANT_H
#define ETUDIANT_H

#include <Individu.h>
#include <iostream>

using namespace std;

/*** Etudiant ***/
class Etudiant : public Individu
{
    /// ATTRIBUTS : formation
    public:    // -non-
    private:   // -non-
    protected:
        string formation;

    /// METHODES
    public:
        // CONSTRUCTEUR
        Etudiant (string nom="", string prenom="", string formation="");

        // DESTRUCTEUR
        virtual ~Etudiant();

        // ENCAPSULATION : formation
        string getFormation() { return formation; }
        void setFormation(string val) { formation = val; }

        // METHODES USUELLES : toString
        string toString();

        // METHODES SPECIFIQUES : -non-
};
#endif // ETUDIANT_H
