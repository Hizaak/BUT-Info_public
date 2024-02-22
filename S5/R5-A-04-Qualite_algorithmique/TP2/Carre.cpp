#include "Carre.hpp"

Carre::Carre():
    ElementGraphique (),
    m_cote (0)
{
}

Carre::Carre(const Carre& carre):
    ElementGraphique (carre),
    m_cote (carre.m_cote)
{
}

Carre::Carre(const Point& point, int cote):
    ElementGraphique (point),
    m_cote (cote)
{
}

Carre::~Carre()
{
}

void Carre::definirCote(int cote)
{
    m_cote = cote;
}

int Carre::cote() const
{
    return m_cote;
}


std::ostream& operator<<(std::ostream& os, const Carre& carre)
{
    // Compatible C :
    // os << "Carre de cote : " << carre.m_cote << " " << *((ElementGraphique*)&carre);
    // OU ALORS :
    os << "Carre de cote : " << carre.m_cote << " " << *(static_cast<const ElementGraphique*>(&carre));
    return os;
}

bool Carre::operator==(const Carre &opD) const
{
    return (this->cote() == opD.cote()) && (this->ElementGraphique::operator==(opD));
}

bool Carre::operator==(const ElementGraphique &opD) const
{
    if (typeid(opD) == typeid(*this))
    {
        // return (*this == (Carre&)opD);
        return ((*this) == static_cast<const Carre &>(opD));
    }
    return false;
}