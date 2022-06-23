 #ifndef CARRE_H
#define CARRE_H

#include "Couleur.h"
#include "Fenetre.h"
#include "Souris.h"

class Carre{
private:
    int coorX, coorY;
    int lenght;
    Couleur color;
    void dessiner(Fenetre&, Couleur) const;
public:
    Carre(const Carre&);
    Carre();
    Carre(int,int,int,Couleur = Couleur(0,0,0));

    void placer(int, int);
    int coordX() const;
    int coordY() const;
    void dimensionner(int);
    int cote() const;
    void definirCouleur(int, int, int);
    void definirCouleur(Couleur);
    Couleur couleur() const;
    void afficher(Fenetre&) const;
    void effacer(Fenetre&) const;
    bool touche(int, int) const;
};


#endif // CARRE_H
