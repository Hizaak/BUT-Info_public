#ifndef CASEACOCHER_H_INCLUDED
#define CASEACOCHER_H_INCLUDED

#include "Carre.h"
#include "Fenetre.h"
#include "Couleur.h"

class CaseACocher : public Carre{

    private:
        bool m_etat;
        void dessiner(Fenetre&, Couleur)const;
    public:
        CaseACocher(const CaseACocher&);
        CaseACocher();
        CaseACocher(int,int,int,Couleur,char);
        CaseACocher(Carre,char);

        void definirCadre(int,int,int,Couleur);
        void definirEtat(char);
        char etat()const;
        void afficher(Fenetre&)const;
        void effacer(Fenetre&)const;
};


#endif // CASEACOCHER_H_INCLUDED
