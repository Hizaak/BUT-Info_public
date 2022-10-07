#include "FenGrille.h"

FenGrille::FenGrille(int largeur, int hauteur):
    Fenetre(),
    m_largeur(largeur),
    m_hauteur(hauteur)
{

}

FenGrille::FenGrille(const char* nom , int largeurFen, int longueurFen, int x, int y, int r, int g, int b, int largeurGrille, int hauteurGrille):
    Fenetre(nom, largeurFen, longueurFen, x, y, r, g, b),
    m_largeur(largeurGrille),
    m_hauteur(hauteurGrille)
{
    this->apparait(nom, largeurFen, longueurFen, x, y, r, g, b);
}

FenGrille::FenGrille(const FenGrille& original):
    Fenetre(original),
    m_largeur(original.m_largeur),
    m_hauteur(original.m_hauteur)
{

}

void FenGrille::apparait(const char* nom , int largeurFen, int longueurFen, int x, int y, int r, int g, int b)
{
    this->Fenetre::apparait(nom, largeurFen, longueurFen, x, y, r, g, b);
    int xx, yy;
    yy = 0;
    this->choixCouleurTrace(211,211,211);
    for(int i = 0; i < (largeurFen/this->m_largeur)+1; i ++){
            xx = this->m_largeur * i;
            this->traceLigne(xx, yy, xx, this->m_largeur);
        }
    xx = 0;
    for (int i = 0; i < (longueurFen/this->m_hauteur)+1; i++){
            yy = this->m_hauteur * i;
            this->traceLigne(xx,yy, this->m_largeur, yy);
    }

}

void FenGrille::effacer()
{
    this->Fenetre::effacer();
    int xx, yy;
    yy = 0;
    this->choixCouleurTrace(this->couleurFond());
    for(int i = 0; i < (this->largeur()/this->m_largeur)+1; i ++){
            xx = this->m_largeur * i;
            this->traceLigne(xx, yy, xx, this->m_largeur);
        }
    xx = 0;
    for (int i = 0; i < (this->hauteur()/this->m_hauteur)+1; i++){
            yy = this->m_hauteur * i;
            this->traceLigne(xx,yy, this->m_largeur, yy);
    }
}

void FenGrille::afficherCase(CaseACocher)
{

}
