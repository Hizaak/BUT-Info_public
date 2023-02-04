/**
 * @file main.cpp
 * @brief Exemples d'utilisation de pair, de list et de map
 * @author Lopistéguy
 * @version 0.1
 * @date jj/mm/aaa
 */

#include <iostream>
#include <map>
#include <list>

using namespace std;

/// @fn listeSimple
////////////////////////////////////////////////
void listeSimple() {

	// Définit une classe ListeS, pour instancier des listes de strings
	typedef list<string> ListeS;

	// Crée un objet uneListeS, instance de ListeS
	ListeS uneListeS;

	// Alimente la liste avec "Pantxika", "Yann", "Philippe" et "Patrick"
	uneListeS.push_back (ListeS::value_type ("Pantxika"));
	uneListeS.push_back (ListeS::value_type ("Yann"));
	uneListeS.push_back (ListeS::value_type ("Philippe"));
	uneListeS.push_back (ListeS::value_type ("Patrick"));

	// Crée un itérateur pour parcourir les éléments qui composent les listes
             // qui sont instances de la classe ListeS
	ListeS::iterator iterateurDeListeS; 	// Peut contenir d’adresse d’un élément qui
                                            // compose une liste instance de ListeS
	// Initialise l'itérateur au premier élément de l’instance uneListeS
	iterateurDeListeS = uneListeS.begin();

	// Parcours complet de la liste uneListeS et affiche chaque élément
	while (iterateurDeListeS != uneListeS.end()) {
		cout << *iterateurDeListeS << endl;
		iterateurDeListeS++;		        // Accède à l’élément suivant qui compose la liste
	}
}


/// @fn listePaires
////////////////////////////////////////////////
void listePaires () {
	// a. Définit le type PairStringString
	typedef pair <string, string> PairStringString;

	// b. Définit une classe ListeP, liste de paires de strings
	typedef list <PairStringString> ListeP;

	// Ou bien a. & b. d’un seul coup : définition d’une classe ListeP, liste de paires de strings
    /*  typedef list <pair <string, string> > ListeP;  */

	// Crée un objet uneListeP, instance de la ListeP
	ListeP uneListeP;

	// Alimente la liste avec des valeurs
	uneListeP.push_back (ListeP::value_type ("Pantxika ", "06.01.01.01.01"));
	uneListeP.push_back (ListeP::value_type ("Yann", "06.02.02.02.02"));
	uneListeP.push_back (ListeP::value_type ("Philippe", "06.03.03.03.03"));
	uneListeP.push_back (ListeP::value_type ("Patrick", "06.04.04.04.04"));

	// Crée un itérateur pour parcourir les éléments qui composent les instances de ListeP
	ListeP::iterator iterateurDeListeP;

	// Initialise l'iterateur au premier element de uneListeP, instance de ListeP
	iterateurDeListeP = uneListeP.begin();

	// Parcours complet de la liste uneListeP et affiche les composants de chacun de ses elements
	while (iterateurDeListeP != uneListeP.end()) {
		cout << iterateurDeListeP->first << " - " << iterateurDeListeP->second << endl;
		iterateurDeListeP++;                // Accède à l'élément suivant
	}
}


/// @fn leMap
////////////////////////////////////////////////
void leMap ()
{
/// DELCARATIONS

    // Définit une classe Annuaire, une map de string avec string en clef
    typedef map <string, string> Annuaire;

    // Crée un objet unAnnuaire, instance de Annuaire
    Annuaire unAnnuaire;

    // Etablit le type IterateurAnnuaire
    typedef Annuaire::iterator IterateurAnnuaire;

    // Crée resultatInsert une paire de valeurs qui récupère le résultat d’une insertion
    pair <IterateurAnnuaire, bool> resultatInsert;  // On aurait pu passer par un typedef
    // La seconde valeur vaut true si l'insertion est frustueuse et false sinon
    // En cas d'insertion fructueuse, la première valeur contient l'adresse de l'élément inséré
    // En cas d'insertion infructueuse, la première valeur contient l'adresse de l'élément ayant
    // la même clef

/// TRAITEMENTS

    // Alimente l'annuaire avec "Pantxika", "06.01.01.01.01" et teste le résultat
    resultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxika", "06.01.01.01.01"));
    if (resultatInsert.second == true) 	     	// Si insertion fructueuse
        cout << "Insertion " << resultatInsert.first -> first
             << " BIEN realisee" << endl;
    else                                    	// Sinon
        cout << "Insertion MAL realisee" << endl;

    // Réalimente l'annuaire avec "Pantxika", "06.01.01.01.01" et teste le résultat
    resultatInsert=unAnnuaire.insert(Annuaire::value_type("Pantxika", "06.01.01.01.01"));
    if (resultatInsert.second == true)      	// Si insertion infructueuse
        cout << "Insertion " << resultatInsert.first -> first
             << " BIEN realisee" << endl;
    else                                    	// Sinon
        cout << "Insertion MAL realisee" << endl;

    // Alimente unAnnuaire de trois autres tuples
    unAnnuaire.insert (Annuaire::value_type ("Yann", "06.02.02.02.02"));
    unAnnuaire.insert (Annuaire::value_type ("Philippe", "06.03.03.03.03"));
    unAnnuaire.insert (Annuaire::value_type ("Patrick", "06.04.04.04.04"));

	// Crée un iterateur pour parcourir les objets de Annuaire
	IterateurAnnuaire    unInterateur;

	// Initialise l'iterateur au premier élément de unAnnuaire
	unInterateur = unAnnuaire.begin ();

    // Parcours complet de la liste et affiche le second composant de chaque élément
	while (unInterateur != unAnnuaire.end()) {
		cout << unInterateur -> second << endl;
		unInterateur ++;         // Accès à l’élément suivant
	}

	// La méthode find() retourne un itérateur sur la paire de clefRecherchee ou bien sur end()
	string clefRecherchee = "Philippe";
    unInterateur = unAnnuaire.find (clefRecherchee);

	// Affiche le numéro de téléphone ou bien : Philippe - clef inconnue
	if (unInterateur != unAnnuaire.end())
            cout << clefRecherchee << "  - telephone : " << unInterateur->second << endl;
    else 	cout << clefRecherchee  << " clef inconnue" << endl;
}


/// @fn main()
////////////////////////////////////////////////
main ()
{
    cout << "### LISTE SIMPLE\n";
    listeSimple ();

    cout << "\n\n### LISTE DE PAIRES\n";
    listePaires ();

    cout << "\n\n### MAP\n";
    leMap ();
}

