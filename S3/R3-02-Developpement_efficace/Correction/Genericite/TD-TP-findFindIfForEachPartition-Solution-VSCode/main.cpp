/**
 * @file main.cpp
 * @brief Exemples d'utilisation de find, find_if, for_each et partition
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include <iostream>
// #include <string>
using namespace std;

#include <map>
#include <list>
#include <algorithm>

typedef string Libelle;
typedef string Reference;
typedef int    Prix;
typedef int    Poids;

/** CODE RELATIF A map::find() **/

void exempleFind() {

    /// DEFINITION D'UN MAP DANS LEQUEL ON VA RECHERCHER

    // Création de la classe MapDeProduits
    typedef map<Reference, pair<Libelle, Prix> >  MapDeProduits;

    // Déclaration de l'objet unMapDeProduits
    MapDeProduits unMapDeProduits;

    // Préparation des valeurs pour peupler unMapDeProduits
    pair<Libelle, Prix>  p1 ("Canape", 10) ;
    pair<Libelle, Prix>  p2 ("Fauteuil", 200);
    Reference           reference1 = "T001";
    Reference           reference2 = "T002";

    // Peuplement de unMapDeProduits
    unMapDeProduits.insert (MapDeProduits::value_type(reference1, p1));
    unMapDeProduits.insert (MapDeProduits::value_type(reference2, p2));

    /// RECHERCHE DANS LE MAP

    // Déclaration de la référence à rechercher
    Reference referenceRecherchee;

    // Déclaration du pointeur existe pour récupérer le résultat de la recherche
    MapDeProduits::iterator existe;  // Le type iterator est défini  d a n s  MapDeProduits

    // Initier une recherche fructueuse
    referenceRecherchee = "T002";     /* Cette référence est dans le map */
    existe = unMapDeProduits.find (referenceRecherchee);  // On récupère le résultat du find()
    // La variable existe pointe sur une paire (key_type, value_type) et ici,
    // value_type est une paire du type (Libelle, Prix)
    if (existe == unMapDeProduits.end())       // La recherche a-t-elle échoué ?
        cout << referenceRecherchee << " n'existe pas\n";
    else                                       // La recherche a réussi !!!
        cout << referenceRecherchee   << " "
             << existe->second.first  << " vaut " // Affiche le libelle
             << existe->second.second << endl;    // Affiche le prix

    // Initier une recherche NON fructueuse
    referenceRecherchee = "X007"; /* Cette référence N'EST PAS dans le map */
    existe = unMapDeProduits.find (referenceRecherchee);
    // La variable existe pointe sur une paire (key_type, value_type) et ici,
    // value_type est une paire du type (Libelle, Prix)
    if (existe == unMapDeProduits.end())   // La recherche a-t-elle échoué ?
        cout << referenceRecherchee << " n'existe pas\n";
    else                                   // La recherche a réussi !!!
        cout << referenceRecherchee   << " "
             << existe->second.first  << " vaut "
             << existe->second.second << endl;
};

/** CODE RELATIF A find_if() **/

/// TROIS DECLARATIONS GLOBALES

// 1/3 : Classe Produits dont l'instance uneListeDeProduits sera peuplée
class Produits {
    // ATTRIBUTS
    public:
        Reference laReference;
        Libelle   libelle;
        Prix      prix;
    // CONSTRUCTEUR
    public:
        Produits (Reference laRef = "", Libelle lib = "", Prix p = 0) {
                  laReference = laRef; libelle = lib; prix = p;
        };
    // METHODE USUELLE : toString
    public:
        string toString(string message="") {
            string resultat =  message;
            resultat += "Reference:" + laReference + "  Libelle:" + libelle;
            resultat += "  Prix:" + to_string(prix);
            return resultat;
        };
};

// 2/3 : Variable globale qui représente la référence du produit à chercher dans listeDeProduits
Reference referenceCherchee;

// 3/3 : Fonction booleenne invoquée depuis le find_if pour chacun des Produits de SA séquence
bool memeReference (Produits produit) {
    return (produit.laReference == referenceCherchee);
}

/// FONCTION D'UTILISATION DE find_if()

