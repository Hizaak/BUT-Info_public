#include <iostream>
#include "Point.hpp"

#ifndef ELEMENTGRAPHIQUE_H
#define ELEMENTGRAPHIQUE_H

class ElementGraphique
{
    private:
        Point m_point;
    public:
        ElementGraphique();
        ElementGraphique(const ElementGraphique& elementGraphique);
        ElementGraphique(const Point& point);
        virtual ~ElementGraphique()=0;

        void placer(const Point& point);
        Point position() const;

        friend std::ostream& operator<<(std::ostream& os, const ElementGraphique& elementGraphique);
        virtual bool operator==(const ElementGraphique& opD) const;
};

#endif // ELEMENTGRAPHIQUE_H