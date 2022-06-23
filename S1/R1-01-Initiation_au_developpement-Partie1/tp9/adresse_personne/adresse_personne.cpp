/*
 Programme : Afficher le prix réduit
 But : Doit afficher le prix réduit à partir de la réduction entrée et du prix
 Date de dernière modification : 26/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/

#include <iostream>
using namespace std;

struct Adresse
{
    string numRue;           // le numéro de rue (par exemple 2bis)
    string nomRue;           // Le nom de la rue (par exemple allée du Parc Montaury)
    unsigned int codePostal; // Le code postal (par exemple 64600)
    string ville;            // le nom de la ville (par exemple Anglet)
};

struct Personne
{
    string nom;      // Le nom de la personne
    string prenom;   // Le prénom de la personne
    Adresse adresse; // L'adresse de la personne
};

//Déclaration des sous-programmes
Adresse adresseDe(const Personne& personne);
//But : retourne l'adresse d'une personne

int main(void)
{
    
    Adresse adresse={"2bis","allée du Parc Montaury",64600,"Anglet"};
    Personne client = {"Jean-Marie", "Bigard", adresse};
    
    Adresse destination=adresseDe(client);
    cout<<destination.numRue<<" "<<destination.nomRue<<" "<<destination.codePostal<<" "<<destination.ville;
}

//Définition des sous-programmes
Adresse adresseDe(const Personne& personne)
{
    return personne.adresse;
}