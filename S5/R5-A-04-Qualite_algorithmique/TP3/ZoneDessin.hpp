#ifndef ZONEDESSIN_HPP
#define ZONEDESSIN_HPP

#include <vector>
#include "ElementGraphique.hpp"

class PEG
{
protected:
    ElementGraphique *m_base;
    const ElementGraphique *m_constBase;

public:
    ElementGraphique *base() const { return this->m_base; }
    bool operator==(const PEG &opD) const { return (*(this->m_constBase)) == (*(opD.m_constBase)); }
    PEG(ElementGraphique *pEG) : m_base(pEG), m_constBase(pEG) {}
    PEG(const ElementGraphique *pEG) : m_base(NULL), m_constBase(pEG) {}
    PEG(const PEG &ori) : m_base(ori.m_base), m_constBase(ori.m_constBase) {}
};

class ZoneDessin
{
private:
    int m_longueur;
    int m_largeur;
    // std::vector<ElementGraphique *> m_listeElements;
    std::vector<PEG> m_listeElements;

public:
    ZoneDessin(/* args */);
    ZoneDessin(const ZoneDessin &zoneDessin);
    ZoneDessin(int largeur, int longueur);
    virtual ~ZoneDessin();
    void dimensionner(int largeur, int longueur);
    int longueur() const;
    int largeur() const;
    void ajouterFin(ElementGraphique *elementGraphique);
    bool enlever();
    ElementGraphique *elementGraphique(int index) const;
    int nombreElements() const;

    friend std::ostream &operator<<(std::ostream &os, const ZoneDessin &zoneDessin);

    int indice(const ElementGraphique &elementGraphique) const;

    void trier();
};

#endif // ZONEDESSIN_HPP