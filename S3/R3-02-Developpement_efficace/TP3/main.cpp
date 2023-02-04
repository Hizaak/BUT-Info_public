/* 
Auteur : Alexandre Maurice
Date : 13/10/2022
Version : 	1.0
Description : 	TP3 - Exercice 1
*/

#include <string>
#include <list>
#include <iostream>
using namespace std;

int main(void){

    typedef list<string> ListeS;
    ListeS uneListeS;
    uneListeS.push_back(ListeS::value_type("Pantxika"));
    uneListeS.push_back(ListeS::value_type("Yann"));
    uneListeS.push_back(ListeS::value_type("Philippe"));
    uneListeS.push_back(ListeS::value_type("Patrick"));

    ListeS::iterator iterateur = uneListeS.begin();
    while (iterateur != uneListeS.end())
    {
        cout << *iterateur << endl;
        iterateur++;
    }
    return 0;
}