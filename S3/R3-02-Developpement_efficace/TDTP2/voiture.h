#ifndef VOITURE_H
#define VOITURE_H
#include "individu.h"
#include <iostream>
using namespace std;

class Voiture{
    private:
        string marque;
        string plaque;
        Individu proprietaire;
    public:
        Voiture(string marque, string plaque, Individu proprietaire);
        string to_string();
        string getPlaque(){
            return this->plaque;
        };
        string getMarque(){
            return this->marque;
        };
};

#endif //VOITURE_H