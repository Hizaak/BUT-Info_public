#include <iostream>
using namespace std;

int main (void)
{
    //Variables
    double noteOral; //Note de l'oral
    double noteEcrit; //Note de l'écrit
    double coefOral; //Coef de l'oral
    double coefEcrit; //Coef de l'écrit
    double noteFinale; //Note finale
    //Entrée des notes et des coefs
    cout<<"Entrez la note d'oral : ";
    cin>>noteOral;
    cout<<"Entrez la note d'ecrit : ";
    cin>>noteEcrit;
    cout<<"Entrez le coef d'oral : ";
    cin>>coefOral;
    cout<<"Entrez la coef d'ecrit : ";
    cin>>coefEcrit;
    //Traitement
    noteFinale=(noteOral*coefOral + noteEcrit*coefEcrit)/(coefOral+coefEcrit); //Formule de la moyenne
    //Affichage
    if (noteFinale<10){
        cout<<"Non recu avec : "<<noteFinale;
    }
    else{
        cout<<"Recu avec : "<<noteFinale;
    }
    return 0;
}