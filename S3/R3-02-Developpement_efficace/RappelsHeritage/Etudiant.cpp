#include "Etudiant.h"

/**
 * @file Etudiant.cpp
 * @brief Etudiant::Etudiant, Etudiant::~Etudiant, Etudiant::toString
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

/*** Etudiant ***/

Etudiant::Etudiant (string nom, string prenom, string formation) : Individu (nom, prenom) {
    this->setFormation (formation);
}

Etudiant::~Etudiant (){
    cout << "  De la formation " << getFormation() << ", ";
}

string Etudiant::toString() {
    string message;
    message = this->Individu::toString() + " en : " + getFormation();
    return message;
}
