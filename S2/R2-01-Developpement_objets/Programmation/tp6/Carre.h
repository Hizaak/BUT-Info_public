#ifndef _CARRE
#define _CARRE
#include "Couleur.h"
#include "Fenetre.h"
class Carre{
    private:
        int m_coordx,m_coordy,m_longueur;
        Couleur m_couleur;
        void dessiner(Fenetre&,Couleur c)const;
    public:
        //Constructeur

        Carre(const Carre&);//De copie
        Carre();//par defaut
        Carre(int, int, int, Couleur = Couleur(0,0,0));//constructeur special


        void placer(int,int);
        int coordX()const;
        int coordY()const;
        void dimensionner(int);
        int cote()const;
        void definirCouleur(int,int,int);
        void definirCouleur(Couleur);
        Couleur couleur()const;
        void afficher(Fenetre&)const;
        void effacer(Fenetre&)const;
        bool touche(int,int)const;

};


#endif
