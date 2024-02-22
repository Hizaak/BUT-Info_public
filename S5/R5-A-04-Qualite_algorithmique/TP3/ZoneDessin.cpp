#include <algorithm>

#include "ZoneDessin.hpp"
#include "Cercle.hpp"
#include "Carre.hpp"

ZoneDessin::ZoneDessin() : m_longueur(0),
                           m_largeur(0)
{
}

ZoneDessin::ZoneDessin(int largeur, int longueur) : m_longueur(longueur),
                                                    m_largeur(largeur)
{
}

ZoneDessin::ZoneDessin(const ZoneDessin &zoneDessin) : m_longueur(zoneDessin.m_longueur),
                                                       m_largeur(zoneDessin.m_largeur)
{
    for (int i = 0; i < zoneDessin.m_listeElements.size(); i++)
    {
        m_listeElements.push_back(zoneDessin.m_listeElements[i]);
    }
}

ZoneDessin::~ZoneDessin()
{
    for (int i = 0; i < m_listeElements.size(); i++)
    {
        // delete m_listeElements[i];
        delete m_listeElements[i].base();
    }
}

void ZoneDessin::dimensionner(int largeur, int longueur)
{
    m_longueur = longueur;
    m_largeur = largeur;
}

int ZoneDessin::longueur() const
{
    return m_longueur;
}

int ZoneDessin::largeur() const
{
    return m_largeur;
}

void ZoneDessin::ajouterFin(ElementGraphique *elementGraphique)
{
    m_listeElements.push_back(elementGraphique);
}

bool ZoneDessin::enlever()
{
    if (m_listeElements.size() > 0)
    {
        // delete m_listeElements[m_listeElements.size() - 1];
        delete m_listeElements[m_listeElements.size() - 1].base();
        m_listeElements.pop_back();
        return true;
    }
    else
    {
        return false;
    }
}

ElementGraphique *ZoneDessin::elementGraphique(int index) const
{
    // return m_listeElements[index];
    return m_listeElements[index].base();
}

int ZoneDessin::nombreElements() const
{
    return m_listeElements.size();
}

std::ostream &operator<<(std::ostream &os, const ZoneDessin &ZoneDessin)
{
    os << "Zone de dessin de largeur " << ZoneDessin.m_largeur << " et de longueur " << ZoneDessin.m_longueur << std::endl;
    for (int i = 0; i < ZoneDessin.m_listeElements.size(); i++)
    {
        // if (dynamic_cast<Cercle *>(ZoneDessin.m_listeElements[i]) != nullptr)
        if (dynamic_cast<Cercle *>(ZoneDessin.m_listeElements[i].base()) != nullptr)
        {
            // os << "Cercle " << i << " : " << *(dynamic_cast<Cercle *>(ZoneDessin.m_listeElements[i])) << std::endl;
            os << "Cercle " << i << " : " << *(dynamic_cast<Cercle *>(ZoneDessin.m_listeElements[i].base())) << std::endl;
        }

        // else if (dynamic_cast<Carre *>(ZoneDessin.m_listeElements[i]) != nullptr)
        else if (dynamic_cast<Carre *>(ZoneDessin.m_listeElements[i].base()) != nullptr)
        {
            // os << "Carre " << i << " : " << *(dynamic_cast<Carre *>(ZoneDessin.m_listeElements[i])) << std::endl;
            os << "Carre " << i << " : " << *(dynamic_cast<Carre *>(ZoneDessin.m_listeElements[i].base())) << std::endl;
        }

        else
        {
            // os << "ElementGraphique " << i << " : " << *(ZoneDessin.m_listeElements[i]) << std::endl;
            os << "ElementGraphique " << i << " : " << *(ZoneDessin.m_listeElements[i].base()) << std::endl;
        }
    }

    return os;
}

// int ZoneDessin::indice(const ElementGraphique &elementGraphique) const
// {
//     for (int i = 0; i < m_listeElements.size(); i++)
//     {
//         if (m_listeElements[i] == &elementGraphique)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

int ZoneDessin::indice(const ElementGraphique &elementGraphique) const
{
    // for (int i = 0; i < m_listeElements.size(); i++)
    // {
    //     if (m_listeElements[i] == elementGraphique)
    //     {
    //         return i;
    //     }
    // }

    // Avec find
    std::vector<PEG>::const_iterator it = std::find(m_listeElements.begin(), m_listeElements.end(), &elementGraphique);
    if (it != m_listeElements.end())
    {
        return it - m_listeElements.begin();
    }
    return -1;
}

void ZoneDessin::trier()
{
    std::sort(m_listeElements.begin(), m_listeElements.end());
}