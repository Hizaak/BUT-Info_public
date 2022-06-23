#include "CaseAvecTexte.h"

CaseAvecTexte::CaseAvecTexte(const CaseACocher& caseAC, char* leTexte) :
    m_texte(leTexte),
    CaseACocher(caseAC)
{
    //ctor
}

CaseAvecTexte::~CaseAvecTexte()
{
    delete [] (*this).m_texte;
}

CaseAvecTexte::CaseAvecTexte(const CaseAvecTexte& other):
    m_texte(other.m_texte),
    CaseACocher(other)
{
    //copy ctor
}

void CaseAvecTexte::definirTexte(char* leTexte) {
    (*this).m_texte=leTexte;
}

void CaseAvecTexte::afficher(Fenetre & f) const {
    (*this).CaseACocher::afficher(f);
    f.choixCouleurTrace((*this).couleur());
    f.ecrit((*this).coordX()+(*this).cote()+10,(*this).coordY()+(*this).cote()/1.3,m_texte);
}

void CaseAvecTexte::effacer(Fenetre & f) const {
    (*this).CaseACocher::effacer(f);
    f.choixCouleurTrace(f.couleurFond());
    f.ecrit((*this).coordX()+(*this).cote()+10,(*this).coordY()+(*this).cote()/1.3,m_texte);
}
