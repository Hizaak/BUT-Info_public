/**
 * @file main.cpp
 * @brief RAPPELS - héritage
La classe Individu est spécialisée dans la sous-classe Etudiant, qui :
- ajoute l'attribut 'formation' et ses accesseurs
- spécialise la méthode usuelle 'toString()',
- et se réfère au constructeur 'Etudiant'
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 *
 * note: Les destructeurs sont différenciés et font savoir leur différence
 */

#include <iostream>
#include <Individu.h>
#include <Etudiant.h>

using namespace std;

int main()
{
    Individu ind1 ("Pierre", "Dupont");
    Etudiant etud1 ("Jean", "Martin", "DUT2");

    cout << ind1.toString() << endl;  // affiche nom et prénom
    cout << etud1.toString() << endl; // affiche en plus la formation

    return 0;
}
