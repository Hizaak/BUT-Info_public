#include "CaseACocher.h"

void CaseACocher::dessiner(Fenetre& f, Couleur c) const
{
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

CaseACocher::CaseACocher(const CaseACocher& source):
    m_carre(source.m_carre),
    m_estActif(source.m_estActif){}

CaseACocher::CaseACocher():
    m_carre()
    {
    (*this).definirEtat('N');
    }

CaseACocher::CaseACocher(Carre carre,char etat):
    m_carre(carre)
    {
    (*this).definirEtat(etat);
    }

CaseACocher::CaseACocher(int x,int y,int longueur,Couleur couleur,char etat):
    m_carre(x,y,longueur,couleur)
    {
    (*this).definirEtat(etat);
    }
