#include "Fenetre.h"
#include "Souris.h"
#include <iostream>
using namespace std;

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int bdsouris=3;
    int bgsouris=1;
    int b, x, y;
    int xold=0;
    int yold=0;

    f.apparait("yee",400,400,0,0,255,255,255);
    s.associerA(f);

    f.choixCouleurTrace(0,0,255);

    while(true){
      int a=0;
        if(s.testeBoutons(x,y,bdsouris))
        {
            cout<<"bouton de droite"<<endl;
            //break;
        }
        if(s.testeBoutons(x,y,bgsouris))
        {
            cout<<"bouton de gauche"<<endl;
            f.traceLigne(x,y,xold,yold);
            xold=x;
            yold=y;
        }

        }
    f.delai(4500);

    return 0;
}
