#include "CaseACocher.h"

CaseACocher::CaseACocher(const CaseACocher& original):
    Carre(original),
    m_etat(original.m_etat)
{

}

CaseACocher::CaseACocher():
    Carre(),
    m_etat(false)
{

}

CaseACocher::CaseACocher(int x, int y, int l, Couleur c, char etat):
    Carre(x,y,l,c),
    m_etat(etat == 'C')
{

}

CaseACocher::CaseACocher(Carre c, char etat):
    Carre(c),
    m_etat(etat == 'C')
{

}

void CaseACocher::definirCadre(int x, int y, int l, Couleur c)

{
    this->placer(x,y);
    this->dimensionner(l);
    this->definirCouleur(c);
}


void CaseACocher::definirEtat(char etat)
{
    if (etat == 'C'){
        this->m_etat = true;
    }
    else{
        this->m_etat = false;
    }
}

char CaseACocher::etat() const
{
    if (this->m_etat){
        return 'C';
    }
    else{
        return 'N';
    }
}

void CaseACocher::afficher(Fenetre& f) const
{
    this->Carre::afficher(f);
    this->dessiner(f, this->couleur());
}

void CaseACocher::effacer(Fenetre& f) const
{
    this->Carre::afficher(f);
    this->dessiner(f, f.couleurFond());
}

void CaseACocher::dessiner(Fenetre& f, Couleur c) const
{
    f.choixCouleurTrace(c);
    if ((*this).m_etat){
           f.traceLigne((*this).coordX(),(*this).coordY(),(*this).coordX()+(*this).cote(),(*this).coordY()+(*this).cote());
           f.traceLigne((*this).coordX(),(*this).coordY()+(*this).cote(),(*this).coordX()+(*this).cote(),(*this).coordY());
        }
}

