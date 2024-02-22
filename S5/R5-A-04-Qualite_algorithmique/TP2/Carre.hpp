#include <iostream>
#include "ElementGraphique.hpp"

#ifndef CARRE_HPP
#define CARRE_HPP

class Carre: public ElementGraphique
{
    private:
        int m_cote;
    public:
        Carre();
        Carre(const Carre& carre);
        Carre(const Point& point, int cote);
        virtual ~Carre();

        void definirCote(int cote);
        int cote() const;
        
        friend std::ostream& operator<<(std::ostream& os, const Carre& carre);
        bool operator==(const Carre& opD) const;
        bool operator==(const ElementGraphique& opD) const;
};

#endif // CARRE_H