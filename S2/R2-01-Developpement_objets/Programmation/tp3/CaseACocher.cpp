#include "CaseACocher.h"

void CaseACocher::dessiner(Fenetre& f, Couleur c) const
{
    (*this).m_carre.afficher(f);
    f.choixCouleurTrace(c);
    if  ((*this).m_estActif){
           f.traceLigne((*this).m_carre.coordX(),(*this).m_carre.coordY(),(*this).m_carre.coordX()+(*this).m_carre.cote(),(*this).m_carre.coordY()+(*this).m_carre.cote());
           f.traceLigne((*this).m_carre.coordX(),(*this).m_carre.coordY()+(*this).m_carre.cote(),(*this).m_carre.coordX()+(*this).m_carre.cote(),(*this).m_carre.coordY());
        }
}

void CaseACocher::definirCadre(int x, int y , int dimension, Couleur c)
{
    (*this).m_carre.placer(x,y);
    (*this).m_carre.dimensionner(dimension);
    (*this).m_carre.definirCouleur(c);

}

Carre CaseACocher::cadre() const
{
    return (*this).m_carre;

}

void CaseACocher::definirEtat(char c)
{
    if (c =='C'){
        (*this).m_estActif=true;
    }
    else{
        (*this).m_estActif=false;
    }

}

char CaseACocher::etat() const
{
    if ((*this).m_estActif){
        return 'C';
        }

    else{
        return 'N';
        }
}

void CaseACocher::afficher(Fenetre& f)const
{
    dessiner(f,(*this).m_carre.couleur());
}

void CaseACocher::effacer(Fenetre& f)const
{
    dessiner(f,f.couleurFond());
}
