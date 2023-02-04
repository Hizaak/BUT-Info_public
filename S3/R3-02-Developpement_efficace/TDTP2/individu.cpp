#include "individu.h"

string Individu::to_string(){
    string message;
    message="L'individu s'appelle :" + getNom()+"), ";
    message += "marque (" + getPrenom()+")";
    return message;
}

Individu::Individu(string nom, string prenom){
    this->nom=nom;
    this->prenom=prenom;
}