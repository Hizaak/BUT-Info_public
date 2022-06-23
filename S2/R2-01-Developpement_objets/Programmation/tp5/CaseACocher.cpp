#include "CaseACocher.h"

CaseACocher::CaseACocher(const CaseACocher& original):
    m_etat(original.m_etat),
    Carre(original) {}


CaseACocher::CaseACocher():
    m_etat(false),
    Carre() {}


CaseACocher::CaseACocher(int a,int b,int c,Couleur d,char e):
    Carre(a,b,c,d) {
    (*this).definirEtat(e);
}


CaseACocher::CaseACocher(const Carre& carreOr, char e):
    Carre(carreOr) {
    (*this).definirEtat(e);
}


void CaseACocher::definirEtat(char val) {
  if (val == 'C') {
    (*this).m_etat = true;
  } else {
    (*this).m_etat = false;
  }
}

void CaseACocher::dessiner(Fenetre& f, Couleur color) const{
    f.choixCouleurTrace(color);

    f.traceLigne((*this).coordX()+1,(*this).coordY()+1,
    (*this).coordX()+(*this).cote(),(*this).coordY()+(*this).cote(),1);
    f.traceLigne((*this).coordX()+(*this).cote(),(*this).coordY(),
    (*this).coordX()+1,(*this).coordY()-1+(*this).cote(),1);
}

char CaseACocher::etat() const {
  if ((*this).m_etat) {
    return 'C';
  } else {
    return 'N';
  }
}

void CaseACocher::afficher(Fenetre & f) const {
  (*this).Carre::afficher(f);
    if ((*this).m_etat) {

    (*this).dessiner(f,(*this).couleur());

  } else {

    (*this).dessiner(f,f.couleurFond());
  }

}

void CaseACocher::effacer(Fenetre & f) const {
  (*this).Carre::effacer(f);

  (*this).dessiner(f,f.couleurFond());


}
