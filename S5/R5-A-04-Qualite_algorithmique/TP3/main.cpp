#include <iostream>
using namespace std;

#include "Point.hpp"
#include "ElementGraphique.hpp"
#include "Carre.hpp"
#include "Cercle.hpp"
#include "ZoneDessin.hpp"


int main(void)
{
    Carre* carre1 = new Carre();
    Carre* carre3 = new Carre();
    Cercle* cercle1 = new Cercle(Point(5,7), 6);
    Carre* carre2 = new Carre(Point(1,2), 3);
    Cercle* cercle2 = new Cercle(Point(4,5), 6);

    ZoneDessin zoneDessin;

    zoneDessin.ajouterFin(carre1);
    zoneDessin.ajouterFin(cercle1);
    zoneDessin.ajouterFin(carre2);
    zoneDessin.ajouterFin(cercle2);
    zoneDessin.ajouterFin(carre3);

    cout << "ZoneDessin : " << zoneDessin << endl;

    int valeurIndice = zoneDessin.indice(*carre1);
    cout << "Indice du carre1 : " << valeurIndice << endl;

    valeurIndice = zoneDessin.indice(*cercle1);
    cout << "Indice du cercle1 : " << valeurIndice << endl;

    valeurIndice = zoneDessin.indice(*carre2);
    cout << "Indice du carre2 : " << valeurIndice << endl;

    valeurIndice = zoneDessin.indice(*cercle2);
    cout << "Indice du cercle2 : " << valeurIndice << endl;

    valeurIndice = zoneDessin.indice(*carre3);
    cout << "Indice du carre3 : " << valeurIndice << endl;


    // test pour voir si le tri fonctionne
    zoneDessin.trier();
    cout << "ZoneDessin : " << zoneDessin << endl;
    
    return 0;
}