/**
 * @file Individu.cpp
 * @brief Individu::Individu, Individu::~Individu, Individu::toString
          Etudiant::Etudiant, Etudiant::~Etudiant, Etudiant::toString
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */
#include <Individu.h>

/*** Individu ***/
Individu::Individu(string nom, string prenom) {
    this->setNom (nom);
    this->setPrenom (prenom);
}

Individu::~Individu() {
    cout << "  Individu " << this->toString() << " ... meurt !!!!\n";
}

string Individu::toString() {
    string message;
    message = getNom() + " " + getPrenom();
    return message;
}
