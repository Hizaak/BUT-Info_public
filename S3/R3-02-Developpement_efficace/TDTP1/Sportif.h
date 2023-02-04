#ifndef SPORTIF_H
#define SPORTIF_H
#include "outils.h"
#include <iostream>

using namespace std;
class Sportif{
    private:
        string nom;
        string prenom;
        unsigned int anneeNaissance;
        
    public:
        Sportif(string nom, string prenom, unsigned int anneeNaissance); //
        ~Sportif(); //
        string getNom(){return nom;}; //
        string getPrenom(){return prenom;}; //
        unsigned int getAge(); //
        unsigned int getAnneeNaissance(){return anneeNaissance;};
        void setNom(string nom){nom=nom;};
        void setPrenom(string prenom){prenom=prenom;};
        void setAge(unsigned int age);


};

#endif // SPORTIF_H