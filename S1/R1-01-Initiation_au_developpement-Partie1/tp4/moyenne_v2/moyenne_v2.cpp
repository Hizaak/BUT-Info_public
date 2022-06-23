#include <iostream>
using namespace std;

int main (void)
{
    float somme=0;
    int nbrNotes=0;
    float note;
    float calculMoyenne;
    do{
        cout<<"Saisissez la note : ";
        cin>>note;
        if(note==999){
            break;
        }
        while(!(note>=0 && note<=20)){
            cout<<"Veuillez saisir une note correcte : ";
            cin>>note;
        }
        nbrNotes++;
        somme+=note;
    }while(!(note==999));
    calculMoyenne=somme/float(nbrNotes);
    cout<<"Votre moyenne est de : "<<calculMoyenne<<"/20";
    return 0;
}