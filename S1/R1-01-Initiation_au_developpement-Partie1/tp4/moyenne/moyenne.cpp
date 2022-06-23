#include <iostream>
using namespace std;

int main (void)
{
    // Variables
    float note;
    float moyenne=0;
    int i;
    for(i=1;i<=10;i++){
        if(i==1){
            cout<<"Entrez la 1ere note : ";
        }
        else{cout<<"Entrez la "<<i<<"eme note : ";}
        cin>>note;
        moyenne=moyenne+note;
    }
    cout<<"Votre moyenne est de : "<<(moyenne/10)<<"/20.";
    return 0;
}