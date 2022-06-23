#include "Fenetre.h"
#include "Souris.h"

int main (int argc, char **argv){

    gtk_init(&argc, &argv);

    Fenetre f;
    Souris s;
    int b, x, y;

    f.apparait("Test TP1",400,400,0,0,255,255,255);
    s.associerA(f);

    f.choixCouleurTrace(0,0,255);
    //f.traceLigne(0,0,200,200);

    f.traceArc(180,180,100,100,0,360,1);
    f.traceArc(190,190,80,80,0,360,1);
    f.traceArc(200,200,60,60,0,360,1);
    f.traceArc(210,210,40,40,0,360,1);
    f.traceArc(220,220,20,20,0,360,1);


    while (!s.testeBoutons(x, y, b));

    f.disparait();

    return 0;
}
