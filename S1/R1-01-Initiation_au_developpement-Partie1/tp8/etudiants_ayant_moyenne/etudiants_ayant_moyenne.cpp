/*
 Programme : inverse deux cases d'un tableau
 But : inverse deux cases d'un tableau
 Date de dernière modification : 20/10/2021
 Auteur : Alexandre MAURICE
 Remarques : /
*/

#include <iostream>
using namespace std;

// Nombre d'étudiants inscrits en semestre 1 :
const unsigned int EFFECTIF_S1 = 15;
struct UnEtudiant{string Nom; string Prenom; double note;};
// Résultats examen du 15 février :


//Déclaration des sous-programmes
void calculerEtudiantsMoyenne(UnEtudiant notesExamDu15fevrier[],unsigned int &pasMoyenne, unsigned int &Moyenne);
//But : 

int main(void)
{
    UnEtudiant notesExamDu15fevrier[EFFECTIF_S1] = {
    {"Almeras", "Valentin", 15}, {"Gueguen", "Lucie", 8.5},
    {"Pomeroy", "Thibault", 4.5}, {"Souchon", "Elodie", 18},
    {"Besnard", "Emmanuel", 12}, {"Gaudreau", "Lucien", 0},
    {"Duret", "Christelle", 10.5}, {"Laffitte", "Anna", 13},
    {"Barbier", "Remi", 15}, {"Blondeau", "Denise", 7},
    {"Berlioz", "Gabriel", 9.5}, {"Dupont", "Benjamin", 3},
    {"Maret", "Ludovic", 13.5}, {"Boutin", "Alain", 12},
    {"Dubuisson", "Marie", 19}};
    cout<<notesExamDu15fevrier[0].note;
}

void calculerEtudiantsMoyenne(UnEtudiant notesExamDu15fevrier[],unsigned int &pasMoyenne, unsigned int &Moyenne, const unsigned int EFFECTIF_S1)
{
    unsigned int &pasMoyenne;
    unsigned int &Moyenne;
    unsigned int i;
    for(i=0;i<EFFECTIF_S1;i++)
    {
        if(notesExamDu15fevrier[i].note>=10)
        {
            pasMoyenne++;
        }
    }
    
}
