#include "Carre.h"

void Carre::placer(int x , int y )
{
    (*this).m_coordx=x;
    (*this).m_coordy=y;
}

int Carre::coordX() const
{
    return (*this).m_coordx;
}

int Carre::coordY() const
{
    return (*this).m_coordy;
}

void Carre::dimensionner(int longueur)
{
    (*this).m_longueur=longueur;
}

int Carre::cote() const
{
    return (*this).m_longueur;
}

void Carre::definirCouleur(int r , int g , int b )
{
    (*this).m_couleur.definir(r,g,b);
}

void Carre::definirCouleur(Couleur c)
{
    (*this).m_couleur.definir(c.rouge(),c.vert(),c.bleu());
}

Couleur Carre::couleur() const
{
    return (*this).m_couleur;
}

void Carre::dessiner(Fenetre& f,Couleur c) const
{
    f.choixCouleurTrace(c);
    f.traceLigne((*this).m_coordx,(*this).m_coordy,(*this).m_coordx,(*this).m_coordy+(*this).m_longueur);
    f.traceLigne((*this).m_coordx,(*this).m_coordy+(*this).m_longueur,(*this).m_coordx+(*this).m_longueur,(*this).m_coordy+(*this).m_longueur);
    f.traceLigne((*this).m_coordx+(*this).m_longueur,(*this).m_coordy+(*this).m_longueur,(*this).m_coordx+(*this).m_longueur,(*this).m_coordy);
    f.traceLigne((*this).m_coordx+(*this).m_longueur,(*this).m_coordy,(*this).m_coordx,(*this).m_coordy);

}


void Carre::afficher(Fenetre& f ) const
{
    (*this).dessiner(f,(*this).m_couleur);
}

void Carre::effacer(Fenetre& f) const
{
    (*this).dessiner(f,f.couleurFond());
}

bool Carre::touche(int x , int y) const
{
    if (  x >=(*this).m_coordx && x<= (*this).m_coordx+(*this).m_longueur
        && y >=(*this).m_coordy && y<= (*this).m_coordy+(*this).m_longueur )
        {
            return true;
        }
    else
    {
        return false;
    }
}

Carre::Carre(const Carre& source):
    m_coordx(source.m_coordx),
    m_coordy(source.m_coordy),
    m_longueur(source.m_longueur),
    m_couleur(source.m_couleur){}

Carre::Carre():
    m_coordx(10),
    m_coordy(10),
    m_longueur(20),
    m_couleur(0,0,255){}

Carre::Carre(int x, int y, int rayon, Couleur couleur):
    m_coordx(x),
    m_coordy(y),
    m_longueur(rayon),
    m_couleur(couleur){}


