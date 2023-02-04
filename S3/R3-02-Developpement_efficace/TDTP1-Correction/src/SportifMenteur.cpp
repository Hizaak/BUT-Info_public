/**
 * @file SportifMenteur.cpp
 * @brief SportifMenteur::SportifMenteur, SportifMenteur::toString, SportifMenteur::getAge
 * @author Lopist�guy
 * @version 0.1
 * @date jj/mm/aaa
 */
#include "SportifMenteur.h"

SportifMenteur::SportifMenteur
(string nom, string prenom, short int annee, string tuteur)
 : Sportif (nom, prenom, annee)   // D�l�gue la construction/init
                                  // des attributs � la super-classe
{
    this->setTuteur (tuteur);     // Traite l'attribut suppl�mentaire local
}
string SportifMenteur::toString() { // sp�cialise toString()
    string message;
    // invoque le toString() de la super-classe Sportif
    message = this -> Sportif::toString();
    message += "  -  tuteur : " + getTuteur();  // compl�te le code
    return message;
}

short int SportifMenteur::getAge() { // sp�cialise getAge()
    short int age;
    // invoque le getAge() de la super-classe Sportif
    age = this->Sportif::getAge(); // obtient l'age r�el
    return (age<18 ? 18 : age);
}
