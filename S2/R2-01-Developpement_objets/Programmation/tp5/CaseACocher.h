#ifndef CASE_A_COCHER_H
#define CASE_A_COCHER_H

#include "Couleur.h"
#include "Fenetre.h"
#include "Carre.h"

class CaseACocher: public Carre {
private:
    bool m_etat;
    void dessiner(Fenetre&, Couleur) const;

public:
    CaseACocher(const CaseACocher&);
    CaseACocher();
    CaseACocher(int,int,int,Couleur,char);
    CaseACocher(const Carre&, char);

    void definirEtat(char);
    char etat() const;
    void afficher(Fenetre &) const;
    void effacer(Fenetre &) const;
};

#endif // CASE_A_COCHER_H
