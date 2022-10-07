#ifndef FENGRILLE_H_INCLUDED
#define FENGRILLE_H_INCLUDED
#include "Fenetre.h"
#include "Couleur.h"
#include "CaseACocher.h"


class FenGrille: public Fenetre{
    private:
        int m_largeur;
        int m_hauteur;
    public:
        FenGrille(int=20, int=20);
        FenGrille(const char *, int, int, int=0, int=0, int=255, int=255, int=255, int=20, int=20);
        FenGrille(const FenGrille&);

        void apparait(const char* ="Sans nom", int=400, int=400, int=0, int=0, int=255, int=255, int=255);
        void effacer();
        void afficherCase(CaseACocher);
};


#endif // FENGRILLE_H_INCLUDED
