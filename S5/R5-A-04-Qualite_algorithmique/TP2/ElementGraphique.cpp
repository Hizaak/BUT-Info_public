#include "ElementGraphique.hpp"

ElementGraphique::ElementGraphique() : m_point()
{
}

ElementGraphique::ElementGraphique(const ElementGraphique &elementGraphique) : m_point(elementGraphique.m_point)
{
}

ElementGraphique::ElementGraphique(const Point &point) : m_point(point)
{
}

void ElementGraphique::placer(const Point &point)
{
    m_point = point;
}

Point ElementGraphique::position() const
{
    return m_point;
}

ElementGraphique::~ElementGraphique()
{
}

std::ostream &operator<<(std::ostream &os, const ElementGraphique &elementGraphique)
{
    os << "Elementgraphique" << elementGraphique.m_point;
    return os;
}

bool ElementGraphique::operator==(const ElementGraphique &opD) const
{
    return (this->position().x() == opD.position().x()) && (this->position().y() == opD.position().y());
}