#include "Cercle.hpp"

Cercle::Cercle() : ElementGraphique(),
                   m_rayon(0)
{
}

Cercle::Cercle(const Cercle &cercle) : ElementGraphique(cercle),
                                       m_rayon(cercle.m_rayon)
{
}

Cercle::Cercle(const Point &point, int rayon) : ElementGraphique(point),
                                                m_rayon(rayon)
{
}

Cercle::~Cercle()
{
}

void Cercle::definirRayon(int rayon)
{
    m_rayon = rayon;
}

int Cercle::rayon() const
{
    return m_rayon;
}

std::ostream &operator<<(std::ostream &os, const Cercle &cercle)
{
    // Compatible C :
    // os << "Cercle de rayon : " << cercle.m_rayon << " " << *((ElementGraphique*)&cercle);
    // OU ALORS :
    os << "Cercle de rayon : " << cercle.m_rayon << " " << *(static_cast<const ElementGraphique *>(&cercle));
    return os;
}

bool Cercle::operator==(const Cercle &opD) const
{
    return (this->rayon() == opD.rayon()) && (this->ElementGraphique::operator==(opD));
}
bool Cercle::operator==(const ElementGraphique &opD) const
{
    if (typeid(opD) == typeid(*this))
    {
        // return (*this == (Cercle&)opD);
        return ((*this) == static_cast<const Cercle &>(opD));
    }
    else
    {
        return false;
    }
}