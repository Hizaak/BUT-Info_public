#include <iostream>
using namespace std;

int main (void)
{
    int nbLignes;
    int i;
    int y;
    cout<<"Entrez le nombre de lignes :";
    cin>>nbLignes; 
    for(i=nbLignes;i>=1;i--){
        for(y=1;y<=i;y++){
            cout<<"*";
        }
    cout<<"\n";
    }
}