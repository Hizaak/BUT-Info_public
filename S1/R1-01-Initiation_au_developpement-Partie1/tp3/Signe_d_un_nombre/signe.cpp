#include <iostream>
using namespace std;

int main (void)
{
    int nombre;  //Nombre entré par l'utilisateur
    cout<<"Entrez un nombre : ";
    cin>>nombre; //Enregistrement de la valeur donnée
    if (nombre<0){ // Si nombre > 0, afficher qu'il est négatif
        cout<<"Le nombre est negatif";
    }
    else if (nombre==0){ // Si nombre > 0, afficher qu'il est nul
        cout<<"Le nombre est nul";
    }
    else if (nombre>0){ // Si nombre > 0, afficher qu'il est positif
        cout<<"Le nombre est positif";
    }
}