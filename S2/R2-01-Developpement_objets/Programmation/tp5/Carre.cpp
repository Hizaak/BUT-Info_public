#include "Carre.h"

Carre::Carre():
    coorX(10),
    coorY(10),
    lenght(20),
    color(0,0,0) {}

Carre::Carre(const Carre& original):
    coorX(original.coorX),
    coorY(original.coorY),
    lenght(original.lenght),
    color(original.color) {}

Carre::Carre(int a, int b, int c, Couleur coul):
    coorX(a),
    coorY(b),
    lenght(c),
    color(coul) {}

void Carre::placer(int x, int y) {
	(*this).coorX = x;
	(*this).coorY = y;
}

int Carre::coordX() const {
	return (*this).coorX;
}

int Carre::coordY() const {
	return (*this).coorY;
}

void Carre::dimensionner(int lenght) {
	(*this).lenght = lenght;
}

int Carre::cote() const {
	return (*this).lenght;
}

void Carre::definirCouleur(int R, int G, int B) {
	(*this).color.definir(R,G,B);
}

void Carre::definirCouleur(Couleur color) {
	(*this).color.definir(color.rouge(),color.vert(),
				color.bleu());
}

Couleur Carre::couleur() const {
	return (*this).color;
}

void Carre::afficher(Fenetre& f) const {
	(*this).dessiner(f, (*this).color);
}

void Carre::effacer(Fenetre& f) const {
	(*this).dessiner(f, f.couleurFond());
}

bool Carre::touche(int x, int y) const {
	if ((((*this).coorX <= x) && ((*this).coorX + (*this).lenght) >= x ) &&
	   (((*this).coorY <= y) && ((*this).coorY + (*this).lenght) >= y )) {
		return true;
	} else {
		return false;
	}
}

void Carre::dessiner(Fenetre& f, Couleur c) const {
	f.choixCouleurTrace(c);

	f.traceLigne((*this).coorX,	(*this).coorY,		(*this).coorX,		 (*this).coorY + (*this).lenght, 1);

	f.traceLigne((*this).coorX,	(*this).coorY,	(*this).coorX + (*this).lenght+1,	 (*this).coorY, 1);

	f.traceLigne((*this).coorX + (*this).lenght,	(*this).coorY,	(*this).coorX + (*this).lenght,	 (*this).coorY+ (*this).lenght, 1);

	f.traceLigne((*this).coorX,	(*this).coorY + (*this).lenght,	(*this).coorX + (*this).lenght+1, 	(*this).coorY+ (*this).lenght, 1);
}
