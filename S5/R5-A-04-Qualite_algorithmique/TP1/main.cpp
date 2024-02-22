#include <iostream>
#include <ctime>

#include "ListIntsV.h"
#include "ListIntsL.h"

using namespace std;


int main() {
    // Exercice 1
    ListIntsV maListIntV;
    int iBeg=clock();
    for (size_t i = 0; i < 99999; i++)
    {
        maListIntV.insertBeg(i);
    }
    int iEnd=clock();
    cout << "Vecteurs" << endl << "Étape 1 : " << (double) (iEnd - iBeg) / CLOCKS_PER_SEC << endl;

    iBeg=clock();
    for (size_t i = 50000; i < 50999; i++)
    {
        maListIntV.removeAt(i);
    }
    iEnd=clock();

    cout << "Étape 2 : " << (double) (iEnd - iBeg) / CLOCKS_PER_SEC << endl;

    // Exercice 2
    ListIntsL maListIntL;
    iBeg=clock();
    for (size_t i = 0; i < 99999; i++)
    {
        maListIntL.insertBeg(i);
    }
    iEnd=clock();
    
    cout << "Listes" << endl << "Étape 1 : " << (double) (iEnd - iBeg) / CLOCKS_PER_SEC << endl;

    iBeg=clock();
    for (size_t i = 50000; i < 50999; i++)
    {
        maListIntL.removeAt(i);
    }

    iEnd=clock();
    cout << "Étape 2 : " << (double) (iEnd - iBeg) / CLOCKS_PER_SEC << endl;

    return 0;
}
