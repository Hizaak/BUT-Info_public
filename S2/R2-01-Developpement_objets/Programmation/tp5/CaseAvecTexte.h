#ifndef CASEAVECTEXTE_H
#define CASEAVECTEXTE_H

#include "CaseACocher.h"


class CaseAvecTexte : public CaseACocher
{
    public:
        CaseAvecTexte(const CaseACocher& caseAC= CaseACocher(), char*leTexte="Sans texte");
        CaseAvecTexte(const CaseAvecTexte& );
        ~CaseAvecTexte();
        void definirTexte(char*);
        void afficher(Fenetre &) const;
        void effacer(Fenetre &) const;

    private:
        char* m_texte;
};

#endif // CASEAVECTEXTE_H
