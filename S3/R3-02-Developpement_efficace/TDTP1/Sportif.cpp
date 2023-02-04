#include "sportif.h"
#include <iostream>
using namespace std;


Sportif :: Sportif(string nom, string prenom, unsigned int anneeNaissance){
    this.setNom(nom);
    this.setPrenom(prenom);
    this.setAge(anneeNaissance);
}

Sportif :: ~Sportif(){
    cout << "tu dégages";
}

Sportif::getAge(){
    return(Outil::anneeActuelle-anneeNaissance);
}