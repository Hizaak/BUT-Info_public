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
    // Le nombre de lignes du tableau contentant les tables de multiplication
    const unsigned short int NB_LIGNES = 11;
    // Le nombre de colonnes du tableau contentant les tables de multiplication
    const unsigned short int NB_COLONNES = 11;
    // Le tableau contenant les tables de multiplication
    unsigned short int tablesDeMultiplication[NB_LIGNES][NB_COLONNES] = {
      0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
      0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
      0,  2,  4,  6,  8,  10, 12, 14, 16, 18, 20,
      0,  3,  6,  9,  12, 15, 18, 21, 24, 27, 30,
      0,  4,  8,  12, 16, 20, 24, 28, 32, 36, 40,
      0,  5,  10, 15, 20, 25, 30, 35, 40, 45, 50,
      0,  6,  12, 18, 24, 30, 36, 42, 48, 54, 60,
      0,  7,  14, 21, 28, 35, 42, 49, 56, 63, 70,
      0,  8,  16, 24, 32, 40, 48, 56, 64, 72, 80,
      0,  9,  18, 27, 36, 45, 54, 63, 72, 81, 90,
      0,  10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int ligne;
    int cases;
    for(ligne=0;ligne<=10;ligne++){
        cout<<"Table de "<<ligne<<endl;
        for(cases=0;cases<=10;cases++){
            cout<<ligne<<"x"<<cases<<"="<<tablesDeMultiplication[ligne][cases]<<endl;
        }
    }
    return 0;
}


    