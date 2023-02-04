#ifndef INDIVIDU_H
#define INDIVIDU_H
#include "voiture.h"
#include <iostream>
using namespace std;
class Individu{
    private:
        string nom;
        string prenom;
        Voiture voiture;
    public:
        Individu(string, string);
        string to_string();
        string getNom(){
            return this->nom;
        };
        string getPrenom(){
            return this->prenom;
        };
};

#endif //INDIVIDU_H 