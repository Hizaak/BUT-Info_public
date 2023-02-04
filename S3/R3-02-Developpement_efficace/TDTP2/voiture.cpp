#include "voiture.h"

string Voiture::to_string(){
    string message;
    message="plaque (" + getPlaque()+"), ";
    message += "marque (" + getMarque()+")";
    return message;
}

Voiture::Voiture(string marque, string plaque, Individu proprietaire){
    this->marque=marque;
    this->plaque=plaque;
    this->proprietaire=proprietaire;
}