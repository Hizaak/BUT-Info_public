#include <iostream>
using namespace std;

int main (void)
{
    // Variables
    int borneMin;
    int borneMax;
    int somme=0;
    int i;
    cout<<"Entrez la borne minimale : ";
    cin>>borneMin;
    cout<<"Entrez la borne maximale : ";
    cin>>borneMax;
    if(borneMin>borneMax){
        cout<<"0";
    }
    else{
        for(i=borneMin;i<=borneMax;i++){
            somme+=i;
        }
        cout<<somme;
    }
    return 0;
}