void exempleFindIf(){

    // Préparation des 3 produits pour peupler uneListeDeProduits
    Produits produit1 ("P001", "Tabouret", 10);
    Produits produit2 ("P002", "Chaise", 20);
    Produits produit3 ("P003", "Table", 30);

    // Creation de uneListeDeProduits
    typedef list<Produits> ListeDeProduits;    // Définition de la classe ListeDeProduits
    ListeDeProduits        uneListeDeProduits; // Déclaration de l’instance uneListeDeProduits

    // Peuplement de uneListeDeProduits
    uneListeDeProduits.push_back(ListeDeProduits::value_type(produit1));
    uneListeDeProduits.push_back(ListeDeProduits::value_type(produit2));
    uneListeDeProduits.push_back(ListeDeProduits::value_type(produit3));

    // Declaration du pointeur existe pour récupérer le résultat de la recherche
    ListeDeProduits::iterator existe;   // Le type iterator est défini   d a n s   ListeDeProduits

    // Initier une recherche fructueuse
    referenceCherchee = "P002";     /* Cette référence est dans uneListeDeProduits */

    // Lance la fonction memeReference() sur la section [begin..end[ de uneListeDeProduits
    existe = find_if (uneListeDeProduits.begin(), uneListeDeProduits.end(), memeReference);
    if (existe == uneListeDeProduits.end())
        cout << referenceCherchee << " n'existe pas\n";
    else
        cout << referenceCherchee << " existe " << existe->libelle << endl;

    // Initier une recherche NON fructueuse
    referenceCherchee = "Y001";     /* Cette référence N'EST PAS dans uneListeDeProduits */
    // Lance la fonction memeReference() sur la section [begin..end[ de uneListeDeProduits
    existe = find_if (uneListeDeProduits.begin(), uneListeDeProduits.end(), memeReference);
    if (existe == uneListeDeProduits.end())
        cout << referenceCherchee << " n'existe pas\n";
    else
        cout << referenceCherchee << " existe " << existe->libelle << endl;
}

/** CODE RELATIF A for_each ET partition() **/

/// QUATRE DECLARATIONS GLOBALES

// 1/4 : Classe Pieces dont l'instance uneListeDePieces sera peuplée

class Pieces {
public:
    Reference laReference;
    Libelle   libelle;
    Prix      prix;
    Poids     poids;

public:
    Pieces (Reference laRef = "", Libelle lib = "", Prix px= 0, Poids pds = 0) {
        laReference = laRef; libelle = lib; prix = px, poids = pds;
    }

    string toString(string message="") {
        string resultat =  message;
        resultat += "Reference:" + laReference + "  Libelle:" + libelle;
        resultat += "  Poids:"  + to_string(poids) + "  Prix:" + to_string(prix);
        return resultat;
    }
};

// 2/4 : Fonction qui affiche les attributs d'une piece
void afficher (Pieces* piece) {
    cout << piece->toString() << endl;
}

// 3/4 : Fonction qui augmente le prix d'une pièce qui pèse plus de 80kg
void surPoids (Pieces* piece) {
    if (piece->poids > 80) piece->prix *= 1.1;
}

// 4/4 : Fonction qui dit si une pièce coute plus de 100 euros
bool tropCestTrop (Pieces* piece) {
    return (piece->prix > 100);
}

/// FONCTION D'UTILISATION DE for_each ET DE partition

void exempleForEachPartition() {

    // Préparation des Pieces
    Pieces piece1 ("E001", "Ecrou", 10, 90), piece2 ("B001", "Boulon", 20, 100), piece3 ("R001", "Rondelle", 100, 1000), piece4 ("C001", "ContrEcrou", 40);

    // Creation de uneListeDePoiteces
    typedef list<Pieces*> ListeDePieces;    // Définit la classe ListeDePieces
    ListeDePieces         uneListeDePieces;	// Déclare l’instance uneListeDePieces


    // Peuplement de uneListeDePieces
    uneListeDePieces.push_back(ListeDePieces::value_type(&piece1));
    uneListeDePieces.push_back(ListeDePieces::value_type(&piece2));
    uneListeDePieces.push_back(ListeDePieces::value_type(&piece3));
    uneListeDePieces.push_back(ListeDePieces::value_type(&piece4));

    cout << "Affichage de toutes les pieces\n";
    for_each (uneListeDePieces.begin(), uneListeDePieces.end(), afficher);

    // + 10% sur les pieces de plus de 80 kg
    for_each (uneListeDePieces.begin(), uneListeDePieces.end(), surPoids);
	// Visualisation du résultat
    cout << "\nAffichage des pieces apres augmentation de 10% des plus de 80 kg\n";
    for_each (uneListeDePieces.begin(), uneListeDePieces.end(), afficher);

    // Reorganise la liste avec les plus de 100euros en début les autres en fin
    ListeDePieces::iterator finDesLourdes = partition(uneListeDePieces.begin(), uneListeDePieces.end(), tropCestTrop);

    cout << "\nAffichage des pieces de PLUS de 100 euros\n";
    for_each (uneListeDePieces.begin(), finDesLourdes, afficher);

    cout << "\nAffichage des pieces de MOINS de 100 euros\n";
    for_each (finDesLourdes, uneListeDePieces.end(), afficher);

}

int main () {
    cout << "##### EXEMPLE map::find #####\n";
    exempleFind();
    cout << "\n\n\n##### EXEMPLE find_if #####\n";
    exempleFindIf();
    cout << "\n\n\n##### EXEMPLE for_each ET partition #####\n";
    exempleForEachPartition();
}
