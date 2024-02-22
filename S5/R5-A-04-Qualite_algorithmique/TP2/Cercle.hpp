#include <iostream>
#include "ElementGraphique.hpp"

#ifndef CERCLE_HPP
#define CERCLE_HPP

class Cercle: public ElementGraphique
{
private:
    int m_rayon;
public:
    Cercle();
    Cercle(const Cercle& cercle);
    Cercle(const Point& point, int rayon);
    virtual ~Cercle();

    void definirRayon(int rayon);
    int rayon() const;

    friend std::ostream& operator<<(std::ostream& os, const Cercle& cercle);

    bool operator==(const Cercle& opD) const;
    bool operator==(const ElementGraphique& opD) const;
};

#endif // CERCLE_HPP