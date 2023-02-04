#include <iostream>
#include <map>
#include <algorithm>
#include <list>

using namespace std;

// Définition de 4 types de données : Libelle, Reference, Prix et Poids
typedef string Libelle;
typedef string Reference;
typedef int Prix;
typedef int Poids;
typedef Reference referenceCherchee;

// 1.1. Créer une classe MapDeProduits sur la base d’un map, telle que la clef est une référence du type string et la valeur est une pair composée d’un libellé et d’un prix.
class MapDeProduit : public map<Reference, pair<Libelle,Prix>> {
    public:

};


class Produit{
    public:
        Reference _reference;
        Libelle _libelle;
        Prix prix;

    // Constructeur
    Produit(Reference reference, Libelle libelle, Prix prix) : _reference(reference), _libelle(libelle), prix(prix) {}
    //Constructeur par copie
    Produit(const Produit& produit) : _reference(produit._reference), _libelle(produit._libelle), prix(produit.prix) {}

    // getter
    Reference getReference() const { return _reference; }
    Libelle getLibelle() const { return _libelle; }
    Prix getPrix() const { return prix; }

    string to_string() const {
        return _reference + " " + _libelle;
    }
};


class Piece{
    private :
        Reference _reference;
        Libelle _libelle;
        Prix prix;
        Poids poids;
    
    public:
        // Constructeur
        Piece(Reference reference, Libelle libelle, Prix prix, Poids poids) : _reference(reference), _libelle(libelle), prix(prix), poids(poids) {}
        //Constructeur par copie
        Piece(const Piece& piece) : _reference(piece._reference), _libelle(piece._libelle), prix(piece.prix), poids(piece.poids) {}

        // getter
        Reference getReference() const { return _reference; }
        Libelle getLibelle() const { return _libelle; }
        Prix getPrix() const { return prix; }
        Poids getPoids() const { return poids; }

        //setter
        void setPrix(Prix prix) { this->prix = prix; }

        string to_string() const {
            return _reference + " " + _libelle;
        }
};

void afficher(Piece* unePiece){
    cout << unePiece->to_string() << endl;
}

void surPoids(Piece* unePiece){
    if(unePiece->getPoids() > 80){
        unePiece->setPrix(unePiece->getPrix() * 1.1);
    }
}

bool tropCestTrop(Piece* unePiece){
    return unePiece->getPoids() > 100;
}

bool memeReference(Produit laReference, Produit leProduit) {
    return laReference._reference == leProduit._reference;
}

void exempleFindIf(){
    Produit p1("ref1", "libelle1", 10);
    Produit p2("ref2", "libelle2", 20);
    Produit p3("ref3", "libelle3", 30);
    Produit p4(p1);
    cout << memeReference(p1, p2);
    cout << memeReference(p1, p4);
}

void exempleForEachEtPartition(){
    Piece p1("ref1", "libelle1", 10, 80);
    Piece p2("ref2", "libelle2", 20, 90);
    Piece p3("ref3", "libelle3", 30, 100);
    Piece p4("ref4", "libelle4", 40, 110);

    list<Piece*> listeDePiece;
    listeDePiece.push_back(&p1);
    listeDePiece.push_back(&p2);
    listeDePiece.push_back(&p3);
    listeDePiece.push_back(&p4);


    for_each(listeDePiece.begin(), listeDePiece.end(), afficher);
    for_each(listeDePiece.begin(), listeDePiece.end(), surPoids);

    partition(listeDePiece.begin(), listeDePiece.end(), tropCestTrop);
    for_each(listeDePiece.begin(), listeDePiece.end(), afficher);
}

int main(void){
    // 1.2. Déclarer unMapDeProduits instance de cette classe.
    MapDeProduit uneMapDeProduit;
    // 1.3. Alimenter unMapDeProduits avec 3 produits différents.
    uneMapDeProduit["1234"] = make_pair("Produit 1", 10);
    uneMapDeProduit["5678"] = make_pair("Produit 2", 20);
    uneMapDeProduit["9012"] = make_pair("Produit 3", 30);

    // On recherche le produit 5678
    MapDeProduit::iterator it = uneMapDeProduit.find("1234");
    if (it != uneMapDeProduit.end()) {
        cout << "Produit trouvé : " << it->second.first << " - " << it->second.second << endl;
    } else {
        cout << "Produit non trouvé" << endl;
    }
    
    //Recherche d'un produit qui n'existe pas
    it = uneMapDeProduit.find("0000");
    if (it != uneMapDeProduit.end()) {
        cout << "Produit trouvé : " << it->second.first << " - " << it->second.second << endl;
    } else {
        cout << "Produit non trouvé" << endl;
    }


    Produit unProduit("1234", "Produit 1", 10);
    // On affiche unProduit
    
    exempleFindIf();

    exempleForEachEtPartition();

    return 0;
}
