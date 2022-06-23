#ifndef CASEACOCHER_H_INCLUDED
#define CASEACOCHER_H_INCLUDED
#include "Carre.h"
#include "Fenetre.h"
#include "Couleur.h"
class CaseACocher{
    private:
        Carre m_carre;
        bool m_estActif;
        void dessiner(Fenetre&,Couleur)const;
    public:
        void definirCadre(int,int,int,Couleur);
        Carre cadre()const;
        void definirEtat(char);
        char etat()const;
        void afficher(Fenetre&)const;
        void effacer(Fenetre&)const;



};

#endif // CASEACOCHER_H_INCLUDED
