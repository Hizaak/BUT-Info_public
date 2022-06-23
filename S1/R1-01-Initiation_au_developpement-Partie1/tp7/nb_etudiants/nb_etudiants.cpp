/*
 Programme :
 But :
 Date de dernière modification :
 Auteur :
 Remarques :
*/
#include <iostream>
using namespace std;

int main (void)
{
      struct Etudiant
        {
            string nom;            // nom de l'étudiant
            string prenom;         // prénom de l'étudiant
            unsigned short int td; // numéro de TD de l'étudiant
            unsigned short int tp; // numéro de TP de l'étudiant
        };
    
        // Nombre d'étudiants inscrits en semestre 1
        const unsigned int EFFECTIF_S1 = 15;
    
        // Etudiants inscrits en semestre 1 :
        Etudiant etudiantsS1[EFFECTIF_S1] = {
            {"Almeras", "Valentin", 1, 1}, 
            {"Gueguen", "Lucie", 1, 1},
            {"Pomeroy", "Thibault", 1, 1}, 
            {"Souchon", "Elodie", 1, 2},
            {"Besnard", "Emmanuel", 1, 2}, 
            {"Gaudreau", "Lucien", 2, 3},
            {"Duret", "Christelle", 2, 3}, 
            {"Laffitte", "Anna", 2, 4},
            {"Barbier", "Remi", 2, 4},     
            {"Blondeau", "Denise", 2, 4},
            {"Berlioz", "Gabriel", 2, 4},  
            {"Dupont", "Benjamin", 3, 5},
            {"Maret", "Ludovic", 3, 5},    
            {"Boutin", "Alain", 3, 5},
            {"Dubuisson", "Marie", 3, 5}};
    // Programme principal
    int nbEtudiant=0;
    int tp_entre;
    unsigned int i;
    cout<<"Entrez le TP dont vous souhaitez connaitre le nombre d'etudiants"<<endl;
    cin>>tp_entre;
    for(i=0;i<=EFFECTIF_S1;i++){
        if (etudiantsS1[i].tp==tp_entre){
            nbEtudiant+=1;
        }
    }
    cout<<nbEtudiant;
    return 0;
}